# JMenuBar

## Menu & MenuBar

메뉴는 공간을 절약함과 동시에 사용자에게 여러 가지 옵션 중에서 하나를 선택하게 하는 컴포넌트이며, 다른 컴포넌트와 달리 컨테이너 안에 배치되지 않는다. 즉, 항상 맨 위에 고정적인 자리를 가진다.

메뉴바는 프레임에만 부착될 수 있으며, **패널은 부착이 불가하다.**

메뉴는 메뉴바에 나타나거나 팝업 메뉴로만 나타나며, 메뉴바에 메뉴를 나열하고, 메뉴바에 나열된 메뉴들에서 각 매뉴 항목을 가진다. 여기서 팝업 메뉴는 사용자가 팝업이 가능한 컴포넌트 위에서 마우스 우클릭을 할 때 등장한다.

메뉴 항목에서는 여러가지를 넣을 수 있는데, 텍스트뿐만 아니라 이미지도 올 수 있고, 체크 박스도 올 수 있다. 또한, 폰트나 색상도 변경 가능하다.

메뉴는 `JAbstractButton` 클래스를 상속하고 있으므로 일종의 버튼이라고 보면 된다. 따라서 누르면 이벤트가 발생한다.

메뉴바는 `JMenuBar` 객체, 메뉴는 `JMenu` 객체, 메뉴 항목은 `JMenuItem` 객체로 만들어진다.    
팝업 메뉴는 `JPopupMenu`를, 체크박스 메뉴항목은 `JCheckboxMenuItem` 객체에 의해 표현된다.

예제 :

```JAVA
...
JFrame frame = new JFrame("메뉴바 예제")

JMenuBar menuBar;   // 메뉴바 선언
JMenu menu;         // 메뉴 선언
JMenuItem menuItem; // 메뉴 항목 선언

menuBar = new JMenuBar();    // 메뉴바 초기화

menu = new JMenu("메뉴1");
menuBar.add(menu);

menuItem = new JMenuItem("메뉴항목1");    // 메뉴항목 선언
//menuItem = new JMenuItem("메뉴항목1", KeyEvent.VK_T); -> 키보드 단축기 설정 가능
menu.add(menuItem);                     // 메뉴에 메뉴 항목 추가

frame.setJmenuBar(menuBar);             // 프레임에 메뉴바 설정
```

각 메뉴 항목마다 **단축기를 설정**하려면 `setMenuShortCut` 메소드를 불러오면 된다.

이벤트 처리: 메뉴 항목(`JMenuItem`)을 눌렀을 때 발생하는 이벤트를 처리하기 위해 `ActionListener` 인터페이스를 구현한다.

## 키보드와의 관계

메뉴는 기억키(mnemonics)와 가속키(accelerators)의 두 가지 종류의 키보드 선택을 지원한다. 기억키는 모든 사용자를 위한 것이고, 가속키는 고급 사용자를 위한 것이라고 생각하면 된다.

기억키는 `setMnemonics()` 메소드를, 가속키는 `setAccelerator()` 메소드를 사용한다. 

  - **기억키** : 키보드를 사용하여 이미 표시되어 있는 메뉴 계층을 둘러보는데 이용된다. 주로 메뉴에 단축키를 설정하여 Alt를 누르면 첫 번째 메뉴가 선택되게 한다.

```java
menuItem.setMnemonics(KeyEvent.VK_T);
```

  - **가속키** : 메뉴 계층 구조를 통하지 않고, 직접 메뉴 항목을 선택할 수 있다. 즉, 메뉴 항목이 선택되는 키들의 조합이다. 예를 들어 `Alt + 1`을 눌렀을 때 Alt 단축기를 가진 메뉴의 서브 메뉴 항목의 첫 번째를 선택하게 된다. 단말 메뉴 항목만이 가속키는 가질 수 있다.

```java
menuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_T, ActionEvent_ALT_MASK));
```

## 전체 예제

