package practice.file.Files;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class ReadAllLines {
    public static void main(String[] args) throws IOException {
        List<String> lines = Files.readAllLines(Paths.get("path\\to\\in.txt"));

        System.out.println(lines);
    }
}
