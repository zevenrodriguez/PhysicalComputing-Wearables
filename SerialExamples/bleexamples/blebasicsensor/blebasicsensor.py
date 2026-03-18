import time
import board
import digitalio
import analogio
from adafruit_ble import BLERadio
from adafruit_ble.advertising.standard import ProvideServicesAdvertisement
from adafruit_ble.services.nordic import UARTService

ble  = BLERadio()
uart = UARTService()           # handles NUS UUIDs automatically
adv  = ProvideServicesAdvertisement(uart)

led    = digitalio.DigitalInOut(board.LED)
led.direction = digitalio.Direction.OUTPUT
sensor = analogio.AnalogIn(board.A0)

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
        raw = sensor.value >> 8          # scale 0–65535 → 0–255
        uart.write(f"{raw}\n".encode())
        time.sleep(0.1)

    print("Disconnected.")