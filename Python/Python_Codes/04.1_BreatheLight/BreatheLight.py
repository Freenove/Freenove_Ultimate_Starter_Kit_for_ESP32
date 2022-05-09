from machine import Pin,PWM
import time

pwm =PWM(Pin(2),10000)
try:
    while True:
        for i in range(0,1023):
            pwm.duty(i)
            time.sleep_ms(1)
            
        for i in range(0,1023):
            pwm.duty(1023-i)
            time.sleep_ms(1)  
except:
    pwm.deinit()
