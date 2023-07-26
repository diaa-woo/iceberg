# pexpect

**expect**란 스크립트 언어인 `TCL(Tool Command Language)`로 만든 **CLI 자동화 도구**이다.   
**pexpect**란 그 도구를 파이썬에서 사용 가능할 수 있도록 해준다.

일반 shell을 사용할 경우 consol창에 interactive하게 입력해야한다. 이 때문에 `subprocess` 모듈을 이용하여 모든 쉘 프로그래밍을 처리하기에는 한계가 있다. 이를 극복하게 해주는 모듈이 해당 모듈이며, 특정 문자열이 출력될때까지 기다렸다가 응답하는 형태의 처리가 가능하다.

## 주요 메소드

- `spawn(command)` : control을 child application으로 넘겨준다.
- `expect(pattern)` 화면에 pattern(문자 포맷)에 맞는 문자열이 나올때까지 기다린다.
- `sendline(str)` : 문자열을 입력한다.
- `interact()` : control을 다시 user에 넘겨준다.