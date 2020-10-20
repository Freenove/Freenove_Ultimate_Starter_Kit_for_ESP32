from machine import Pin,PWM
import time

pins=[15,2,0];

pwm0=PWM(Pin(pins[0]),1000)
pwm1=PWM(Pin(pins[1]),1000)
pwm2=PWM(Pin(pins[2]),1000)

def setColor(rgb):              
    pwm0.duty(1023-(rgb>>20))
    pwm1.duty(1023-(rgb>>10))
    pwm2.duty(1023-(rgb>>0))

def wheel(pos):
    WheelPos=pos%1023
    if WheelPos<341:
        return (((1023-WheelPos*3)<<20)|((WheelPos*3)<<10))
    elif WheelPos>=341 and WheelPos<682:
        WheelPos -= 341;
        return (((1023-WheelPos*3)<<10)|(WheelPos*3))
    else :
        WheelPos -= 682;
        return (((WheelPos*3)<<20)|(1023-WheelPos*3))

try:
    while True:
        for i in range(0,1023):
            setColor(wheel(i))
            time.sleep_ms(5)
except:
    pwm0.deinit()
    pwm1.deinit()
    pwm2.deinit()