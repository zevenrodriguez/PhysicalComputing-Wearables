import board
import time
import digitalio

led = digitalio.DigitalInOut(board.D13) #Set Pin 13 as a Digital IN/Out Pin
# object variable name = module.class(module.variable)
# led turns into a DigitalInOut object
led.direction = digitalio.Direction.OUTPUT #Tell microcontroller to send voltage through pin to ground
# object.class = module.class.variable


while True:
    led.value = True # pin connects to ground
    time.sleep(0.1) # wait 0.1 seconds
    led.value = False # pin disconnects from ground
    time.sleep(0.1) # wait 0.1 seconds

