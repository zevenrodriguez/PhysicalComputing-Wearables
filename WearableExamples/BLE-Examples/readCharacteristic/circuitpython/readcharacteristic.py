# SPDX-FileCopyrightText: 2019 Kattni Rembor for Adafruit Industries
#
# SPDX-License-Identifier: MIT

from adafruit_ble import BLERadio
from adafruit_ble.advertising.standard import ProvideServicesAdvertisement
from adafruit_ble.services.nordic import UARTService
import time

ble = BLERadio()
uart = UARTService()
advertisement = ProvideServicesAdvertisement(uart)

while True:
    ble.start_advertising(advertisement)
    while not ble.connected:
        pass

    print("Connected!")
    
    while ble.connected:
        # Read from the internal server_rx buffer
        if uart._server_rx.in_waiting:
            num_bytes = uart._server_rx.in_waiting
            print(f"Bytes waiting: {num_bytes}")
            
            # Read the data
            data = uart._server_rx.read(num_bytes)
            print(f"Raw data: {data}")
            print(f"Hex: {data.hex()}")
            
            try:
                message = data.decode('utf-8').strip()
                print(f"Message: '{message}'")
            except Exception as e:
                print(f"Decode error: {e}")
        
        time.sleep(0.1)
