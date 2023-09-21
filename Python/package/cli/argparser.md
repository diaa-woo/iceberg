[상위 문서로 이동](../../README.md)

# Argparser

`run.py`라는 파이썬 스크립트가 있을 때, 우리는 해당 파일을 명령 프롬프트에서 다음과 같이 실행 가능하다.

```sh
./run.py
```

만약 어떤 옵션에 따라서 파이썬 스크립트가 다르게 동작하도록 해주려면 아래처럼 명령행을 통해 이러한 인자를 받아야한다. 

```sh
./run.py -d 1 -f
```

이렇게 옵션을 넣으면 `run.py` 스크립트에서는 사용자가 입력한 명령행의 인자를 파싱한 후 인자 값에 따라 적당한 동작을 수행해줘야 한다. 이처럼 명령행의 인자를 파싱할 때 사용하는 모듈이 바로 `argparser`이다.

## 기초

아마도 가장 자주 사용하는 옵션의 형태는 다음과 같다. 여기서 `-d`는 어떤 추가 인자 값을 하나 받는 형태이고. `-f` 옵션은 더 이상 추가 인자는 필요없는 형태이다.

```sh
./run.py -d 1 -f
```

명령행을 파싱하기 위해 `argparse` 모듈을 임포트한다. 그리고 파싱할 인자를 `add_argument` 메서드를 통해 추가해준다. 이때 다음 사항에 주의해야 한다.

- 추가 옵션을 받는 경우 `action="store"`를 사용한다.
- 추가 옵션을 받지 않고 단지 옵션의 유/무만 필요한 경우 `action="store_true`를 사용한다.
- 사용자가 입력한 옵션 값은 `dest` 인자로 지정한 변수에 저장된다.

```py
# run.py
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("-d", "--decimal", dest="decimal", action="store")        # Extra Value
parser.add_argument("-f", "--fast", dest="fast", action="store_true")         # existence/nonexistence
args = parser.parse_args()

print(args.decimal)
print(args.fast)
```

위와 같이 작성한 후 아래와 같이 터미널에서 옵션 명령행을 입력해서 실행해보자.

```sh
./run.py -d 1 -f 
```

사용자가 입력한 `-d`, `-f` 옵션에 대해 파싱한 후 1과 `True` (`-f` 옵션이 존재하므로) 값을 `args` 객체에 저장하여 리턴시켜준다.

```
1           # args.deciaml
True        # args.fast
```

## command line argument를 사용하지 않기

말이 조금 이상하다만 `argparse`는 기본적으로 command line을 통해 입력되는 argument를 파싱할 수 있다. 그런데 간혹 어떤 파일에 이런 argument들이 저장되어 있고 해당 파일의 각 라인에 대해서 argument 파싱을 해야할 때가 있다. 이 경우 `parser.parse_args`의 인자로 리스트를 넘겨주면 된다.

```py
import argparse

parser = argparse.ArgumentParser()
parser.add_argument(dest="width", action="store")
parser.add_argument(dest="height", action="store")
parser.add_argument("--frames", dest="frames", action="store")
parser.add_argument("--qp", dest="qp", action="store")
parser.add_argument("--configure", action="store")

args = parser.parse_args(["64", "56", "--frames", "60", "--qp", "1", "--configure", "AI"])
print(args.width, args.height, args.frames, args.qp, args.configure)
```

## 출처
https://wikidocs.net/73785