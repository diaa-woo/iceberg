# AppBar Menu Icon

## AppBar()
<p>leading: 앱 바에서 간단한 위젯들을 왼쪽으로 이동시켜주는 위젯(listview에서도 사용됨)</p>

```Dart
appBar: AppBar(
    leading: IconButton(...),
)
```

<p>actions: 앱 바에서 복수의 위젯들을 오른쪽으로 배치시켜주는 위젯(listview에서도 사용됨)</p>

```Dart
actions [
    IconButton(...)
]
```

<p>IconButton: 아이콘이 들어간 버튼(다른 곳에서도 사용 가능)</p>

```Dart
IconButton(
    icon: Icon(Icons.menu),  //아이콘 버튼에 해당되는 아이콘을 추가시킴
    onPressed: () {  //클릭 하였을 시
        print(...)
    }
)
```