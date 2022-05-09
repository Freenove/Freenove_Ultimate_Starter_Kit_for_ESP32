from machine import UART
import time

usart_flag=0

myUsart = UART(2, baudrate=9600, bits=8, parity=0, rx=13, tx=14, timeout=10) 
myUsart.write(str("\r\nESP32 initialization completed!\r\n")+\
      str("Please input some characters,\r\n")+\
      str("select \"Newline\" below and click send button. \r\n"))

while True:
    if myUsart.any():
        usart_buffer=myUsart.read()
        usart_flag=1
    if usart_flag==1:
        myUsart.write(usart_buffer+str("\r\n"))
        usart_flag=0