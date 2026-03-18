import time
import usb_cdc

lines = 0
last_sent = time.monotonic()

# This example listens for newline-terminated text from the host.
# It counts non-empty lines and writes a status line every 2 seconds.

buffer = b""

while True:
    if usb_cdc.console.in_waiting > 0:
        data = usb_cdc.console.read(usb_cdc.console.in_waiting)
        if data:
            buffer += data
            while b"\n" in buffer:
                line, buffer = buffer.split(b"\n", 1)
                text = line.decode("utf-8", errors="ignore").strip()
                if text:
                    lines += 1

    now = time.monotonic()
    if now - last_sent > 2.0:
        usb_cdc.console.write(f"Hello! I heard you {lines} times\r\n".encode("utf-8"))
        last_sent = now

    time.sleep(0.01)
