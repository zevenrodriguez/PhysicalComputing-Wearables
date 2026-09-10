"""CircuitPython Essentials PWM with variable frequency piezo example"""
import time
import board
import pwmio

# For the M0 boards:
piezo = pwmio.PWMOut(board.A2, duty_cycle=0, frequency=440, variable_frequency=True)

melody = (262, 294, 330, 349, 392, 440, 494, 523)
note_index = 0
start_time = time.monotonic()
interval = 0
playing = False

while True:
    if time.monotonic() - start_time > interval:
        playing = not playing
        if playing:
            piezo.frequency = melody[note_index]
            piezo.duty_cycle = 65535 // 2
            note_index = (note_index + 1) % len(melody)
            interval = 0.25
        else:
            piezo.duty_cycle = 0
            interval = 0.5 if note_index == 0 else 0.05

        start_time = time.monotonic()
