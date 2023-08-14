import threading

def count(num):
    while num > 0 :
        num = num -1
        print(num)

    print('Thread exit')


t = threading.Thread(target=count, args=(10,))
t.start()
print('main exit')