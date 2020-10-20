from machine import Pin

button=Pin(4,Pin.IN,Pin.PULL_UP)
activeBuzzer=Pin(13,Pin.OUT)

activeBuzzer.value(0)

while True:
    if not button.value():
        activeBuzzer.value(1)
    else:
        activeBuzzer.value(0)
