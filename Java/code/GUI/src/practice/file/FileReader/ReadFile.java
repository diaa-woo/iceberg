package practice.file.FileReader;

import java.io.FileReader;
import java.io.IOException;

public class ReadFile {
    public static void main(String[] args) throws IOException {
        FileReader reader = new FileReader("path\\to\\in.txt");

        int ch;
        while ((ch = reader.read()) != -1) {
            System.out.print((char) ch);
        }
    }
}
