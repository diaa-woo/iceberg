package practice.file.PrintWriter;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

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
            FileWriter fw = new FileWriter(file);
            PrintWriter writer = new PrintWriter(fw);

            // 4. 파일에 쓰기
            writer.write("안녕하세요!\n");
            writer.println("Nice to meet you!");
            writer.print("!!");

            // 5. PrinterWriter close
            writer.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
