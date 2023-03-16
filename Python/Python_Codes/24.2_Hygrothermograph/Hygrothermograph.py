from time import sleep_ms
from machine import I2C, Pin
from I2C_LCD import I2cLcd
import dht

DHT = dht.DHT11(Pin(18))
i2c = I2C(scl=Pin(14), sda=Pin(13), freq=400000)
devices = i2c.scan()
if len(devices) == 0:
    print("No i2c device !")
else:
    for device in devices:
        print("I2C addr: "+hex(device))
        lcd = I2cLcd(i2c, device, 2, 16)

try:
    while True:
        DHT.measure()
        lcd.move_to(0, 0)
        lcd.putstr("Temperature: ")
        lcd.putstr(str(DHT.temperature()))
        lcd.move_to(0, 1)
        lcd.putstr("Humidity:    ")
        lcd.putstr(str(DHT.humidity()))
        sleep_ms(2000)
except:
    pass












