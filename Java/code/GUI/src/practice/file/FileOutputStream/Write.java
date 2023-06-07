package practice.file.FileOutputStream;

import java.io.FileOutputStream;

public class Write {
    public static void main(String[] args) {
        try {
            String filePath = "C:\\Users\\SW2148\\study\\Java\\code\\GUI\\src\\practice\\file\\FileOutputStream\\file.txt";
            FileOutputStream f = new FileOutputStream(filePath, true);
            String lineToAppend = "\r\nHello World!";
            byte[] byteArr = lineToAppend.getBytes();   // converting bytes
            f.write(byteArr);
            f.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
