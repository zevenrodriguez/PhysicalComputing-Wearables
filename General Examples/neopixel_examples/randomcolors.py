import time
import board
import neopixel
import random

startTime = time.monotonic()
interval = 1.0

pixels = neopixel.NeoPixel(board.NEOPIXEL, 10, brightness=0.1, auto_write=False)

while True:
    if time.monotonic() - startTime > interval: 
        startTime = time.monotonic()
        # for loops in python allow use to itterate through a collection. The range function creates a sequence of numbers.
        for neoPixelNum in range(len(pixels)):
            pixels[neoPixelNum] = (0,0,0)
            pixels.show()
        # random.randint(int,int) gives you a whole number from a range. We use the random.randint to set which pixel we want to set the color on and what color to set.
        randomPixel = random.randint(0,len(pixels)-1)  
        pixels[randomPixel] = (random.randint(0, 255),random.randint(0,255),random.randint(0,255))
        pixels.show()
        