from machine import ADC,Pin,PWM
import time
import math

in1Pin=Pin(12, Pin.OUT)
in2Pin=Pin(14, Pin.OUT)

enablePin=Pin(13, Pin.OUT)
pwm=PWM(enablePin,10000)

adc=ADC(Pin(36))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

def driveMotor(dir,spd):
    if dir:
        in1Pin.value(1)
        in2Pin.value(0)
    else :
        in1Pin.value(0)
        in2Pin.value(1)
    pwm.duty(spd)
    
try:
    while True:
        potenVal = adc.read()
        rotationSpeed = potenVal - 2048
        if (potenVal > 2048):
            rotationDir = 1;
        else:
            rotationDir = 0;
        rotationSpeed=int(math.fabs((potenVal-2047)//2)-1)
        driveMotor(rotationDir,rotationSpeed)
        time.sleep_ms(10)
except:
    pwm.deinit()




