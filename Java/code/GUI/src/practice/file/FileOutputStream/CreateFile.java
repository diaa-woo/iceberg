package practice.file.FileOutputStream;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

public class CreateFile {
    public static void main(String[] args) {

        File file = new File("path\\to\\file.txt");

        try {
            FileOutputStream fileOutputStream = new FileOutputStream(file, false);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

}
