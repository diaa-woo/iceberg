# zsh

## zsh란?
<p></p>
z shell이라고도 하며 Bourne Shell (sh)의 확장된 버전으로, 많은 새로운 기능들과 플러그인 및 테마를 지원한다. 기본 bash 명령어를 전부 이어받으며 전환이 매우 쉽다.

### 주요 기능
<p></p>

- 자동 cd: 디렉토리 이름을 쉽게 나타낼 수 있다.
- 재귀 경로 확장: 예를 들어 "/u/lo/b"는 "/usr/local/bin"으로 확장된다.
- 철자 교정 및 대략적인 완성: 디렉토리 이름을 입력하는 데 약간의 실수가 있으면 zsh가 이를 커버해준다.
- 플러그인 및 테마 지원: zsh에는 다양한 플러그인 프레임워크가 포함되어 있다.

## zsh 설치
<p></p>

```sh
sudo apt install zsh && chsh -s $(which zsh)
curl -L https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh | sh  #zsh 설치
```