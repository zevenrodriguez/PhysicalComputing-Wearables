# inspect_device.py
import asyncio
from bleak import BleakScanner, BleakClient

DEVICE_NAME = "CIRCUITPYb9ac"  # change if needed

async def main():
    print(f"Scanning for '{DEVICE_NAME}'...")
    device = await BleakScanner.find_device_by_name(DEVICE_NAME, timeout=10)
    if not device:
        print("Device not found!")
        return

    print(f"Found: {device.name} ({device.address})\n")

    async with BleakClient(device) as client:
        print("Connected! Listing all services and characteristics:\n")
        for service in client.services:
            print(f"Service: {service.uuid}")
            print(f"         {service.description}")
            for char in service.characteristics:
                print(f"  Char:  {char.uuid}")
                print(f"         {char.description}")
                print(f"         Properties: {char.properties}")
            print()

asyncio.run(main())