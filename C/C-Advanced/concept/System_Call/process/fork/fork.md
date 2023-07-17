# fork
   
> 프로세스를 생성하고자 할 때 사용하는 함수

이 fork함수로 호출된 프로세스는 **부모 프로세스**가 되고 후에 생성되는 프로세스는 **자식 프로세스**가 된다. 이 때 생성된 자식 프로세스는 <u>부모 프로세스의 메모리를 그대로 복사하여 가진다.</u>   
    
이 함수 호출 이후 코드부터는 각자의 메모리를 사용하여 실행된다.

```C
// unistd.h header file

pid_t fork(void);  // 성공시: 부모 프로세스에서는 자식 프로세스의 PID값을 반환 받음.
// 자식 프로세스는 0 반환 받음
// 실패시: 음수 값(-1) 반환
```

예제1: fork1.c

```C
#include <stdio.h>
#include <unistd.h>
 
int main() {
    int x;
    x = 0;
     
    fork();
     
    x = 1;
    printf("PID : %ld,  x : %d\n",getpid(), x);
     
    return 0;
}
```

출력:
```   
PID: 1261, x : 1   
PID: 1262, x : 2
```   
   
fork 함수가 실행 된 직후에는 자식 프로세스 부모 프로세스와 동일한 주소 공간의 복사본을 가지면서, 각기 다른 프로세스에서 동일한 코드를 실행한다. (그래서 두개의 문장이 출력이 되는 것)   
   
다음 그림을 참조하면 좋다.   
   
<img src="https://t1.daumcdn.net/cfile/tistory/998B843A5A646DCF0C">
   
다음에는 fork 함수의 리턴값을 검사하여 부모와 자식 코드를 각각 분리한 코드이다. 위에서 나온 듯 fork 함수는 **부모 프로세스에게는 자식 프로세스의 PID를 반환하며 자식 프로세스에게는 0을 반환한다.**   
   
예제2: fork2.c

```C
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
 
int main() {
     
    pid_t pid;
     
    int x;
    x = 0;
     
    pid = fork();
     
    if(pid > 0) {  // 부모 코드
        x = 1;
        printf("부모 PID : %ld,  x : %d , pid : %d\n",(long)getpid(), x, pid);
    }
    else if(pid == 0){  // 자식 코드
        x = 2;
        printf("자식 PID : %ld,  x : %d\n",(long)getpid(), x);
    }
    else {  // fork 실패
        printf("fork Fail! \n");
        return -1;
    }
     
    return 0;
 
}
```

출력:
```   
부모 PID : 1984, x : 1, pid : 1987
자식 PID : 1987, x : 2   
```   

위에 쓰여진 조건문은 fork문으로 생성된 부모 프로세스와 자식 프로세스를 분리해줄 수 있는 조건문이다. 새로 생성된 자식 프로세스의 아이디는 0을 반환하기에 이를 이용한 코드이다.   
   
다음 이미지를 이해한다면 fork를 이해한 것이다.   

<img src="https://t1.daumcdn.net/cfile/tistory/99AF5F3A5A646DDB38">

이 글은 다른 포스팅의 글을 적극적으로 활용했다는 것을 밝힘니다.   
출처: https://codetravel.tistory.com/23





