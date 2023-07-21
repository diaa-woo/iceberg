# Subprocess

`subprocess` 모듈은 파이썬 프로그램 내에서 새로운 프로세스를 스폰하고 여기에 입출력 파이프를 연결하여 리턴코드를 휙득할 수 있도록 하는 모듈로, 다른 언어로 만들어진 프로그램을 통합, 제어할 수 있게 만드는 모듈이다. 이 모듈은 기존에 오래된 몇몇 모듈과 함수(`os.system`, `os.spawn*`)들을 대체하기 위해 만들어졌다. 

단순히 bash만을 사용할 수 있는 모듈일 줄 알았는데... 생각보다 강력한 모듈이었다. 잘만 사용하면 다른 언어의 코드를 실행시키고 결과값만 낼름 가져오는 형태를 취할 수도 있는, 기존 함수의 형태를 발전시킬 수 있는 나름 대단한 모듈이라고 생각한다.

## `Popen`

프로세스를 제어하는 또 하나의 역할이라고 생각하면 편하다. 단순히 쉘 명령어 전달 그 이상의 역할로 OS Process 제어 및 파이프라인 제공등의 역할을 해준다.

Popen 클래스는 인스턴스 초기화시에 여러가지 옵션들을 인자로 받을 수 있다. 

```py
class subprocess.Popen(args, bufsize=-1, excutable=None,
                       stdin=None, stdout=None, stderr=None,
                       preexec_fn=None, close_fds=None, shell=False,
                       cwd=None, env=None, universal_newlines=False,
                       startupinfo=None, creationflags=0, restoreflags=0,
                       restore_signals=True, start_new_session=False, pass_fds=()
                      )
```

`args`는 프로그램 인자의 리스트이거나, 단일 문자열이다.(만약 `shell` 값이 `True`라면 단일 문자열이어도 된다. 물론 보안상의 문제는 있지만.)

### 서브 프로세스의 입출력

`stdin`, `stdout`, `stderr`은 서브 프로세스의 표준 입출력 핸들러를 가르킨다. 이에 유효한 값은 `PIPE`나 `DEVNULL` 혹은 이미 존재하는 다른 파일 핸들러 및 파일 객체일 수 있다. `PIPI`를 넘기는 경우, 자식 프로세스에게 새로운 파이프가 생성되어 연결된다. 디폴트값은 `None`이며, 이 경우 리다이렉션이 일어나지 않고, 부모 프로세스(파이썬 프로그램 자신)의 입출력을 상속받는다. 참고로 `stderr`에는 `STDOUT`을 줄 수 있는데, 이렇게 하여 에러 문구를 표준 출력으로 받을 수는 있다.

### 문자열 출력에 대한 변환

`universal_newlines`는 라인엔딩 변환을 하느냐 않하느냐 차이를 보이는데, 이 값이 `True`이면 문자열을 주고 받게 되므로, 파일 겍체를 파이프연결한 경우 이 값은 `False`가 되어야 한다. 개행 문자는 플랫폼마다 다른데, 이 값이 `True`로 넘어가는 경우, `os.linesep`을 사용하여 개행 문자를 변환하게 된다.
`shell` 파라미터 값이 True인 경우, 주어진 명령을 쉘을 통해서 처리한다. 이는 쉘 스크립트 대신 파이썬 스크립트를 통해서 배치 명령의 흐름을 제어하고자 할 때 유용하다. 이 기능을 사용하면 파일 이름 와일드카드나, 환경변수 확장 등의 쉘 기능을 이용할 수 있다. `glob`, `fnmath`, `os.walk()`, `os.path.expandvars()`, `os.path.expanduser()`, `shutil` 등의 모듈, 함수를 참고할 것

### 컨텍스트 매니저

`Popen` 객체는 컨텍스트 매니저 프로토콜을 구현하고 있어서 `with` 구문에 사용될 수 있다. 빠져나오는 경우 표준 파일 디스크립터는 닫히게 되고, 프로세스를 기다린다.

```py
with Popen(["ifconfig"], stdout=PIPE) as proc:
    log.write(proc.stdout.read())
```

### Popen 객체의 메소드들

다음 메소드들은 `Popen` 생성자를 이용해서 만든 객체가 제공하는 메소드들이다.

`.poll()`: 자식 프로세스가 종료되었는지를 확인한다.
`.wait(timeout=None)`: 자식 프로세스가 종료되길 기다린다. 자식 프로세스의 리턴 코드를 돌려준다.
`.communicate(input=None, timeout=None)`: 자식 프로세스의 표준 입력으로 데이터를 보낸다음, 표준 출력의 EOF르 만날 때까지 이를 읽어온다. (프로세스가 끝날 때까지 기다린다.) 이 함수는 (stdout_data, stderr_data)의 튜플을 리턴한다. 이 함수를 사용하려면 stdin=PIPE 옵션으로 자식 프로세스를 시작해야 한다.
`Popen.send_signal(signal)`: 자식 프로세스에 시그널을 보낸다.
`Popen.terminate()`: 자식 프로세스에 종료 시그널을 보낸다.
`Popen.kill()`: 자식 프로세스를 강제로 죽인다.
`Popen.args`: 주어진 args 를 리턴한다.
`Popen.stdin`: 만약 PIPE라면 이 객체는 읽고 쓸 수 있는 스트림 객체이다.
`Popen.stdout`: PIPE라면 읽을 수 있는 객체이다.
`Popen.stderr`: PIPE라면 읽을 수 있는 객체이다.
`Popen.pid`: 자식 프로세스의 pid값
`Popen.returncode`: 자식 프로세스가 종료되었을 때 리턴코드 값을 가진다.

## `subprocess.run`

이전에는 여러 함수들이 존재하였는데, python `3.5` 버전 이후 여러 함수들의 기능들이 통합되었다고 한다.   
`subprocess.run()` 함수는 기존의 api와 비슷하게 내부적으로는 `Popen()`을 사용하며, `subprocess.call()`에 익숙하다면 큰 어려움이 없다고 한다.

이전 api와 달리, 완료된 프로세스의 정보를 담은 객체를 리턴하며, 여기서 실행한 명령과 종료 코드를 볼 수 있따. 자식 프로세스가 화면에 출력하는 글자들은 똑같이 화면으로 출력된다. 단 여기서 `capture_output` 옵션을 사용하면, 리턴되는 객체가 출력된 내용을 캡쳐해 두게 된다.

`run()` 함수 호출시에 사용할 파라미터
- 실행할 명령: 문자열 혹은 문자열의 연속열
- `stdin=`: 표준 입력으로 데이터를 넣어줄 객체
  - 기본적으론 바이너리 모드지만, `encoding=` 인자가 넘겨진 경우에는 텍스트 모드로 취급
- `input=`: 표준 입력으로 전달해 줄 데이터.
  - 기본적으론 바이트스트림이지만, `encoding=` 옵션이나 `text=True`로 전달했다면 문자열을 전달할 수 있다.
- `stdout=`: 표준 출력의 내용을 전달할 IO 객체
  - `subprocess.PIPE`를 전달하여 캡쳐 가능
- `stderr=`: 표준 오류의 내용을 전달할 IO 객체
  - `subprocess.PIPE`를 전달하여 캡쳐하거나, `subprocess.STDOUT`을 전달하여 표준 출력과 하나로 병합하는 방법도 존재
- `capture_output=`: `True`를 전달하는 경우, 표준출력과 표준에러를 각각 `stdout`, `stderr`으로 캡처
- `shell=`: `True`를 전달하면 별도의 쉘 실행, 그 위에서 명령 실행
  - 다만 보안적인 부분이 존재해 책임은 전적으로 개발자에게 있음!
- `timeout=`: 만료시간 제한
  - 만료시간 지날 시 자식 프로세스를 죽이며, 그 뒤 `TimeoutExpired` 예외 발생
- `check=`: `True`로 전달시 자식 프로세스의 리턴 코드가 9ㅇ이 아니라면 `CalledProcessError` 예외를 일으킨다.
- `encoding=`: 표준출력 및 표준오류의 인코딩
  - 이 값이 있으면 출력 내용은 문자열로 열린다.
- `errors`, `text=` : 표준 오류 및 표준 출력을 텍스트 모드로 열 것인지를 결정하는 bool 값
- `env=`: 새 프로세스의 환경 변수를 정의하는 맵핑
- `universal_newlines`
- 그 외 키워드 인자 : `popen()` 함수의 키워드 인자로 전달

### 호출 결과

자식 프로세스의 리턴 코드를 확인하거나, 출력 내용을 리턴받는 건 `CompleteProcess` 클래스의 인스턴스이다.

객체 속성
- `args`: 프로세스를 시작하는 데 사용된 인자
- `returncode` : 자식 프로세스가 리턴한 코드
- `stdout`: 자식 프로세스의 표준 출력을 캡쳐한 내용
- `stderr`: 자식 프로세스의 표준 오류를 캡쳐한 내용
- `check_returncode()`: `returncode` 속성이 0이 아니면 `CalledProcessError` 예외 일으킴

## 출처

https://soooprmx.com/python-subprocess-1