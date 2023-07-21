import os
import time
from multiprocessing import Process, freeze_support

def task(idx, count):
    print(f"PID : {os.getpid()}")
    logic = sum([i ** 2 for i in range(count)])
    return idx, logic

if __name__ == "__main__" :
    freeze_support()        # 윈도우 환경에서 프로세스 개체에 대한 코드 실행 가능하도록 설정
    
    job = [("First", 10 ** 7), ("Second", 10 ** 7), ("Third", 10 ** 7), ("Forth", 10 ** 7)]
    
    start = time.time()
    
    process = []
    for idx, count in job:
        p = Process(target=task, args=(idx, count))
        p.start()
        process.append(p)
    
    for p in process:
        p.join()
        
    print(f"End Time : {time.time() - start}s")
    
    start = time.time()
    
    for idx, count in job:
        task(idx, count)
    
    print(f"End Time : {time.time() - start}s")
    