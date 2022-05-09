from machine import Pin,PWM,ADC
import time

pwm0=PWM(Pin(15,Pin.OUT),10000)
pwm1=PWM(Pin(2,Pin.OUT),10000)
pwm2=PWM(Pin(5,Pin.OUT),10000)
adc0=ADC(Pin(36))
adc1=ADC(Pin(39))
adc2=ADC(Pin(34))
adc0.atten(ADC.ATTN_11DB)
adc1.atten(ADC.ATTN_11DB)
adc2.atten(ADC.ATTN_11DB)
adc0.width(ADC.WIDTH_10BIT)
adc1.width(ADC.WIDTH_10BIT)
adc2.width(ADC.WIDTH_10BIT)

try:
    while True:
        pwm0.duty(1023-adc0.read())
        pwm1.duty(1023-adc1.read())
        pwm2.duty(1023-adc2.read())
        time.sleep_ms(100)
except:
    pwm0.deinit()
    pwm1.deinit()
    pwm2.deinit()
















