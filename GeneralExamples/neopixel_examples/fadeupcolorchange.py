"""CircuitPython Essentials NeoPixel example"""
import time
import board
import neopixel

colors = [(255,127,0),(0,255,127),(127,0,255)]
currentcolor = 0

fadeValueR = 0
fadeValueG = 0
fadeValueB = 0

fadeDoneR = False
fadeDoneG = False
fadeDoneB = False

startTime = time.monotonic()
interval = 0.01

pixels = neopixel.NeoPixel(board.NEOPIXEL, 10, brightness=0.1, auto_write=False)

while True:
    #print("current time:" + str(now))
    if time.monotonic() - startTime > interval:
        startTime = time.monotonic()

        if fadeValueR < colors[currentcolor][0]:
            fadeValueR=fadeValueR+1

        if fadeValueG < colors[currentcolor][1]:
            fadeValueG=fadeValueG+1

        if fadeValueB < colors[currentcolor][2]:
            fadeValueB=fadeValueB+1

        if fadeValueR == colors[currentcolor][0]:
            fadeDoneR=True

        if fadeValueG == colors[currentcolor][1]:
            fadeDoneG=True

        if fadeValueB == colors[currentcolor][2]:
            fadeDoneB=True

        if(fadeDoneR == True and fadeDoneG == True and fadeDoneB == True):
            #new color
            fadeDoneR=False
            fadeDoneG=False
            fadeDoneB=False
            fadeValueR = 0
            fadeValueG = 0
            fadeValueB = 0
            currentcolor=currentcolor+1
            if(currentcolor > len(colors)-1):
                currentcolor = 0


        for neoPixelNum in range(len(pixels)):
            pixels[neoPixelNum] = (fadeValueR,fadeValueG,fadeValueB)
            pixels.show()
