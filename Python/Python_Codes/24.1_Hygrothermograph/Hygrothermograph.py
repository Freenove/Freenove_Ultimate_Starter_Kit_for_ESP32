import machine
import time
import dht

DHT = dht.DHT11(machine.Pin(13))

while True:
    DHT.measure()
    print('temperature:',DHT.temperature(),'humidity:',DHT.humidity())
    time.sleep_ms(2000)
    
    
    

    
    
    
    
    
    
    


