# provider
   
## 사용하는 이유
   
1. Flutter dev 공식 추천임
2. 가장 보편적임

## State Mangement

state: UI에 변화가 생기도록 영향을 미치는 데이터   
앱 수준의 데이터 -> 앱의 화면에 모든 변화를 일으키는 데이터   
위젯 수준의 데이터 -> 위젯 수준에서 처리하여 화면에 변화를 주는 데이터

setState: state가 변해서 UI가 변해야 하는 경우 이 메소드를 사용
- Buildmethod 호출
- Flutter가 기본 제공하는 state Managemnet

앱 수준으로 전부 초기화 시킬 시, 필요한 것 외의
고정된 텍스트도 re-build가 되는데, 이럴 경우 위젯 트리의
깊이가 넓어질수록 상당히 비효율적이며, 앱의 performance에도 큰
영향을 미치게 해줌

setState UI의 state는 state 클래스에서 관리하게 되는데, 

문제점
- 비효율성: 오직 한개의 위젯의 state만 업데이트 하려 해도 그 이하 
위젯 전체를 리빌드 해버림
- 동시에 다른 위젯의 state를 업데이트 시켜주지 못함!
	- 아주 단순한 기능만 가지고 있음

state management의 두가지 개념
- 위젯이 쉽게 데이터에 접근할 수 있는 방법
-변화된 데이터에 맞추어서 UI를 다시 그려주는 기능

코드
Provider.of<Salmon>(context) => 이러면 위젯이 전달 받기를 원하는 데이터가 되어줌
제공자      데이터타입 

ex)
final fish = Provider.of<Salmon>(context)
-> 이러면 fish를 무한정으로 복사 가능하며 필요할 때마다 불러서
전달되어 질 수 있는 데이터가 될 수 있는 것임

Provider == widget 
