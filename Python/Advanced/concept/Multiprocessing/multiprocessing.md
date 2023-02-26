# Multi Processing

## 프로세스 기반 병렬 처리

**프로세스 기반 병렬 처리(Multi Processing)**란 **쓰레딩(Threading)** 모듈과 비슷한 API를 활용하여 **프로세스 스포닝(Process Spawning)**을 지원하는 패키지이다.

`프로세스(Process)`란 프로그램이 메모리 상에서 실행중인 작업을 의미하는데, 이 **하나 이상의 프로세스를 동시에 처리하는 것**을 멀티 프로세싱이라고 칭한다.

병렬 프로그래밍 중의 한 기법인데, 이를 활용하여 대용량 데이터 처리 및 작업 효율성 상승 등의 효과를 볼 수 있다.

멀티 프로세싱은 다수의 프로세스로 처리하므로 **안전성**이 높지만, 각각 독립된 메모리 영역을 가지고 있어 작업량이 많을수록 **오버헤드(Overhead)**가 발생할 수 있다.

조금 덧붙이면, 객체지향 프로그래밍이라는 개념도 이 멀티프로세싱이라는 개념을 통해 만들어진 듯 하다.

- `프로세스 스포닝(Process Spawning)`이란 **부모 프로세스(Parent Process)**가 운영체제에 요청해 새로운 **자식 프로세스(Child Process)**를 만들어내는 과정
- `스레드(Thread)`는 `프로세스(Process)` 안에서 실행되는 여러 흐름 단위를 의미한다.

## Process

```Python
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
```

![Process-Result](../../image/Multiprocessing/process2.png)

`프로세스(Process)` 클래스는 Process 객체를 생성한 후 `start()` 메서드를 호출해서 스폰한다.

이후 각 프로세스는 `join()` 메서드를 통해 자식 프로세스가 종료될 때까지 대기한다. 프로세스 종료까지 대기하는 이유는 각 프로세스마다 ID가 존재하기에 process 목록을 통해 프로세스가 종료될때까지 기다린 후 확인하기 위하여 대기를 걸어준다.

`프로세스(Process)`는 각 작업마다 새로운 프로세스가 할당되어 작업을 처리한다.

![Process-Result](../../image/Multiprocessing/process.png)

그렇다고 무조건 빨라요 빼액! 이 짓은 하지 말자...

## poll

```Python
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
```

![Poll_result](../../image/Multiprocessing/poll.png)

`폴(Poll)` 객체는 여러 입력 값에 걸쳐 함수의 실행을 병렬 처리하고 입력 데이터를 프로세스에 분산시켜준다.

위 명령어에서는 인스턴스를 생성하고 2개의 작업자를 생성시켜준다 : `p = Pool(processes = 2)`

`map()` 메서드를 통해 **실행하려는 함수**와 **반복 가능한 객체**를 입력하여 각 프로세스에 매핑한다.

`Poll`은 사전에 `Proceeses`의 개수를 설정하여 반복한다.
  
- 프로세스의 개수가 2개라면, **첫 번째**와 **세 번째** 작업은 같은 `PID`를 갖는다.

위에건 프로세스를 공장처럼 찍어내는 것이고, 이건 일부만 프로세스를 만들어 돌리는 것.

## parallel

```Python
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
```

![parallel](../../image/Multiprocessing/parallel.png)

`joblib` 라이브러리는 `multiprocessing` 모듈과 동일한 기능을 포함하고 있다.

다만 주요한 차이점은 매개 변수를 좀 더 쉽게 전달할 수 있으며, 대규모 `Numpy` 기반 데이터 구조에 대해 작업자 프로세스와 공유 메모리를 효율적으로 사용할 수 있다.

`Parallel(n_jobs=프로세스 개수)(delayed(함수)(인수))`의 구조로 사용할 수 있다.

`Parallel` 클래스는 병렬 매핑을 위한 클래스이다. `벡엔드(Backend)`를 설정하거나, `배치 크기(batch_size)` 등을 추가로 설정해줄 수 있다.

`delayed` 메서드는 함수의 인수를 캡처하는 데 사용되는 Decorator이다.

대규모 작업에서는 `joblib`를 활용하는 것이 효과적이다.