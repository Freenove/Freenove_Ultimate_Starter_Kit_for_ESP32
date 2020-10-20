#
#20ms一个周期，0.5ms代表0度，1.5ms代表90度，2.5ms代表180度
#0.5ms/20ms=2.5%, 1.5ms/20ms=7.5%, 2.5ms/20ms=12.5%
#1024*2.5%=25.6, 1024*7.5%=76.8, 1024*12.5%=128

#myServoWriteDuty函数参数范围：26-128
#myServoWriteAngle函数参数范围：0-180
#myServoWriteTime函数参数范围：500-2500
#

from machine import Pin,PWM

class myServo(object):
    def __init__(self, pin: int=15, hz: int=50, duty: int=512):
        self._servo = PWM(Pin(pin),hz,duty) #默认设置引脚为15，PWM频率为50Hz，占空比为512

    # duty范围：26-128
    def myServoWriteDuty(self, duty):
        if duty <= 26:
            duty = 26
        if duty >= 128:
            duty = 128
        self._servo.duty(duty)
        
    # pos范围：0-180
    def myServoWriteAngle(self, pos):
        if pos <= 0:
            pos = 0
        if pos >= 180:
            pos = 180
        pos_buffer=(pos/180)*(128-26)
        self._servo.duty(int(pos_buffer)+26)
        
    # ms范围：500-2500
    def myServoWriteTime(self, us):
        if us <= 500:
            us = 500
        if us >= 2500:
            us = 2500
        pos_buffer=(1024*us)/20000
        self._servo.duty(int(pos_buffer))
        
    def deinit(self):
        self._servo.deinit()
