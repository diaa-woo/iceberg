[상위 문서로 이동](../../README.md)

# Dunder Method

**Double or magic methods in Python**

*Double Under(Underscores)* 의 약자. 즉 `__`를 의미한다. 이렇게 underscore(언더바) 두개로 시작해서 두개로 끝나는 특별한 메서드를 우리는 dunder이자 Magic Method라고 칭할 수 있다.

## 사용처

Magic Method는 별도로 호출되는 메서드는 아니다.

클래스 내에서 특별한 행위가 일어났을 때 내부적으로 호출되는 메서드인데, C++의 Operator를 구현한 함수와 약간은 유사하다고 볼 수 있다. 

하나의 예시로, + operator를 이용해 숫자를 더하는 상황에서 `__add__()` 메서드가 호출되게 된다.

참고로 `dir()` 명령어를 통하여 클래스에 있는 각종 dunder method들을 확인할 수 있다.

## Class에 Magic Method 구현하기

Magic Method는 개발자가 별도로 선언한 클래스에서도 구현이 가능하다. 아래는 `__gt__` Magic Method를 별도의 클래스에 구현하여 출력화 함께 `greater` 결과를 반환하는 Dunder 예시이다.

```py
class A:
      def __init__(self, val):
            self.v = val
      
      def __gt__(self, val):
            print(f"{self.v} > {val}")

            return self.v > val
      
if __name__ == "__main__" :
      test = A(10)
      print(test > 5)
```

가장 하단의 `print(test > 5)`에서 Class A의 `__gt__`가 호출되고, 이에 따라서 `self.v > val`을 stdout으로 출력한다.

결과
```
10 > 5
True
```

## 출처
https://armin.tistory.com/596