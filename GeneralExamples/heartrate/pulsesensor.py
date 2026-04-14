# =============================================================
#  PulseSensor — CircuitPython Port
#  Based on pulsesensor.com Arduino Playground examples:
#    • GettingStartedProject  (signal read + LED blink)
#    • Getting_BPM_to_Monitor (BPM + IBI calculation)
#
#  Tested boards: Raspberry Pi Pico, Adafruit Feather RP2040,
#                 QT Py RP2040, XIAO RP2040, Metro M4 Express
#
#  Wiring:
#    PulseSensor RED   → 3.3 V  (or 5 V if your board has it)
#    PulseSensor BLACK → GND
#    PulseSensor PURPLE→ analog input pin (change ANALOG_PIN below)
#    Optional LED      → LED_PIN (any digital-out pin)
# =============================================================

import time
import board
import analogio
import digitalio

# ── User settings ────────────────────────────────────────────
ANALOG_PIN  = board.A0          # Purple signal wire
LED_PIN     = board.LED         # Built-in LED blinks with heartbeat

# Threshold: 0–65535 (CircuitPython ADC is 16-bit, not 10-bit)
# Arduino default 550/1024 → scaled: round(550/1024 * 65535) ≈ 35200
# Raise this number to decrease sensitivity; lower it to increase.
THRESHOLD   = 35200

SAMPLE_HZ   = 500               # How often we read the sensor (Hz)
SAMPLE_INTERVAL = 1.0 / SAMPLE_HZ   # seconds between samples

# BPM averaging window — number of IBI samples to average
IBI_HISTORY_SIZE = 10
# =============================================================


# ── Hardware setup ───────────────────────────────────────────
sensor = analogio.AnalogIn(ANALOG_PIN)

led = digitalio.DigitalInOut(LED_PIN)
led.direction = digitalio.Direction.OUTPUT


# ── State variables (mirrors Arduino Playground globals) ─────
signal          = 0       # raw ADC reading
bpm             = 0       # beats per minute
ibi             = 600     # interbeat interval in ms (seed 600)
pulse           = False   # True while signal is above threshold
first_beat      = True    # used to seed the IBI history
second_beat     = False

rate            = [0] * IBI_HISTORY_SIZE   # IBI history ring buffer
last_beat_time  = 0       # time (ms) of last detected beat
peak            = 2048    # highest point in the pulse wave (16-bit midpoint)
trough          = 65535   # lowest  point in the pulse wave
amplitude       = 100     # peak–trough; used for adaptive threshold
threshold_level = THRESHOLD

last_sample_time = 0      # tracks when we last sampled


def millis():
    """Return elapsed milliseconds (matches Arduino millis())."""
    return int(time.monotonic() * 1000)


def read_pulse():
    """
    Called at SAMPLE_HZ.  Updates global state exactly like the
    Arduino Timer-interrupt ISR in PulseSensor_BPM.
    Returns (bpm, ibi, pulse_detected_this_sample).
    """
    global signal, bpm, ibi, pulse, first_beat, second_beat
    global rate, last_beat_time, peak, trough, amplitude, threshold_level

    now    = millis()
    signal = sensor.value          # 0–65535 (16-bit)
    beat_found = False

    # Track the rising and falling edges of the pulse wave
    if signal < threshold_level and pulse:
        # Signal dropped back below threshold → end of beat
        pulse = False
        led.value = False
        amplitude     = peak - trough
        threshold_level = amplitude // 2 + trough   # adaptive threshold
        peak   = threshold_level
        trough = threshold_level

    if signal > threshold_level and not pulse:
        # Signal just rose above threshold → new beat detected
        pulse = True
        led.value = True
        ibi_ms = now - last_beat_time
        last_beat_time = now
        beat_found = True

        if second_beat:
            second_beat = False
            # Seed all IBI history with the very first real IBI
            for i in range(IBI_HISTORY_SIZE):
                rate[i] = ibi_ms

        if first_beat:
            first_beat  = False
            second_beat = True
            # Can't trust the very first IBI — skip BPM calc this round
            return bpm, ibi, False

        # Shift IBI history and add latest value
        rate_total = 0
        for i in range(IBI_HISTORY_SIZE - 1):
            rate[i]     = rate[i + 1]
            rate_total += rate[i]
        rate[IBI_HISTORY_SIZE - 1] = ibi_ms
        rate_total += ibi_ms

        ibi = ibi_ms
        bpm = int(60000 / (rate_total // IBI_HISTORY_SIZE))

    # Track wave peak and trough between beats
    if pulse:
        if signal > peak:
            peak = signal
    else:
        if signal < trough:
            trough = signal

    return bpm, ibi, beat_found


# ── Main loop ────────────────────────────────────────────────
print("PulseSensor CircuitPython — place finger on sensor…")
print("Signal | BPM | IBI(ms)")

beat_count = 0

while True:
    now = millis()

    # Only sample at SAMPLE_HZ — no blocking sleep, stays responsive
    if (now - last_sample_time) >= int(SAMPLE_INTERVAL * 1000):
        last_sample_time = now
        current_bpm, current_ibi, new_beat = read_pulse()

        if new_beat:
            beat_count += 1
            print(f"♥  Beat #{beat_count}  BPM: {current_bpm}  IBI: {current_ibi} ms")

        # Uncomment the line below to stream raw signal to Serial Plotter
        # print(signal)
