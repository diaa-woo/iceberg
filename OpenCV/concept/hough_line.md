[상위 문서로 이동](../README.md)

# 직선 검출 - Line Detection

직선 검출 알고리즘은 *허프 변환(Hough Transform)* 을 활용해 직선을 검출한다. 허프 변환은 이미지에서 직선을 찾는 가장 보편적인 알고리즘이며, 이미지에서 선과 같은 단순한 형태를 빠르게 검출할 수 있고, 직선을 찾아 이미지나 영상을 보정하거나 복원한다.

허프 선 변환은 이미지 내의 **어떤 점이라도 선 집합의 일부일 수 있다는 가정** 하에 직선의 방정식($y=ax+b$)을 이용해 직선을 검출한다. (극좌표($p, \theta$)의 점으로 변환해서 사용)

극좌표 방정식으로 변환한다면 $p=x\sin{\theta}+y\cos{\theta}$이 되어, 직선과 원점의 거리($p$)와 직선과 x축이 이루는 각도($\theta$)를 구할 수 있다.

## 표준 허프 변환(Standard Hough Transform) & 멀티 스케일 허프 변환(Multi-Scale Hough Transform)

### 표준 허프 변환

<img src="https://076923.github.io/assets/posts/Python/OpenCV/lecture-28/2.webp">

표준 허프 변환은 **입력 이미지(x, y 평면)** 내의 점 $p$를 지나는 직선의 방정식을 구한다. 한 점을 통과하는 직선의 방정식을 구하면 기울기 $a$와 절편 $b$를 구할 수 있다. 점 $p$에 대해 직선의 방정식을 수식으로 표현하면 그림 (a)와 같이 $y=ax+b$로 표현할 수 있다.

모든 점에 대해 모든 직선의 방정식을 구한다면 **평면상에서 점들의 궤적이 생성되며, 동일한 궤적 위의 점은 직선으로 볼 수 있다.** 

하지만, 한 점을 지나는 모든 직선의 방정식을 표현한다면 그림 (b)와 같이 기울기 $a$는 음의 무한대($-\infty$)에서 양의 무한대($\infty$)의 범위를 갖는다. 또한, 수평인 영역에서 기울기 $a$는 0을 갖는다. 기울기와 절편을 사용해 모든 직선의 방정식을 표현하는 것은 좋은 방식이 아니므로, *삼각함수* 를 활용해 각 선을 극좌표($p,\theta$)의 점으로 변환해서 나타낸다.

### 멀티 스케일 허프 변환

표준 허프 변환을 개선한 방법이다. 검출한 직선의 값이 더 정확한 값으로 반환되도록, 거리($p$)와 각도($\theta$)의 값을 조정해 사용한다. 두 값을 조정하는 방법으로 조금 더 우수한 검출을 할 수 있다.

### 메인 코드

```py
import numpy as np
import cv2

src = cv2.imread("road.jpg")
dst = src.copy()
gray = cv2.cvtColor(src, cv2.COLOR_BGR2GRAY)
canny = cv2.Canny(gray, 5000, 1500, apertureSize=5, L2gradient=True)
lines = cv2.HoughLines(canny, 0.8, np.pi/180, 150, srn=100, stn=200, min_theta=0, max_theta=np.pi)

for i in lines:
      rho, theta = i[0][0], i[0][1]
      a, b = np.cos(theta), np.sin(theta)
      x0, y0 = int(a*rho), int(b*rho)

      scale = src.shape[0] + src.shape[1]

      x1 = int(x0 + scale * -b)
      y1 = int(y0 + scale * a)
      x2 = int(x0 - scale * -b)
      y2 = int(y0 - scale * a)

      cv2.line(dst, (x1, y1), (x2, y2), (0,0,255), 2)
      cv2.circle(dst, (x0, y0), 3, (255, 0, 0), 5, cv2.FILLED)

cv2.imshow("dst", dst)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

### 세부 코드

```py
src = cv2.imread("road.jpg")
dst = src.copy()
gray = cv2.cvtColor(src, cv2.COLOR_BGR2GRAY)
canny = cv2.Canny(gray, 5000, 1500, apertureSize=5, L2gradient=True)
```

이미지 전처리를 하는 과정이다. 원본과 복사본을 선언하고, *그레이스케일 이미지(gray)와 케니 엣지 이미지(canny)를 사용한다.* 케니 엣지 알고리즘의 임계값은 각각 5000과 1500로 주요한 가장자리만 남긴다. 커널은 5의 크기를 가지고 L2그라디언트를 True로 사용한다.

```py
lines = cv2.HoughLines(canny, 0.8, np.pi / 180, 150, srn = 100, stn = 200, min_theta = 0, max_theta = np.pi)
```

`cv2.HoughLines(검출 이미지, 거리, 각도, 임곗값, 거리 약수, 각도 약수, 최소 각도, 최대 각도)`를 이용하여 직선 검출을 진행한다.
- *거리* & *각도* 는 누산 평면에서 사용되는 해상도를 나타낸다.
  - *거리* 의 단위는 픽셀을 의미하며, **0.0 ~ 1.0의 실수 범위** 를 갖는다.
  - *각도* 의 단위는 라디안을 사용하며 **0 ~ 180** 의 범위를 갖는다.
- *임계값* 은 허프 변환 알고리즘이 직선을 결정하기 위해 만족해야 하는 누산 평면의 값을 의미한다.
  - 누산 평면은 각도 * 거리 의 차원을 갖는 **2차원 히스토그램으로 구성된다.**
- *거리 약수* 와 *각도 약수* 는 거리와 각도에 대한 약수(divisor)를 의미한다.
  - 두 값 모두 0의 값을 인수로 활용할 경우, **표준 허프 변환** 이 적용되며, 하나 이상의 값이 0이 아니라면 **멀티 스케일 허프 변환** 이 적용된다.
- *최소 각도* 와 *최대 각도* 는 검출할 각도의 범위를 설정한다.

참고로 누산 평면(Accumulator Plane)이란 **특정 연산을 수행하여 얻은 결과를 저장하기 위한 공간을 가리킨다.** 이 결과는 주로 특정 패턴, 객체, 또는 특징의 검출에 사용된다.

누산 평면은 2D 혹은 3D 매열로 표현되며, 주로 히스토그램, 누적합, 에지 감지 등의 연산에서 사용된다. 이러한 연산들은 이미지에서 특정 패턴을 찾거나 감지하기 위해 사용된다.

```py
for i in lines:
      rho, theta = i[0][0], i[0][1]
      a, b = np.cos(theta), np.sin(theta)
      x0, y0 = int(a*rho), int(b*rho)

      scale = src.shape[0] + src.shape[1]

      x1 = int(x0 + scale * -b)
      y1 = int(y0 + scale * a)
      x2 = int(x0 - scale * -b)
      y2 = int(y0 - scale * a)

      cv2.line(dst, (x1, y1), (x2, y2), (0, 0, 255), 2)
      cv2.circle(dst, (x0, y0), 3, (255, 0, 0), 5, cv2.FILLED)
```

검출을 통해 반환되는 `lines` 변수는 (N, 1, 2)차원 형태를 갖는다. 내부 차원의 요소로는 검출된 거리(`rho`)와 각도(`theta`)가 저장되어 있다.

반복문을 활용해 `lines` 배열에서 **거리** 와 **각도** 를 반환할 수 있으며, 거리와 각도를 다시 직선의 방정식의 형태로 구성해야 결과 이미지 위에 표현할 수 있다.

`x`와 `y`는 각각 $x=r\cos{\theta}, r=\sin{\theta}$ 의 형태를 가지므로, 이 수식을 활용해 $x0$와 $y0$의 좌표를 구한다.

허프 변환 함수는 시작점과 도착점을 알려주는 함수가 아닌, **가장 직선일 가능성이 높은 거리와 각도를 검출한다!** 해서 검출된 정보는 직선의 방정식에 더 가깝기에, 출력 이미지 위에 표현하기 위해 $x0$와 $y0$를 직선의 방정식 선분을 따라 평행이동시켜 선을 그린다

`scale`에 적절한 값을 지정해 이미지 밖으로 $x1,y1,x2,y2$를 할당한다.

선 그리기 함수(`cv2.line`)와 원 그리기 함수(`cv2.circle`)를 활용해 (x1, y1) ~ (x2, y2)와 (x0, y0)의 위치를 표시한다.

## 점진성 확률적 허프 변환(Progressive Probabilistic Hough Transform)

점진성 확률적 허프 변환은 또다른 허프 변환 함수를 사용해 직선을 검출한다. 앞선 알고리즘은 모든 점에 대해 직선의 방정식을 세워 계산하기 때문에 비교적 많은 시간이 소모된다. 허나 이 허프 변환은 *앞선 알고리즘을 최적화한 방식* 이다. 모든 점을 대상으로 직선의 방정식을 세우는 것이 아닌, **임의의 점 일부만 누적해서 계산한다.** 때문에 **확률적이다.** 그러므로, 정확도가 높은 입력 이미지에 대해 검출에 드는 시간이 대폭 줄어든다. 

또한 이 알고리즘은 시작점과 끝점을 *반환* 하므로 더 간편하게 사용할 수 있다.

### 메인 코드

```py
import numpy as np
import cv2

src = cv2.imread("road.jpg")
dst = src.copy()
gray = cv2.cvtColor(src, cv2.COLOR_BGR2GRAY)
canny = cv2.Canny(gray, 5000, 1500, apertureSize = 5, L2gradient = True)
lines = cv2.HoughLinesP(canny, 0.8, np.pi / 180, 90, minLineLength = 10, maxLineGap = 100)

for i in lines:
    cv2.line(dst, (int(i[0][0]), int(i[0][1])), (int(i[0][2]), int(i[0][3])), (0, 0, 255), 2)

cv2.imshow("dst", dst)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

### 세부 코드

```py
lines = cv2.HoughLinesP(canny, 0.8, np.pi/180, 90, minLineLength=10, maxLineGap=100)
```

`cv2.HoughLinesP(검출 이미지, 거리, 각도, 임곗값, 최소 선 길이, 최대 선 간격)` 를 이용하여 직선 검출을 진행한다.
- *검출 이미지* , *거리* , *각도* , *임곗값* 은 앞선 허프 변환 알고리즘 함수와 동일한 의미를 갖는다.
- *최소 선 길이* 는 검출된 직선이 가져야 하는 **최소한의 선 길이** 를 의미한다. 이 값보다 낮은 경우 직선으로 간주하지 않는다.
- *최대 선 간격* 은 검출된 직선들 사이의 **최대 허용 간격** 을 의미한다. 이 값보다 간격이 좁은 경우 직선으로 간주하지 않는다.

```py
for i in lines:
      cv2.line(dst, (int(i[0][0]), int(i[0][1])), (int(i[0][2]), int(i[0][3])), (0, 0, 255), 2)
```

검출을 통해 반환되는 `lines` 변수는 (N, 1, 4)차원 형태를 갖는다. 마지막 차원에서는 x1, y1, x2, y2의 순서로 *시작점* 과 *끝점* 을 표시한다. 별도의 계산 없이 선 그리기 함수(`cv2.circle()`)를 활용해 (x1, y1) ~ (x2, y2)의 위치를 표시한다.

## 출처
https://076923.github.io/posts/Python-opencv-28/