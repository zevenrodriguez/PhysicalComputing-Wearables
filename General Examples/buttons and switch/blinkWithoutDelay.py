import board
import time
import digitalio

led = digitalio.DigitalInOut(board.D13)
led.direction = digitalio.Direction.OUTPUT

flipflop = False
startTime = time.monotonic() # Starts counting when the program runs
interval = 0.5

while True:
    now = time.monotonic()
    print("current time:" + str(now))

    """
    Timer explained:
    now - startTime > interval
    0 - 0 > 0.5
    0.1 - 0 > 0.5 False
    0.2 - 0 > 0.5 False
    0.3 - 0 > 0.5 False
    0.5 - 0 > 0.5 False
    0.6 - 0 > 0.5 True
    startTime = 0.6
    0.7 - 0.6 > 0.5 False
    1.2 - 0.6 > 0.5 True
    startTime = 0.6
    1.3 - 1.2 > 0.5 False
    """

    if now - startTime > interval:
        startTime = time.monotonic()
        if flipflop == False:
            flipflop = True;
        else:
            flipflop = False

        led.value = flipflop
