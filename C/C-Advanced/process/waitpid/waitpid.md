# waitpid

>자식 프로세스의 종료를 기다린다.
   
posix thread에서 pthread_join()과 같은 역할을 지니며, 헤더파일은 `<sys/wait.h>`에 정보가 들어가 있다.
   
```C
//헤더파일 함수 원형

pid_t waitpid(pid_t pid, int *status, int options);
```

waitpid 함수는 인수로 주어진 pid 번호의 자식 프로세스가 종료되거나, 시그널 함수를 호출하는 신호가 전달될 때 까지 waitpid 호출한 영역에서 **일시중지.**   

__인자값__
   
첫 번째 인자(pid)
- pid가 -1일 경우(pid == -1) : 임의의 자식 프로세스를 기다림
- pid가 0보다 클 경우(pid > 0): 프로세스 ID가 pid인 자식 프로세스를 기다림
- pid가 -1보다 작을 경우(pid < -1): 프로세스 그룹 ID가 pid의 절댓값과 같은 자식 프로세스를 기다림
- pid가 0일 경우(pid == 0): waitpid를 호출한 프로세스의 프로세스 그룹 PID와 같은 프로세스 그룹 ID를 가진 프로세스를 기다림.

이때 waitpid 함수의 오류는 지정한 pid의 프로세스 또는 프로세스 그룹이 없는 경우에 발생하며, 그리고 pid가 자식 프로세스가 아닐때 발생함!   
   
두 번째 인자(*status)
- 자식 프로세스가 **정상적**으로 종료시 : 프로세스 ID 반환
  - WIFEXITED(statloc) 매크로가 true를 반환
  - 하위 8비트를 참조하여 자식 프로세스가 exit, _exit, _Exit에 넘겨준 인자값을 얻을 수 있음, <u>WEXITSTATUS(statloc)</u>도 마찬가지
- 자식 프로세스가 **비정상적**으로 종료시: 프로세스 ID 반환
  - WIFSIGNALED(statloc) 매크로가 true를 반환
  - 비정상 종료 이유를 <u>WTERMSIG(statloc) 매크로</u>를 사용하여 구할 수 있음
- waitpid 함수 오류: -1 퉤
  - ECHILD: 호출자의 자식 프로세스가 없는 경우
  - EINTR: 시스템 콜이 인터럽트 되었을 때

옵션(options)
- -1
  - 프로세서 그룹 ID가 pid의 절대값과 같은 자식 프로세스를 기다린다.
  - 임의의 자식프로세스를 기다린다.
  - wait(2)와 동일하다.
- 0
  - 프로세스 그룹 ID가 호출 프로세스의 ID와 같은 자식 프로세스를 기다린다.
  - 프로세스 ID가 pid의 값과 같은 자식 프로세스를 기다린다.
- WCONTINUED: 중단되었다가 재개된 자식 프로세스의 상태 받음
- WNOHANG: 기다리는 PID가 종료되지 않아서 즉시 종료 상태를 회수할 수 없는 상황에서 호출자는 차단되지 않고 반환값으로 0을 받음
- WUNTRACED: 중단된 자식 프로세스의 상태를 받음

매크로
- WIFEXITED(status)
  - 자식이 정상적으로 종료되었다면 non-zero
- WEXITSTATUS(status)
  - exit()를 호출하기 위한 인자나 return 값이 설정되고 종료된 자식의 반환 코드의 최하위 8비트를 평가한다.
  - 이 매크로는 정상종료(WIFEXITED(status))일때만 평가된다.
- WIFSIGNALED(status)
  - 자식 프로세스가 어떤 신호때문에 종료되었다면 참을 반환
- WTERMSIG(status)
  - 자식 프로세스를 종료하도록 한 신호의 번호를 반환한다.
  - WIFSIGNALED가 non_zero일 경우에만 동작한다.
- WIFSTOPPED(status)
  - 반환의 원인이 된 자식 프로세스가 현재 정지되어 있다면 참을 반환한다.
- WSTOPSIG(status)
  - 자식을 정지하도록 야기한 신호의 숫자를 반환함.
  - WIFSTOPPED가 non-zero일 경우에만 사용 가능

예제 소스코드: waitpid.c

```C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    pid_t childPid; //process id 구조체 생성
    int status;

    childPid = fork();  

    if(childPid > 0) {  //부모 프로세스
        int ret;
        printf("부모 PID : %ld, pid : %d\n", (long)getpid(), childPid);
        sleep(3);
        ret = waitpid(childPid, &status, 0);  //세번째 인자에 0을 넣으면 wait 함수와 동일한 동작을 함

        printf("부모 종료 %d %d %d \n", ret, WIFEXITED(status), WEXITSTATUS(status));
        exit(0);
    }

    else if(childPid == 0) {  //자식 코드
        printf("자식 시작 PID : %ld\n", (long)getpid());
        sleep(5);

        printf("자식 종료\n");
        exit(0);
    }

    else {  //fork 실패
        perror("fork Fail!\n");
        return -1;
    }
}
```

출력:

```
부모 PID : 1281, pid : 1286
자식 시작 PID : 1286
자식 종료
부모 종료 1286 1 0 
```

출처: 
https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=endfirst&logNo=20018509790
https://codetravel.tistory.com/42