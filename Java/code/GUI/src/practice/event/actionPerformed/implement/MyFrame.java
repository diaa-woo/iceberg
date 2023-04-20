package practice.event.actionPerformed.implement;

import javax.swing.*;

public class MyFrame extends JFrame{

    public MyFrame() {
        JPanel panel = new JPanel();
        JButton btn = new JButton("버튼");
        btn.addActionListener(new MyListener());
        panel.add(btn);
        this.add(panel);
        setSize(300, 200);
        this.setVisible(true);
    }

    public static void main(String[] args) {
        MyFrame m = new MyFrame();
    }
}
