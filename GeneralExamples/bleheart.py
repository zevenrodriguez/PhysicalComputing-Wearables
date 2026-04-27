import time
import board
import digitalio
from adafruit_ble import BLERadio
from adafruit_ble.advertising.standard import ProvideServicesAdvertisement
from adafruit_ble.services.nordic import UARTService
from max30102 import MAX30102

import busio

class LockingI2C:
    def __init__(self, i2c):
        self._i2c = i2c

    def writeto(self, addr, buf, **kwargs):
        while not self._i2c.try_lock():
            pass
        try:
            self._i2c.writeto(addr, buf, **kwargs)
        finally:
            self._i2c.unlock()

    def readfrom_into(self, addr, buf, **kwargs):
        while not self._i2c.try_lock():
            pass
        try:
            self._i2c.readfrom_into(addr, buf, **kwargs)
        finally:
            self._i2c.unlock()

    def readfrom_mem_into(self, addr, reg, buf):
        while not self._i2c.try_lock():
            pass
        try:
            self._i2c.writeto(addr, bytes([reg]))
            self._i2c.readfrom_into(addr, buf)
        finally:
            self._i2c.unlock()

    def writeto_mem(self, addr, reg, data):
        while not self._i2c.try_lock():
            pass
        try:
            self._i2c.writeto(addr, bytes([reg]) + bytes(data))
        finally:
            self._i2c.unlock()
            
# Then use it like this:
raw_i2c = busio.I2C(board.SCL, board.SDA)
sensor = MAX30102(i2c=LockingI2C(raw_i2c))
sensor.setup_sensor()

# --- BLE Setup ---
ble  = BLERadio()
uart = UARTService()
adv  = ProvideServicesAdvertisement(uart)
print(uart.uuid)

# --- LED Setup ---
led = digitalio.DigitalInOut(board.LED)
led.direction = digitalio.Direction.OUTPUT

# --- MAX30102 Setup ---
#i2c = board.I2C()
#sensor = MAX30102(i2c=i2c)
#sensor.setup_sensor()                          # defaults: LED mode 2, 400Hz, 8x avg, pw 411
sensor.set_active_leds_amplitude(0x1F)         # ~6.4mA, good for finger contact

# --- Heart Rate Detection State ---
IR_THRESHOLD  = 50000   # Below this = no finger on sensor
PEAK_MIN_FALL = 1000    # IR must drop this much after a peak to reset detector
SAMPLE_WINDOW = 10      # Beat intervals to average for BPM

ir_buffer     = []
SMOOTH_SIZE   = 16      # Rolling average window
peak_times    = []
in_peak       = False
peak_val      = 0
current_bpm   = 0


def smooth_ir(buf):
    return sum(buf) / len(buf) if buf else 0


def detect_beat(ir_smoothed, now):
    """
    Simple threshold peak detector on the smoothed IR signal.
    Returns True on the rising edge of each beat.
    """
    global in_peak, peak_val

    if ir_smoothed < IR_THRESHOLD:
        # No finger — reset state
        in_peak  = False
        peak_val = 0
        return False

    if not in_peak:
        if ir_smoothed > peak_val:
            peak_val = ir_smoothed          # Track rising signal
        else:
            # Signal started falling — we just passed a peak
            in_peak = True
            return True                     # Beat detected!
    else:
        if ir_smoothed < peak_val - PEAK_MIN_FALL:
            # Signal has fallen enough — ready to detect next peak
            in_peak  = False
            peak_val = ir_smoothed

    return False


def calculate_bpm():
    if len(peak_times) < 2:
        return 0
    intervals = [peak_times[i] - peak_times[i - 1] for i in range(1, len(peak_times))]
    avg_interval = sum(intervals) / len(intervals)
    return int(60.0 / avg_interval) if avg_interval > 0 else 0


# --- Main Loop ---
while True:
    print("Advertising...")
    ble.start_advertising(adv)

    while not ble.connected:
        pass

    ble.stop_advertising()
    print("Connected!")

    while ble.connected:

        # Handle incoming BLE commands
        if uart.in_waiting:
            msg = uart.readline().decode("utf-8").strip()
            print("Got:", msg)
            if msg == "LED_ON":
                led.value = True
            elif msg == "LED_OFF":
                led.value = False

        # Poll the sensor FIFO
        sensor.check()

        if sensor.available():
            red_sample = sensor.pop_red_from_storage()
            ir_sample  = sensor.pop_ir_from_storage()

            # Smooth the IR signal
            ir_buffer.append(ir_sample)
            if len(ir_buffer) > SMOOTH_SIZE:
                ir_buffer.pop(0)
            ir_smoothed = smooth_ir(ir_buffer)

            now = time.monotonic()

            if detect_beat(ir_smoothed, now):
                peak_times.append(now)
                if len(peak_times) > SAMPLE_WINDOW + 1:
                    peak_times.pop(0)

                new_bpm = calculate_bpm()

                # Sanity-check: only send plausible human heart rates
                if 40 <= new_bpm <= 200 and new_bpm != current_bpm:
                    current_bpm = new_bpm
                    print(f"BPM: {current_bpm}")
                    uart.write(f"{current_bpm}\n".encode())

                    # Flash LED on beat
                    led.value = True
                    time.sleep(0.05)
                    led.value = False

            elif ir_smoothed < IR_THRESHOLD and current_bpm != 0:
                # Finger removed — notify client
                current_bpm = 0
                peak_times.clear()
                ir_buffer.clear()
                print("No finger detected")
                uart.write("0\n".encode())

    print("Disconnected.")
