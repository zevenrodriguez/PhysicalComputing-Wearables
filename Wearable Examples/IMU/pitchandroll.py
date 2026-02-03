import time
import math
import board
from adafruit_lis3mdl import LIS3MDL

i2c = board.I2C()  # uses board.SCL and board.SDA
# i2c = board.STEMMA_I2C()  # For using the built-in STEMMA QT connector on a microcontroller

# check for LSM6DS33 or LSM6DS3TR-C Accelerometer/Gyro
try:
    from adafruit_lsm6ds.lsm6ds33 import LSM6DS33 as LSM6DS
    sensor = LSM6DS(i2c)
except RuntimeError:
    from adafruit_lsm6ds.lsm6ds3trc import LSM6DS3TRC as LSM6DS
    sensor = LSM6DS(i2c)

lis3mdl = LIS3MDL(i2c) # Optional: For compass heading, not required for step counting

from adafruit_lsm6ds import Rate
from adafruit_lsm6ds import GyroRange
from adafruit_lsm6ds import AccelRange

sensor.accelerometer_range = AccelRange.RANGE_2G
print("Accelerometer range set to: %d G" % AccelRange.string[sensor.accelerometer_range])

sensor.gyro_range = GyroRange.RANGE_125_DPS
print("Gyro range set to: %d DPS" % GyroRange.string[sensor.gyro_range])

sensor.accelerometer_data_rate = Rate.RATE_12_5_HZ
print("Accelerometer rate set to: %d HZ" % Rate.string[sensor.accelerometer_data_rate])

sensor.gyro_data_rate = Rate.RATE_12_5_HZ
print("Gyro rate set to: %d HZ" % Rate.string[sensor.gyro_data_rate])

alpha = 0.98
roll = 0.0
pitch = 0.0
t_prev = time.monotonic()

# assuming gyro.gyro or gyro.gyro_rate returns (x,y,z) in deg/s
while True:
    ax, ay, az = sensor.acceleration  # m/s^2
    gx, gy, gz = sensor.gyro  # deg/s

    t_now = time.monotonic()
    dt = t_now - t_prev
    t_prev = t_now

    # integrate gyro
    roll += gx * dt
    pitch += gy * dt

    # accel-based angles
    roll_acc = math.degrees(math.atan2(ay, az))
    pitch_acc = math.degrees(math.atan2(-ax, math.sqrt(ay*ay + az*az)))

    # complementary filter
    roll = alpha * roll + (1 - alpha) * roll_acc
    pitch = alpha * pitch + (1 - alpha) * pitch_acc

    print("roll:", roll, "pitch:", pitch)

    time.sleep(0.05)