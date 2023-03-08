import os
import time
from joblib import Parallel, delayed

def task(idx, count):
    print(f"PID : {os.getpid()}")
    logic = sum([i ** 2 for i in range(count)])
    return idx, logic

job = [("First", 10 ** 7), ("Second", 10 ** 7), ("Third", 10 ** 7), ("Fourth", 10 ** 7)]

start = time.time()

result = Parallel(n_jobs=4)(delayed(task)(idx, count) for idx, count in job)

print(result)
print(f"End Time : {time.time() - start}s")

start = time.time()

result = [task(*j) for j in job]

print(result)
print(f"End time : {time.time() - start}s")