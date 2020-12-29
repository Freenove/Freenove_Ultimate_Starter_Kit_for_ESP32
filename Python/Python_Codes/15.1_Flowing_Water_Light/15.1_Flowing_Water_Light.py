import time
from my74HC595 import Chip74HC595

chip = Chip74HC595(14,12,13,5)
# ESP32-14: 74HC595-DS(14)
# ESP32-12: 74HC595-STCP(12)
# ESP32-13: 74HC595-SHCP(11)
# ESP32-5 : 74HC595-OE(5)

while True:
    x=0x01
    for count in range(8):
        chip.shiftOut(1,x)
        x=x<<1;
        time.sleep_ms(300)
    x=0x01
    for count in range(8):
        chip.shiftOut(0,x)
        x=x<<1
        time.sleep_ms(300)
   