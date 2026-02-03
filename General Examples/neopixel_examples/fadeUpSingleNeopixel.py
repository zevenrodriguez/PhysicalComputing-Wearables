"""CircuitPython Essentials NeoPixel example"""
import time
import board
import neopixel

fadeValue = 0
startTime = time.monotonic()
interval = 0.01

pixels = neopixel.NeoPixel(board.NEOPIXEL, 10, brightness=0.1, auto_write=False)


while True:
    now = time.monotonic()
    pixels[0] = (255,0,0)
    #print("current time:" + str(now))
    if now - startTime > interval:
        startTime = time.monotonic()
        fadeValue=fadeValue+1
        if fadeValue > 255:
            fadeValue = 0
        pixels[0] = (fadeValue,0,0)
        pixels.show()