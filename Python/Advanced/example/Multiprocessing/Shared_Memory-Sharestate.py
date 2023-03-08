from multiprocessing import Process, Value
import time

def stateTest(status) :
    for i in range(5):
        print(status.value)
        time.sleep(0.5)

if __name__ == '__main__':
    status = Value('i', 0)
    p = Process(target=stateTest, args=(status,))
    p.start()
    
    time.sleep(1)
    status.value = 1
    time.sleep(1)
    status.value = 0
    