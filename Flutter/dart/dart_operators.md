# Dart_Operators

## Arithmetic Operator
<p></p>

> +, -, *, /, ~/, %, ++, --

이때 ~/ 연산자는 몫을 구하는 연산자이다.

- 11/2 = 5.5
- 11~/2 = 5
- 11%2 = 1

## Assignment Operator
<p></p>

> =, +=, -=, *=, /=, ~/= 등

## Relational Operator
<p></p>

> ==, !=, >, <, >=, <=

## Bitshift Operator
<p></p>
사실 잘 안쓰긴 함 ㅋㅋ

> &, |, ^, ~, <<, >>

## Type check Operator
<p></p>

- as: 형 변환
- is: 객체가 특정 타입이면 true
- is!: 객체가 특정 타입이면 false (=특정 타입이 아니면 true)

as는 다른 타입으로 변환은 되지 않고 상위 타입으로 변환할 수 있다.<br>

## Conditional Expression
<p></p>

- ?
- ?.
- ??

1. ? 연산자
   1. 그냥 똑같은 삼항 연산자이다(형태: 조건문 ? true 일시 실행 : false 일시 실행)
   2. ex) (a>0) ? '양수' : '음수';
2. ?. 연산자
   1. null 체크를 편하게 해주는 조건적 멤버 접근 연산자(Conditional member access)이다. 이 연산자는 좌항이 null이면 null을 리턴하고, 아니면 우항의 값을 리턴한다.
   2. 형태: 좌항?.우항
3. ?? 연산자
   1. 위의 조건적 멤버 접근 연산자의 상위호환인 ?? 연산자가 있다. 이 연산자는 null 체크뿐만 아니라 null일 경우에 대한 처리까지 가능함. 좌항이 null이 아니면 좌항 값을 리턴하고 null이면 우항 값을 리턴한다.
   2. 형태: 좌항 ?? 우항

## Cascade notation
<p></p>
캐스케이드 표기법(..)은 한 객체로 해당 객체의 속성이나 멤버 함수를 연속으로 호출할 때 유용하다. 매번 객체를 표기하고 호출하는 불필요한 과정을 줄여주기 때문.<br><br>

```Dart
Employee employee = Employee()
..name = 'Kim'
..setAge(25)
..showInfo()

class Employee {
   var name = 'employee';
   int age;

   setAge(int age) {
      this.age = age;
   }

   showInfo() {
      print('$name is $age.');
   }
}
```