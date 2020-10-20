from machine import UART
import time

myUsart = UART(1, baudrate=115200, bits=8, parity=0, rx=5, tx=2, timeout=10) 
myUsart.write("ESP32 initialization completed!\r\n")

while True:
    myUsart.write("Running time : ")
    a=str(time.ticks_ms()/1000)
    myUsart.write(a)
    myUsart.write(" s\r\n")
    time.sleep(1)