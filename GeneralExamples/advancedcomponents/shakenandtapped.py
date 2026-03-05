import time
import board
import adafruit_lis3dh
import busio

i2c = busio.I2C(board.ACCELEROMETER_SCL, board.ACCELEROMETER_SDA)
lis3dh = adafruit_lis3dh.LIS3DH_I2C(i2c, address=0x19)
lis3dh.range = adafruit_lis3dh.RANGE_8_G

lis3dh.set_tap(2, 60)

while True:
    if lis3dh.shake(shake_threshold=15):
        print("Shaken!")

    if lis3dh.tapped:
        print("Tapped!")
    time.sleep(0.1)

