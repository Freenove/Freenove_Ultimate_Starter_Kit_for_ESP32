from machine import ADC,Pin
import time

xVal=ADC(Pin(36))
yVal=ADC(Pin(39))
zVal=Pin(14,Pin.IN,Pin.PULL_UP)

xVal.atten(ADC.ATTN_11DB)
yVal.atten(ADC.ATTN_11DB)
xVal.width(ADC.WIDTH_12BIT)
yVal.width(ADC.WIDTH_12BIT)

while True:
  print("X,Y,Z:",xVal.read(),",",yVal.read(),",",zVal.value())
  time.sleep(1)

  
  
  
  
  