# 정적 메소드(Static Method, Class Method)

정적메서드를 지원하는 두 가지 방법이 있다.

`@staticmethod`, `@classmethod`

같은 면과 다른 면을 각각 살펴보자.

## 공통점

먼저 공통점으로는 둘 다 인스턴스를 만들지 않아도 class의 메서드를 바로 실행할 수 있다는 것이다.

```py
#staticmethod
class hello:
    num = 10

    @staticmethod
    def calc(x):
        return x + 10

print(hello.calc(10))
#결과
20
```

```py
#classmethod
class hello:
    num = 10

    @classmethod
    def calc(cls, x):
        return x + 10

print(hello.calc(10))
#결과
20
```

둘 다 객체를 만들지 않고 바로 해당 메서드를 사용했다. 차이점은 calc 메서드를 만들 때 cls라는 인자가 추가된 점이다.

## 차이점

만약 hello 클래스의 num 속성에 접근하려면 어떻게 해야할까? 우선 객체로 접근하는 것이 아니기 때문에 `self.num`을 사용할 수 없다. 억지로 사용하고 싶음 `@staticmethod`는 다음과 같이 해야한다.

```py
class hello:
      num = 10

      @staticmethod
      def calc(x):
            return x + 10 + hello.num

print(hello.calc(10))
```

그닥 좋아보이진 않지만 정적 변수로 접근했다. `@classmethod`는 어떨까

```py
class hello:
      num = 10

      @classmethod
      def calc(cls, x):
            return x + 10 + cls.num

print(hello.calc(10))
```

classmethod는 cls가 있는데 이것은 '클래스'를 가리킨다. 이것으로 클래스의 어떤 속성에도 접근할 수 있다. 위 예시 경우 또한 `cls.num`을 통해 `hello`클래스의 `num` 속성에 접근했다.

만약 상속 관계가 있는 클래스들에선 `cls`가 가리키는 클래스는 어떤 클래스일까?

```py
class hello:
      t = '상속함'

      @classmethod
      def clac(cls):
            return cls.t
      
class hello_2(hello):
      t = '상속 받음'

print(hello_2.calc())

# 결과
상속함
```

상속받은 `hello_2` 클래스가 `t` 속성을 업데이트했다. `cls.t`가 상속시켜 준 클래스에 있더라도 이것이 가리키는 것은 상속받은 클래스의 `t` 속성이다. `cls`는 상속 받은 클래스에서 먼저 찾는다.

그 외 `@classmethod`는 클래스의 어떤 옵션을 바꾸는 용도로 사용 가능하다.

## 결론

위에 설명만 보면 `@classmethod`이 더 유리해보이지만, `@staticmethod`도 유틸리티 성격에 맞게 사용할 수 있다. 그러니 상황과 때에 맞게 사용하믄 좋다.

## 출처

https://wikidocs.net/21054