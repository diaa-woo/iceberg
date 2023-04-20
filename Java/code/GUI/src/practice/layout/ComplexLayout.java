package practice.layout;

import javax.swing.*;

public class ComplexLayout extends JFrame{

    public ComplexLayout() {
        JPanel pane = new JPanel();
        JButton[] b = new JButton[4];
        for(int i=0; i<b.length; i++) {
            b[i] = new JButton("button"+i);
        }
        pane.add(b[0]);
        pane.add(b[1]);
        this.add(pane, "North");
        this.add(b[2], "West");
        this.add(b[3], "Center");

        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Practice Frame");
        setVisible(true);
    }
}

