package project.smallTextEditor;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileOutputStream;

public class Editor extends JFrame{
    private JPanel editorPanel;
    private JTextArea editorTextArea;
    private JScrollPane editorScroll;
    private JButton saveButton;

    public Editor() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("SmallEditor");
        setSize(350, 250);
        this.setLayout(new FlowLayout());

        // textEditor
        editorPanel = new JPanel();
        editorTextArea = new JTextArea(20, 30);
        editorScroll = new JScrollPane(editorTextArea);

        // Save Button 생성
        saveButton = new JButton("save");
        saveButton.addActionListener(new SaveAction());

        editorPanel.add(editorScroll);
        editorPanel.add(saveButton);

        this.add(editorPanel);
        this.setVisible(true);
    }

    public class SaveAction implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            if(e.getSource() == saveButton) {
                try {
                    String filePath = "C:\\Users\\SW2148\\study\\Java\\code\\GUI\\src\\project\\smallTextEditor\\test.txt";
                    FileOutputStream f = new FileOutputStream(filePath, false);
                    String lineToAppend = editorTextArea.getText();
                    byte[] byteArr = lineToAppend.getBytes();
                    f.write(byteArr);
                    f.close();
                } catch (Exception error) {
                    error.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args) {
        Editor e = new Editor();
    }
}
