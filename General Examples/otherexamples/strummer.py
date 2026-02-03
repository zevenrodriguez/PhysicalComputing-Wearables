"""CircuitPython Essentials Servo standard servo example"""
import time
import board
import analogio
import pwmio
# from adafruit_motor folder import servo module
from adafruit_motor import servo

# create a PWMOut object on Pin A2.
pwm = pwmio.PWMOut(board.A2, duty_cycle=2 ** 15, frequency=50)

# Create a servo object, my_servo.
my_servo = servo.Servo(pwm)

light = analogio.AnalogIn(board.LIGHT)


while True:

    if(light.value > 1000):
        my_servo.angle = 0
    else:
        my_servo.angle = 180
        time.sleep(0.01)
