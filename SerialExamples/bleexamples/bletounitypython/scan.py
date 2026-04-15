# scan.py — run this to see ALL nearby BLE devices
import asyncio
from bleak import BleakScanner

async def main():
    print("Scanning for 10 seconds...")
    devices = await BleakScanner.discover(timeout=10)
    if not devices:
        print("No devices found at all.")
    for d in devices:
        print(f"  Name: {d.name!r:30}  Address: {d.address}")

asyncio.run(main())