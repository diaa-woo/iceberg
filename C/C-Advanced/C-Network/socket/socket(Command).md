# socket(Command)

__형식__

- 헤더: `sys/types.h`, `sys/socket.h`
- 형태: `int socket(int domain, int type, int protocol)`
- 인수:
  - `int domain`: 인터넷을 통해 통신할 지, 같은 시스템 내에서 프로세스끼리 통신할 지의 여부를 설정
  - `int type`: 데이터의 전송 형태 지정
  - `int protocol`: 통신에 있어 특정 프로토콜을 사용을 지정하기 위한 변수이며, 보통 0 값을 사용
- 반환: -1 == 실패, -1 이외: 소켓 디스크럽터

__인수 추가 설명__

- `int domain`
  - `PF_INET`, `AF_INET` : IPv4 인터넷 프로토콜 사용
  - `PF_INET6`: IPv6 인터넷 프로토콜 사용
  - `PF_LOCAL`, `AF_UNIX`: 같은 시스템 내에서 프로세스끼리 통신
  - `PF_PACKET`: Low Level Socket을 인터페이스로 이용
  - `PF_IPX`: IPX 노벨 프로토콜 사용
- `int type`
  - `SOCK_STREAM`: TCP/IP 프로토콜
  - `SOCK_DGRAM`: UDP/IP 프로토콜
  - `SOCK_RAW`: 사용자 정의
- `int protocol`
  - default 값인 `0` 써도 ㄱㅊ(이미 위에서 잡아줘서 굳이 필요 X)
  - `IPPROTO_TCP` : TCP
  - `IPPROTO_UDP` : UDP

__TCP/IP 통신 함수 사용 순서__

<img src="https://blog.kakaocdn.net/dn/bVSNqV/btryXerTjV9/lV04Fo13UmKP44W4XUb7LK/img.gif"/>

출처: https://blockdmask.tistory.com/212
https://badayak.com/entry/C%EC%96%B8%EC%96%B4-%EC%86%8C%EC%BC%93-%EC%83%9D%EC%84%B1-%ED%95%A8%EC%88%98-socket