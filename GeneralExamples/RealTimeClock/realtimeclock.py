import time
import board
import adafruit_ds1307


i2c = board.I2C()  # uses board.SCL and board.SDA
rtc = adafruit_ds1307.DS1307(i2c)

'''
t = time.struct_time((2025, 4, 8, 11, 9, 35, 0, -1, -1))
rtc.datetime = t
'''
t = rtc.datetime
prevMin  = t.tm_min
print(prevMin)

while True:
    current_time = rtc.datetime
    #print(current_time)
    if abs(current_time.tm_min - prevMin) >= 1:
        prevMin = current_time.tm_min
        #move motors
        print("moveMotor")
    time.sleep(0.01)
