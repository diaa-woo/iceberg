# Flutter Basic Code

## 프로젝트 구성

<ul>
    <li>pubspec.ymal: 프로젝트의 메타데이터를 정의하고 관리함</li>
    <li>android / ios 폴더: 각 환경에서 빌드할 수 있는 라이브러리 포함</li>
    <li>test 폴더: 프로젝트를 테스트 해볼 수 있는 다트 파일 포함</li>
    <li>lib 폴더: 프로젝트의 메인 소스를 넣어줌</li>
</ul>

## flutter 기본 코드

Stateless Widget:

```Dart
import 'package:flutter/material.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
    @override
    Widget build(BuildContext context) {
        return MaterialApp(
            title: 'First app',  //프로젝트의 제목 지정
            theme: ThemeData(  //앱의 기본 테마
                primarySwatch: Colors.blue //특정 색의 음영들을 끌어모아서 사용하는 명령어
            ),
            home: MyHomePage(),  //앱이 성공적으로 실행되었을 때 띄워지는 화면, Scaffold로 대체 가능
        );
    }
}

class MyHomePage extends StatelessWidget {
    @override
    Widget build(BuildContext context) {
        return Scaffold(
            appBar: AppBar(  //앱바 정의
                title: Text('First app'),
            ),
            body: center(   //body: 앱 화면을 구성해주는 시작 요소(중요!), Center: 레이아웃을 중앙으로 모아줌  
                child: Column(  //Center 레이아웃은 여러 개의 자식들을 가질 수 있음, Column: 위젯들을 세로로 배치해줌
                    children: <Widget>[  //Column 레이아웃은 다양한 위젯들을 내포하기 때문에 여러개의 자식들을 지님, []는 배열을 지칭
                        Text('Hello'),
                    ], 
                ),  
            )  
        );
    }
}
```

<p>MaterialApp 내에서는 Text 불필요(앱을 통틀어서 부르는 제목), 다만 Scaffold에서는 Text가 필요함(앱 바에서만 적용)</p>