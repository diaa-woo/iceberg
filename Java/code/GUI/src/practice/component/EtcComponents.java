package practice.component;

import javax.swing.*;
import java.awt.*;

public class EtcComponents extends JFrame{

    public EtcComponents() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Practice Component");
        this.setLayout(new FlowLayout());

        ImageIcon img1 = new ImageIcon("../../assets/image1.png");
        ImageIcon img2 = new ImageIcon("../../assets/image2.png");

        // 버튼에 이미지와 문자가 모두 나타나도록 설정
        JButton btn1 = new JButton("버튼1", img1);
        this.add(btn1);

        // Label을 이미지 또는 문자로 생성
        JLabel lbl1 = new JLabel("Label 입니다.");
        JLabel lbl2 = new JLabel(img2);
        this.add(lbl1);
        this.add(lbl2);

        // 체크박스 3개 생성 + true가 된 곳은 체크가 되도록 설정!
        JCheckBox chk1 = new JCheckBox("C++");
        JCheckBox chk2 = new JCheckBox("Ruby");
        JCheckBox chk3 = new JCheckBox("Java", true);
        this.add(chk1);
        this.add(chk2);
        this.add(chk3);

        // 단일 선택 체크박스 - awt
        CheckboxGroup group = new CheckboxGroup();
        Checkbox man = new Checkbox("남자", true, group);
        Checkbox woman = new Checkbox("여자", true, group);
        this.add(man);
        this.add(woman);

        JRadioButton rdo1 = new JRadioButton("고래");
        JRadioButton rdo2 = new JRadioButton("상어");
        JRadioButton rdo3 = new JRadioButton("새우");
        this.add(rdo1);
        this.add(rdo2);
        this.add(rdo3);

        setSize(400, 400);
        setVisible(true);
    }

    public static void main(String[] args) {
        EtcComponents e = new EtcComponents();
    }
}
