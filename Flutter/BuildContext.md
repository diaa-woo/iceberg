# BuildContext

## BuildContext

<p>1. widget tree에서 현재 widget의 위치를 알 수 있는 정보</p>

<p>빌드 함수는 Scaffold 위젯이나 MaterialApp 등의 위젯을 반환할 때, 해당 화면의 정보값이 담겨 있는 것이 BuildContext이다.</p>

<p>2. StatelessWidget이나 state 빌드 메서드에 의해서 반환된 위젯의 부모가 된다.</p>

<p>3. Scaffold.of(context) method</p>

<p>현재 주어진 context에서 위로 올라가면서 가장 가까운 Scaffold를 찾아서 반환하라!</p>

<p> 얘가 진짜 Scaffold의 buildContext 값을 반환해줌</p>