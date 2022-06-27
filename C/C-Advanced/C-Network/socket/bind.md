# bind

> bind()함수는 소켓에 주소를 할당해주는 함수

- 헤더
  - `#include <sys/types.h>`
  - `#include <sys/socket.h>`
- 형태
  - `int bind(int sockfd, struct sockaddr *myaddr, socklen_t addrlen);`
- 인자
  - `int sockfd`: 소켓 식별자 또는 소켓 디스크럽터
  - `struct sockaddr *myaddr`
    - 주소 정보 할당
    - 인터넷을 통해 통신하는 **AF_INET**인 경우에는 struct **sockaddr_in**을 사용
    - 시스템 내부 통신인 **AF_UNIX**인 경우 **struct sockaddr**을 사용
  - `socklen_t addrlen`: myaddr 구조체의 크기
- 반환
  - 0: 주소 할당 성공
  - -1: 주소 할당 실패

sockaddr_in 구조체의 구조

```C
struct sockaddr_in {
    sa_family_t         sin_family;  //소켓 주소체계(AF_INET, AF_INET6, AF_LOCAL)
    unsigned short int  sin_port;  // 포트 주소
    struct in_addr      sin_addr;  // IP 주소
    unsigned char       sin_zero[8];  //사용하지 않는 필드 0을 채워줌
}
```

sockaddr 구조체의 구조

```C
struct sockaddr {
    sa_family_t     sa_family;  //소켓 주소 체계
    char            sa_data[4];  //14byte Protocol address
}
```

예제

```C
struct sockaddr_in addr;
memset(&addr, 0, sizeof(addr));
addr.sin_family      = AF_INET;   // IPv4 인터넷 프로토롤 
addr.sin_port        = htons( 4000);  // 사용할 port 번호는 4000
addr.sin_addr.s_addr = htonl( INADDR_ANY);   // 32bit IPV4 주소
 
if ( -1 == bind(Sock, (struct sockaddr*)&addr, sizeof(addr)) ) {
    printf("bind() error!!");
    exit(1);
}
```

출처: https://mousepotato.tistory.com/54