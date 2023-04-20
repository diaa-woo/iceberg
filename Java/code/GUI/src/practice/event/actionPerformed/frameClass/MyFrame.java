package practice.event.actionPerformed.frameClass;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyFrame extends JFrame implements ActionListener {
    private JButton btn;

    public MyFrame() {
        this.setSize(300, 200);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        btn = new JButton("버튼");
        btn.addActionListener(this);
        panel.add(btn);
        this.add(btn);
        this.setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == btn) {
            btn.setText("클릭됨");
        }
        // 버튼 및 컴포넌트가 여러개라면 if then else가 길어지는 형태
    }

    public static void main(String[] args) {
        MyFrame f = new MyFrame();
    }
}
