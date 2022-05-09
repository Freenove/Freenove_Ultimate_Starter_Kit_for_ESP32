from machine import TouchPad, Pin
import time

tp = TouchPad(Pin(33,Pin.IN,Pin.PULL_UP))

while True:
    print("Touch value:",tp.read())
    time.sleep_ms(1000)
