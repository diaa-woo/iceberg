# Widget kinds

## 공통
<p>backgroundColor: 해당 위젯의 배경 색깔을 지정해줌</p>

```Dart
background: Colors.redAccent,
```

<p>Icon: 앱 화면에 material 라이브러리에 포함되어 있는 아이콘을 출력시켜 줌

```Dart
Icon(Icons.check_circle_outline)
```

<p>AssetImage: pubspec.ymal에서 assets 설정을 건드려 이미지 파일을 불러온 뒤, 화면에 이미지를 출력해준다.

```Dart
backgroundImage: AssetImage('(이미지 경로)')
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

<p>debugShowCheckedModeBanner: 화면 위에 디버그라는 표시를 가려줌</p>

```Dart
debugShowCheckedModeBanner: false,
```

## Scaffold & Container
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

<p>crossAxisAlignment: 위젯들을 가로로 나열해줌(위 main 축과 같이 가로로 축을 놔두어서 상,중,하단으로 구분하여 배치함)

```Dart
crossAxisAlignment: CrossAxisAlignment.start,
```

<p>SizedBox: 눈에 보이지 않지만 위젯들 간의 거리를 벌려주는 일종의 공백을 넣어주는 위젯</p>

```Dart
SizedBox(
    height: 10.0,  //Box의 높이 설정
    width: 10.0, //Box의 길이 설정
)
```

<p>Row: 위젯들을 가로로 정렬시켜줌(Column과 속성이 동일)

```Dart
Row(
    children: [...]
)
```

<p>CircleAvater: 둥근 칸을 만들어준다. 보통 이미지를 삽입할 때 주로 사용된다.

```Dart
CircleAvater(
    backgroundImage: AssetImage('(이미지 경로)'),
    radius: 60.0,  #해당 위젯의 크기
)
```

<p>Divider: 구분선을 표시해준다.

```Dart
Divider(
    height: 60.0,  //위와 아래의 위젯 사이의 거리를 합함(이 명령어는 위에 위젯과 30px, 아래 위젯과 30px 떨어짐)
    color: Colors.grey[850],
    thickness: 0.5,  //구분선의 두께
    endIndent: 30.0,  //화면의 끝과 벌어지는 간격
)
```

## Text
<p>앱 화면에 텍스트를 띄워주는 위젯으로 다양한 위젯들을 포함시킬 수 있다.</p>
<p>TextStyle: 텍스트 위젯에 사용되는 위젯으로, 텍스트의 크기와 색상, 즉 스타일을 지정해준다.</p>

```Dart
Text('NAME',
    style: TextStyle(
        color: Colors.white,  //텍스트 색상
        letterSpacing: 2.0,  //철자 간의 간격
        fontSize: 28.0,  //글자의 크기 설정
        fontWeight: FontWeight.bold,  //글자의 굵기 설정
        ...
    )
)
```