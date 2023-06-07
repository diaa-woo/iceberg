# `java.io.FileOutputStream`

## File Create

```java
public FileOutputStream(String name) throws FileNotFoundException
public FileOutputStream(String name, boolean append) throws FileNotFoundException
public FileOutputStream(File file) throws FileNotFoundException
public FileOutputStrema(File file, boolean append) throws FileNotFounException
public FileOutputStream(FileDescriptor fdObj)
```

첫 번째 파라미터는 생성할 파일의 이름 문자열, 혹은 File, FileDescriptor 객체를 전달한다.

두 번째 파라미터(`append`)는 만약 생성하려는 파일이 존재할 경우, 기존 파일을 덮어쓸지, 아님 기존 파일을 열어서 내용을 이어붙일지를 지정해준다.

append가 true일 시 파일의 내용을 이어붙이고, false일 시 파일을 덮어쓴다.

Default 값은 false이다.

```JAVA
package practice.file.FileOutputStream;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

public class CreateFile {
    public static void main(String[] args) {

        File file = new File("path/to/file.txt");

        try {
            FileOutputStream fileOutputStream = new FileOutputStream(file, false);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

}
```

### 결과 1 - 예외

```
java.io.FileNotFoundException: [path] (지정된 경로를 찾을 수 없습니다)
        at java.base/java.io.FileOutputStream.open0(Native Method)
        at java.base/java.io.FileOutputStream.open(FileOutputStream.java:298)
        at java.base/java.io.FileOutputStream.<init>(FileOutputStream.java:237)
        at CreateFile.main(CreateFile.java:11)
```

경로가 정상적이지 않을 때!

# 결과 2

apppend 값으로 파일 이어붙이기 + 덮어쓰기 한 것을 확인할 수 있음

## file write

`FileOutputStream` 클래스는 바이너리 데이터를 파일에 쓰는데 유용하다. 다만 `int`, `float`와 같은 기본 데이터 유형 뿐만 아니라 문자 지향 데이터 작성에도 사용할 수 있다.

문자열을 쓰기 전 먼저 바이트 배열로 변환해야 한다. 이를 위해 `getBytes()` 메소드를 사용할 수 있다.

append 매개변수를 true로 잡아줘야 하는데, 이는 생성된 파일에 내용을 추가로 작성해주어야 하기 때문이다. 물론 append를 false로 쓰면 덮어쓰기가 된다.

```JAVA
package practice.file.FileOutputStream;

import java.io.FileOutputStream;

public class Write {
    public static void main(String[] args) {
        try {
            String filePath = "C:\\path\\to\\file.txt";
            FileOutputStream f = new FileOutputStream(filePath, true);
            String lineToAppend = "\r\nHello World!";
            byte[] byteArr = lineToAppend.getBytes();   // converting bytes
            f.write(byteArr);
            f.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
```