import time
import board
import digitalio
import usb_cdc

# This example listens for "LED_ON" / "LED_OFF" lines sent from index.html
# and turns the board's red LED (D13) on or off. It replies with the new state
# so the web page can show it as the "Response".

led = digitalio.DigitalInOut(board.LED)
led.direction = digitalio.Direction.OUTPUT
led.value = False

# Use the data port if boot.py enabled it, otherwise fall back to the console port
serial = usb_cdc.data if usb_cdc.data else usb_cdc.console

buffer = b""

while True:
    if serial.in_waiting > 0:
        data = serial.read(serial.in_waiting)
        if data:
            buffer += data
            while b"\n" in buffer:
                line, buffer = buffer.split(b"\n", 1)
                try:
                    text = line.decode("utf-8").strip()
                except UnicodeError:
                    text = ""
                if text == "LED_ON":
                    led.value = True
                    serial.write(b"LED is ON\r\n")
                elif text == "LED_OFF":
                    led.value = False
                    serial.write(b"LED is OFF\r\n")
                elif text:
                    serial.write(f"Unknown command: {text}\r\n".encode("utf-8"))
                print(f"Received: {text}")

    time.sleep(0.01)
