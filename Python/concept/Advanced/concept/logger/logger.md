[상위 문서로 이동](../../README.md)

# Python Logger

## Introduction

> The only time that print is a better option than logging is when the goal is to display a help statement for a command line application.

Shell과 같은 커맨드 인터페이스에서 `--help` 옵션을 받아 **사용법 도움말** 을 출력할 때 이외에는 항상 **logging** 이 **print** 보다 낫다는 뜻으로, 사실상 웬만한 상황에서는 **print 대신 logging을 사용하는 것이 낫다** 는 의미이다.

그 이유는 아래와 같은 내용을 들고 있다.

- The log record, which is created with every logging event, contains readily available diagnostic information such as the file name, full path, function, and line number of the logging event.
- Events logged in included modules are automatically accessible via the root logger to your application’s logging stream, unless you filter them out.
- Logging can be selectively silenced by using the method logging.Logger.setLevel() or disabled by setting the attribute logging.Logger.disabled to True.

정리하자면,
- 로깅 이벤트를 통해 생성되는 **로그 기록** 에는 파일명, 파일 경로, 함수명이나 라인 넘버 등 로깅 이벤트 발생 시점의 정보가 자세히 담겨 있어 **프로그램 사후 진단** 이 편하고,
- 사용하고 있는 하위 모듈에서 발생하는 로깅 이벤트들도 쉽게 접근할 수 있으며,
- 로깅 레벨 설정 등을 통해 기록될 로그를 **선택적으로 필터링** 할 수 있다는 것이다.

터미널 콘솔 창에 맥락 없이 주르르 떠 있는 print 내용을 보면서 문제를 파악하고 필요에 따라 프린트 구문을 넣었다 지웠다 하기보단, 로거를 통해 **체계적으로** 어플리케이션 실행 상태를 기록하고 선택적으로 필터링해 볼 수 있게 만드는 편이 장기적으로는 나을 것이다.

## Getting Started

```py
import logging

logging.warning('Watch out!')   # will print a message to console
logging.info('I told you so')   # will not print anything
```

**logging** built-in 모듈을 임포트하고 logging.warning, logging.info 등의 함수를 이용해 로그 메시지를 출력할 수 있다. 로그를 출력할 때 사용되는 메소드 이름인 warning, info는 **출력될 로그의 레벨** 을 의미하는데, 예를 들면 logging.warning 함수로 출력하는 메시지는 `logging.WARNING`의 로그 레벨을 가지게 된다.

여기서, 로그 레벨의 용도는 뭘까?

### Log Levels

로그는 아래 목록 중 하나의 레벨을 가지며, 각 레벨의 로그는 각기 다른 용도를 지니고 있다.

- <span style="background-color:lightgray;font-weight:bold">DEBUG</span>: 프로그램 작동에 대한 상세한 정보를 가지는 로그. 문제의 원인을 파악할 때에만 이용.
- <span style="background-color:skyblue;font-weight:bold">INFO</span>: 프로그램 작동이 예상대로 진행되고 있는지 트래킹하기 위해 사용.
- <span style="background-color:pink;font-weight:bold">WARNING</span>: 예상치 못한 일이나 추후 발생 가능한 문제를 표시하기 위함.
- <span style="background-color:orange;font-weight:bold;color:white">ERROR</span>: 심각한 문제로 인해 프로그램이 의도한 기능을 수행하지 못하고 있는 상황을 표시.
- <span style="background-color:red;font-weight:bold;color:white">CRITICAL</span>: 더욱 심각한 문제로 인해 프로그램 실행 자체가 언제라도 중단될 수 있음을 표시.

로거 설정 시 레벨을 지정해 주면 해당 레벨 이상의 (더 심각한 쪽으로) 로그 이벤트만이 기록된다. 디폴트로 설정되는 로그 출력 레벨은 **WARNING** 으로, WARNING 이상의 심각도를 가지는 이벤트만 트래킹 되도록 세팅된다. 따라서 위의 예제를 실행하면, INFO 로그 이벤트는 출력되지 않고 *"Watch out!"* 구문만이 출력된다.

```
WARNING:root:Watch out!
```

### Log to File

그런데 위와 같이 출력만 하기보다는 프로그램 실행 중에 로그 이벤트들이 파일의 형태로 저장이 된다면 더 좋을 것이다. 텍스트 파일의 형태로 저장이 되면 터미널 스크롤을 한참 올리거나 원하는 내용을 찾아 헤메는 등의 수고를 덜 수 있다.

```py
import logging
logging.basicConfig(filename="example.log", level=logging.WARNING)
logging.debug('This message should go to the log file')
logging.info('So should this')
logging.warning('And this, too')
logging.error('And non-ASCII stuff, too, like Øresund and Malmö')
```

`logger.basicConfig` 함수에서 로그가 저장될 위치와 저장할 로그 레벨 임계값을 설정해 두면, 이후의 로그 이벤트들이 필터링되어 로그 파일에 기록된다. 이 함수는 따로 호출해 놓지 않았다면 debug, info 등과 같은 함수들이 불릴 때 디폴트 세팅으로 자동 호출된다.

```log
WARNING:root:And this, too
ERROR:root:And non-ASCII stuff, too, like Øresund and Malmö
```

로거 레벨을 `WARNING`으로 해놓았기 때문에 `WARNING` 이상의 레벨을 가지는 로그들만 골라 기록된 것을 볼 수 있다. 만약 **모든 로그** 를 출력하고 싶다면 level을 `logging.DEBUG`로 설정해주면 된다. 반대로 정말 심각한 이벤트만 기록되게 하고 싶다면 `logging.ERROR`이나 `logging.CRITICAL`로 로거 레벨을 설정하자.

기본 설정에서는 이미 존재하는 동일 경로 로그 파일이 있다면, 내용을 덮어쓰지 않고 그 뒤에 쭉 append 되는데, 만약 이전의 기록을 날리고 **새로 작성** 하게 하고 싶다면 **filemod="w"** 옵션을 제공해 주자.

```py
logging.basicConfig(filename="example.log", filemod="w", level=logging.WARNING)
```

참고로, `logging.basicConfig` 함수는 오직 최초 한 번의 호출만이 유효하게 작동하며, 이후의 호출은 아무 기능을 하지 않는다.

### Log Formatting

```py
import logging

logging.basicConfig(
    format='%(asctime)s %(levelname)s:%(message)s',
    level=logging.DEBUG,
    datefmt='%m/%d/%Y %I:%M:%S %p',
)

logging.debug("Sample debug message")
```

`logging.basicConfig`에서 로그 이벤트의 출력 포맷을 설정하는 것도 가능하다. <span style="background-color:lightgray;font-weight:bold">format</span> 인자에 어떤 식으로 포맷팅 할 지 나타내는 스트링을 하나 제공해주면 된다. 위 예시에서는 현재 시간과 로그 이벤트 레벨, 그리고 로그 메시지를 출력하도록 세팅했다. 위 코드를 실행시키면 아래와 같이 결과가 출력된다.

```
10/25/2023 02:46:28 PM DEBUG:Sample debug message
```

예시에 쓰인 Attribute 외에도 PID등 다른 정보를 추가해 원하는 대로 로그 포맷을 설정할 수 있다. 사용 가능한 다른 Attribute들은 아래의 표를 참고하자.

| **어트리뷰트 이름** | **포맷** | **설명** |
| --- | --- | --- |
| **args** | 직접 포맷할 필요는 없습니다. | message를 생성하기 위해 msg에 병합되는 인자의 튜플. 또는 (인자가 하나뿐이고 딕셔너리일 때) 병합을 위해 값이 사용되는 딕셔너리. |
| **asctime** | %(asctime)s | 사람이 읽을 수 있는, LogRecord가 생성된 시간. 기본적으로 '2003-07-08 16:49:45,896' 형식입니다 (쉼표 뒤의 숫자는 밀리초 부분입니다). |
| **created** | %(created)f | LogRecord가 생성된 시간 (time.time()이 반환하는 시간). |
| **exc_info** | 직접 포맷할 필요는 없습니다. | 예외 튜플 (sys.exc_info에서 제공) 또는, 예외가 발생하지 않았다면, None. |
| **filename** | %(filename)s | pathname의 파일명 부분. |
| **funcName** | %(funcName)s | 로깅 호출을 포함하는 함수의 이름. |
| **levelname** | %(levelname)s | 메시지의 텍스트 로깅 수준 ('DEBUG', 'INFO', 'WARNING', 'ERROR', 'CRITICAL'). |
| **levelno** | %(levelno)s | 메시지의 숫자 로깅 수준 (DEBUG, INFO, WARNING, ERROR, CRITICAL). |
| **lineno** | %(lineno)d | 로깅 호출이 일어난 소스 행 번호 (사용 가능한 경우). |
| **message** | %(message)s | 로그된 메시지. msg % args로 계산됩니다. Formatter.format()이 호출될 때 설정됩니다. |
| **module** | %(module)s | 모듈 (filename의 이름 부분). |
| **msecs** | %(msecs)d | LogRecord가 생성된 시간의 밀리초 부분. |
| **msg** | 직접 포맷할 필요는 없습니다. | 원래 로깅 호출에서 전달된 포맷 문자열. args와 병합하여 message를 만듭니다. 또는 임의의 객체 (임의의 객체를 메시지로 사용하기를 보세요). |
| **name** | %(name)s | 로깅 호출에 사용된 로거의 이름. |
| **pathname** | %(pathname)s | 로깅 호출이 일어난 소스 파일의 전체 경로명 (사용 가능한 경우). |
| **process** | %(process)d | 프로세스 ID (사용 가능한 경우). |
| **processName** | %(processName)s | 프로세스 이름 (사용 가능한 경우). |
| **relativeCreated** | %(relativeCreated)d | logging 모듈이 로드된 시간을 기준으로 LogRecord가 생성된 시간 (밀리초). |
| **stack_info** | 직접 포맷할 필요는 없습니다. | 현재 스레드의 스택 바닥에서 이 레코드를 생성한 로깅 호출의 스택 프레임까지의 스택 프레임 정보 (사용 가능한 경우). |
| **thread** | %(thread)d | 스레드 ID (사용 가능한 경우). |
| **threadName** | %(threadName)s | 스레드 이름 (사용 가능한 경우). |

## Advanced Usage

위에서는 간단하게 로깅을 구현하고 싶을 때 사용할 수 있는 high-level 도구들을 소개했고, 아래에서부턴 구체적인 내용을 다룬다.

먼저 logging 라이브러리에는 크게 네 가지의 클래스가 존재한다.
- **Logger**
- **Handler**
- **Filter**
- **Formatter**

**Logger** 는 warning, info, setLevel과 같이 프로그램 쪽에서 접근할 수 있는 로깅 관련 인터페이스를 제공한다.    
**Handler** 는 로그 이벤트 출력을 특정한 파일이나 콘솔 출력, 혹은 네트워크 소켓 등 적절한 곳으로 로그를 보내주는 역할을 한다.   
**Filter** 는 단순한 레벨 수준을 통한 로그 필터링이 아닌, 더 심화된 로그 필터링을 설정할 때 사용된다.   
**Formatter** 는 로그 이벤트를 사람이 읽을 수 있는 형태로 변환해 주는 역할을 한다.

그리고 로그 이벤트 정보 자체는 라이브러리 내의 **LogRecord** 클래스 인스턴스의 형태로 각 컴포넌트 사이에서 전달된다.

## 출처
https://jh-bk.tistory.com/40