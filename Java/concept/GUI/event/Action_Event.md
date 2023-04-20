# Action Event

- 사용자가 버튼 클릭하는 경우
- 사용자가 메뉴 항목을 선택하는 경우
- 사용자가 텍스트 필드에서 엔터키를 누르는 경우

```JAVA
package practice.event.action;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyFrame extends JFrame {
    private JButton btnYellow, btnPink;
    private JPanel panel;

    public MyFrame() {
        this.setSize(300, 200);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        panel = new JPanel();
        btnYellow = new JButton("Yellow");
        btnYellow.addActionListener(new MyListener());
        panel.add(btnYellow);
        btnPink = new JButton("Pink");
        btnPink.addActionListener(new MyListener());
        panel.add(btnPink);

        this.add(panel);
        this.setVisible(true);
    }

    private class MyListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            if(e.getSource() == btnYellow) {
                panel.setBackground(Color.YELLOW);
            } else if(e.getSource()==btnPink) {
                panel.setBackground(Color.PINK);
            }
        }
    }

    public static void main(String[] args) {
        MyFrame f = new MyFrame();
    }
}

```

- `getSource()` 메소드를 이용해 이벤트를 발생시킨 객체를 식별한다.
- `getId()` 메소드를 이용해 이벤트의 타입을 식별한다.
- `getActionCommand()` 메소드를 이용해 이벤트를 발생시킨 컴포넌트의 이름을 식별한다.