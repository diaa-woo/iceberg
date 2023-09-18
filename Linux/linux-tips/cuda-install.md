# CUDA 설치

Ubuntu에서 nvidia-driver만 설치해준다고 CUDA가 자동으로 설치되는 것은 아니다. 그래서 CUDA-Toolkit을 설치해주고, 이를 환경변수로 적용시켜주어야 CUDA를 직접 사용해줄 수 있다. 

## CUDA 설치

설치 환경
- Ubuntu 22.04(linux kernel : 6.2.0-generic)
- nvidia-driver ver : 535
- CUDA ToolKit Version : 12.2

### 설치할 드라이버 확인

```sh
sudo ubuntu-drivers devices
```

해당 명령어를 입력하면 설치 가능한 nvidia-drivier 디바이스 목록이 출력된다. 여기서 recommended로 뜨는 드라이버를 설치하는 것을 추천한다고 적혀있다. 대신 `open` version 보단 정규버전을 사용하는 것이 더 나을 것 같다.

아래 사이트에 nvidia graphic driver 버전에 따라 설치할 수 있는 CUDA 버전이 적혀져있다. 해당 사이트를 참고해도 좋고, 아님 driver 설치 후 명령어 `nvidia-smi`를 통해 표시되는 CUDA 버전에 맞춰 설치해도 좋다.

### 드라이버 설치

```sh
sudo apt install nvidia-driver-535  # 각 시스템에 해당하는 드라이버!
sudo apt install dkms nvidia-modprobe

# Optional
sudo apt update
sudo apt upgrade -y
```

재부팅을 한 후, 잘 설치가 되었는지 확인한다.

```sh
nvidia-smi
```

### CUDA Toolkit 설치

자신이 원하는 CUDA version download 웹사이트에 접속한 후, 자신의 시스템 조건에 맞춰서 옵션을 선택한 후 명령어를 입력해준다.

```sh
wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu2204/x86_64/cuda-keyring_1.1-1_all.deb
sudo dpkg -i cuda-keyring_1.1-1_all.deb
sudo apt-get update
sudo apt-get -y install cuda
```

### (서버에 처음 설치하는 경우) gcc 관련 설치

```sh
sudo apt update 
sudo apt install build-essential 
sudo apt-get install manpages-dev
```

### 환경변수 등록

먼저 출력되는 CUDA 목록에서 설치하고자 하는 CUDA 버전 폴더를 확인한다.

```sh
ls /usr/local | grep cuda
```

만약, `CUDA-12.2` 폴더가 대상이라면 다음 명령어로 환경변수를 등록할 수 있다. 만약 설치하고자 하는 CUDA 버전이 해당 버전을 12.2 대신 치환하여 기입한 후 실행하믄 된다.

```sh
sudo sh -c "echo 'export PATH=$PATH:/usr/local/cuda-11.8/bin'>> /etc/profile"
sudo sh -c "echo 'export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/cuda-11.8/lib64'>> /etc/profile"
sudo sh -c "echo 'export CUDARDIR=/usr/local/cuda-11.8'>> /etc/profile"
source /etc/profile
```

### nvcc 버전 확인

```sh
nvcc -V
```

만일 오류가 발생한다면

```sh
sudo apt install nvidia-cuda-toolkit
```

을 실행한다. 끝!