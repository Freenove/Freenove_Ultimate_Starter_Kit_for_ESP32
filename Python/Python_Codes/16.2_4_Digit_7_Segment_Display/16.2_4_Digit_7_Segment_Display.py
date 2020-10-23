import time
from my74HC595 import Chip74HC595
from machine import Pin

comPin=[25,26,27,14];
num =[0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8,
      0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e]

def led_display():
    for i in range(0,4):
        chns=Pin(comPin[i],Pin.OUT)
        chns.value(1)
        chip.shiftOut(0,num[i])
        time.sleep_ms(1)
        chip.clear()
        chns.value(0)
  
#Pin(15) - 74hc595.ds
#Pin(4)  - 74hc595.st_cp
#Pin(2)  - 74hc595.sh_cp
chip = Chip74HC595(15,4,2)
try:
    while True:
        led_display()
except:
    pass





