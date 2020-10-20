from machine import TouchPad, Pin
import time

PRESS_VAL=70    #Set a threshold to judge touch
RELEASE_VAL=200 #Set a threshold to judge release

led=Pin(2,Pin.OUT)
tp = TouchPad(Pin(4,Pin.IN,Pin.PULL_UP))
isProcessed = 0

def reverseGPIO():
    if led.value():
        led.value(0)
    else:
        led.value(1)
        
while True:
    if tp.read() < PRESS_VAL:
        if not isProcessed:
            isProcessed = 1
            reverseGPIO()
            print("Touch detected!")
            time.sleep_ms(100)
    if tp.read() > RELEASE_VAL:
        if isProcessed:
            isProcessed = 0
            print("Touch released!")
            time.sleep_ms(100)


