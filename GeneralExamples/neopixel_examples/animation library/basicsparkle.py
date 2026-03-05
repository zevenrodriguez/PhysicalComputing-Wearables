import board
import neopixel
from adafruit_led_animation.animation.sparkle import Sparkle

pixels = neopixel.NeoPixel(board.NEOPIXEL, 10, brightness=0.1, auto_write=False)

sparkle = Sparkle(pixels, speed=0.05, color=(127,127,0), num_sparkles=10)

while True:
    sparkle.animate()
