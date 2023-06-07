# scanner

Scanner 클래스를 이용하면, 파일의 텍스트를 delimiter를 이용하여 잘러서 읽을 수 있다. (기본 delimiter는 줄바꿈을 포함한 공백('\t', '\f', '\r', '', '\n'))

```java
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
```

- `scanner.next()` : `Scanner`의 `next()` 메소드를 사용하여, 기본 delimiter의 공백으로 구분된 문자열 단위로 텍스트 파일을 읽어들임.
- `scanner.nextLine()` : `Scanner`의 `nextLine()` 메소드를 사용하면, 라인 단위로 텍스트 파일을 읽을 수 있다.

