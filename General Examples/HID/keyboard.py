import board
import digitalio

import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keyboard_layout_us import KeyboardLayoutUS
from adafruit_hid.keycode import Keycode

kbd = Keyboard(usb_hid.devices)
layout = KeyboardLayoutUS(kbd)



# Make the 2 input buttons
buttonA = digitalio.DigitalInOut(board.BUTTON_A)
buttonA.direction = digitalio.Direction.INPUT
buttonA.pull = digitalio.Pull.DOWN

buttonB = digitalio.DigitalInOut(board.BUTTON_B)
buttonB.direction = digitalio.Direction.INPUT
buttonB.pull = digitalio.Pull.DOWN

wasPressedA = False;
wasPressedB = False


while True:
    if buttonA.value == True:
        wasPressedA = True # Keeps track that the button is pressed
    else:
        if wasPressedA == True:
            wasPressedA = False # Resets the variable for next time the button is pressed
            # Press then release in one command
            kbd.send(Keycode.A)
            #or press then release seperately
            #kbd.press(Keycode.A)
            #kbd.release(Keycode.A)

    if buttonB.value == True:
        wasPressedB = True # Keeps track that the button is pressed
    else:
        if wasPressedB == True:
            wasPressedB = False # Resets the variable for next time the button is pressed
            # Type the word puppies the \n means press enter
            layout.write('puppies\n')
