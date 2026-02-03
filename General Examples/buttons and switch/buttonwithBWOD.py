import time
import board
import digitalio

led = digitalio.DigitalInOut(board.D13)
led.direction = digitalio.Direction.OUTPUT

switch = digitalio.DigitalInOut(board.BUTTON_A)
switch.direction = digitalio.Direction.INPUT 
switch.pull = digitalio.Pull.DOWN 

flipflop = False
startTime = time.monotonic()
interval = 0.5


while True:
    print("Current switch value: " + str(switch.value))
    if switch.value == True:
        now = time.monotonic()
        print("current time:" + str(now))
        if now - startTime > interval:
        startTime = time.monotonic()
        if flipflop == False:
            flipflop = True;   
        else:
            flipflop = False

        if flipflop == True:
            led.value = True
        else:
            led.value = False

    time.sleep(0.01)  # debounce delay

    