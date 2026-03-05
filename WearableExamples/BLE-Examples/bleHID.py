# SPDX-FileCopyrightText: 2020 John Park for Adafruit Industries
#
# SPDX-License-Identifier: MIT

"""
This example acts as a BLE HID keyboard to peer devices.
Attach five buttons with pullup resistors to Feather nRF52840
  each button will send a configurable keycode to mobile device or computer
"""
import time
import board
import digitalio
# Uncomment if setting .pull below.
# from digitalio import Pull

import adafruit_ble
from adafruit_ble.advertising import Advertisement
from adafruit_ble.advertising.standard import ProvideServicesAdvertisement
from adafruit_ble.services.standard.hid import HIDService
from adafruit_ble.services.standard.device_info import DeviceInfoService
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keyboard_layout_us import KeyboardLayoutUS
from adafruit_hid.keycode import Keycode


hid = HIDService()

device_info = DeviceInfoService(software_revision=adafruit_ble.__version__,
                                manufacturer="Adafruit Industries")
advertisement = ProvideServicesAdvertisement(hid)
# Advertise as "Keyboard" (0x03C1) icon when pairing
# https://www.bluetooth.com/specifications/assigned-numbers/
advertisement.appearance = 961
scan_response = Advertisement()
scan_response.complete_name = "CircuitPython HID"

ble = adafruit_ble.BLERadio()
if not ble.connected:
    print("advertising")
    ble.start_advertising(advertisement, scan_response)
else:
    print("already connected")
    print(ble.connections)

k = Keyboard(hid.devices)
kl = KeyboardLayoutUS(k)


# Setup the button
button = digitalio.DigitalInOut(board.SWITCH)
button.direction = digitalio.Direction.INPUT
button.pull = digitalio.Pull.UP

while True:
    while not ble.connected:
        pass
    print("Start typing:")

    while ble.connected:
        if button.value == False and button_already_pressed == False:
            #kl.write("e")
            k.send(Keycode.A)
            # Mark as pressed so we don't count it again in the next loop
            button_already_pressed = True
       
    # 2. Reset the 'memory' when the button is released
        if button.value == True:
            button_already_pressed = False
       
        time.sleep(0.01) # Debounce
       

    ble.start_advertising(advertisement)
