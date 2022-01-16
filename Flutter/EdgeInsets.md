# EdgeInsets

## EdgeInsets란
<p></p>
<p> 시각적 가장자리, 왼쪽, 오른쪽, 위쪽, 아래쪽 측면에서 오프셋을 지정한다. padding이나 margin 위젯에서 주로 호출된다. </p>

<p>참고로 padding은 위젯의 안쪽 레이아웃을 잡아주고 margin은 바깥쪽 레이아웃을 잡아준다.</p>

## 종류

### EdgeInsets.all
<p></p>
<p> 전체 여백을 지정하는 옵션</p>

```Dart
EdgeInsets.all(8.0)
```

### EdgeInsets.only
<p></p>
<p> 특정영역에만 여백을 지정하는 옵션</p>

```Dart
EdgeInsets.only(bottom: 5.0)
EdgeInsets.only(left: 40.0)
```

### EdgeInsets.fromLTRB
<p></p>
<p> 왼쪽, 위, 오른쪽, 밑순으로 세세하게 여백을 지정해줄 수 있다.</p>


```Dart
EdgeInsets.fromLTRB(4.0, 0.0, 4.0, 0.0)
```

### EdgeInsets.zero
<p></p>
<p> 각 방향에서 오프셋이 0으로 지정한다.</p>

```Dart
EdgeInsets.zero
```

