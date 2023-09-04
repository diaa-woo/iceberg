# Redis

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FcrqLWH%2Fbtsh1TDBEqv%2FHLKQ2k2c2N7b3qqImDPrnK%2Fimg.png">

'키-값' 구조의 비정형 데이터를 저장하고 관리하기 위한 비관계형 데이터베이스 관리 시스템(DBMS)으로, redis라는 이름은 *Remote Dictionary Server*의 약자이다. *살바토르 산필리포(Salvatore Sanfilippo)*가 개발해 현재는 Redis Labs가 지원하는 오픈소스 기반 데이터베이스다. 

주로 DB, 캐시, 메시지 브로커, 스트리밍 엔진으로써 사용된다.

## 특징

### 인메모리 데이터베이스
Redis의 가장 큰 특징 중 하나는 데이터를 메모리로 불러와 처리하는 메모리 기반 DBMS, 즉 인메모리 데이터베이스라는 점이다. 데이터를 디스크나 SSD에 저장하는 데이터베이스보다 빠른 성능을 기대할 수 있다.

### 다양한 데이터 타입

<img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FSF5tc%2Fbtsh179wBJ9%2FV4HX9A8qmw07anKkM2z6QK%2Fimg.png">

Strings, Hashes, lists, sets, sorted sets, bitmaps, hyperloglogs, geospatial indexs, streams와 같은 다양한 데이터 타입을 지원한다.

## `redis-cli` 사용법

### 데이터 쓰기

`SET` 명령어에 키와 값을 지정하여 데이터를 저장한다.

```
SET key value [expiration EX seconds|PX milliseconds] [NX|XX]

# 예시
SET hello world
```

### 데이터 읽기

`GET` 명령어에 읽을 데이터의 키를 지정하여 값을 읽을 수 있다.

```
GET key

# 예시
GET hello
```

### 키 목록 조회

`KEYS` 명령은 지정한 패턴과 일치하는 키 목록을 출력한다. 모든 키 목록을 확인하고 싶을 때는 *으로 지정한다.

```
KEYS pattern

# 예시
KEYS *
```

지정한 데이터가 없을 때는 `(empty list or set)`이라는 메세지가 출력된다.

### 데이터 삭제

`DEL` 명령어에 삭제할 키를 지정하여 데이터를 삭제할 수 있다.

```
DEL key [key ...]

# 예시
DEL hello
```

### 모든 데이터 삭제

`FLUSHALL`이라는 명령어를 사용한다.

```
FLUSHALL [ASYNC]
```

## 참고

https://passwd.tistory.com/entry/Redis-%EA%B0%9C%EB%85%90-%EB%B0%8F-%EC%84%A4%EC%B9%98%EC%8B%A4%ED%96%89