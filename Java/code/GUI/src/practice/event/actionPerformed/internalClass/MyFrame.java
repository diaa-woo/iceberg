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
