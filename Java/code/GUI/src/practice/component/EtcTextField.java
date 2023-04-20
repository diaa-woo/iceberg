package practice.component;

import javax.swing.*;
import java.awt.*;

public class EtcTextField  extends JFrame {

    public EtcTextField() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Practice Component");
        this.setLayout(new FlowLayout());

        // 한 줄을 입력하기 위한 텍스트 필드, 10은 초기열 크기
        JTextField txt1 = new JTextField(10);
        this.add(txt1);

        // 여러줄을 입력하기 위한 텍스트 영역(행, 열)
        JTextArea txt2 = new JTextArea(5 ,10);
        this.add(txt2);
        // textArea 영역에 스크롤바 추가
        this.add(new JScrollPane(txt2));

        JPasswordField txt3 = new JPasswordField(10);
        this.add(txt3);

        setSize(200, 200);
        setVisible(true);
    }

    public static void main(String[] args) {
        EtcTextField t = new EtcTextField();
    }

}
