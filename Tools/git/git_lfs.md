[상위 문서로 이동](README.md)

# Git LFS (Large File Storage)

기본적으로 git은 여러 개의 작은 소스코드 파일들을 위한 *버전 컨트롤 시스템(VCS)* 이다. 따라서 Github의 경우 50Mb부터 Warning이 표시되고, 100Mb부터는 push시 Error가 발생한다. 그럼에도 불구하고 경우에 따라서 반드시 대용량 파일을 git repo에 포함시켜야하는 상황이 존재할 수 있다.(예를 들면 학습된 모델 파라미터를 올려야할 때.) 이러한 경우에 사용할 수 있는 해결책은 바로 **Git LFS(Large File Storage)** 이다!

<img src="https://velog.velcdn.com/images%2Fshin6949%2Fpost%2Fa560dda4-90aa-4885-9168-c2db31149a70%2Fimage.png">

Git LFS는 대용량 파일을 별도의 서버에 올리고, 원래 위치에는 포인터를 남긴다. 즉, 대용량 파일은 다른 서버에서 받아오고 있지만, 포인터가 설정되어 있기 때문에 사용자 입장에서는 Git Push, Pull 등을 그대로 사용할 수 있다.

## 설치 - Ubuntu

```sh
curl -s https://packagecloud.io/install/repositories/github/git-lfs/script.deb.sh | sudo bash
sudo apt install git-lfs
```

## 특정 repo에 git lfs 적용 & 해제하기

(해당 레포로 이동 후)

```sh
git lfs install         # 적용
git lfs uninstall       # 해제
```

## LFS로 File 관리하기

lfs를 적용한 후, 관리할 파일을 track한다. 기본적으로는 해당 파일을 `git add`하기 전에, `git lfs track`을 해주어야 한다. 만약 기존에 add해 둔 파일을 lfs로 관리해야 하는 상황이라면 `git rm --cache`로 먼저 unstaging을 시킨 다음, 다시 `git lfs track`을 해줘야 한다

```sh
git rm --cached <file path>
git lfs track <file path>
```

그러면 해당 파일의 내용이 원래의 contents가 아니라 *lfs pointer* 로 바뀌는 것을 알 수 있다. 도한, lfs로 트래킹하는 파일에 대한 정보는 `.gitattributes`을 통해서 관리가 되어 이 변경사항을 꼭 add해주어야 한다. 나머지는 일반적인 `git push`와 동일하다.

```sh
git add .gitattributes
git commit -m <message>
git push
```

## LFS File 관리 해제하기

`.gitattributes`의 맨 마지막 라인을 보면 어떤 규칙으로 파일들이 lfs로 관리되고 있는지 볼 수 있다. 그리고 새로 track할 때와 마찬가지로 `git lfs untrack`을 할 때마다 `.gitattributes`의 내용이 변경된다. 이 작업도 파일이 unstaging 된 상태에서 진행해주어야 한다.

## LFS로 관리중인 File 다운로드 받기

단순히 git lfs로 관리중인 파일이 아래와 같이 lfs pointer만 가지고 있을 경우, `lfs pull` 명령어로 컨텐츠를 다운받아올 수 있다.

```
version https://git-lfs.github.com/spec/v1
oid sha256:265d20bff17c6e19af9c76ef9e00c89de14e34135e23ac2626f6db56e7fb3182
size 15927
```

`git lfs pull` --> 실제 파일 컨텐츠를 다운받음.

## LFS 파일 목록 확인

```sh
git lfs ls-files  # lfs로 관리중인 파일 목록 확인
```

## LFS를 subdir에 대하여 적용하기

```sh
git rm -r --cached "<file_path>/**/*"
git lfs track <file_path>/**/*      # 큰 따옴표 없이!
```

## LFS가 적용된 repo clone하기

git clone을 하고나서 pull이나 fetch를 해도 제대로 lfs가 동작하지 않고, pointer 정보만 가져오게 되므로, 이 때는 `git lfs pull`을 해주어야 한다.

```sh
git clone [url]
git lfs pull
```

## LFS migrate

lfs track로 파일을 추적하더라도, git의 history에 남아있는 파일들은 아직도 과거의 방식대로 기록이 되어있다. 이를 전부 git lfs로 바꾸는 방법은 오직 history rewrite 밖에는 방법이 없다. 그래서 이러한 경우에 필요한 명령어가 바로 `git lfs migrate`이다.

```sh
git lfs migrate import --include="<file_path>/*"
git push
```

## 출처
https://newsight.tistory.com/330
https://velog.io/@shin6949/Git-LFS-%EC%82%AC%EC%9A%A9%ED%95%98%EA%B8%B0