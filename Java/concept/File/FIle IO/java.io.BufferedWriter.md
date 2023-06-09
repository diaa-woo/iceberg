# BufferedWriter

```JAVA
package practice.file.BufferedWriter;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
public class WriteFile {
    public static void main(String[] args) {
        try {

            // 1. 파일 객체 생성
            File file = new File("C:\\path\\to\\out.txt");

            // 2. 파일 존재여부 체크 및 생성
            if(!file.exists()) {
                file.createNewFile();
            }

            // 3. Buffer를 사용해서 File에 write할 수 있는 BufferedWriter 생성
            FileWriter fw = new FileWriter(file);
            BufferedWriter writer = new BufferedWriter(fw);

            // 4. 파일에 쓰기
            writer.write("안녕하세요!");

            // 5. BufferedWriter close
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

`FileWriter`만으로도 파일을 쓸 수 있다. 하지만 `BufferedWriter`와 함께 사용할 경우 버퍼를 동시에 제공해 주어 더 효율적으로 사용할 수 있다.

참고로 `FileWriter` 두번째 파라미터(`append`)는 기존에 작성한 파일이 있을 경우, 이어 붙일지 쓸지를 결정한다. 기본값은 `False` 이다.