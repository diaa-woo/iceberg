package practice.file.File;

import java.io.File;
import java.io.IOException;
public class CreateFile {
    public static void main(String[] args) {

        File file = new File("C:\\Users\\SW2148\\study\\Java\\code\\GUI\\src\\practice\\file\\File\\file.txt");

        try {
            if(file.createNewFile()) {
                System.out.println("File Created");
            } else {
                System.out.println("File already exists");
            }
        } catch(IOException e) {
            e.printStackTrace();
        }

    }
}
