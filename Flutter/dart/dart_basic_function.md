# Function

## 개요
<br>
다트는 완전한 객체 지향 언어이다. 때문에 다트에서는 모든 것이 객제인데, 여기서 함수도 객체로 표현한다.(자바스크립트의 자리를 노리고 있는 다트의 야심이 보임. 하지만 어림도 업..읍읍)
<br><br>
함수가 객체이기 때문에 갖는 특징이 있는데, 먼저 <b>변수가 함수를 참조</b>할 수 있다. 그리고 <b>함수의 인자로 함수를 전달</b>할 수도 있다. 
<br><br>
다트에서의 새로운 개념은, <b>선택 매개변수(Optional Parameter)</b>이다. 선택 매개변수는 또 두 가지로 나뉘는데. 하나는 <b>이름 있는 선택 매개변수(named optional parameter)</b>이고, 다른 하나는 <b>위치적 선택 매개변수(Positional Optional Parameter)</b>이다.
(코틀린에도 같은 개념은 존재함)
<br><br>
그리고 <b>익명 함수(Anonymous Function)</b>또한 지원하며, 그의 친구인 <b>람다식(Lambda Expression)</b>또한 지원한다.
<br><br>
정리

 - 변수가 함수 참조 가능
 - 다른 함수의 인자로 함수 전달 가능
 - 이름 있는 선택 매개변수
 - 위치적 선택 매개변수
 - 익명 함수 및 람다

## 변수가 함수 참조 가능
<br>
타입 변수명 = () {}

```Dart
getName() {
    return 'Hwang';
}

var name = getName();
```
<br>
dart에서는 함수 타입을 생략할 수 있지만, 가급적 명시해주는 것이 좋음!

## 다른 함수의 인자로 함수 전달 가능
<br>
함수A(함수B(), 함수C()) { }

```Dart
int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int multi(int a, int b) {
    return a * b;
}

main() {
    int a = 10;
    int b = 5;

    print('${a+b} * ${a-b} = ${multi(add(a, b), sub(a,b))}');
}
```

## 이름 있는 선택 매개변수
<br>
함수 호출 시 매개변수에 인자 값을 넘겨줄 때 매개변수명을 이용하여 인자 값을 넘겨줄 수 있다. 매개변수명으로 인자 값을 넘겨줄 매개변수는 {}로 감싸줘야한다.

<br><br>
ex) getAddress (String 매개변수명1, {String 매개변수명2, String 매개변수명3}) {}

```Dart
String getAddress(String city, {String district, String zipCode = '111222'}) {
    return '$city시 $district구 $zipCode;' 
}

main() {
    print('${getAddress('서울', district: '강남')}');
    print('${getAddress('서울', district: '강남', zipCode: '012345')}');
}
```

## 위치적 선택 매개변수
<br>
앞선 이름 선택 매개변수에서 zipCode의 초기값을 지정한 형태를 살펴봤다. 비슷한 개념이다. 위치적 선택 매개변수는 미리 초깃값을 지정해놓고 함수 호출 시 해당 매개변수에 인자 값을 넘겨주지 않으면 초깃값을 사용하는 것이다.
<br><br>
선언 방법은 선택 매개변수 지정을 { } 대신에 [ ]로 하는 것이 차이점
<br><br>
함수(매개변수, [매개변수 = 초깃값, 매개변수 = 초깃값]) { }
<br><br>
초깃값을 변경하고 싶으면 새로운 인자 값을 넘겨주면 된다. 주의할 점은 이름 있는 선택 매개변수와 마찬가지로 필수 매개변수는 꼭 인자 값을 줘야 하고 매개변수 위치를 꼭 고려해야한다.

```Dart
String getAddress(String city, [String district, String zipCode = '111222']) {
    return '$city시 $district구 $zipCode;' 
}

main() {
    print('${getAddress('서울'}');
    print('${getAddress('서울','서초')}');
}
```

## 익명 함수 및 람다식
