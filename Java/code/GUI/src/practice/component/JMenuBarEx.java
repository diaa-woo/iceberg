package practice.component;

import javax.swing.*;
import java.awt.event.*;

public class JMenuBarEx extends JFrame implements ActionListener, ItemListener {

    //FIELDS
    private JMenuBar menuBar = new JMenuBar();
    private JMenu firstMenu, secondMenu, subMenu;
    private JMenuItem menuItem1, menuItem2;
    private JMenuItem subMenuItem1, subMenuItem2;
    private ButtonGroup group = new ButtonGroup();
    private JRadioButtonMenuItem rbMenuItem1, rbMenuItem2;
    private JCheckBoxMenuItem cbMenuItem1, cbMenuItem2;

    JMenuBarEx() {

        // Initialize First Menu
        firstMenu = new JMenu("First Menu");
        firstMenu.setMnemonic(KeyEvent.VK_F);   // 단축기 설정
        menuBar.add(firstMenu);

        // Create Menu Field
        menuItem1 = new JMenuItem("menu item 1", KeyEvent.VK_1);
        menuItem1.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_M, ActionEvent.ALT_MASK));
        menuItem1.addActionListener(this);  // 리스너를 설정해야 이벤트 처리 가능
        firstMenu.add(menuItem1);

        ImageIcon icon = new ImageIcon("icon.png");
        menuItem2 = new JMenuItem("Menu Item 2", icon);     // 이미지 등록
        menuItem2.addActionListener(this);
        firstMenu.add(menuItem2);

        // 라디오 버튼 메뉴 항목 생성
        firstMenu.addSeparator();   // 구분자 생성

        rbMenuItem1 = new JRadioButtonMenuItem("Radio Button Item 1");
        rbMenuItem1.setSelected(true);      // 선택되어 있도록 설정
        group.add(rbMenuItem1);             // 버튼 그룹에 추가
        firstMenu.add(rbMenuItem1);         // 그룹에 추가하는 것과 메뉴에 추가하는 것은 별도!

        rbMenuItem2 = new JRadioButtonMenuItem("Radio Button Item 2");
        group.add(rbMenuItem2);
        firstMenu.add(rbMenuItem2);
        
        // 체크 박스 메뉴 항목 생성
        firstMenu.addSeparator();
        cbMenuItem1 = new JCheckBoxMenuItem("Check Box item 1");
        cbMenuItem1.addItemListener(this);  // 체크박스는 아이템 이벤트가 발생함(액션 이벤트와는 별도 처리)
        firstMenu.add(cbMenuItem1);

        cbMenuItem2 = new JCheckBoxMenuItem("Check Box item 2");
        cbMenuItem2.addItemListener(this);
        firstMenu.add(cbMenuItem2);

        // Create SubMenu
        subMenu = new JMenu("Sub Menu");
        subMenu.setMnemonic(KeyEvent.VK_S);     // 단축기 설정

        subMenu.addSeparator();

        subMenuItem1 = new JMenuItem("Sub Menu item 1");
        subMenuItem1.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_1, ActionEvent.ALT_MASK));
        subMenu.add(subMenuItem1);

        subMenuItem2 = new JMenuItem("Sub Menu item 2");
        subMenuItem2.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_2, ActionEvent.ALT_MASK));
        subMenu.add(subMenuItem2);

        menuBar.add(subMenu);

        // Initialize Second Menu
        secondMenu = new JMenu("Second Menu");
        secondMenu.addActionListener(this);
        secondMenu.setMnemonic(KeyEvent.VK_S);
        menuBar.add(secondMenu);


        // 프레임에 메뉴바 추가하기
        setJMenuBar(menuBar);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == menuItem1) {
            System.out.println("This is the menu Item 1.");
        }
        else if(e.getSource() == menuItem2) {
            System.out.println("This is the menu Item 2.");
        }
    }

    @Override
    public void itemStateChanged(ItemEvent e) {
        if(e.getSource() == cbMenuItem1) {
            System.out.println("Check Box item 1");
        }
        else if (e.getSource() == cbMenuItem2) {
            System.out.println("Check Box item 2");
        }
    }

    public static void main(String[] args) {
        JMenuBarEx frame = new JMenuBarEx();
        frame.setSize(500, 500);
        frame.setVisible(true);
    }

}
