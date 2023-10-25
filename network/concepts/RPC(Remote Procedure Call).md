---
sticker: emoji//260e-fe0f
---
# RPC
## RPC의 개념
**Remote Procedure Call(원격 프로시저 호출)** 의 약자로, 별도의 원격 제어를 위한 코딩 없이 <span style="color:#7030a0;font-weight:bold">다른 주소 공간에서 함수나 프로시저를 실행할 수 있게 하는 프로세스 간 통신 기술</span>을 말한다.
다시 말해, RPC를 이용하면 프로그래머는 함수 또는 프로시저가 실행 프로그램이 존재하는 로컬 위치에 있든, 원격 위치에 있든<span style="color:#0070c0;font-weight:bold"> 상관없이 동일한 기능을 수행</span>할 수 있음을 의미한다.

### 함수 vs 프로시저
**함수(Function)**: <span style="color:#7030a0;font-weight:bold">Input에 따른 Output의 발생</span>을 목적으로 한다. 따라서 Return값을 필수로 가져야 하며, <span style="color:#0070c0;font-weight:bold">Client단</span>에서 처리되기 때문에 주로 <span style="color:#0070c0;font-weight:bold">간단한 계산 및 수치 등을 도출</span>할 때 사용한다.
**프로시저(Procedure)**: Output값 자체에 집중하기보단, '<span style="color:#7030a0;font-weight:bold">명령 단위가 수행하는 절차</span>'에 집중한 개념이라고 보면 된다. 따라서 Return값이 있을수도 있고, 없을수도 있으며, <span style="color:#0070c0;font-weight:bold">Server단</span>에서 처리되기 때문에 <span style="color:#0070c0;font-weight:bold">함수보다 큰 단위의 실행, 프로세싱 </span>등을 할 때 사용한다.

---

## 쓰임새?
일반적으로 **프로세스(Process)** 는 <span style="color:#ff0000;font-weight:bold">자신의 주소공간 안에 존재하는 함수만 호출하여 실행 가능</span>하다.
그러나, **RPC**의 경우 **자신과 다른 주소공간에서 동작하는 프로세스의 함수를 실행할 수 있게 해주는데**, 이는 네트워크를 통한 메시징을 수행하기 때문이다. 
![사진](../Pictures/Pasted%20image%2020231025130729.png)
=> <span style="color:#00b050;font-weight:bold">요즘 유행하는 MSA(Micro Service Architecture) 구조의 서비스를 만들 때, 언어나 환경에 구애받지 않고, 비즈니스 로직을 개발하는데에 집중할 수 있다!"</span>

## RPC의 목표
- Client-Server간의 커뮤니케이션에 필요한 상세정보는 **최대한 감춘다.** (=> <span style="color:#0070c0;font-weight:bold">언어나 환경에 구애를 받지 않는다!</span>)
- Client와 Server는 각각 일반 메소드를 호출하는 것처럼 원격지의 프로시저를 호출할 수 있다.
![사진](../Pictures/Pasted%20image%2020231025131435.png)

## RPC의 동작방식 - IDL 기반
![사진](../Pictures/Pasted%20image%2020231025132140.png)
1. **IDL(Interface Definition Language)** 을 사용하여 서버의 호출 규약을 정의
   <span style="color:#0070c0;font-weight:bold">함수명, 인자, 반환값</span>에 대한 <span style="color:#7030a0;font-weight:bold">데이터 타입이 저장된 IDL 파일</span>을 **'rpcgen' 컴파일러를 이용**하여 stub 코드를 자동으로 생성

    **IDL(Interface Definition Language)** : 인터페이스 정의 언어. 어느 한 언어에 국한되지 않는 언어 중립적인 방법으로 인터페이스를 표현함으로써, **구현 언어(C, C++, Java 등)가 아닌 정의 언어** 로, <span style="color:#7030a0;font-weight:bold">구현 언어로의 매핑(mapping)을 지원</span>

2. **stub**은 원시소스코드 (C, Java 등)의 형태로 만들어지므로, **클라이언트, 서버 프로그램에 각각 포함하여 빌드**
3. 클라이언트 프로그램 입장에서는 자신의 프로세스 주소공간의 함수를 호출하는 것처럼 보이는데, **클라이언트 stub에 정의된 함수를 호출**하는 것임.
4. **stub 코드**는 데이터 타입을 **XDR(External Data Representation) 형식으로 변환**하여 RPC 호출을 실행.

    **XDR 변환 이유** : 기본 데이터 타입(정수형, 부동소수점 등)에 대한 **메모리 저장방식(Little-Endian/Big-Endian)** 이 <span style="color:#ff0000;font-weight:bold">CPU Architecture별로 다르며</span>, 네트워크 전송과정에서 **바이트 전송 순서를 보장**하기 위함. 
5. 서버는 수신된 함수/프로시저 호출에 대한 처리를 **서버 stub을 통해 처리 완료 후, 결과값을 XDR 변환하여 Return**
6. 최종적으로 **클라이언트** 프로그램은 **서버가 Return한 결과값을 전송받음.**

## RPC의 대표적인 구현체
- 구글의 <span style="color:#0070c0">ProtocolBuffer</span>
- 페이스북의 <span style="color:#0070c0">Thrift</span>
- 트위터의 <span style="color:#0070c0">Finalge</span>
- <span style="color:#8a8a8a;text-decoration:line-through">carla</span>

## RPC의 장점
- **고유 프로세스 개발에 집중** 가능 (<span style="color:#0070c0;font-weight:bold">하부 네트워크 프로토콜에 신경쓰지 않아도</span> 되기 때문)
- **프로세스간 통신 기능을 비교적 쉽게** 구현하고 정교한 제어 가능

## RPC의 단점
- <span style="color:#ff0000;font-weight:bold">호출 실행과 반환 시간이 보장되지 않음</span> (네트워크 구간을 통하여 RPC 통신을 하는 경우, <span style="text-decoration:underline;">네트워크가 끊겼을 때</span> 치명적 문제 발생)
- <span style="color:#ff0000;font-weight:bold">보안이 보장되지 않음</span>


## 출처
https://co-no.tistory.com/28