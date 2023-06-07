package practice.file.BufferedReader;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ReadFile {
    public static void main(String[] args) throws IOException {

        BufferedReader reader = new BufferedReader(
                new FileReader("path\\to\\in.txt")
        );

        String str;
        while ((str = reader.readLine()) != null) {
            System.out.println(str);
        }

        reader.close();
    }
}
