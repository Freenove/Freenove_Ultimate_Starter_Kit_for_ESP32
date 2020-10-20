from keypad import KeyPad
import time

keyPad=KeyPad(14,27,26,25,13,21,22,23)

def key():
    keyvalue=keyPad.scan()
    if keyvalue!= None:
        print(keyvalue)
        time.sleep_ms(300)
        return keyvalue
            
while True:
    key()
    
    
    
    
    
    
    
    
    