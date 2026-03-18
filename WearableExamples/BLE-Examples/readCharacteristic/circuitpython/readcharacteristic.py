# SPDX-FileCopyrightText: 2019 Kattni Rembor for Adafruit Industries
#
# SPDX-License-Identifier: MIT

from adafruit_ble import BLERadio
from adafruit_ble.advertising.standard import ProvideServicesAdvertisement
from adafruit_ble.services.nordic import UARTService
import time

# Initialize BLE radio and UART service
ble = BLERadio()
uart = UARTService()
advertisement = ProvideServicesAdvertisement(uart)

print("=" * 50)
print("BLE UART Peripheral Server Starting")
print("=" * 50)
print("UART Service UUID:", uart.uuid)
print("Waiting for client connections...")
print("=" * 50)

connection_count = 0

while True:
    ble.start_advertising(advertisement)
    print("\n📡 Advertising UART service...")
    
    # Wait for a connection
    while not ble.connected:
        time.sleep(0.1)
    
    # Connection established
    connection_count += 1
    print(f"\n✓ Connection #{connection_count} established!")
    
    # Give time for client to discover characteristics
    print("⏳ Initializing service discovery (2 seconds)...")
    time.sleep(2.0)
    
    print("✓ Service ready - waiting for messages...")
    
    # Main communication loop
    while ble.connected:
        try:
            if uart.in_waiting:
                data = uart.read(uart.in_waiting)
                print(f"\n📨 Received {len(data)} bytes: {data}")
                
                try:
                    message = data.decode('utf-8').strip()
                    print(f"📝 Message: '{message}'")
                except Exception as e:
                    print(f"⚠️  Decode error: {e}")
        except Exception as e:
            print(f"❌ Error reading from UART: {type(e).__name__}: {e}")
            break
        
        time.sleep(0.1)
    
    print("\n✗ Client disconnected!")
    ble.stop_advertising()
    time.sleep(1)
