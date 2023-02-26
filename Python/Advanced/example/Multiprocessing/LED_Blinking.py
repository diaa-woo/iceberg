import time
import os
from multiprocessing import Process, freeze_support

def togglePin(GPIO_Status):
    if GPIO_Status == False :
        return True
    else :
        return False

def task(GPIO, sleepTime) :
    status = False
    print(f"PID: {os.getpid()}")
    while 1:
        status = togglePin(status)
        time.sleep(sleepTime)
        print(f"{GPIO} pin is {status}")
    
if __name__ == "__main__" :
    freeze_support()       
    
    LEDS = [("GPIO10", 1), ("GPIO8", 3.2), ("GPIO15", 7)]
    
    process = []
    for GPIO, sleepTime in LEDS:
        p = Process(target=task, args=(GPIO, sleepTime))
        p.start()
        process.append(p)
        
    for p in process:
        p.join()
        
    