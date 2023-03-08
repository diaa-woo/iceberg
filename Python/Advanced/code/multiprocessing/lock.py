from multiprocessing import Process, Lock

def f(l, i):
    l.acquire()
    try:
        print('Hello World!', i)
    finally:
        l.release()

if __name__ == '__main__':
    lock = Lock()
    num2 = [11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
    
    for num in range(10):
        Process(target=f, args=(lock, num)).start()
        Process(target=f, args=(lock, num2[num])).start()