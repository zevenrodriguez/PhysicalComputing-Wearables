"""CircuitPython Essentials: PWM with Fixed Frequency example."""
import time
import board
import pwmio

# LED setup for most CircuitPython boards:
led = pwmio.PWMOut(board.D13, frequency=5000, duty_cycle=0)

curValue = 0

while True:
    curValue = curValue + 64
    if (curValue >=65536):
        curValue = 0
    led.duty_cycle = curValue
    print("PWM Out:" + str(curValue))
    time.sleep(0.1)