# Container

자바에서 Container는 창의 역할을 한다.

- 한 개 이상의 Container 위에 **Component들이 올려질 영역**
- Container는 실제로는 Component보다 작은 개념
- ex AWT) Frame, Window, Panel, Dialog, Applet
- ex Swing) JFrame, JDialog ,JApplet, JPanel, JScrollPane
  
## Frame 생성하기

1. `JFrame` 객체 생성

```java
import javax.swing.*;

public class FrameTest1 {
    public static void main(String[] args) {
        JFrame f = new JFrame("Frame Test");
        f.setSize(300, 200);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }
}
```

2. `JFrame` 상속

```java
import javax.swing.*;

public class FrameTest extends JFrame {

    public FrameTest() {
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Practice Frame");
        setVisible(true);
    }

    public static void main(String[] args) {
        FrameTest f = new FrameTest();
    }
}
```

## 메소드 or 생성자

| 생성자 또는 메소드 | 설명 |
| ----------------- | ----|
| `void add(Component c)` | 지정된 컴포넌트를 프레임에 추가 |
| `JMenuBar getJMenuBar()` | 이 프레임에 대한 메뉴를 얻음 |
| `void pack()` | 프레임의 크기를 추가된 컴포넌트들의 크기에 맞도록 조절한다. |
| `void setDefaultCloseOperaion()` | 사용자가 프레임을 닫을 때 수행되는 동작을 설정한다. 일반적으로 `JFrame.EXIT_ON_CLOSE`로 지정 |
| `void setIconImage(Icon Image)` | 프레임이 최소화되었을 때의 아이콘 지정 |
| `void setLayout(LayoutManager layout)` | 프레임에 놓이는 컴포넌트들을 배치 관리자 지정, 디폴트는 `BorderLayout`이다. |
| `void setLocation(int x, int y)` | 프레임의 (x, y)좌표 지정 |
| `void setResizeable(boolean value)` | 프레임의 크기 변경 허용 여부 |
| `void setSize(int width, int height)` | 프레임의 크기 설정 |
| `void setMenuBar(JMenuBar menu)` | 현재 프레임에 메뉴바를 붙인다. |

## Panel

Component들이 가질 수 있는 컨테이너이다. (컴포넌트들을 붙일 수 있는 판)

### 메소드 & 생성자

| 생성자 or 메소드 | 설명 |
| --------------- | --- |
| `JPanel()` | 새로운 Panel 생성 |
| `JPanel(boolean isDoubleBuffered)` | 만약 매개변수가 참이면 더블 버퍼링 사용 |
| `JPanel(LayoutManager layout)` | 지정된 배치 관리자를 사용하는 Panel 생성 |
| `void add(Component c)` | 지정된 컴포넌트 Panel에 추가 |
| `void remove(Component c)` | 지정된 컴포넌트 Panel에 제거 |
| `void setLayout(LayoutManager layout)` | 배치 관리자를 지정한다. 디폴트는 `FlowLayout` |
| `void setSize(int width, int height)` | Panel의 크기 지정 |
| `void setLocation(int x, int y)` | Panel의 위치 지정 |
| `vodi setToolTipText(String text)` | 사용자가 마우스를 Panel의 빈 곳에 올려놓으면 팁을 표시 |

