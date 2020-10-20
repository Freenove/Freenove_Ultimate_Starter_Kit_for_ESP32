from myservo import myServo
from machine import ADC,Pin
import time

servo=myServo(15)

adc2=ADC(Pin(34))
adc2.atten(ADC.ATTN_11DB)
adc2.width(ADC.WIDTH_12BIT)

try:
    while True:
        adcValue=adc2.read()
        angle=(adcValue*180)/4096
        servo.myServoWriteAngle(int(angle))
        time.sleep_ms(50)
except:
    servo.deinit()