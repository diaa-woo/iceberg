# Class

클래스는 데이터(Data, Attribute)와 기능(Function)을 함께 묶어 제공해주는 기능이다. 기본 개념은 여타 다른 객체 지향 프로그래밍과 동일하며 기능 역시 모두 동일하게 제공하지만, 파이썬의 클래스 매커니즘은 최소한의 새로운 문법과 개념을 추가해두었다.  

## 객체

우선 객체에 대해 명확히 짚고 넘어가자.

> 컴퓨터 과학에서 객체는 클래스에서 정의한 것을 토대로 메모리(실제 저장공간)에 할당된 것으로 사용되는 데이터 또는 식별자에 의해 참조되는 공간을 의미하며, 변수, 자료구조, 함수 또는 메소드가 될 수 있다. 

> 절차적 프로그래밍에서 하나의 객체는 자료나 명령을 포함할 수 있지만 두 가지를 동시에 포함하지는 않는다. (명령은 프로시저나 함수의 형태를 가진다). 다만 객체지향 프로그래밍에서 객체는 클래스의 인스턴스이다. 클래스 객체는 자료와 그 자료를 다루는 명령의 조합을 포함하여 객체가 메시지를 받고 자료를 처리하며 메시지를 다른 객체로 보낼 수 있도록 한다. 실세계의 비유로 설명하자면, 가령 어떤 사람이 집에서 살기를 원할 때, 그 집의 청사진(집의 설계도)이나 축소 모형 따위는 전혀 필요가 없다. 필요한 것은 설계에 맞는 실제 집이다. 이 비유에서 청사진은 클래스를, 실제 집은 객체를 나타낸다.- wikipedia.org

... 어렵게 설명한다. 그냥 클래스는 설계도고, 객체는 그 설계도를 바탕으로 만들어 진 **실제** 돌아가는 여러 개의 구동체다라고 이해하는게 낫겠다.(OOP 관점) 객체랑 변수랑 시스템 관점에서는 큰 차이점이 없지만,(어차피 함수니 구조체니 싹다 메모리에 주소 집어넣는거다.) 클래스 내의 객체는 아예 독립적으로 구동되는 것이 가장 큰 차이점이다. 어찌보면 함수 같은데, 또 어떻게보면 그냥 구조체이기도 하고, 또 어떨땐 그냥 변수이기도 한, 이상한 놈인건 확실하다.

얘는 클래스에서 인스턴스라는 개념으로도 불리는데, 일반적으로 실행중인 임의의 프로세스, 클래스의 현재 생성된 오브젝트를 말하기도 하며, 물리 메모리의 일부를 가르키키도 한다. 객체 입장에서는 이 물리 메모리의 일부라는 표현이 가장 적합하다.

참고: OOP의 기본 개념이다.

- Abstraction(추상화): 만들고자 하는 것들의 공통적인 것을 바탕으로 하나로 묶는 것 -> 여러 기능들을 하나로 묶어 사용하기 편하게 만들어줌
- Encapsulation(캡슐화): 최소한의 외부 접근만을 허용하는 것 -> 보안 및 간소화
- Polymorphism(다형성): 자료형에 구애 받지 않고 프로그래밍 하는 것 -> 이건 구조체와 비슷한데 애초에 클래스는 구조체의 상위호환인 격이다.
- Inheritance(상속): 하위 개념이 상위 개념의 속성 및 동작 등을 물려받는 것.

## A Word About Names and Objects : 이름과 객체에 대한 한마디

지금부터는 공식 문서를 기반으로 작성한다. 오역 & 의역 존재 가능성 多! ㅠ

> Objects have individuality, and multiple names (in multiple scopes) can be bound to the same object.

위에서 설명하였듯 오브젝트는 개별성을 가지고 있고, 여러개의 이름들이 동일한 객체에 바인딩될 수 있다. 

> This is known as aliasing in other languages. 

다른 언어에서는 앨리어싱(aliasing)이라고도 불린다 - 리눅스에서도 종종 쓰이는 표현.

>  This is usually not appreciated on a first glance at Python, and can be safely ignored when dealing with immutable basic types (numbers, strings, tuples). 

보통 파이썬을 처음 사용할 때는 이 개념이 그리 높이 평가되지 않고, 불변하는 기본형들(numbers, strings, tuples)을 다루는 동안에는 무시해도 무방했었다. - 쓸 일이 없었쥬. 막말로 처음에는 클래스 없이도 잘 사용하셨잖어

> However, aliasing has a possibly surprising effect on the semantics of Python code involving mutable objects such as lists, dictionaries, and most other types

그러나, 앨리어싱은 리스트, 딕셔너리, 그리고 다른 타입들과 같이 꾸준히 변하는 가변 객체를 사용한 파이썬 코드를 사용할 시 앨리어싱은 극적인 효과를 나타나게 해줄 수 있다. 

> This is usually used to the benefit of the program, since aliases behave like pointers in some respects.

일부 aliases들은 어떤 면에서 포인터처럼 작동하기 때문에 일반적으로 프로그램의 이점을 위해 사용되기도 한다. 

>  For example, passing an object is cheap since only a pointer is passed by the implementation; and if a function modifies an object passed as an argument, the caller will see the change — this eliminates the need for two different argument passing mechanisms as in Pascal.

예를 들어, 포인터로만 구현되어 전달되는 경우

## Python Class 선언

```python
class Horse:
    ...
```

## 생성자(Constructor) 선언

```python
class Horse:
    def __init__(self, age, height, color, xpos, ypos):
        self.age = age
        self.height = height
        self.color = color
        self.xposition = xpos
        self.yposition = ypos
        self.velocity = 0
```

하나의 설계도. Java의 생성자와 기능이 동일하며, 외부 값과 기본 데이터 정의를 해줄 수 있다. 다만 생성자의 이름은 무조건 `__init__`이고, 매개변수 중 무조건 첫 번째로 `self`가 와야 한다. 근데 `self`는 뭐고

## self keyword

클래스 외부에서 해당 함수를 호출한 객체를 찾는 일은 객체의 이름만 알면 된다.
근데 클래스 내부에서 호출한 객체를 찾으려면 방법이 없다.

이에 도입되는 것이 `self` 키워드이다.
파이썬은 `self` 키워드를 통해 해당 함수를 호출한 객체를 가리킨다.

