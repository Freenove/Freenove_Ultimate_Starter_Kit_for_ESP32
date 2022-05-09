from machine import Pin

led = Pin(2, Pin.OUT)

#create button object from pin13,Set Pin13 to Input
button = Pin(13, Pin.IN,Pin.PULL_UP) 

try:
    while True:
      if not button.value():     
        led.value(1)  #Set led turn on
      else:
        led.value(0)  #Set led turn off
except:
    pass