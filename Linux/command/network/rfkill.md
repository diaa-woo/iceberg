[상위 문서로 이동](../README.md)

# RFKill

많은 컴퓨터 시스템에는 Wi-Fi, BT등과 같은 전파 송수신 장치가 포함되어 있다. 다만 이러한 장치들은 전력을 소비하고, 만일 장치 사용시가 아니라면 전력 낭비로 이어진다.

`RFKill`은 리눅스 커널의 서브시스템으로 컴퓨터의 전파 송수신 장치들에 대해 질의하고, 활성화하고, 비활성화 할 수 있도록 해주는 인터페이스는 제공한다.   
송수신 장치가 비활성화되는 경우, 소프트웨어가 그 장치를 재활성화 시킬 수 있는 상태(*소프트 블럭(soft block)*)나 소프트웨어로는 그 장치를 재활성화 시킬 수 없는 상태(*하드 블럭(hard block)*) 중 하나로 장치의 상태가 변화된다.

RFKill 핵심부는 서브시스템에 API를 제공한다. RFKill을 지원하는 것으로 서명된 커널 드라이버는 이러한 API를 활용해 커널에 자신을 등록하고, 장치를 활성화하고 비활성화하는 방법을 제공한다. 또한, RFKill 핵심부는 사용자 어플리케이션이 이해할 수 있는 통지를 제공하며, 사용자 어플리케이션이 송수신 장치의 상태를 질의할 수 있는 방법을 제공한다.

*RFKill* 인터페이스는 `/dev/rfkill`에 위치하며, 그 안에는 시스템의 모든 전파 송수신 장치의 상태정보가 포함되어 있다. 각각의 장치는 현재의 RFKill 상태를 `sysfs`에 등록해 둔다. 추가적으로, RFKill이 활성화되어 있는 장치의 상태가 변화되면 RFKill은 *uevents* 이벤트를 발생시킨다.

**RFKill**은 명령행 도구로 시스템의 RFKill-지원 장치에 질의를 하고, 상태를 변경할 수 있도록 해준다.

## 명령어

`rfkill list`를 사용해 장치의 목록을 얻는다. 각각의 장치는 `0`번 부터, 연관된 *인덱스 번호*를 부여 받는다. 이 인덱스 번호를 사용해 **rfkill**에 어떤 장치를 블럭하거나 블럭을 해제하도록 지정할 수 있다.

```bash
rfkill block 0
```

위 명령어는 시스템의 첫번째 RFKill-지원 장치를 블럭한다.

또한  **rfkill**를 사용해 특정 종류의 장치들이나 모든 RFKill-지원 장치들을 블럭할 수도 있다. 

```bash 
rfkill block wifi
```

위 명령어는 모든 Wi-Fi 장치를 블럭한다. 모든 RFKill-지원 장치를 블럭하려면, 다음과 같이 해야한다.

```sh
rfkill block all
```

블럭된 장치를 해제하려면 `rfkill block` 대신, `rfkill unblock`를 사용한다. **rfkill**이 블럭할 수 있는 장치들의 종류를 확인하려면 `rfkill help`를 실행하면 된다.

## 출처
https://access.redhat.com/documentation/ko-kr/red_hat_enterprise_linux/6/html/power_management_guide/rfkill