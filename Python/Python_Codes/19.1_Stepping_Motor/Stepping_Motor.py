from stepmotor import mystepmotor
import time

myStepMotor=mystepmotor(14,27,26,25)

try:
    while True:  
        myStepMotor.moveSteps(1,32*64,2000)
        myStepMotor.stop()
        time.sleep_ms(1000)
        myStepMotor.moveSteps(0,32*64,2000)
        myStepMotor.stop()
        time.sleep_ms(1000)
except:
    pass
    
    
    
    
    
    
    
    
    
    
    

    
    