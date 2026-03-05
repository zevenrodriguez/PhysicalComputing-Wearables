import board
import time
import neopixel

interval = 1.0 #increase or decrease to speed up or slow down blink

pixels = neopixel.NeoPixel(board.NEOPIXEL, 10, brightness=0.1, auto_write=False)

while True:

    pixels.fill((0,255,0))
    pixels.show()
    time.sleep(interval)

    pixels.fill((255,200,0))
    pixels.show()
    time.sleep(interval)

    time.sleep(0.01)# Write your code here :-)
