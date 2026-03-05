import board
import time
import neopixel

flipflop = False
startTime = time.monotonic() # Starts counting when the program runs
interval = 1.0 #increase or decrease to speed up or slow down blink

pixels = neopixel.NeoPixel(board.NEOPIXEL, 10, brightness=0.1, auto_write=False)

while True:

    print("current time:" + str(time.monotonic()))

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

    time.sleep(0.1)

