package practice.event.actionPerformed.implement;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyListener implements ActionListener {
    public void actionPerformed(ActionEvent e) {
        System.out.println("Clicked!");
    }
}
