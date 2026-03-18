import time
import board
import digitalio
from adafruit_apds9960.apds9960 import APDS9960

from adafruit_ble import BLERadio
from adafruit_ble.advertising.standard import ProvideServicesAdvertisement
from adafruit_ble.services.nordic import UARTService

ble  = BLERadio()
uart = UARTService()           # handles NUS UUIDs automatically
adv  = ProvideServicesAdvertisement(uart)
print(uart.uuid)


led    = digitalio.DigitalInOut(board.LED)
led.direction = digitalio.Direction.OUTPUT


i2c = board.I2C()  # uses board.SCL and board.SDA
apds9960 = APDS9960(i2c)

apds9960.enable_proximity = True
apds9960.proximity_gain = 2

currentValue = 0
proximity_readings = []
num_readings = 10  # Number of readings to average


while True:
    print("Advertising...")
    ble.start_advertising(adv)
    while not ble.connected:
        pass
    ble.stop_advertising()
    print("Connected!")

    while ble.connected:
        # Read any incoming message from the browser
        if uart.in_waiting:
            msg = uart.readline().decode("utf-8").strip()
            print("Got:", msg)
            if msg == "LED_ON":
                led.value = True
            elif msg == "LED_OFF":
                led.value = False

        # Send sensor value as a simple string
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
            currentValue = int(currentValue)
            uart.write(f"{currentValue}\n".encode())
            time.sleep(0.1)

    print("Disconnected.")