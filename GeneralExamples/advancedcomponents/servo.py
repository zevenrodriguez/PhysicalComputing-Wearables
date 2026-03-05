# Write your code here :-)
"""CircuitPython Essentials Servo standard servo example"""
import time
import board
import pwmio
# from adafruit_motor folder import servo module
from adafruit_motor import servo

# create a PWMOut object on Pin A2.
pwm = pwmio.PWMOut(board.A2, duty_cycle=2 ** 15, frequency=50)

# Create a servo object, my_servo.
my_servo = servo.Servo(pwm)

startTime = time.monotonic()
interval = 1
flipflop = False

while True:

    print("current time:" + str(time.monotonic()))

    if time.monotonic() - startTime > interval:
        startTime = time.monotonic() #when the timer goes off save a timestamp of when that happened
        # check the value of flipflop, if flipflop equals true or false, set flipflop to the oposite value, this will ensure it flips between the 2 colors
        if flipflop == False:
            my_servo.angle = 180
            flipflop = True
        else:
            my_servo.angle = 0
            flipflop = False

    time.sleep(0.1)
