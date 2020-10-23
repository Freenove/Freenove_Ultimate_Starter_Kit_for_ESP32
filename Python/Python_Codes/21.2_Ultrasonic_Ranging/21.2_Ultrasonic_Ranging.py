from hcsr04 import SR04
import time

SR=SR04(13,14)

time.sleep_ms(2000)
try:
    while True:
        print('Distance: ',SR.distance(),'cm')
        time.sleep_ms(500)
except:
    pass












