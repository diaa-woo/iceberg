# 1. Types, Variable, Constant

## Types

 - num: int & double의 supertype
 - int: Integer
 - double: real number
 - String: 문자열
 - bool: true and false, Boolean type
 - var: 타입 미지정(자동 선언) 및 타입 변경 불가
 - dynamic: 타입 미지정(자동 선언) 및 타입 변경 가능
 - List: array of Dart
 - Set: 순서가 없고 중복 없는 collection
 - Map: key, value 형태를 가지는 collection

## Variable
<br>
타입 변수명 = '초깃값';

```Dart
String lastName = 'Seo';
```

<br>
다트의 변수는 참조(reference)를 저장하는데, lastName 변수는 Seo라는 값을 가진 String 객체에 대한 참조를 가지는 것이다.
<br><br>
var, dynamic 타입을 사용하는 경우는 자료형 지정 안해도 됨

## Constant
<br>
상수와 변수의 차이는 값의 변경 유무인데, 상수는 값 변경이 불가하다. 그리고 상수와 같은 특징을 가지는 리터럴이란 것도 있는데, 이들의 차이는 리터럴은 값 그 자체이고 상수는 그 값을 가진 후 값이 변경되지 않는다.

### final
런타임에 상수화가 된다.(값을 가져온 뒤 상수화 처리)

```Dart
final int PRICE = 10000; //10000은 리터럴
final NAME = 'KIM'; //타입은 생략 가능
PRICE = 2000; //에러
```

### const
<br>
컴파일 시점에 상수가 된다.(그냥 프로그램 돌릴때 부터 상수)

```Dart
const int PRICE = 10000; //10000은 리터럴
const NAME = 'KIM'; //타입은 생략 가능
PRICE = 2000; //에러
```