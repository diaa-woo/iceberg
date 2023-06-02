# For Loop

## 문법

**for 문법**

```bash
for VARIABLE in 1 2 3 4 5 .. N
do 
    command1 ${VARIABLE}
    command2 ${VARIABLE}
    commandN ${VARIABLE}
done
```

in 뒤 조건문에는 `$(COMMAND)` 구문으로 명령어 실행 결과를 넣을 수 있음.

아래 내용은 이를 활용한 예제

### 세 번 수행하면서 변수 출력

```bash
for i in 1 2 3; 
do
    echo $i;
done
```

### 외부 명령어 결과 출력

```bash
for i in $(ls);
do
    echo $i;
done
```

## `{START...END...INCREMENT}` 구문 이용

{} 구문으로 루프의 조건을 지정해줄 수 있음. INCREMENT를 생략할 경우 1로 설정됨

### 1에서 5까지 출력

```bash
for i in {1..5}
do
    echo "Welcome $i times"
done
```