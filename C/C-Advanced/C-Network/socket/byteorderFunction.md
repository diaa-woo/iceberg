# byte order function

__기본 형식__

```C
#include <netinet/in.h>

unsigned short int htons(unsigned short int hostshort);
unsigned long int htonl(unsigned long int hostshort);
unsigned short int ntohs(unsigned short int hostshort);
unsigned long int ntohl(unsigned long int hostshort);
```

__설명__
   
데이터는 바이트 단위로 저장되지만 저장되는 방식에 있어서 CPU마다 차이가 발생한다.**(Little Endian, Big Endian의 차이)**. 이런 이유로 서로 다른 데이터 저장 방식을 사용하는 시스템끼리 통신을 하게 될 경우 전혀 원하지 않는 값들을 서로 주고 받는 경우가 발생할 수 있다.   
   
이런 문제를 해결하기 위해 데이터 통신을 할 때는 명시적으로 네트워크 byte order를 따르도록 데이터의 byte order를 변경한다. 네트워크 byte order는 Big Endian을 따른다.

- **htonl()**: long integer(일반적으로 4byte) 데이터를 네트워크 byte order로 변경함
- **htons()**: short integer(일반적으로 2byte) 데이터를 네트워크 byte order로 변경한다.
- **ntohl()**: long integer 데이터를 호스트 byte order로 변경한다.
- **ntohs()**: short integer 데이터를 호스트 byte order로 변경한다.

__반환값__
   
네트워크 byte order된 2바이트 값을 넘겨줌.
