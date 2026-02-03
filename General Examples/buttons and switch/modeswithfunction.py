"""CircuitPython Essentials Digital In Out example"""
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
ispressed = False
modes = 0

flipflop = False
startTime = time.monotonic() # Starts counting when the program runs
interval = 1.0 #increase or decrease to speed up or slow down blink

pixels = neopixel.NeoPixel(board.NEOPIXEL, 10, brightness=0.1, auto_write=False)

def animation1():
    #global tells python to look for these variable outside of the function
    global startTime
    global interval
    global flipflop
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
    # str() converts variable output into string
    # When adding string + string you get a sentence
    # string + number, string + bool, string + variable wont work
    #print("Current switch value: " + str(switch.value))
    if switch.value == True:
        #pressed
        ispressed = True #keeps track that the button was pressed at some point in time
    else:
        #released
        if ispressed == True:
            #Did the user press the button at any point in time
            print("Clicked")
            ispressed = False #we want to reset the click action
            modes = modes + 1
            print("current Mode: " + str(modes))
    if modes == 0:
        print("Mode 0: Off")
        #Pixels off code below
    elif modes == 1:
        print("Mode 1: All Pixels On")
        #Pixels on code below
    elif modes == 2:
        print("Mode 2: Animation")
        #Pixels animation code below
        animation1()
    else:
        modes = 0
    time.sleep(0.01)  # debounce delay












