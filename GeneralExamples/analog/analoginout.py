import time
import board
import analogio
 
analog_out = analogio.AnalogOut(board.A0)
curValue = 0

while True:
    curValue = curValue + 1
    if (curValue >=65536):
        curValue = 0
    analog_out.value = curValue
    print("Analog Out:" + str(curValue))
    time.sleep(0.1)