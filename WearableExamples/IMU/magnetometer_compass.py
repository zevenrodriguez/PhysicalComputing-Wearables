# CircuitPython example: magnetometer-as-compass (calibrate + tilt compensation)
# Save as magnetometer_compass.py on your CIRCUITPY drive or copy to your project.

import board
import busio
import time
import math

# Try to import drivers; adjust imports if your accelerometer driver differs
import adafruit_lis3mdl

# Optional: try to use LSM6DS3 accelerometer for tilt compensation if present
try:
    from adafruit_lsm6ds.lsm6ds3 import LSM6DS3
except Exception:
    LSM6DS3 = None

# Initialize I2C and sensors (adjust pins if your board differs)
i2c = busio.I2C(board.SCL, board.SDA)
mag = adafruit_lis3mdl.LIS3MDL(i2c)

accel = None
if LSM6DS3:
    try:
        accel = LSM6DS3(i2c)
    except Exception:
        accel = None

# Set your local declination in degrees (positive east, negative west)
# Replace with your location's declination (e.g., from NOAA or an online calculator)
DECLINATION_DEG = 1.5  # example: +1.5° east


def calibrate_mag(sensor, seconds=10):
    """Collect min/max per axis while rotating sensor to compute offsets and scales."""
    print("Rotate sensor in all orientations for {} seconds...".format(seconds))
    t0 = time.monotonic()
    mins = [float("inf")] * 3
    maxs = [float("-inf")] * 3
    while time.monotonic() - t0 < seconds:
        mx, my, mz = sensor.magnetic  # (uT)
        for i, v in enumerate((mx, my, mz)):
            if v < mins[i]:
                mins[i] = v
            if v > maxs[i]:
                maxs[i] = v
        time.sleep(0.05)
    offsets = [ (maxs[i] + mins[i]) / 2.0 for i in range(3) ]
    ranges = [ (maxs[i] - mins[i]) / 2.0 for i in range(3) ]
    avg = sum(ranges) / 3.0
    scales = [ (avg / r) if r != 0 else 1.0 for r in ranges ]
    print("Calibration done.")
    print("offsets:", offsets)
    print("scales:", scales)
    return offsets, scales


def apply_calibration(x, y, z, offsets, scales):
    x = (x - offsets[0]) * scales[0]
    y = (y - offsets[1]) * scales[1]
    z = (z - offsets[2]) * scales[2]
    return x, y, z


def simple_heading(mx, my):
    hd = math.degrees(math.atan2(my, mx))
    hd = (hd + 360.0) % 360.0
    return hd


def tilt_compensated_heading(mx, my, mz, ax, ay, az):
    # Normalize accelerometer (to 1 g)
    norm = math.sqrt(ax*ax + ay*ay + az*az)
    if norm == 0:
        return None
    axn, ayn, azn = ax/norm, ay/norm, az/norm

    # Compute pitch and roll (radians)
    pitch = math.asin(-axn)
    roll = math.atan2(ayn, azn)

    # Rotate magnetic vector to horizontal plane
    Xh = mx * math.cos(pitch) + mz * math.sin(pitch)
    Yh = mx * math.sin(roll) * math.sin(pitch) + my * math.cos(roll) - mz * math.sin(roll) * math.cos(pitch)

    hd = math.degrees(math.atan2(Yh, Xh))
    hd = (hd + 360.0) % 360.0
    return hd


if __name__ == "__main__":
    # Run calibration (adjust seconds as desired)
    offsets, scales = calibrate_mag(mag, seconds=12)

    # optional EMA smoothing (on heading as vector to avoid wrap issues)
    alpha = 0.2
    ema_x = None
    ema_y = None

    while True:
        mx, my, mz = mag.magnetic
        mx, my, mz = apply_calibration(mx, my, mz, offsets, scales)

        heading = None
        if accel:
            try:
                ax, ay, az = accel.acceleration  # m/s^2
                h = tilt_compensated_heading(mx, my, mz, ax, ay, az)
                if h is not None:
                    heading = h
            except Exception:
                heading = None

        if heading is None:
            # fallback to simple 2D heading using X/Y
            heading = simple_heading(mx, my)

        # apply declination
        heading = (heading + DECLINATION_DEG) % 360.0

        # smooth using vector EMA
        hx = math.cos(math.radians(heading))
        hy = math.sin(math.radians(heading))
        if ema_x is None:
            ema_x, ema_y = hx, hy
        else:
            ema_x = alpha * hx + (1 - alpha) * ema_x
            ema_y = alpha * hy + (1 - alpha) * ema_y

        smoothed = math.degrees(math.atan2(ema_y, ema_x)) % 360.0

        print("raw heading: {:.1f}°  smoothed: {:.1f}°".format(heading, smoothed))
        time.sleep(0.2)
