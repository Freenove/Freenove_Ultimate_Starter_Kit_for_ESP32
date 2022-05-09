from machine import Pin,PWM
import time
from irrecvdata import irGetCMD

ledPin=PWM(Pin(14,Pin.OUT),10000) 
buzzerPin=Pin(13,Pin.OUT)
recvPin = irGetCMD(15)

def handleControl(value):
    buzzerPin.value(1)
    time.sleep_ms(100)
    buzzerPin.value(0)
    
    if value == '0xff6897':   #0
        print('0')
        ledPin.duty(1)
    elif value == '0xff30cf': #1
        print('1')
        ledPin.duty(100)
    elif value == '0xff18e7': #2
        print('2')
        ledPin.duty(300) 
    elif value == '0xff7a85': #3
        print('3')
        ledPin.duty(1000)
    else:
        return
try:
    while True:
        irValue = recvPin.ir_read()
        if irValue:
            print(irValue)
            handleControl(irValue)
except:
    ledPin.deinit()
        
