[상위 문서로 이동](../README.md)

# Singleton

우리는 정의된 클래스를 통해 객체를 생성할 수 있다. 마치 붕어빵 틀을 한 번 만들어두면 이 붕어빵 틀을 통해 여러 개의 붕어빵을 구울 수 있는 것과 유사하다.

```py
class Student:
    pass

a = Student()
b = Student()

print(id(a), id(b))
print(a is b)
```

위 코드는 Student 클래스로부터 서로 다른 a, b라는 서로 다른 객체가 생성되었다. 이 경우는 a와 b는 id값도 다르며, `is`를 통해 다른 객체임을 확인할 수 있다. 파이썬에서 클래스는 기능적으로 보면 객체를 생성하는 역할이지만, **사실 `type`이라는 메타 클래스로부터 생성된 객체이다.** 즉, 위 코드가 실행되면 아래 그림과 같이 객체가 생성된다.

<img src="https://wikidocs.net/images/page/69361/singleton_01.png">

싱글톤 패턴은 **사용자가 여러 번 객체 생성을 하더라도 클래스로부터 오직 하나의 객체만 생성되도록 하는 디자인 패턴**이다. 이러한 싱글톤 패턴은 오직 유일한 객체를 통해서만 어떤 리소스에 접근해야하는 제약이 있는 상황에서 유용하게 사용할 수 있다. 클래스를 사용하는 입장에서는 실수로 여러 번 객체 생성을 시도하더라도 내부적으로는 오직 하나의 객체만 생성되고 사용된다.

## 객체 생성과 초기화

파이썬에서 객체의 생성과 초기화에는 `__new__`와 `__init__`이라는 메서드가 사용된다. 보통 클래스를 정의할 땐 `__init__`만을 정의하는데, `__new__`는 클래스에 **정의되어 있지 않으면 알아서 object 클래스의 `__new__`가 호출된다.** 생성된 객체에 속성(property)를 추가할 때 `__init__`이 호출되는 것이다.

사용자가 클래스의 `__new__` 메서드를 재정의 할 때는 사용자가 직접 object 클래스의 `__new__` 메서드를 호출해서 객체를 생성하고 생성된 객체를 리턴하는 코드를 구현해야 한다. 이를 오버라이딩이라고도 한다.

예제

```py
class Foo(object):
    def __new__(cls, *args, **kwargs):
        print("__new__ is called\n")
        instance = super().__new__(cls)
        return instance

    def __init__(self):
        print("__init__ is called\n")


s = Foo()
```

위 `Foo()` 클래스에는 `__new__` 메서드가 재정의되어 있으므로 object 클래스의 `__new__` 함수는 호출되지 않는다. 또한 `instance`함수는 `super().__new__(cls)`를 통해 object 클래스의 `__new__`함수를 호출하였고, 이를 통해 생성된 객체를 반환하였다.

최종적으로 아래와 같은 구조를 띄고 있다.

<img src="https://wikidocs.net/images/page/69361/singleton_02_00.png">

## Python 싱글톤 구현

유일한 객체가 생성되도록 해주는 싱글톤 패턴을 구현하기 위해서는 앞서 살펴봤던 `__new__` 메서드를 재정의해준 후 해당 메서드 내에서 이미 객체가 생성됐다면 객체를 생성해주지 않도록 처리하면 디자인 패턴을 구현할 수 있다. 객체의 생성 여부는 모든 클래스 객체의 속성 변수로 `__instance`를 추가한 후 해당 변수로 관리해주도록 해주면 된다.

```py
class Singleton(object):
    def __new__(cls, *args, **kwargs):
        if not hasattr(cls, "_instance"):         # Foo 클래스 객체에 _instance 속성이 없다면
            print("__new__ is called\n")
            cls._instance = super().__new__(cls)  # Foo 클래스의 객체를 생성하고 Foo._instance로 바인딩
        return cls._instance                      # Foo._instance를 리턴

    def __init__(self):
        cls = type(self)
        if not hasattr(cls, "_init"):             # Foo 클래스 객체에 _init 속성이 없다면
            print("__init__ is called\n")
            self.data = data
            cls._init = True


s1 = Singleton()
s2 = Singleton()
print(s1)
print(s2)
```

<img src="https://wikidocs.net/images/page/69361/singleton_02.png">

## 출처

https://wikidocs.net/69361