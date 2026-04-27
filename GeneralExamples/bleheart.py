import time
import board
import digitalio
from adafruit_ble import BLERadio
from adafruit_ble.advertising.standard import ProvideServicesAdvertisement
from adafruit_ble.services.nordic import UARTService
from adafruit_max3010x import MAX30105

# --- BLE Setup ---
ble  = BLERadio()
uart = UARTService()
adv  = ProvideServicesAdvertisement(uart)
print(uart.uuid)

# --- LED Setup ---
led = digitalio.DigitalInOut(board.LED)
led.direction = digitalio.Direction.OUTPUT

# --- MAX30102 Setup ---
i2c = board.I2C()
sensor = MAX30105(i2c)
sensor.setup_sensor()
sensor.set_led_mode(2)          # Red + IR LEDs
sensor.set_sample_rate(400)     # 400 samples/sec
sensor.set_pulse_width(411)     # Max resolution
sensor.set_led_amplitude(0x1F)  # LED brightness (0x00–0xFF)

# --- Heart Rate Detection State ---
IR_THRESHOLD    = 50000   # Minimum IR value — finger must be on sensor
PEAK_MIN_DELTA  = 500     # IR must rise by this much to count as a beat
SAMPLE_WINDOW   = 10      # Number of beat intervals to average over

ir_buffer       = []
buffer_size     = 20       # Rolling window for smoothing
peak_times      = []       # Timestamps of detected beats
last_was_peak   = False
last_peak_val   = 0
current_bpm     = 0


def smooth(buf):
    return sum(buf) / len(buf) if buf else 0


def detect_beat(ir_val, timestamp):
    """Simple peak detector. Returns True if a beat is detected."""
    global last_was_peak, last_peak_val

    if ir_val > IR_THRESHOLD:
        if not last_was_peak and ir_val > last_peak_val + PEAK_MIN_DELTA:
            last_was_peak = True
            last_peak_val = ir_val
            return True
        elif ir_val < last_peak_val - PEAK_MIN_DELTA:
            last_was_peak = False
            last_peak_val = ir_val
    else:
        # No finger detected — reset
        last_was_peak = False
        last_peak_val = 0

    return False


def calculate_bpm():
    """Calculate BPM from the last SAMPLE_WINDOW beat intervals."""
    if len(peak_times) < 2:
        return 0
    intervals = [
        peak_times[i] - peak_times[i - 1]
        for i in range(1, len(peak_times))
    ]
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

        # Read IR from MAX30102
        sensor.read_sensor()
        ir = sensor.ir

        # Smooth the IR signal
        ir_buffer.append(ir)
        if len(ir_buffer) > buffer_size:
            ir_buffer.pop(0)
        ir_smooth = smooth(ir_buffer)

        now = time.monotonic()

        # Beat detection
        if detect_beat(ir_smooth, now):
            peak_times.append(now)
            if len(peak_times) > SAMPLE_WINDOW + 1:
                peak_times.pop(0)

            new_bpm = calculate_bpm()

            # Only send if BPM is in a plausible human range
            if 40 <= new_bpm <= 200 and new_bpm != current_bpm:
                current_bpm = new_bpm
                print(f"Heart Rate: {current_bpm} BPM")
                uart.write(f"{current_bpm}\n".encode())
                led.value = True   # Flash LED on each beat
                time.sleep(0.05)
                led.value = False

        elif ir_smooth < IR_THRESHOLD:
            # No finger — notify client
            if current_bpm != 0:
                current_bpm = 0
                print("No finger detected")
                uart.write("0\n".encode())

        time.sleep(0.005)  # ~200 Hz poll rate

    print("Disconnected.")
