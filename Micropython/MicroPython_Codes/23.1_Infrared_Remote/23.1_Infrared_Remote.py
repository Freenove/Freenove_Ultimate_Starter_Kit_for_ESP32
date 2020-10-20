from irrecvdata import irGetCMD

recvPin = irGetCMD(15)
try:
    while True:
        irValue = recvPin.ir_read()
        if irValue:
            print(irValue)
except:
    pass














