package practice.file.Files;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class CreateFile {
    public static void main(String[] args) {

        Path filePath = Paths.get("C:\\Users\\SW2148\\study\\Java\\code\\GUI\\src\\practice\\file\\Files\\file.txt");

        try {
            Path newFilePath = Files.createFile(filePath);
            System.out.println(newFilePath);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
