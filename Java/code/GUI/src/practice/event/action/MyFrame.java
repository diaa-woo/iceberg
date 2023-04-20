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
