import board
import neopixel
from adafruit_led_animation.animation.rainbow import Rainbow
from adafruit_led_animation.color import PINK

pixels = neopixel.NeoPixel(board.NEOPIXEL, 10, brightness=0.1, auto_write=False)

rainbow = Rainbow(pixels, speed=0.1, period=2)

while True:
    rainbow.animate()
