# FileReader

```
hello
how are you
nice to meet you
```
txt 파일 준비

```JAVA
FileReader(File file)
FileReader(File file, Charset charset)  // Java 11 이후
FileReader(FileDescriptor fd)
FileReader(String fileName)
FileReader(String fileName, Charset charset)  // Java 11 이후
```

FileReader는 character 파일을 읽을 수 있는 기능을 제공한다.   
인코딩을 지정할 수 있지만 그건 Java 11 이후에서만 제공된다. 이전 버전에서 인코딩 지정은 다른 방법을 사용해야 한다.

이 클래스는 `java.io.InputStreamReader` 클래스를 상속받기 때문에, `InputStreamReader` 클래스의 read() 메소드를 사용하여 char를 한 글자씩 읽어올 수 있다.

```java
public int read() throws IOException
```

`read()` 메소드는, 텍스트 파일에서 한 글자씩 글자를 읽어, 하나의 char를 리턴한다. 더 이상 읽을 글자가 없으면, -1을 리턴한다.

## code

```Java
package practice.file.FileReader;

import java.io.FileReader;
import java.io.IOException;

public class ReadFile {
    public static void main(String[] args) throws IOException {
        FileReader reader = new FileReader("path\\to\\in.txt");

        int ch;
        while((ch = reader.read()) != -1) {
            System.out.print((char) ch);
    }
}

```

`read()` 메소드는, stream의 끝에서 -1을 리턴함