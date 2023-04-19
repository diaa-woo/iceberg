# Context Manager

컨텍스트 매니저는 원하는 타이밍에 정확하게 리소스를 할당하고 제공하는 역할을 한다. 가장 많이 사용되는 컨텍스트 매니저는 `with`문이고, 이들의 진가는 수행 코드를 동시에 실행시켜야 하는 경우에 발휘된다.

## 사용 예시

```python
with open('some_file', 'w') as opened_file:
    opened_file.write('hola')
```

위 코드는 파일을 열고 어떤 데이터를 쓰고 닫는 코드이다. 만약 데이터를 쓰는 동안 에러가 발생한다면, 파일을 닫으려고 시도할 것이다. 이 과정을 `with` 없이 수행하려면 다음과 같은 코드가 필요하다.

```python
file = open('somefile', 'w')
try:
    file.write('Hola')
finally:
    file.close()
```

두 코드를 비교하면 우선 `with`를 사용함으로써 표준 코드를 많이 줄이고, 만약 try 코드에서 인터럽트를 낼 시 finally로 가지 못하는 경우도 있는데 `with`는 무슨 일이 있어도 반드시 파일은 확실하게 닫아진다. 가장 큰 장점 중에 하나다.

일반적으로 파일을 잠그거나 해제하거나, 열려있는 파일을 닫을 때 컨텍스트 매니저를 사용한다.

## Class로 기능 향상

최소한 컨텍스트 메니저는 `__enter__`와 `__exit__` 메소드를 가지고 있다. with문은 기본적으로 시작할 때  `__enter__`로 시작한 후 `__exit__`로 나가는데, 이를 이용하여 나만의 컨텍스트 매니저를 만들 수가 있다.

```python
class File(object):
    def __init__(self, file_name, method):
        self.file_obj = open(file_name, method)
    def __enter__(self):
        return self.file_obj
    def __exit__(self, type, value, trace_back):
        self.file_obj.close()
```

방금 정의한 `__enter__`문과 `__exit__`문을 `with`문으로 사용할 수 있다. 해당 코드를 실행하면

```python
with File('demo.txt', 'wb') as opened_file:
    opened_file.write('Hola~')
```

다음과 같은 순서로 코드가 동작한다.

1. Context Manager는 File class의 `__exit__` 메소드를 저장한다.
2. Context Manager는 실행될 때 해당 클래스의 `__enter__`문을 실행한다.
3. `__enter__` 메소드는 파일을 열고 그 파일을 반환한다.
4. 열려진 파일은 `opened_file`에 실리게 된다.
5. `.write()`을 사용하여 파일을 쓸 수 있다.
6. `with`문은 저장된 `__exit__`문을 호출한다.
7. `__exit__` 메소드는 그 파일을 닫아준다.

이 과정을 보아 애초에 `with`문은 `__exit__`문을 들고 있어 `with`의 생애주기는 무조건 `__exit__`로 종료되게 설정되어 있다. 예외처리와는 전혀 다르게 아예 물아일체인 격이다.

## Handling Exception

그런데 위의 `__exit__` 메소드는 매개변수를 `self`를 제외하고 총 3개를 받는다. 저 매개변수들의 역할은, 처리 과정, 즉 위 과정 중 4~6번에서 오류가 발생한다면 저 3개의 매개변수를 `__exit__` 메소드에 넣어버린다. 그러면 `__exit__` 메소드에서는 다음에 어떤 단계들이 요구되는지에 따라 파일을 닫을 수 있는 방법을 결정할 수 있다. 

만약 어떤 파일 객체에서 예외가 발생한다면 어떻게 될까? 예를 들어 파일 객체가 지원되지 않는 메소드에 접근하려 한다고 생각해볼 때

(코드)

```python
with File('demo.txt', 'wb') as opened_file:
    opened_file.undefined_function('Hola!')
```

다음과 같은 코드에서 `with`문이 어떻게 에러를 처리해댜 하는지 단계를 살펴보자.

1. `type`, `value`, `traceback`의 에러가 `__exit__` 메소드를 통과한다.
2. `__exit__` 메소드가 예외를 처리하도록 한다.
3. `__exit__` 메소드가 True를 반환한다면, 예외는 적절하게 처리된다.
4. `__exit__` 메소드가 True가 아닌 다른 것을 반환하면, `with`문에서 예외가 발생한다.
