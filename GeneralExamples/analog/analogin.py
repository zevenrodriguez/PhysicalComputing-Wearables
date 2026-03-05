import time
import board
import analogio
 
analogin = analogio.AnalogIn(board.A1)

while True:
    potVoltage = analogin.value
    #potVoltage = (analogin.value * 3.3) /65536
    print("Analog Voltage:" + str(potVoltage))
    time.sleep(0.1)