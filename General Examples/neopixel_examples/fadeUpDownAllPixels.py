import time
import board
import neopixel

fadeValue = 0
fadeToggle = False
startTime = time.monotonic()
interval = 0.01
increase = 5

pixels = neopixel.NeoPixel(board.NEOPIXEL, 10, brightness=0.1, auto_write=False)

while True:
    now = time.monotonic()
    #print("current time:" + str(now))
    if now - startTime > interval:
        startTime = time.monotonic()
        # fadeValue is greater than or equal to 255
        if(fadeValue >= 255):
            fadeToggle = True
        # fadeValue is less than or equal to 0
        if(fadeValue <= 0):
            fadeToggle = False

        if(fadeToggle == False):
            fadeValue=fadeValue+increase
        
        if(fadeToggle == True):
            fadeValue = fadeValue-increase

    for neoPixelNum in range(len(pixels)):
        pixels[neoPixelNum] = (fadeValue,0,0)
        pixels.show()