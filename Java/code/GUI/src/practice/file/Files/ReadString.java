package practice.file.Files;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class ReadString {
    public static void main(String[] args) throws IOException {
        String str = Files.readString(Paths.get("path\\to\\in.txt"));

        System.out.println(str);
    }
}
