package practice.file.DataOutputStream;

import java.io.*;

public class WriteFile {
    public static void main(String[] args) {
        try {

            // 1. 파일 객체 생성
            File file = new File("path\\to\\out.txt");

            // 2. 파일 존재여부 체크 및 생성
            if (!file.exists()) {
                file.createNewFile();
            }

            // 3. Writer 생성
            FileOutputStream fos = new FileOutputStream(file);
            BufferedOutputStream bos = new BufferedOutputStream(fos);
            DataOutputStream dos = new DataOutputStream(bos);

            // 4. 파일에 쓰기
            dos.writeUTF("안녕하세요");

            // 5. DataOutputStream Close
            dos.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
