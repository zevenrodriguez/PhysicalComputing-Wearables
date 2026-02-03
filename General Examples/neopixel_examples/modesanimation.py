import time
import board
import digitalio
import neopixel


# LED setup.
led = digitalio.DigitalInOut(board.D13)
led.direction = digitalio.Direction.OUTPUT

# BUTTON_A is an reference to the 2 buttons on the Circuit Python Express
switch = digitalio.DigitalInOut(board.BUTTON_A)
switch.direction = digitalio.Direction.INPUT

# pull controls the electrical behavoir of the pin
# The standard Pull.DOWN as electricity flows through the pin, switch.value = False(LOW), When the button is pressed, switch.value = True(HIGH)
switch.pull = digitalio.Pull.DOWN

wasPressed = False # Keeps track of the last time button was pressed
mode = 0

flipflop = False
startTime = time.monotonic() # Starts counting when the program runs
interval = 1.0 #increase or decrease to speed up or slow down blink

pixels = neopixel.NeoPixel(board.NEOPIXEL, 10, brightness=0.1, auto_write=False)

def animation1():
    # tell your function these variables exists already
    global startTime, interval, flipflop, pixels
    if time.monotonic() - startTime > interval:
        startTime = time.monotonic() #when the timer goes off save a timestamp of when that happened
        # check the value of flipflop, if flipflop equals true or false, set flipflop to the oposite value, this will ensure it flips between the 2 colors
        if flipflop == False:
            pixels.fill((0,255,0))
            flipflop = True
        else:
            pixels.fill((255,200,0))
            flipflop = False
        pixels.show()

while True:
    print("Current Mode: " + str(mode))
    # print("Current switch value: " + str(switch.value))
    if switch.value == True:
        wasPressed = True # Keeps track that the button is pressed
    else:
        # This is the state when the button is de-pressed
        # Check if the button was pressed in the past
        if wasPressed == True:
            wasPressed = False # Resets the variable for next time the button is pressed
            mode = mode + 1 # Change the mode

    if mode == 0:
        led.value = False
        pixels.fill((0,0,0))
        pixels.show()
    elif mode == 1:
        led.value = True
        pixels.fill((255,255,255))
        pixels.show()
    elif mode == 2:
        #animation
        animation1()
        print("You are in mode 2")
    else:
        print("Back to mode 0")
        mode = 0

    time.sleep(0.01)  # debounce delay



