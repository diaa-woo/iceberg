# 액션 이벤트 actionPerformed()

- **이벤트를 발생시키는 Component(버튼)가 있어야한다.**
- 이벤트 발생 감지 방법: **Listener 인터페이스**를 달아준다.
  - 클래스에서 Implements시켜 method 구현

```Java
MyClass implements ActionListener {
    public void actionPerformed(ActionEvent e) {
        // 꼭 구현해야 하는 메소드
        // Action 이벤트를 처리하는 코드가 여기에 들어옴.
    }
}
```

  - new로 생성하여 Component마다 리스너를 붙이는 방법

```Java
button1.addActionListener(new ActionListener({메소드 구현...}));
```

## Event Listener 위치

- 별도의 클래스로 Event Listener를 작성
  - 별도의 클래스를 두어 이벤트 동작만을 위한 처리를 작성하게 해줌
  - 별도의 클래스이기 때문에 클래스간 변수를 사용하도록 처리해주어야 한다.

```Java
MyClass implements ActionListener {
    public void actionPerformed(ActionEvent e) {
        // 꼭 구현해야 하는 메소드
        // Action 이벤트를 처리하는 코드가 여기에 들어옴.
    }
}
```

```Java
public class MyFrame extends JFrame {

    public MyFrame() {
        JPanel panel = new JPanel();
        btn = new JButton("버튼");
        btn.addACtionListener(new MyListener());
        panel.add(btn);
        this.add(panel);
        this.setVisible(true);
    }
}

```
- 내부 클래스로 Event Listener 작성
  - 위와 같이 별도로 클래스를 만들면 MyFrame안의 멤버 변수를 쉽게 사용할 수 없는데, 이를 위해 내부 클래스를 만들어 사용할 수 있다.

```Java
package practice.event.actionPerformed.internalClass;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyFrame extends JFrame {
    private JButton btn;

    public MyFrame()
    {
        this.setSize(300, 200);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("내부 클래스 이용하기");

        JPanel panel = new JPanel();
        btn = new JButton("버튼");
        btn.addActionListener(new MyListener());
        panel.add(btn);
        this.add(panel);
        this.setVisible(true);
    }
    private class MyListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            if(e.getSource() == btn) {
                btn.setText("클릭됨");
            }
        }
    }

    public static void main(String[] args) {
        MyFrame f = new MyFrame();
    }
}
```

- 프레임 클래스가 Event Listener를 구현하도록 작성
  - `public class Simple extends JFrame implements ActionListener {...}`의 형태로 actionPerformed를 구현할 수 있다.
  - 각 컴포넌트들의 공통된 동작을 하는 것이 아니라 다양한 동작을 할 때는, 각 컴포넌트에서 Event Listener를 구현하도록 한다.

