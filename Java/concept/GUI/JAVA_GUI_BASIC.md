# JAVA GUI BASIC

## JAVA의 GUI

### 특징
1. 강력한 GUI 컴포넌트 제공
2. **대체적으로 쉬움**

### 프로그래밍 방법

#### GUI 컴포넌트 이용!
- AWT
  - OS가 제공하는 자원을 이용하여 컴포넌트 생성 - Native
  - `java.awt` 패키지
- Swing
  - 컴포넌트 자체가 자바로 작성되어 있어 어떤 플랫폼에서도 일관된 화면 작성 가능 - Cross Platform!
  - `javax.swing` 패키지

이 문서는 Java Swing에 대해 더 자세히 다름

### Swing Component Example

- JButton
- JCheckBox
- JRadioButton
- JTextField
- JPasswordField
- JTextArea
- JComboBox
- JList
- JProgressBar
- JTooTip
- JScrollPane
- JMenu
- JDialog
- JFrame
  
그외 등등..

### Swing의 특징!

- Swing GUI Component
  - 형식화된 텍스트 입력 & 패스워드 필드 동작과 같은 복잡한 기능들 제공
- 자바 2D API
  - 그림, 이미지, 애니메이션 기능 제공
  - 교체 가능한 룩앤필(Look-and-Feel) 지원
- 데이터 전송
  - 자르기, 복사, 붙이기, 드래그 앤 드롭 등의 데이터 전송 기능 제공

대부분의 프로그램은 Swing API 중 아주 작은 부분 집합만을 이용함. 따라서 대부분의 경우 다음의 두 가지 패키지만 포함하면 된다.

- `javax.swing`
- `javax.swing.event`

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbKw1J9%2Fbtq21BwUMVT%2FOYw8IYG6x4LHpJEZUvqEM1%2Fimg.png">

### 컨테이너와 컴포넌트

#### 컨테이너
- 다른 컴포넌트를 포함할 수 있는 GUI 컴포넌트
- 다른 컨테이너에 포함될 수 있음
  - AWT 컨테이너: Panel, Frame, Applet, Dialog, Window
  - Swing 컨테이너: JPanel, JFrame, JApplet, JDialog, JWindow

#### 컴포넌트
- 컨테이너에 포함되어야 비로소 화면에 출력될 수 있는 GUI 객체
- 다른 컴포넌트를 포함할 수 없는 순수 컴포넌트
- 모든 GUI 컴포넌트가 상속받는 클래스 : `java.awt.Component`
- Swing 컴포넌트가 상속받는 클래스 : `javax.swing.JComponent`

### GUI 작성 절차

1. **컨테이너를 생성한다.**
2. **컴포넌트를 추가한다.**

해당 절차를 사용하여 제작한 코드

```java
package practice;

import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
public class practice_gui extends JFrame{
    //Constructor
    public practice_gui() {
        setSize(300, 200);  // 크기 설정
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("프레임 작성예시");

        setLayout(new FlowLayout());  // 배치 관리자 설정
        JButton button = new JButton("버튼");

        // 컴포넌트 생성 및 추가
        this.add(button);
        setVisible(true);
    }

    public static void main(String[] args) {
        new practice_gui();
    }
}
```

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2F4ABst%2Fbtq20EHCHfz%2FvdZODVQst2eA7gOW6JMYKK%2Fimg.png">

## 기초 컨테이너와 컴포넌트

### Swing 클래스 계층 구조
- **Component**   
  : 화면에 표시되어서 사용자와 상호작용하는 시각적인 객체를 나타냄
- **Container**   
  : 내부에 다른 컴포넌트를 추가할 수 있는 기능을 제공   
  : 이 클래스의 `add()`를 사용하면 컨테이너 안에 컴포넌트를 추가
- **Window**   
  : 경계선, 타이틀 바, 버튼을 가지고 있는 윈도우를 정의
- **Frame**   
  : 자바 GUI 애플리케이션의 기초(`AWT`)
- **JFrame**   
  : Frame 클래스를 `Swing`의 출시에 맞추어 변경

### 중요한 메소드
- `setLocation(x,y)` | `setBoudns(x, y, width, height)` | `setSize(width, height)` : 프레임의 위치와 크기를 설정
- `setIconImage(IconImage)` : 윈도우 시스템에 타이틀 바, Task 스위치에 표시할 아이콘을 알려줌
- `setTitle()` : 타이틀 바의 제목 변경
- `setResizable(boolean)` : 사용자가 크기를 조절할 수 있는지 설정

예제:

```java
package practice;

import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
public class ContentPaneEx extends JFrame {
    public ContentPaneEx() {
        setTitle("ContentPane과 JFrame 예제");  // 프레임 타이틀
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container contentPane = getContentPane();    // ContentPane 정보 가져오기
        contentPane.setBackground(Color.orange);     // 배경색 : orange
        contentPane.setLayout(new FlowLayout());     // ContentPane에 FlowLayout 배치관리자 달기
        
        contentPane.add(new JButton("OK"));     // OK버튼
        contentPane.add(new JButton("Cancel")); // Cancel 버튼
        contentPane.add(new JButton("Ignore")); // Ignore 버튼
        
        setSize(300, 150);              // 프레임 크기 300 x 150
        setVisible(true);                            // 화면에 프레임 출력
    }

    public static void main(String[] args) {
        new ContentPaneEx();
    }
}

```

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FcWVNlK%2Fbtq2QVcqOBM%2Fb7qE2nsfmv9hFWVURh3KBk%2Fimg.png">

18번째 줄의 `FlowLayout`의 배치 관리자는 컴포넌트를 순서대로 부착하는 일을 맡은 객체이다.

#### Swing 응용프로그램의 종료
- `System.exit(0);`
  - 언제 어디서나 무조건 종료, 응용 프로그램 내에서 스스로 종료
  - 프래임의 오른쪽 상단의 종료 버튼(x)을 클릭시 -> 프레임 윈도우를 닫음 **(프레임이 화면에서 보이지 않게 됨)**
- **But 프레임이 보이지 않게 되지만 응용프로그램이 종료한 것은 아님**
  - 키보드나 마우스 입력을 받지 못함
  - 허나 다시 `setVisible(true)`를 호출하면, 그대로 다시 보이게 되고 이전처럼 작동함

**이를 해결하기 위해 프레임 종료 버튼 클릭 시 프레임 & 프로그램을 함께 종료시키는 방법인 `setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE)`을 사용하는 것**

### 기초 컴포넌트

- **레이블(Label)**
  - 편집 불가능한 텍스트를 표시
  - ex: `JLabel label = new JLabel("Hello World!");`

- **버튼(Button)**
  - 이벤트를 발생시킬 수 있는 버튼 
  - ex: `JButton btn = new JButton("클릭");`
  - 버튼의 종류
    - `JButton`
    - `JCheckBox`
    - `JRadioButton`

- **텍스트 필드(TextField)**
  - 입력이 가능한 한 줄의 텍스트 필드
  - ex: `JTextField text = new JTextField(20);`
  - 텍스트 필드의 종류
    - `JTextField` : 기본적인 텍스트 필드
    - `JFormattedTextField` : 사용자가 입력할 수 있는 문자를 제한
    - `JPasswordField` : 사용자가 입력하는 내용이 보이지 않음
    - `JComboBox` : 사용자가 직접 입력할 수도 잇지만 항목 중에서 선택할 수 있음
    - `Jspineer` : 텍스트 필드와 버튼이 조합된 것

## 배치 관리자

### 컨테이너와 배치 개념
- **컴포넌트는 컨테이너에 부착되지 않으면 화면상 나타날 수 없음**
- **컨테이너마다 하나의 배치 관리자가 존재하며, 삽입되는 모든 컴포넌트의 위치와 크기를 결정하고 적절히 배치**
- **컨테이너의 크기가 변하면 내부 컴포넌트들의 위치와 크기를 모두 재조절 & 재배치해야 함.**

### 배치 관리자 대표 유형 3가지

- `FlowLayout`
- `BorderLayout`
- `GridLayout`

| AWT와 Swing의 컨테이너 | 디폴트 배치관리자 |
|-----------------------|-----------------|
| `Window` | `BorderLayout` |
| `Frame`, `JFrame` | `BorderLayout` |
| `Dialog`, `JDialog` | `BorderLayout` |
| `Panel` , `JPanel` | `FlowLayout` |
| `Applet`, `JApplet` | `FlowLayout` |

### FlowLayout 배치 관리자
- **배치관리자를 지정하지 않으면 묵시적으로 FlowLayout으로 지정!**
- **컴포넌트를 수평 방향으로 배치하는 관리자**
  - 왼쪽에서 오른쪽, 위에서 아래로 순차적으로 배열
  - if) 한 줄에 모두 배치하지 못한다면 다음 줄에 연속하여 배열
- **Constructor**
  - `FlowLayout()`
  - `FlowLayout(int align)`
  - `FlowLayout(int align, inthgap, int vgap)`
- 각 매개변수 지정방식
  - `align`: 정렬 방식   
  : ex) LEFT, CENTER, RIGHT
  - `hgap`, `vgap` : 컴포넌트 사이의 수직, 수평 간격을 지정하는 값 -> 픽셀 단위

예제:

```java
package practice.layout;

import java.awt.*;
import javax.swing.*;
public class FlowLayoutEx extends JFrame{
    public FlowLayoutEx() {
        setTitle("FlowLayout Example");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container contentPane = getContentPane();

        contentPane.setLayout(new FlowLayout(FlowLayout.LEFT, 30, 40));

        contentPane.add(new JButton("버튼 1"));
        contentPane.add(new JButton("버튼 2"));
        contentPane.add(new JButton("버튼 3"));
        contentPane.add(new JButton("버튼 4"));
        contentPane.add(new JButton("버튼 5"));
        contentPane.add(new JButton("버튼 6"));

        setSize(300, 200);
        setVisible(true);
    }

    public static void main(String[] args) {
        new FlowLayoutEx();
    }
}
```
<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fd6waCQ%2Fbtq21dJRjhv%2FpFTGX5cixDoDCz05k8VcUk%2Fimg.png">


### BorderLayout 배치 관리자
- **컴포넌트를 추가할 때 방향을 지정하여 추가할 수 있는 기능을 제공**
- **배치 방향: 동, 서, 남, 북 중앙**
  - East(LINE_END), West(LINE_START)
  - South(PAGE_END), North(PAGE_START), center
- **배치 방법** 
  - `add(Component comp, int index)` : comp를 index의 공간에 배치
- **생성자**
  - `BorderLayout()`
  - `BorderLayout(int hGap, int vGap)`
- **add() 메서드**
  - `void add(Component comp, int index)`

```java
package practice.layout;

import java.awt.*;
import javax.swing.*;
public class BorderLayoutEx extends JFrame{
    public BorderLayoutEx() {
        setTitle("FlowLayout Example");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container contentPane = getContentPane();

        contentPane.setLayout(new BorderLayout(30, 20));

        contentPane.add(new JButton("버튼 1"), BorderLayout.CENTER);
        contentPane.add(new JButton("버튼 2"), BorderLayout.NORTH);
        contentPane.add(new JButton("버튼 3"), BorderLayout.SOUTH);
        contentPane.add(new JButton("버튼 4"), BorderLayout.EAST);
        contentPane.add(new JButton("버튼 5"), BorderLayout.WEST);

        setSize(300, 200);
        setVisible(true);
    }

    public static void main(String[] args) {
        new BorderLayoutEx();
    }
}
```
<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FuBr4p%2Fbtq2XjRqxe0%2FrC41MzRQG1kngNDWEq1Oi0%2Fimg.png">

### GridLayout 배치 관리자
- **컴포넌트를 행과 열을 가진 배열 형태로 배치**
- **컨테이너 공간을 동일한 사각형 격자(Grid)로 분할하고 각 셀에 컴포넌트 하나씩 배치**
  - 생성자에 행 수와 열 수 지정
  - 셀에 왼쪽에서 오른쪽으로, 다시 위에서 아래로 순서대로 배치
- **Constructor**
  - `GridLayout()`
  - `GridLayout(int row, int cols)`
  - `GridLayout(int rows, int cols, int hgap, int vgap)`
- 매개변수 뜻
  - `rows`, `cols` : 배치할 행과 열(Default: 1)
  - `hgap`, `vgap` : 컴포넌트 사이의 간격, 픽셀 단위 
  - 즉, rows * cols 만큼의 셀을 가진 격자로 컨테이너 공간을 분할 배치

```java
package practice.layout;

import java.awt.*;
import javax.swing.*;

public class GridLayoutEx extends JFrame {
    public GridLayoutEx() {
        setTitle("GridLayout Example");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container contentPane = getContentPane();

        contentPane.setLayout(new GridLayout(1, 10));

        for(int i = 0; i<10; i++) {
            String text = Integer.toString(i);
            JButton btn = new JButton(text);
            this.add(btn);
        }

        setSize(300, 200);
        setVisible(true);
    }

    public static void main(String[] args) {
        new GridLayoutEx();
    }
}
```
