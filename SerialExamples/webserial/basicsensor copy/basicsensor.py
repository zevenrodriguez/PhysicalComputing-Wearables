import time
import usb_cdc
from adafruit_apds9960.apds9960 import APDS9960
import board

i2c = board.I2C()  # uses board.SCL and board.SDA
apds9960 = APDS9960(i2c)

apds9960.enable_proximity = True
apds9960.proximity_gain = 2

currentValue = 0
proximity_readings = []
num_readings = 10  # Number of readings to average

while True:
    proximity = apds9960.proximity
    proximity_readings.append(proximity)
    
    # Keep only the last num_readings
    if len(proximity_readings) > num_readings:
        proximity_readings.pop(0)
    
    # Calculate average
    average_proximity = sum(proximity_readings) / len(proximity_readings)
    
    if currentValue != average_proximity:
        print(f"Average Proximity: {average_proximity}")
        currentValue = average_proximity
        usb_cdc.data.write(f"{average_proximity}\r\n".encode("utf-8"))
    
    time.sleep(0.05)