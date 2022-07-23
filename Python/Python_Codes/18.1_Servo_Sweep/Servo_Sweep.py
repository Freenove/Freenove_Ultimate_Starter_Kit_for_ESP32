from myservo import myServo
import time

servo=myServo(15)#set servo pin
servo.myServoWriteAngle(0)#Set Servo Angle
time.sleep_ms(1000)

try:
    while True:       
        for i in range(0,180,1):
            servo.myServoWriteAngle(i)
            time.sleep_ms(15)
        for i in range(180,0,-1):
            servo.myServoWriteAngle(i)
            time.sleep_ms(15)        
except:
    servo.deinit()