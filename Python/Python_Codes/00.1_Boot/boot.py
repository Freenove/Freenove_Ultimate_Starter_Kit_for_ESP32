# This file is executed on every boot (including wake-boot from deepsleep)
#import esp
#esp.osdebug(None)
#import webrepl
#webrepl.start()

import os
files=os.listdir()
if len(files)>=2:
    print('The device have %d files'%len(files))
    for i in range(len(files)):
        if files[i]!='boot.py':
            print('file name:',files[i])
            exec(open(files[i]).read(),globals())
            
else:
    print("MicroPython has no files!")
