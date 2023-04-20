package practice.event.actionPerformed.frameClass;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public abstract class MyFrame2 extends JFrame implements ActionListener {
    private JButton btn;

    public MyFrame2() {
        this.setSize(300, 200);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        btn = new JButton("버튼");
        btn.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if(e.getSource()==btn) {
                    btn.setText("클릭됨");
                }
            }
        });
        panel.add(btn);
        this.add(panel);
        this.setVisible(true);
    }

    public static void main(String[] args) {
        MyFrame f = new MyFrame();
    }

}
