# Thread

하나의 작업이 오래 걸리는 작업이라면 이 작업을 백그라운드로 실행해두고 결과가 리턴되기 전까지 다른 작업을 하고 싶을 때 주로 사용한다. Thread 개념은 일반 OS에 통용되는 Thread와 동일하며, 코드를 병렬로 실행시켜주는 역할을 수행해준다. 스레드를 생성하여 실행하는 순간 코드는 두 개의 분기로 나누어져서 이론적으로 동시에 실행된다. 물론 실제론 CPU의 시간을 나누어서 번갈아가며 실행된다.

파이썬에서는 스레드를 생성하기 위해 `Threading` 모듈을 제공한다.

## 생성 및 실행

스레드를 생성하기 위해 우선 Thread 객체를 생성하고 `start()` 메서드를 호출하여 스레드를 실행시킨다.

`threading.Thread`를 상속받은 클래스 또는 일반 함수를 사용할 수 있다.

**쓰레드가 실행할 함수를 작성하고 그 함수명을 `threading.Thread()` 함수의 target argument에 지정한다.** 예를 들어, 아래 예제에서 count 함수를 쓰레드가 실행하도록 `threading.Thread()` 함수의 파라미터로 `target=count`을 지정했다. 그리고 스레드가 실행하는 함수에 파라미터를 전달하기 위해서 args 키워드에 필요한 파라미터를 지정한다.


```python
import threading

def count(num):
    while num > 0 :
        num = num -1
        print(num)

    print('Thread exit')


t = threading.Thread(target=count, args=(10,))
t.start()
print('main exit')
```

## 데몬 쓰레드

Thread 클래스에서 daemon 속성은 서브쓰레드가 데몬 쓰레드인지 아닌지를 지정하는 것인데, 데몬 쓰레드는 백그라운드에서 실행되는 쓰레드로 메인 쓰레드가 종료되면 즉시 종료되는 쓰레드이다. 메인 쓰레드가 종료할 지라도 자신의 작업이 끝날때까지 실행되는 서브 쓰레드와는 반대되는 개념이다.

예제)
```python
import threading, requests, time
 
def getHtml(url):
    resp = requests.get(url)
    time.sleep(1)
    print(url, len(resp.text), ' chars')
 
# 데몬 쓰레드
t1 = threading.Thread(target=getHtml, args=('http://google.com',))
t1.daemon = True 
t1.start()
 
print("### End ###")
```

## 출처
http://pythonstudy.xyz/python/article/24-%EC%93%B0%EB%A0%88%EB%93%9C-Thread