# listen

__형식__

- 헤더: `#include <sys/socket.h>`
- 형태: `int listen(int sock, int backlog);`
- 인자
  - `int sock`: 소켓 식별자 또는 소켓 디스크럽터
  - `int backlog`: 연결 요청을 대기시킬 공간 설정(백로그큐 라고 함)
- 반환
  - `0`: 성공
  - `-1`: 실패

__예제__

```C
if (-1 == listen(sock, 5)) {
    printf("listen() error!!\n);
    exit(1);
}
```

보통 백로그 큐는 5로 잡는다.(연결 대기 제한 수)
   
추가설명: 클라이언트가 `connect()`를 하게 되면 클라이언트는 서버에게 connect request를 보내게 되는데, 서버는 connect request 신호를 받고 대기 큐에서 클라이언트를 대기시킨다. 그리고 서버는 자신과 연결되어있는 클라이언트가 없다면 대기 큐에 있는 클라이언트를 한명 잡아다가 연결을 하게 된다. **이때 대기 큐의 제한을 걸어주는 게 백로그 큐이다.**   
(대기 큐는 5로 잡고 10개의 클라이언트가 연결신청을 하여 대기 상태에 있다고 해서 전부 연결대기는 아니고 5개만이 연결 대기 상태이다.)

출처: https://mousepotato.tistory.com/55