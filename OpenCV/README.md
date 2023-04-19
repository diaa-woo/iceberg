# OpenCV 공부

OpenCV는 __Open Source Computer Visible Library__의 약어로 컴퓨터 비전 라이브러라를 의미한다.
   
실시간 이미지 프로세싱에 중점을 두었으며, Open Source Licence는 BSD 라이선스를 사용하였다.

OpenCV는 계산 효율성과 실시간 처리에 중점을 두고 설계 되었으며
500가지가 넘는 알고리즘이 최적화돼 있으며 이 알고리즘을 구성하거나 지원하는 함수는 알고리즘 수의 10배가 넘는다고 한다.

물체 인식, 얼굴 인식, 제스처 인식을 비롯해 자율주행 자동차, OCR 판독기, 불량 검사기 등에 할 수 있다고 하는데, 우리는 한번 자율주행 자동차 분야에 적용해볼 생각이다. 

원래는 C가 주 개발언어였으나 2.0 부터는 C++이 주가 되었고, Python이 등장한 이후부터는 Python에서 엄청나게 많이 사용되는 추세이다.

나는 효율적인 마크다운 작성과 코드 작성을 위해 주피터 노트북 작성은 코랩으로 하되, 실제 개발환경은 가상환경을 따로 만들어서 동작한다

이 내용은 다음 포스트를 기반으로 작성하였다. 학습을 목적으로 적었기에 블로그 포스트는 따로 하지 않는다. : https://076923.github.io/posts/Python-opencv-1/

(EDIT) 나는 ubuntu 20.04 윈도우 환경을 번갈아가면서 사용하기에, ubuntu에선 상대경로가 되던게 윈도우에서는 안되는 경우가 있다. 그래서 OS가 다른 환경에서 사용할 때 경로 같은 OS적인 부분들을 잘 다뤄줘야 할 필요가 있어보인다.

## OpenCV 설치

OpenCV는 다음과 같은 패키지를 보유하고 있다.

```
opencv-python
opencv-contrib-python
opencv-python-headless
opencv-contrib-python-headless
```

`contrib`는 일반 opencv-python에서 확장 모듈을 설치하는 것이다.

`headless`는 GUI 종속 라이브러리가 없는 서버 환경(Docker, Cloud)에서 사용할 수 없는 환경에서 라이브러리를 제외하고 사용하는 것이다.

평범한 상황일 때는 `opencv-python`을 쓰도록 하자

설치는 pip를 통해서 하면 된다

```sh
pip3 install opencv-python
```

## 문서 바로가기

[카메라 출력](concept/Call_Camera.md)
[이미지 출력](concept/Call_Image.md)
[비디오 출력](concept/Call_Video.md)
[대칭](concept/Reverse.md)
[회전](concept/Rotate.md)
[확대/축소](concept/zoom.md)
[크기 조절](concept/resize.md)
[자르기](concept/Slice.md)
