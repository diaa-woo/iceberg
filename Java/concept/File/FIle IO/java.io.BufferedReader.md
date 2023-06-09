# BufferedReader

`BufferedReader`를 사용하면, buffer를 사용하기 때문에 `FileReader`보다 좀 더 효율적으로 파일을 읽어올 수 있다.

```java
public BufferedRead(Reader in)
public BufferedReader(Reader in, int sz)
```

첫 번째 파라미터는 `Reader` 객체를 전달한다. 앞에서 살펴보았던, `FileReader`를 전달할 수도 있고, `InputStreamReader` 등의 다른 Reader 객체를 전달할 수도 있다.

두 번째 파라미터는 buffer 사이즈를 지정하낟. 파라미터로 입력되는 단위는 `byte`이고, `BufferedReader`의 기본 buffer 사이즈는 8KB이다.

## BufferedReader 객체 생성

```java
BufferedReader bufferedReader = new BufferedReader(
    new FileReader("path\\to\\file.txt"),
    16 * 1024
);
```

## code

```java
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
```

`while ((str = reader.readLine()) != null)`   
`BufferedReader`의 `readLine()` 메소드는, 텍스트 파일을 한 줄씩 읽어서 리턴한다. 더 이상 읽을 내용이 없으면, null을 리턴한다.

## 인코딩 지정해서 읽기

### FileReader

Java 11 이후

```java
BufferedReader reader = new BufferedReader(
    new FileReader("d:\\file.txt", Charset.forName("UTF-8"))
);
```

### InputStreamReader

Java 11 이전

```java
BufferedReader reader = new BufferedReader(
    new InputStreamReader(new FileInputStream("d:\\file.txt"), "UTF-8")
);
```

