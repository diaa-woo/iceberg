package practice;

import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
public class ContentPaneEx extends JFrame {
    public ContentPaneEx() {
        setTitle("ContentPane과 JFrame 예제");  // 프레임 타이틀
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container contentPane = getContentPane();    // ContentPane 정보 가져오기
        contentPane.setBackground(Color.orange);     // 배경색 : orange
        contentPane.setLayout(new FlowLayout());     // ContentPane에 FlowLayout 배치관리자 달기
        
        contentPane.add(new JButton("OK"));     // OK버튼
        contentPane.add(new JButton("Cancel")); // Cancel 버튼
        contentPane.add(new JButton("Ignore")); // Ignore 버튼
        
        setSize(300, 150);              // 프레임 크기 300 x 150
        setVisible(true);                            // 화면에 프레임 출력
    }

    public static void main(String[] args) {
        new ContentPaneEx();
    }
}
