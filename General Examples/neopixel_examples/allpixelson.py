"""CircuitPython Essentials NeoPixel example"""
import board
import neopixel

# The values below are tuples. A collection which is ordered and unchangeable.
RED = (255, 0, 0)
YELLOW = (255, 150, 0)
GREEN = (0, 255, 0)
CYAN = (0, 255, 255)
BLUE = (0, 0, 255)
PURPLE = (180, 0, 255)
WHITE = (255, 255, 255)
OFF = (0, 0, 0)


pixels = neopixel.NeoPixel(board.NEOPIXEL, 10, brightness=0.1, auto_write=False)
'''
pin: pin neopixels are connected to
amount: how many neopixels are connected to the pin
brightness: (range from 0 off to 1.0 full brightness) 
auto_write=True pixels automatically update when a color is set. Update process is slow.
auto_write=False pixels will update when you call the pixelVariable.show() Faster process.
'''
while True:
    pixels.fill(GREEN)
    pixels.show()