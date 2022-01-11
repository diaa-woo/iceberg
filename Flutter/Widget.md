# Widget

## Widget
<ol>
    <li> 독립적으로 실행되는 작은 프로그램</li>
    <li> 주로 바탕화면 등에서 날씨나 뉴스, 생활정보 등을 보여줌</li>
    <li> 그래픽이나 데이터 요소를 처리하는 함수를 가지고 있음</li>
</ol>

## Flutter 상에서 위젯이란?
<ol>
    <li> UI를 만들고 구성하는 모든 기본 단위 요소</li>
    <li> 눈에 보이지 않는 요소들까지 위젯</li>
    <li> <b>플러터에선 모든 것이 위젯임!</b></li>
</ol>

## 위젯들의 종류
<p>Stateful -> Value 값을 지속적으로 추적 보존</p>
<p>Stateless -> 이전 상호작용의 어떠한 값도 저장하지 않음</p>

### Stateless Widget(상대가 없는 정적인 위젯)
<ol>
    <li> 스크린상에 존재만 할 뿐 아무것도 하지 않음</li>
    <li> 어떠한 실시간 데이터도 저장하지 않음</li>
    <li> 어떤 변화(모양, 상태)를 유발시키는 value값을 가지지 않음</li>
</ol>

### Stateful Widget(계속 움직임이나 변화가 있는 위젯)
<ol>
    <li> 사용자의 interaction에 따라서 모양이 바뀜</li>
    <li> 데이터를 받게 되었을 때 모양이 바뀜</li>
    <li> 어떤 변화(모양, 상태)를 유발시키는 value값을 가지지 않음</li>
</ol>

### Inherited Widget

## Flutter Widget tree
<ol>
    <li> Widget들은 tree 구조로 정리될 수 있음</li>
    <li> 한 Widget내에 얼마든지 다른 widget들이 포함될 수 있음</li>
    <li> Widget은 부모 위젯과 자식 위젯으로 구성</li>
    <li> Parent Widget을 Widget Container라고 부르기도 함</li>
</ol>

root widget -> MaterialApp Widget(전체 앱 부분)(flutter 패키지 전부 사용 가능) -> Custom Widget(앱의 디자인 시작) -> Scaffold(**)(앱 화면과 기능을 구성해주기 위한 빈 페이지 구성)(이 밑으로 모든 앱의 구성요소들을 집어 넣어줌) -> 그 뒤로 내가 만들고 싶은대로 적어 넣어주면 됨.