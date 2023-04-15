package practice.component;

import java.awt.Container;
import java.awt.FlowLayout;

import javax.swing.JFrame;
import javax.swing.JLabel;
public class JLabelEx extends JFrame{

    public JLabelEx() {
        setTitle("JLabel 예시");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container contentPane = getContentPane();
        contentPane.setLayout(new FlowLayout());

        contentPane.add(new JLabel("Hello World!"));

        setSize(300, 200);
        setVisible(true);
    }

    public static void main(String[] args) {
        new JLabelEx();
    }
}
