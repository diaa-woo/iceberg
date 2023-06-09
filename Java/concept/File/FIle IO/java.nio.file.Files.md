# `java.nio.file.Files`

## write

```java
public static Path createFile(Path path, FileAttribute<?>... attrs) throws IOException
```

Java 7 이후부터는 `Files.createFile()` 메소드를 이용해서 파일을 생성할 수 있다.   
두 번째 파라미터인 `FileAttribute` 객체는 Optional로, 필수가 아니다


```Java
package practice.file.Files;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class CreateFile {
    public static void main(String[] args) {

        Path filePath = Paths.get("path\\to\\file.txt");

        try {
            Path newFilePath = Files.createFile(filePath);
            System.out.println(newFilePath);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

```

### 결과 1 

디렉토리 존재하지 않을 시

`NoSuchFileException`

### 결과 2

파일 생성 성공 시

경로 출력

### 결과 3

생성하려는 파일이 이미 있을 경우,

`FileAlreadyExistException`

## Files 내용 입력

```JAVA
package practice.file.Files;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class WriteFile {
    public static void main(String[] args) {
        try {

            // 1. Path 객체 생성
            Path path = Paths.get("path\\to\\out.txt");

            // 2. 파일에 쓰기
            Files.write(path, "안녕하세요".getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

Files의 static 메소드인 `Files.write()`는 파라미터로 받은 `byte[]`를 파일에 써 준다.

## File 읽기

`java.nio.file.Files` 클래스는 Java 7 이후부터 사용할 수 있다.   
Files 클래스는 모두 static 메소드로 구성되어 있으며, 클래스 사용시 텍스트 파일 내용 전체를 List나 배열, String에 쉽게 담을 수 있다.

```Java
public static List<String> readAllLines(Path path) throws IOException
public static List<String> readAllLines(Path path, Charset cs) throws IOException
public static byte[] readAllBytes(Path path, Charset cs) throws IOException
public static String readString(Path path) throws IOException   // Java 11 이후
public static String readString(Path path, Charset cs) throws IOException   // Java 11 이후
```

### readAllLines

```Java
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
```

개행줄 단위로 String을 읽어와서 리스트에 저장시킨다.

### readAllBytes

```java
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
```

### readString

```java
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
```