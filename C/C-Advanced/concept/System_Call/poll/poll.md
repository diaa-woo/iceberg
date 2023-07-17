# poll

## 소개

**여러 File Descrioptor을 감시하여 event가 발생할 때까지 기다린다. 그 후 이벤트가 발생 시 그에 대한 정보를 제공해준다.** 인터럽트와 동일한 형태의 함수인데, select와 비슷한 함수이다.

### 사용 예시

예를 들어 어떤 서버가 여러 클라이언트에 대해 연결을 갖게 되고, 입력을 처리해야 할 때, 여러 개의 쓰레드를 나누어 처리하는 것도 하나의 방법이다. 허나 이럴 경우 쓰레드를 무한으로 증식해야 한다는 치명적인 결함이 있는데, 이 같은 불필요한 방법 대신 `poll()` 함수를 이용해 몇십개의 socket에 대해 지켜보다가 하나의 socket에 읽을 데이터가 생겼다면 그 socket에서 read 후 처리를 할 수 있다.

## 함수 설명

```C
int poll(struct pollfd *fds, nfds_t nfds, int timeout);
```

- **fds**: `pollfd`의 구조체 포인터이다. 아래는 선언문

```C
struct pollfd {
    int   fd;           /* file descriptor  */
    short events;       /* requested events */
    short revents;      /* returned events  */
}
```
- fd: 점검할 file descriptor
- events: fd에 대해 주시할 event. 이 event들은 OR로 여러 가지를 줄 수 있다.
- revents: fd에 발생한 event. 이는 사용자가 설장하는 것이 아닌 `kernel`이 설정해준다.

아래의 표를 살펴보면 revents에는 모든 event가 설정되어질 수 있다.

|event 이름|event에 설정 가능|kernel이 revents에 설정|설명|
|----------|----------------|----------------------|----|
|`POLLIN`| O | O | high priority외의 자료를 바로 읽을 수 있음 (`POLLRDNORM` | `POLLRDBAND`와 동일!)| 
|`POLLRDNORM`| O | O | 보통 자료를 바로 읽을 수 있음 |
|`POLLRDBAND` & `POLLPRI`| O | O | 우선 순위 자료를 바로 읽을 수 있음 |
|`POLLOUT` & `POLLWRNORM`| O | O | 보통 자료를 쓸 수 있음 |
|`POLLRDNORM`| O | O | 보통 자료를 바로 읽을 수 있음 |
|`POLLRDNORM`| O | O | 보통 자료를 바로 읽을 수 있음 |
|`POLLRDNORM`| O | O | 보통 자료를 바로 읽을 수 있음 |
|`POLLRDNORM`| O | O | 보통 자료를 바로 읽을 수 있음 |
