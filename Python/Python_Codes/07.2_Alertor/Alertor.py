from machine import Pin,PWM
import math
import time

PI=3.14
button=Pin(4,Pin.IN,Pin.PULL_UP)
passiveBuzzer=PWM(Pin(13),2000)

def alert():
    for x in range(0,36):
        sinVal=math.sin(x*10*PI/180)
        toneVal=2000+int(sinVal*500)
        passiveBuzzer.freq(toneVal)
        time.sleep_ms(10)
try:
    while True:
        if not button.value():
            passiveBuzzer.init()
            alert()   
        else:
            passiveBuzzer.deinit()
except:
    passiveBuzzer.deinit()
