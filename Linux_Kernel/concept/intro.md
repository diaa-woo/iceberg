[상위 문서로 이동](../README.md)

# 들어가며

## 커널 모듈?

커널 모듈(Kernel Module)이란 **필요에 따라 커널에 로드 및 언로드할 수 있는 코드 조각**이다. 모듈을 통하여 시스템을 재부팅하지 않고도 커널의 기능을 확장할 수 있다. 예를 들어, 모듈의 한 유형인 장치 드라이버는 커널이 시스템에 연결된 하드웨어에 엑세스할 수 있게 해준다. 모듈이 없더라면 *모놀리식 커널*을 빌드하고 커널 이미지에 직접 새 기능을 추가해야 할 것이다. 그렇게 된다면 커널의 덩치가 커질 뿐 아니라, 새로운 기능을 넣을 때마다 커널을 다시 빌드하고 재부팅해야 한다는 단점이 있다.

## 커널 모듈 패키지

리눅스 배포판들은 패키지 내에 `modprobe`, `insmod`, `depmod` 명령을 제공한다.

Ubuntu/Debian

```sh
sudo apt install build-essential kmod
```

## 커널 모듈 확인법

현재 커널에 어떤 모듈이 이미 로드되어 있는지 확인하려면 `lsmod` 사용

```sh
sudo lsmod
```

모듈은 `/proc/modules` 파일에 저장되므로 다음과 같이 볼 수도 있다.

```sh
sudo cat /proc/modules
```

목록이 길어질 경우 특정 항목을 검색하는 것을 추천함.

## 커널 다운로드 필요?

이 가이드를 따르는게 목적이라면 X. 하지만 시스템을 엉망으로 만들 가능성을 피하기 위해 가상 머신에서 실행되는 테스트 배포 내에서 예제를 실행하는 것이 좋음.

## header 설치

어떤 모듈이든 빌드하기 전에 커널용 헤더 파일을 설치해야 한다.

Ubuntu/Debian

```sh
sudo apt update
apt-cache search linux-headers-`uname -r`
```

이 코드를 작동할 시 어떤 커널 헤더 파일을 사용할 수 있는지 알려줍니다. 그 뒤 다음과 같이 입력합니다.

```sh
sudo apt install linux-headers-<version>-generic
```

