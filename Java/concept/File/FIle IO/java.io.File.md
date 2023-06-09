# `java.io.File`

## Write

```java
public boolean createNewFile() throws IOException
```

File 클래스의 `createNewFile()` 메소드를 이용하여, 새로운 파일 및 디렉터리를 생성할 수 있다.   
이 메소드는, 파일을 성공적으로 생성하면 true를 리턴하고, 기존에 이미 동일한 이름의 파일이 있는 경우 false를 리턴한다.

```JAVA
package practice.file.File;

import java.io.File;
import java.io.IOException;
public class CreateFile {
    public static void main(String[] args) {

        File file = new File("\\path\\to\\file.txt");   // 경로 지정!

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
```

## 결과 1 - 예외

```
java.io.IOException: 지정된 경로를 찾을 수 없습니다
        at java.base/java.io.WinNTFileSystem.createFileExclusively(Native Method)
        at java.base/java.io.File.createNewFile(File.java:1026)
        at CreateFile.main(CreateFile.java:10)
```

코드에서 지정한 경로가 올바르지 않을 경우 발생 - `IOException`

### 결과 2 - True 반환

```
File created
```

경로가 제대로 있을 시, 파일을 생성하고 성공했다는 메세지 출력

### 결과 3 - False 반환

```
File already exists
```

기존에 만들어진 파일이 존재할 시 파일 생성하지 않고 false 리턴