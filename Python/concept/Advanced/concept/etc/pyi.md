

# PYI

## .pyi 파일이란?

PYI 파일은 인터페이스 구현을 위한 코드 스텁 참조를 포함하는 **Python Interface 정의 파일** 이다. 각 Python 모듈은 일반 Python 파일이지만 빈 메서드가 있는 `.pyi` 스텁으로 표시된다. `PYI` 파일의 구문은 일반 Python 모듈의 구문과 동일하다. 빈 메소드의 구현은 최종 사용자가 모듈이 작성된 특정 목표를 달성하도록 남겨둔다. PYI 파일은 프로그램의 완전한 구현을 포함하는 `py`파일과는 다르다. PYI파일은 웬만한 편집기에서 다 편집 가능하다.

## example

```py
# example.pyi
def get_focused() -> bool: ...
def get_pressed() -> str: ...
def get_mods() -> int: ...
```