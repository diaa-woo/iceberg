# Widget kinds

## 공통
<p>backgroundColor: 해당 위젯의 배경 색깔을 지정해줌</p>

```Dart
background: Colors.redAccent,
```

## AppBar
<p> centerTitle: 앱바의 타이틀을 중앙으로 둘 것인지 입력해줌</p>

```Dart
centerTitle: true,
```

<p>elevation: (단어 뜻: 높이) 앱바가 띄워진 수치를 정해줌(0.0은 아예 띄우는 효과가 사라짐, 앱 화면과 동화되는 느낌을 줌)</p>

```Dart
elevation: 0.0,
```


## Scaffold
<p>Padding Widget: 레이아웃의 일종으로, 해당 위젯이 화면 속 원하는 위치로 이동시켜주는 위젯(특정 위치로부터 떨어지는 수치를 지정해줌)</p>
<p> 그 속에서도 여러 다른 위젯들을 집어 넣을 수 있음.</p>

```Dart
body: Padding(
    padding: EdgeInsets.fromLTRB(30.0(left), 40.0(top), 0.0(right), 0.0(bottom)),
    child: Column(...)  //이제 위에 잡아준 위치로 Column 내에 속해있는 자식 위젯들이 집어넣어 짐.
),
```

<p>mainAxisAlignment: 위젯들을 세로로 나열해줌(Column과의 차이: Column은 단순히 세로로만 나열해주기만 하고, 이 위젯은 앱 스트림 내에 상,중,하단으로 구분하여 정렬해줌)</p>

```Dart
mainAxisAlignment: MainAxisAlignment.center,  //축 내에서 중단으로 이동해줌
```

## Text
<p>앱 화면에 텍스트를 띄워주는 위젯으로 다양한 위젯들을 포함시킬 수 있다.</p>
<p>TextStyle: 텍스트 위젯에 사용되는 위젯으로, 텍스트의 크기와 색상, 즉 스타일을 지정해준다.</p>

```Dart
Text('NAME',
    style: TextStyle(
        color: Colors.white,  //텍스트 색상
        letterSpacing: 2.0,  //철자 간의 간격
        ...
    )
)
```