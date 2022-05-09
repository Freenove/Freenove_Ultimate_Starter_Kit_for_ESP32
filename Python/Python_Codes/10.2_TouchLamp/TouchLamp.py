from machine import TouchPad, Pin
import time

PRESS_VAL=70    #Set a threshold to judge touch
RELEASE_VAL=200 #Set a threshold to judge release

led=Pin(2,Pin.OUT)
tp = TouchPad(Pin(4,Pin.IN,Pin.PULL_UP))
isPressed = 0

def reverseGPIO():
    if led.value():
        led.value(0)
        print("Turn off led")
    else:
        led.value(1)
        print("Turn on led")
        
while True:
    if tp.read() < PRESS_VAL:
        if not isPressed:
            isPressed = 1
            reverseGPIO()
            print("Touch detected!")
            time.sleep_ms(100)
    if tp.read() > RELEASE_VAL:
        if isPressed:
            isPressed = 0
            print("Touch released!")
            time.sleep_ms(100)


