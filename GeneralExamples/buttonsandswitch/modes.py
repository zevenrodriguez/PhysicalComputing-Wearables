import time
import board
import digitalio

# BUTTON_A is an reference to the 2 buttons on the Circuit Python Express
switch = digitalio.DigitalInOut(board.BUTTON_A)
switch.direction = digitalio.Direction.INPUT

# pull controls the electrical behavoir of the pin
# The standard Pull.DOWN as electricity flows through the pin, switch.value = False(LOW), When the button is pressed, switch.value = True(HIGH)
switch.pull = digitalio.Pull.DOWN

wasPressed = False # Keeps track of the last time button was pressed
mode = 0

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
        print("You are in mode 0")
    elif mode == 1:
        print("You are in mode 1")
    elif mode == 2:
        print("You are in mode 2")
    else:
        print("Back to mode 0")
        mode = 0

    time.sleep(0.01)  # debounce delay
