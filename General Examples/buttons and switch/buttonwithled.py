import time
import board
import digitalio
import neopixel


# BUTTON_A is an reference to the 2 buttons on the Circuit Python Express
switch = digitalio.DigitalInOut(board.BUTTON_A)
switch.direction = digitalio.Direction.INPUT

# pull controls the electrical behavoir of the pin
# The standard Pull.DOWN as electricity flows through the pin, switch.value = False(LOW), When the button is pressed, switch.value = True(HIGH)
switch.pull = digitalio.Pull.DOWN
# Pull.UP inverses the behavior and enables the built in resistor

pixels = neopixel.NeoPixel(board.NEOPIXEL, 10, brightness=0.1, auto_write=False)

while True:
    # str() converts variable output into string
    # When adding string + string you get a sentence
    # string + number, string + bool, string + variable wont work
    print("Current switch value: " + str(switch.value))
    if switch.value == True:
        pixels.fill((0,255,0))
        pixels.show()
    else:
        pixels.fill((0,0,0))
        pixels.show()

    time.sleep(0.01)  # debounce delay
