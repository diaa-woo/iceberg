# 파일 입출력

## 파일 생성

```py
f=open("new.txt", "w")
f.close()
```

### syntax

```
파일 객체 = open(파일_이름, 파일_열기_모드)
```

파일 읽기 모드의 종류
- r : 읽기 모드;  파일을 읽기만 할 때 사용
- w : 쓰기 모드;  파일에 내용을 쓸 때 사용
- a : 추가 모드;  파일의 마지막에 새로운 내용을 추가할 때 사용    

만일 특정 경로에 파일을 저장하고 싶다면 `파일_이름`에 경로를 입력하면 됨.

### `f.close()`

파일을 열었을 때 꼭 실행해줄 것. 물론 프로그램을 종료할 때 파이썬 프로그램이 열려 있는 파일의 객체를 자동으로 닫아주지만, 간혹 비정상 종료로 인해 쓰기 모드로 열었던 파일이 그대로 유지될 경우 다시 접근할 경우에 오류가 발생함

## 쓰기 모드로 열어 내용 쓰기

```py
f = open("new.txt", 'w')
for i in range(1, 11):
    data = "%d번째 줄입니다. \n" % i
    f.write(data)
f.close()
```

data에 String 데이터를 넣어준 후, `write()`함수를 이용하여 데이터를 직접적으로 넣는 형태이다. 해당 프로그램을 실행시켰을 경우 다음과 같은 결과값을 출력한다.

```txt
1번째 줄입니다. 
2번째 줄입니다. 
3번째 줄입니다. 
4번째 줄입니다. 
5번째 줄입니다. 
6번째 줄입니다. 
7번째 줄입니다. 
8번째 줄입니다. 
9번째 줄입니다. 
10번째 줄입니다. 
```

## 파일 읽기

### `readline`

```py
f = open("new.txt", 'r')
line = f.readline()
print(line)
f.close()
```

파일을 읽기 모드로 연 후 `readline()`을 사용해 파일의 첫 번째 줄을 읽어 출력하는 예제이다.

모든 파일 내용을 확인하고 싶다면?

```py
f = open('new.txt', 'r')
while True:
    line = f.readline()
    if not line : break
    print(line)
f.close()
```

### `readlines`

```py
f = open('new.txt', 'r')
lines = f.readlines()
for line in lines:
    print(line)
f.close()
```

readlines로 파일을 읽어오면 파일의 모든 줄을 읽어서 각각의 줄을 요소로 가지는 리스트를 리턴한다. 만약 줄 바꿈 문자(`\n`)가 같이 따라온다면 문자열 변수 뒤에 `.strip()`를 추가해주자.

### `read()`

```py
f = open('new.txt', 'r')
data = f.read()
print(data)
f.close()
```

파일 내용 전체를 문자열로 리턴한다.


### `for`문 이용

```py
f = open('new.txt')
for line in f:
    print(line)
f.close()
```

파일 객체는 기본적으로 위와 같이 for문과 함께 사용해 파일을 줄 단위로 읽을 수 있다.


## 새로운 애용 추가

쓰기 모드로 파일을 열 때 이미 존재하는 파일을 열면 그 파일의 내용이 모두 사라지게 된다. 하지만 원래 있던 값을 유지하며 단지 새로운 값을 추가할 경우가 반드시 존재한다. 이런 경우 추가 모드(`a`)로 열면 된다.

```py
f = open('new.txt', 'r')
for i in range(11, 20):
    data = "%번째 줄입니다.\n" % i
    f.write(data)
f.close()
```

## with문과 함께 사용

대표적인 **Context_manager**인 with문과 함께 사용할 수 있다.

```py
with open('new.txt', 'w') as f:
    f.write("Hello World!")
```

`with 블록` 내에서만 파일 객체 `f`를 사용할 수 있고, 블록을 벗어날 시 자동으로 객체가 닫힌다. 자세한 내용은 다음 내용을 참조. [Context Manager란?](../Context_Manager/Context%20Manager.md)

## 출처
https://wikidocs.net/26