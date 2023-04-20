# Component

실제로 Container 위에 올려져서 화면 구성을 담당하는 요소들이다.

- ex AWT) Button, TextField, TextArea, List
- ex Swing) JButton, JTextField, JChoice, JList, JMenu, JCheckbox, JScrollBar, JTextArea, JCanvas

## Component 생성하기

```Java
import javax.swing.*;

class FrameTest extends JFrame {

    public FrameTest() {
        JButton button = new JButton("버튼");
        
        // Container 위에 Component 추가
        this.add(button);

        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Practice Frame");
        setVisible(true);
    }
}
```

### 모양을 설정하는 메소드

| 메소드 | 설명 |
| ----- | ---- | 
| `void setBorder(Border)`, `Border getBorder()` | 컴포넌트의 테두리를 설정하거나 가져옴. |
| `void setBackground(Color)`, `Color getBackGround()` | 컴포넌트의 배경색을 설정하거나 가져옴. |
| `void setForeground(Color)`, `Color getForeground()` | 컴포넌트의 전경색을 설정하거나 가져옴. |
| `void setOpaque(boolean)`, `Boolean isOpaque()` | 컴포넌트의 불투명을 설정하거나 불투명상태를 확인한다. |
| `void setFont(Font)`, `Font getFont()` | 컴포넌트의 글꼴을 설정하거나 가져온다. |
| `void setCursor(Cursor)`, `Cursor getCursor()` | 컴포넌트에 마우스 커서를 가져갔을 때 보이는 커서 모양을 설정하거나 가져온다. |
 