## pipewire 실행 오류

오류 내용

```sh
[E][00063.506470] mod.protocol-native | [module-protocol-:  733 lock_socket()] server 0x558a4e38d0: unable to lock lockfile '/run/user/1000/pipewire-0.lock': Resource temporarily unavailable (maybe another daemon is running)
[E][00063.506649] pw.conf      | [          conf.c:  595 load_module()] 0x558a4be270: could not load mandatory module "libpipewire-module-protocol-native": Resource temporarily unavailable
[E][00063.506918] default      | [      pipewire.c:  125 main()] failed to create context: Resource temporarily unavailable
```

사운드 카드 어케 설정해야하는지 몰라서 한참 헤매고 있다가 문득 ㅇ? 서비스 오류 아닐까? 하고 찾아보다가 xdg-desktop-portal이 없다해서 그거 찾다가 시간 좀 날렸다. 그냥 GNOME 같은 디스플레이 표시 기능이라 굳이 고칠 필요가 없었는데 필요한 줄 알고 해메다가 비중요성을 깨닫고 잘은 몰라도 넘어갔다.. 근데 저 xdg를 찾는 도중에 pipewire 명령어를 실행해보라고 해서 실행해봤다가 저 오류가 떠가지고 아 저게 안됐구나! 라고 해서 열심히 찾아봤다. 그 결과 여러 가지 솔루션이 나왔는데...

1. rtkit 문제
아무래도 저수준을 다루다보니까 보안 문제니 의존성 패키지 미설치니 하는 얘기가 꽤 나왔다. 그중 Gentoo 포럼에서는 이 얘기가 주로 다뤘었는데, 나는 패키지도 깔려있고 아무리 생각해도 저 오류는 아닌거 같아서 일단 넘겼다.
2. configuare file 문제
세 번째 줄을 위주로 서칭을 하던 도중 pipewire.conf 파일에서 다른 프로그램 실행과 충돌이 일어나서 그런 걸 수도 있다는 글을 발견했다. 즉, 이미 실행되고 있는 파일 하나를 계속 실행시키려 해서 문제가 발생한다는 것이었다. 그래서 `/etc/pipewire`에서 확인해봤는데, 저 파일이 없었다..? 포럼 아래를 더 스크롤 해보니 저 위치에 설정파일이 없으면 `/usr/share/pipewire`에서 복사해 집어넣으라고 했었다. 그러고 나서 configuare 파일을 열어 포럼에 나온 그대로 처리해주고 재부팅 시켜봤지만.. 바뀐게 없었다 ㅠ

**해결 방법** (참고: https://gitlab.freedesktop.org/pipewire/pipewire/-/issues/480)   
그냥, 벌집 쑤신 꼴이었다. pipewire를 설치하면서 `pipewire.service` 등 pipewire 서비스는 다 돌려서 이미 돌아가고 있는 프로그램이었는데, 그 상태에서 내가 또 프로그램을 수동으로 돌리니까 저 주소에 접근할 수 없다며 난리를 치는 것이었다... 오류 첫째줄에 `maybe another daemon is running` 여기서 파악했어야 하는데.. 경험 미숙으로 인한 초보적인 실수..

## 결국 롤백
그렇게 열심히 pipewire를 사용하려다... pulseAudio로 롤백한 후 다시 시작하였다. 이전까지 깔아뒀던 pipewire 설정들과 파일들을 전부 지우고 초기로 돌렸다

```sh
systemctl --user --now disable pipewire.service pipewire.socket
systemctl --user --now disable pipewire-pulse.service pipewire-pulse.socket
systemctl --user --now disable pipewire-media-session.service

sudo apt purge libspa-0.2-bluetooth libspa-0.2-dev libspa-0.2-modules pipewire

sudo vim /etc/pulse/default.pa  # 수정했던 내용들 다시 롤백, bluetooth 및 source 등등

systemctl --user --now unmask pulseaudio.socket pulseaudio.service
systemctl --user --now enable pulseaudio.socket pulseaudio.service

sudo reboot
```

`pactl info`를 확인해보면 Server Name이 pulseAudio만 남겨진 것으로 롤백에 성공하였다.

## ~~rsnapshot~~

좀 뜬금없지만 이 패키지를 한번 사용해보려고 한다. 앞으로 세팅하면서 또 무슨일이 벌어질지 모르니... Git처럼 버전 관리 시스템이 하나 필요하다고 생각해서이다.   
사용하려는 백업은 풀 백업으로 할거고 rsnapshot을 통해 롤백한 버전을 백업시켜놔 앞으로 망하더라도 쭉 문제없이 진행할 수 있도록... 그렇게... 해야겠다. 백업하는데 시간이 좀 걸린다.

이것 또한 삽질이었다. 깃 처럼 복원기능이 아예 없음!

참고 사이트: <a href="https://smarthink.tistory.com/34" target="__blank">rsnapshot</a>

## 다시 Pulseaudio단부터 차근차근

이번엔 공식사이트 위주로 참조하여 설정하기를 도전해보았다. `pulseaudio-module-bluetooth` 모듈을 설치해주고, `/etc/pulse/default.pa`와 `/etc/pulse/system.pa` 파일에서 bluetooth 관련 모듈을 활성화시켜주고 pulse 유저를 bluetooth 그룹에 포함시키면서 오디오를 추가해준 결과, bluetooth 모듈에 오디오 관련 모듈(Headset AG)이 생겼다.

```sh
sudo apt install pulseaudio-module-bluetooth

sudo vim /etc/pulse/system.pa  

--open
load-module module-bluetooth-policy
load-module module-bluetooth-discover
---

sudo usermod -a -G bluetooth pulse
```

그리고 블루투스를 연결하고 `pactl list`를 통해 a2dp, HSP/HFP 둘 다 활성화 되어 있고 카드까지 추가된 것을 확인할 수 있었다.   

https://www.freedesktop.org/wiki/Software/PulseAudio/Documentation/User/Bluetooth/ 

## 전환

이제 오디오 source 입력을 받기 위해서 a2dp_source를 켜줘야 하는데, disabled 되어 있는 것을 확인했다. 그래서 이걸 켜기 위해서 자료를 알아본 결과 Arch linux 포럼에서는 bluez5.58을 써야 한다는데 우분투는 5.48이 최대였었고 pulseaudio bluetooth 모듈은 이 bluez에 의존성이 너무나 강해서 같이 죽고 같이 사는 존재였었다. 


https://wiki.archlinux.org/title/bluetooth_headset#A2DP_not_working_with_PulseAudio




