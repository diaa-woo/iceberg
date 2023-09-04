# LibGL Error

가끔 노트북이나 데스크탑을 사용하다보면 `libGL error: failed to load driver: iris` 이런 오류가 뜬다. 

이런 경우는 환경변수 `LD_PRELOAD`를 설정해주면 된다. 참고로 필자의 환경은 Ubuntu 22.04이다.

먼저 모든 악의 근원인 `libstdc++.so.6` 라이브러리를 다음 명령어로 찾아준다.

```sh
find / -name libstdc++.so.6 2>/dev/null
```

그 중 snap이나 `/usr/lib/..`에 들어가 있는 라이브러리 경로를 자신이 사용하고 있는 셸의 설정파일(ex: `.zshrc`)에 `LD_PRELOAD` 환경 변수로 설정해준다.

```sh
export LD_PRELOAD=/usr/lib/x86_64-linux-gnu/libstdc++.so.6
```

## anaconda

아나콘다는 좀 특이케이스이다. 지만의 개발 환경을 지니고 있으며, 가끔 특이한 라이브러리도 들고오기에 충분히 오류가 뜰 수 있다. 해서 anaconda 같은 경우는 따로 `libstdcxx-ng` 모듈을 설치해줘야 한다.

```sh
conda install -c conda-forge libstdcxx-ng
```

## 출처

https://stackoverflow.com/questions/71010343/cannot-load-swrast-and-iris-drivers-in-fedora-35/72200748#72200748