package practice.component;

import java.awt.Container;
import java.awt.FlowLayout;

import javax.swing.*;

public class JButtonEx extends JFrame {
    public JButtonEx() {
        setTitle("JButton Example");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container contentPane = getContentPane();
        contentPane.setLayout(new FlowLayout());

        JButton button1 = new JButton("버튼1!");

        contentPane.add(button1);
        contentPane.add(new JButton("버튼2!"));   // 일반 푸시 버튼
        contentPane.add(new JCheckBox("와우"));   // 일반 체크박스 버튼
        contentPane.add(new JRadioButton("1"));
        contentPane.add(new JRadioButton("2"));

        setSize(300, 200);
        setVisible(true);
    }

    public static void main(String[] args) {
        new JButtonEx();
    }
}
