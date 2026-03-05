import board
import neopixel
from adafruit_led_animation.animation.solid import Solid
from adafruit_led_animation.color import PINK

pixels = neopixel.NeoPixel(board.NEOPIXEL, 10, brightness=0.1, auto_write=False)

solid = Solid(pixels, color=PINK)

while True:
    solid.animate()
