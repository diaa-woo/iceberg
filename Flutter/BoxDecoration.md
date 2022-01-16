# BoxDecoration

## BoxDecoration
<p></p>
<p> 사각형 모양의 UI를 꾸밀 수 있다. (혹은 박스, 위젯을 꾸며주기도 한다.)</p>

<p>Example Code:</p>

```Dart
import 'pacakage:flutter/material.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
    @override
    Widget build(BuildContext context) {
        return MaterialApp(
            title: 'Test',
            home: Scaffold(
                body: Center(
                    child: Container(
                        height: 150,
                        width: 150,
                        alignment: Alignment.center,
                        decoration: BoxDecoration(
                            ...  //이곳에 들어갈 코드를 작성한다.
                        )
                        child: Text('Main')
                    )
                )
            )
        )
    }
}
```

<p> 위 샘플코드를 메인으로 두고 저 컨테이너를 BoxDecoration을 이용하여 꾸며볼 것이다.</p>

## 종류
<p></p>
<p> color: 색상을 지정해줄 수 있다.</p>

```Dart
BoxDecoration(
    color: Colors.red,
)
```

<p> image: 이미지를 지정해줄 수 있다. 다만 DecorationImage라는 위젯을 추가로 호출해주어야 한다.</p>

```Dart
BoxDecoration(
    image: DecorationImage(
        image: AssetImage(
            '[이미지의 위치]'
        )
    )
)
```

<p> border: 테두리를 지정해줄 수 있다.</p>

```Dart
BoxDecoration(
    border: Border.all(
        color: Colors.black,
        style: BorderStyle.solid,
        width: 10
    )
)
```

<p> shape: 모양을 바꿀 수 있다.</p>

```Dart
BoxDecoration(
    shape: BoxShape.circle,
)
```

<p> borderRadius: 테두리를 둥글게 할 수 있다.</p>

```Dart
BoxDecoration(
    borderRadius: BorderRadius.circular(10.0),  //위젯 모서리의 전체적인 둥글기를 구성  
)
```

<p>vertical, horizontal으로 위아래, 왼쪽오른쪽만 radius를 설정할 수 있다.</p>

```Dart
borderRadius: BorderRadius.vertical(
    bottom: Radius.circular(10),
)
```

<p> gradient: 그라데이션을 설정한다.</p>

```Dart
gradient: LinearGradient(
    begin: Alignment.topLeft,
    end: Alignment.bottomRight,
    colors: [
        Colors.red,
        Colors.blue,
    ]
)
```

<p> boxShadow: 네모 모양의 그림자를 여러 개 추가한다.</p>

```Dart
boxShadow [
    BoxShadow(
        color: Colors.grey,
        blurRadius: 5.0,
        spreadRadius: 3.0,
    )
]
```
