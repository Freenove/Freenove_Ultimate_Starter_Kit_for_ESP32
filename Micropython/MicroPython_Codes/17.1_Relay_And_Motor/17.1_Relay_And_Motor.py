import time
from machine import Pin

relay = Pin(13, Pin.OUT)        
button = Pin(15, Pin.IN,Pin.PULL_UP) 

def reverseRelay():
    if relay.value():
        relay.value(0)
    else:
        relay.value(1)

while True:
  if not button.value():
      time.sleep_ms(20)
      if not button.value():
          reverseRelay()
          while not button.value():
              time.sleep_ms(20)
    
            