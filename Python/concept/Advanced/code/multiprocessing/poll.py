import os
import time
from multiprocessing import Pool, freeze_support

def task(pairs):
    print(f"PID : {os.getpid()}")
    idx, count = pairs
    logic = sum([i ** 2 for i in range(count)])
    return idx, logic

if __name__ == "__main__" :
    freeze_support()
    job = [("First", 10 ** 7), ("Second", 10 ** 7), ("Third", 10 ** 7), ("Fourth", 10 ** 7)]
    
    start = time.time()
    
    p = Pool(processes = 2)
    result = p.map(task, job)
    
    print(result)
    print(f"End Time : {time.time() - start}s")
    
    start = time.time()
    
    result = [task(j) for j in job]
    
    print(result)
    print(f"End Time : {time.time() - start}s")