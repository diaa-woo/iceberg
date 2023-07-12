[상위 문서로 이동](../../README.md)

# Property

클래스에서 메서드를 통해 속성의 값을 가져오거나 저장하는 경우가 있다. 이때 값을 가져오는 메서드를 getter, 값을 저장하는 메서드를 setter라고 부른다.

기존 getter-setter 코드

```py
class Person:
    def __init__(self):
        self.__age = 0

    def get_age(self):
        return self.__age       # getter
    
    def set_age(self, value):   # setter
        self.__age = value
    
james = Person()
james.set_age(20)
print(james.get_age())
```

실행 결과:   

```
20
```

파이썬에서는 @property를 사용하면 getter, setter를 간단하게 구현할 수 있다.
- **@property**
- **@메서드이름.setter**

```py
class Person:
    def __init__(self):
        self.__age = 0

    @property
    def age(self):          #  getter
        return self.__age
    
    @age.setter
    def age(self, value):    #  setter
        self.__age = value

james = Person()
james.age = 20      # 인스턴스.속성 형식으로 접근하여 값 저장
print(james.age)    # 인스턴스.속성 형식으로 값을 가져옴
```

값을 가져오는 메서드에는 `@property` 데코레이터를 붙이고, 값을 저장하는 메서드에는 `@메서드이름.setter` 데코레이터를 붙인다.

특히 `@property`와 `@age.setter`를 붙이면 `james.age`처럼 메서드를 속성처럼 사용할 수 있다.

## 출처
https://dojang.io/mod/page/view.php?id=2476