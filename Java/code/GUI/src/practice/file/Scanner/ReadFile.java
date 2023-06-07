package practice.file.Scanner;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class ReadFile {
    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(new File("path\\to\\in.txt"));

        while(scanner.hasNext()) {
            String str = scanner.next();
            System.out.println(str);
        }
    }
}
