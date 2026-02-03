''' Place the microcontroller with the usb facing away from you,
Button A will be the left button, Button B will be the right'''


import time
import board
import digitalio
import adafruit_lis3dh
import busio

import usb_hid
from adafruit_hid.mouse import Mouse

# Define button A
buttonA = digitalio.DigitalInOut(board.BUTTON_A)
buttonA.direction = digitalio.Direction.INPUT
buttonA.pull = digitalio.Pull.DOWN

# Define button A
buttonB = digitalio.DigitalInOut(board.BUTTON_B)
buttonB.direction = digitalio.Direction.INPUT
buttonB.pull = digitalio.Pull.DOWN

# Define Accelerometer
i2c = busio.I2C(board.ACCELEROMETER_SCL, board.ACCELEROMETER_SDA)
lis3dh = adafruit_lis3dh.LIS3DH_I2C(i2c, address=0x19)
lis3dh.range = adafruit_lis3dh.RANGE_8_G

# Define Mouse
m = Mouse(usb_hid.devices)

threshold = 5

wasPressedB = False

while True:
    # While you are pressing button A the mouse is active
    # Tip the controller forward and back to move your mouse up and down
    # Rotate Left and Right to move the mouse towards the left and right direction
    if buttonA.value == True:
        x, y, z = lis3dh.acceleration
        print((x, y, z))
        # Move Up or Down if the y axis is higher or lower then the threshold
        if y > -threshold:
            #move up
            m.move(0, 10, 0)
        if y < threshold:
            #move down
            m.move(0, -10, 0)

        # Move Left or Right if the X axis is higher or lower then the threshold
        if x > -threshold:
            #move up
            m.move(-10, 0, 0)

        if x < threshold:
            #move down
            m.move(10, 0, 0)
    # if buttonB is clicked then press and release the left mouse button
    if buttonB.value == True:
        wasPressedB = True
    else:
        if wasPressedB == True:
            wasPressedB = False
            m.press(Mouse.LEFT_BUTTON)
            m.release_all()   # or m.release(Mouse.LEFT_BUTTON)

    time.sleep(0.1)
