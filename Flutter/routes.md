# routes

> 원하는 화면(파일)로 바로 이동해줄 수 있음!

굳이 navigator에서 바로 이동하지 않는 이유
- 파일이 점점 많아질 수록 이동하려는 클래스를 무조건 포함시켜줘야 함 -> 번거로움
- 클래스 이름이 길면, 입력해줘야 하는 클래스 이름도 역시 많음 -> 번거로움
- 결정적으로, 관리하기가 여간 쉬운게 아님!

이렇게 직관적이고 관리하기 편하게 하기 위해 routes를 사용해 줌!   
   
코드
```Dart
import 'package:flutter/material.dart';

void main() {
  runApp(MaterialApp(
    title: 'Named routes Demo',
    // "/"을 앱이 시작하게 될 route로 지정합니다. 본 예제에서는 FirstScreen 위젯이 첫 번째 페이지가
    // 될 것입니다.
    initialRoute: '/',
    routes: {
      // When we navigate to the "/" route, build the FirstScreen Widget
      // "/" Route로 이동하면, FirstScreen 위젯을 생성합니다.
      '/': (context) => FirstScreen(),
      // "/second" route로 이동하면, SecondScreen 위젯을 생성합니다.
      '/second': (context) => SecondScreen(),
    },
  ));
}
```
   
출처: https://flutter-ko.dev/docs/cookbook/navigation/named-routes