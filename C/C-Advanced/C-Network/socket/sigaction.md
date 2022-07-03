# sigaction

## Sigaction Function

> sigaction() 함수는 signal()보다 향상된 기능을 제공하는 시그널 처리를 결정하는 함수.

__형태__

- 헤더: `signal.h`
- 형태: `int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)`
- 인수
  - `int signum`: 시그널 번호
  - `struct sigaction *act`: 설정할 행동. 즉, 새롭게 지정할 처리 행동
  - `struct sigaction *oldact`: 이전 행동, 이 함수를 호출하기 전에 지정된 행동 정보가 입력됨.
- 반환
  -  `0` : 성공
  -  `-1`: 실패

## Sigaction Struct

__형태__

```C
struct sigaction {
    void (*sa_handler)(int);    // 시그널을 처리하기 위한 핸들러
                                // SIG_DFL, SIG_IGN 또는 핸들러 함수
    void (*sa_sigaction)(int, siginfo_t *, void *);  // 밑의 sa_flags가 SA_SIGNINGO일 때, sa_handler 대신에 동작하는 핸들러

    sigset_t sa_mask;           // 시그널을 처리하는 동안 블록화할 시그널 집합의 마스크
    int sa_flags;               // 요 안에 이런저런 매크로 설정 가능
    void (*sa_restorer)(void);  // 사용 X
}
```

__sa_flag 옵션__   
   
OR 연산자(`|`)를 사용해서 여러 옵션을 연속해서 쓰는 것도 ㄱㄴ!

- `SA_NOCLDSTOP`: signum이 `SIGCHILD`일 경우, 자식 프로세스가 멈추었을 때, 부모 프로세스에 `SIGCHILD` 전달 X
- `SA_ONESHOT`, `SA_RESETHAND`: 시그널을 받으면 설정된 행동을 취하고, 시스템 기본 설정인 `SIG_DFL`로 재설정됨.
- `SA_RESTART`: 시그널 처리에 의해 방해 받은 시스템 호출은 시그널 처리가 끝나면 재시작함.
- `SA_NOMASK`, `SA_NODEFER`: 시그널을 처리하는 동안에 전달되는 시그널은 블록 X
- `SA_SIGINFO`: 이 옵션을 사용하면 `sa_handler` 대신 `sa_sigaction`이 동작하며, `sa_handler` 보다 더 다양한 인수를 받을 수 있음. `sa_sigaction`이 받는 인수에는 **시그널 번호, 시그널이 만들어진 이유, 시그널을 받는 프로세스의 정보**이다.

출처: https://badayak.com/entry/C%EC%96%B8%EC%96%B4-%EC%8B%9C%EA%B7%B8%EB%84%90-%EC%B2%98%EB%A6%AC-%ED%95%A8%EC%88%98-sigaction