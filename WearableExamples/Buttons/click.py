import time
import board
import digitalio


# Setup the button
button = digitalio.DigitalInOut(board.SWITCH)
button.direction = digitalio.Direction.INPUT
button.pull = digitalio.Pull.UP


# Variables to track the state
button_already_pressed = False
click_count = 0


print("Ready to register clicks...")


while True:
    # 1. Check if the button is currently down AND it wasn't down before
    if button.value == False and button_already_pressed == False:
        click_count += 1
        print("Click Registered! Total clicks: " + str(click_count))
       
        # Mark as pressed so we don't count it again in the next loop
        button_already_pressed = True
       
    # 2. Reset the 'memory' when the button is released
    if button.value == True:
        button_already_pressed = False
       
    time.sleep(0.01) # Debounce