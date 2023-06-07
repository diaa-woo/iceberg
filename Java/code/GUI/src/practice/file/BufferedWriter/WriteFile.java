package practice.file.BufferedWriter;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
public class WriteFile {
    public static void main(String[] args) {
        try {

            // 1. 파일 객체 생성
            File file = new File("C:\\Users\\SW2148\\study\\Java\\code\\GUI\\src\\practice\\file\\BufferedWriter\\out.txt");

            // 2. 파일 존재여부 체크 및 생성
            if(!file.exists()) {
                file.createNewFile();
            }

            // 3. Buffer를 사용해서 File에 write할 수 있는 BufferedWriter 생성
            FileWriter fw = new FileWriter(file);
            BufferedWriter writer = new BufferedWriter(fw);

            // 4. 파일에 쓰기
            writer.write("안녕하세요!");

            // 5. BufferedWriter close
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
