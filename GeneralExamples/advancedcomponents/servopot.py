# Write your code here :-)
"""CircuitPython Essentials Servo standard servo example"""
import time
import board
import pwmio
# from adafruit_motor folder import servo module
from adafruit_motor import servo
import analogio
from adafruit_simplemath import map_range


# create a PWMOut object on Pin A2.
pwm = pwmio.PWMOut(board.A2, duty_cycle=2 ** 15, frequency=50)

# Create a servo object, my_servo.
my_servo = servo.Servo(pwm)
analogin = analogio.AnalogIn(board.A1)

while True:
    #print(analogin.value)
    currentangle = int(map_range(analogin.value,0,65520,0,180))
    print(currentangle)
    my_servo.angle = currentangle
    time.sleep(0.01)
