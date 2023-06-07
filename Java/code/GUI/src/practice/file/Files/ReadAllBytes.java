package practice.file.Files;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class ReadAllBytes {
    public static void main(String[] args) throws IOException {
        byte[] bytes = Files.readAllBytes(Paths.get("path\\to\\in.txt"));

        System.out.println(new String(bytes));
    }
}
