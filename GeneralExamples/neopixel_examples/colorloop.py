
import time
import board
import neopixel

# colors = [] is a list, which is a collection of values. To loop through these values we use an index number to reference which value we want in the list. Example color[0] will give use the group of values (255,0,0) which we will use to represent red.
# In this list we have collection of tuples
colors = [(255, 0, 0),(255, 150, 0),(0, 255, 0),(0, 255, 255),(0, 0, 255),(180, 0, 255),(255, 255, 255),(0, 0, 0)]

startTime = time.monotonic()
interval = 1.0
currentColor = 0

pixels = neopixel.NeoPixel(board.NEOPIXEL, 10, brightness=0.1, auto_write=False)

# the len() function gives you the size of a group of items
print(len(colors))

while True:

    if time.monotonic()-startTime > interval:
        startTime = time.monotonic()
        pixels.fill(colors[currentColor])
        pixels.show()
        currentColor = currentColor + 1
        if currentColor >= len(colors):
            currentColor = 0



