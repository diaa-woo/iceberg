package practice.component;

import javax.swing.*;
import java.awt.*;

public class JTextFieldEx extends JFrame {
    public JTextFieldEx() {
        setTitle("TextField Example");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container contentPane = getContentPane();
        contentPane.setLayout(new FlowLayout());

        contentPane.add(new JTextField());
        contentPane.add(new JFormattedTextField());
        contentPane.add(new JPasswordField());
        contentPane.add(new JComboBox<String>());
        contentPane.add(new JSpinner());

        setSize(500, 400);
        setVisible(true);
    }

    public static void main(String[] args) {
        new JTextFieldEx();
    }
}
