# 카메라 출력

OpenCV를 이용하면 카메라 출력을 쉽게 할 수 있다.
카메라 출력은 카메라가 `스트리밍 형태`로 동작할 수 있을 때 사용된다.   

여기서 말하는 스트리밍 형태란 저장된 이미지나 동영상 파일이 아니라 __데이터를 실시간으로 받아오고 분석해야 하는 경우__ 카메라를 이용해 데이터를 처리해주는 경우를 말한다.

카메라를 사용해 데이터를 받아오기 때문에 연결된 카메라의 장치 번호를 통해 받아오며, 사용중인 플랫폼에서 카메라에 대한 접근 권한이 허용되어야 한다.   
-> ex) 권한과의 전쟁 Linux

## 메인 코드

```Python
import cv2

capture = cv2.VideoCapture(0)
capture.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
capture.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

while cv2.waitKey(33) < 0 :
  ret, frame = capture.read()
  cv2.imshow("VideoFrame", frame)

capture.release()
cv2.destroyAllWindows()
```

## 코드 설명

### Video 캡처

```python
# cv2.VideoCatpture(index)

capture = cv2.VideoCapture(0)
```
`비디오 출력 클래스(cv2.VideoCapture)`를 통해 내장 카메라 또는 외장 카메라에서 정보를 받아올 수 있다.

`cv2.VideoCapture(index)`로 카메라의 __장치 번호(ID)__와 연결한다. `index`는 **카메라의 장치번호**를 의미한다.

노트북의 경우, 일반적으로 내장 카메라가 존재하므로 노트북 카메라의 장치 번호는 `0`이 된다.

허나 카메라를 추가적으로 연결하여 **외장 카메라**를 사용하는 경우, 장치 번호가 `1_n`까지 순차적으로 할당된다. (찾는 방법을 안알려주는거 보니 아마 1부터 시작하거나 녹아다로 찾아내시라는 거 같다...)

### 카메라 세팅

```python
# capture.set(propid, value)

capture.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
capture.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
```

`카메라 속성 설정 메서드(capture.set)`로 카메라의 속성을 설정한다.

`capture.set(propid, value)`로 카메라의 속성(propid)과 값(value)을 설정할 수 있다.

`propid`는 변경하려는 **카메라 설정**을 의미한다.

`value`는 변경하려는 카메라 설정의 **속성값**을 의미한다.

### 지속 출력

```python
while cv2.waitKey(33) < 0 :
  ret, frame = capture.read()
  cv2.imshow("VideoFrame", frame)
```

`반복문(While)`을 활용하여 카메라에서 프레임을 지속적으로 받아와준다.

`키 입력 대기 함수(cv2.waitkey)`는 지정된 시간 동안 키 입력이 있을 때까지 프로그램을 지연시킨다.

`cv2.waitkey(delay)`로 키 입력을 기다린다. `delay`는 **지연 시간**을 의미한다.

이 시간의 단위는 밀리초 단위이며, 이 시간 동안 키 입력을 기다리고 입력이 없을 경우 다음 구문을 실행한다.

키 입력 대기 함수는 입력된 키의 **아스키 코드 값**을 반환한다.

즉, 어떤 키라도 입력되기 전까지 33ms마다 반복문을 실행한다.

- `delay`가 **0**일 경우, 지속적으로 키 입력을 검사하여 __프레임이 넘어가지 않는다.__
- `while cv2.waitKey(33) != ord('q') :`으로 사용할 경우, `q`가 입력될 때 `while`문을 종료한다.  

<br/>

`프레임 읽기 메서드(capture.read)`를 이용하여 `카메라의 상태` 및 `프레임`을 받아온다.

`ret`은 카메라의 상태가 저장되며 정상 작동할 경우 `True`를 반환한다. 작동하지 않을 경우 `False`를 반환한다.

`frame`에 현재 시점의 프레임이 저장된다.

<br/>

`이미지 표시 함수(cv2.imshow)`를 이용하여 특정 __윈도우 창__에 __이미지__를 띄운다.

`cv2.imshow(winname, mat)`으로 `윈도우 창의 제목`과 `이미지`를 할당한다.

`winname`은 문자열로 표시하며, 할당한 문자열이 변수와 비슷한 역할을 한다.

`mat`은 이미지를 의미하며, 윈도우 창에 할당한 이미지를 의미한다.

__VideoFrame__ 이름을 갖는 윈도우 창에 프레임이 표시된다.

### 프로그램 종료

```python
capture.release()
cv2.destoryAllWindows()
```

`메모리 헤제 메서드(capture.release())`로 카메라 장치에서 받아온 __메모리를 헤제한다__

`모든 윈도우 창 제거 함수(cv2.destoryAllWindows)`를 이용하여 모든 윈도우 창을 닫는다.

만약, 특정 윈도우 창만 닫는다면, `cv2.destoryWindow(winname)`으로 __특정 윈도우 창만 닫을 수 있다__