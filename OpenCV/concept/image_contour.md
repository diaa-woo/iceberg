[상위 문서로 이동](../README.md)

# Image Contour

Contour란 같은 값을 가진 곳을 연결한 선이라고 생각하면 된다. 우리 주위에 자주 접할 수 있는 Contour의 예로 지도에서 같은 높이를 가진 지점을 연결한 등고선, 기상도에서 같은 기압을 가진 곳을 연결한 등압선 등이 있다.

<img src="https://postfiles.pstatic.net/20151027_27/samsjang_1445912220279mJiyJ_PNG/oobcontour_2.png?type=w2">

이미지 Contour란 동일한 색 또는 동일한 색상 강도(Color Intensity)를 가진 부분의 가장 자리 경계를 연결한 선이다. 이미지에 있는 물체의 모양 분석이나 객체 인식 등에 유용하게 활용되는 도구이다.

보다 정확한 이미지 Contour를 확보하기 위해 바이너리 이미지를 사용한다. 즉, 이미지에서 Contour를 찾기 전에 `threshold`나 `canny edge detection`을 적용하는 것이 좋다.

OpenCV의 `cv2.findContours()` 함수는 *Suzuki85* 라는 알고리즘을 이용해서 Contour를 찾는 함수이다. 이 함수는 원본 이미지를 변경시키기 때문에 향후 원본이미지를 활용하기 위해서 원본 이미지의 복사본을 가지고 Contour를 찾도록 하는 것이 좋다.

주의할 점은 **검정색 배경에서 흰색 물체를 찾는 것** 과 비슷하기에 **Contour를 찾고자 하는 대상은 흰색으로, 배경은 검정색으로 변경해야 한다!**

## 예제

```py
import numpy as np
import cv2

def contour():
      img = cv2.imread('globe.jpg')
      imgray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

      ret, thr = cv2.threshold(imgray, 127, 255, 0)
      contours, _ = cv2.findContours(thr, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

      cv2.drawContours(img, contours, -1, (0, 0, 255), 1)
      cv2.imshow('thresh', thr)
      cv2.imshow('contour', img)

      cv2.waitKey(0)
      cv2.destroyAllWindows()

contour()
```

## 함수 설명

### cv2.findContours()

```py
cv2.findContours(thr, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
```

Input: 세 개의 인자를 필요로 한다.
- `thresh`: contour 찾기를 할 소스 이미지. thresholding을 통해 변환된 바이너리 이미지어야 함.
- `cv2.RETR_TREE`: 두 번째 인자는 *contour* 추출 모드이며, 2번째 리턴값인 *hierarchy* 의 값에 영향을 줌
  - `cv2.RETR_EXTERNAL`: 이미지의 가장 바깥쪽의 contour만 추출
  - `cv2.RETR_LIST`: contour간 계층구조 상관관계를 고려하지 않고 contour만 추출
  - `cv2.RETR_CCOMP`: 이미지에서 모든 contour를 추출한 후, 2단계 contour 계층 구조로 구성함. 1단계 계층에서는 *외곽 경계* 부분을, 2단계 계층에서는 *구멍(hole)의 경계 부분* 을 나타내는 contour로 구성됨
- `cv2.CHAIN_APPROX_SIMPLE`: 세 번째 인자는 contour 근사 방법
  - `cv2.CHAIN_APPROX_NONE`: contour을 구성하는 모든 점을 지정
  - `cv2.CHAIN_APPROX_SIMPLE`: contour의 수평, 수직, 대각선 방향의 점은 모두 버리고 끝 점만 남겨둠. 예를 들어 똑바로 세워진 직사각형의 경우, 4개의 모서리 점만 남기고 다 버림
  - `cv2.CHAIN_APPROX_TC89__1`: `Teh-Chin 연결 근사 알고리즘`(Ten-Chin chain approximation algorithm) 적용

여기서 *근사(알고리즘)* 란 어떤 최적화 문제에 대한 해의 근사값을 구하는 알고리즘을 의미한다. 즉 참값에 가까운 수를 리턴한다는 것이다. 
  
Return: `thr`, 이미지에서 찾은 `contour`와 `contour들 간의 계층 구조`를 리턴한다. 

### cv2.drawContours()

```py
cv2.drawContours(img, contours, -1, (0, 255, 0), 3)
```

`cv2.drawContours()` 함수는 찾은 contour를 실제로 그리는 함수이며, 5개의 인자를 가진다.
- `img`: contour를 나타낼 대상 이미지
- `contours`: img에 그릴 contour. 이 값은 `cv2.findContours()` 함수의 2번째 리턴 값으로 리스트형 자료임. i번째 contour의 첫 번째 픽셀 좌표는 `contours[i][0]`과 같이 접근 가능
- `-1` : img에 실제로 그릴 contour 인덱스 파라미터. 이 값이 음수이면 모든 contour를 그림
- `(0, 255, 0)`: contour선의 BGR 색상값. 여기서는 Green으로 지정.
- `1`: contour 선의 두깨

## 이미지 상의 객체들에 대한 주요 속성 도출

객체들의 주요 속성
- Aspect Ratio(종횡비; 가로 세로 비율)
- Extent
- Solidity
- Equivalent Diameter
- Orientation
- Mask and Pixel Points
- Mean Color/Mean Intensity
- Extreme Points

### Aspect Ratio - 종횡비
주어진 Contour의 외접하는 직사각형(Bounding Rect)을 구한 후 이 직사각형의 폭과 높이를 이용해서 `Aspect Ratio`의 값을 구한다.

$Aspect\,Ratio=\frac{Width}{Height}$

```py
x,y,w,h = cv2.boundingRect(cnt)
aspect_ratio = float(w)/h
```

### Extent - 범위 & 넓이
Contour의 넓이와 Contour의 외접 직사각형 넓이의 비

$Extent = \frac{Object\,Area}{Bounding\,Rectangle\,Area}$

```py
area = cv2.contourArea(cnt)
x,y,w,h = cv2.boundingRect(cnt)
rect_area = w*h
extent = float(area)/rect_area
```

### Solidity - 견고성
Contour의 넓이와 이 Contour의 Convex Hull 넓이의 비

$Solidity = \frac{Contour\,Area}{Convex\,Hull\,Area}$

```py
area = cv2.contourArea(cnt)
hull = cv2.convexHull(cnt)
hull_area = cv2.contourArea(hull)
solidity = float(area)/hull_area
```

### Equivalent Diameter
Contour의 넓이와 동일한 넓이를 가진 원의 지름

$Equivalent\,Diameter=\sqrt{\frac{4 \times Contour\,Area}{\pi}}$

```py
area = cv2.contourArea(cnt)
equivalent_diameter = np.sqrt(4*area/np.pi)
```

### Orientation
객체가 향하고 있는 방향

```py
(x,y), (MajorAxis, MinorAxis), angle = cv2.fitEllipse(cnt)
```

### Mask & Pixel Points
가끔 객체를 구성하는 모든 점들, 다시 말하면 모든 픽셀들의 좌표를 추출할 필요가 있다. 이럴 경우 `cv2.findNonZero()` 함수를 이용하는데, 아래와 같은 방법으로 활용한다.

```py
mask = np.zeros(imgray.shape, np.uint8)
cv2.drawContours(mask, [cnt], 0, 255, -1)
pixels = cv2.findNonZero(mask)
```

### Mean Color/Mean Intensity

Contour 내의 평균 색상, Gray Scale 이미지일 경우 평균 intensity 값을 찾기 위해 `cv2.mean()` 함수를 활용하면 된다. 위 예제에서 활용된 mask를 그대로 활용한다.

```py
mean_value = cv2.mean(img, mask=mask)
```

## 예제

```py
import numpy as np
import cv2

def convex():
      img = cv2.imread("korea.png")
      imgray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

      ret, thr = cv2.threshold(imgray, 127, 255, 0)
      contours, _ = cv2.findContours(thr, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

      # 한반도에 해당하는 Contour -> 가변임. 바꿔야 함.
      cnt = contours[18]

      # 무게 중심 (cx, cy)
      mmt = cv2.moments(cnt)
      cx = int(mmt['m10']/mmt['m00'])
      cy = int(mmt['m01']/mmt['m00'])

      x, y, w, h = cv2.boundingRect(cnt)
      korea_rect_area = w*h
      korea_area = cv2.contourArea(cnt)
      hull = cv2.convexHull(cnt)
      hull_area = cv2.contourArea(hull)
      ellipse = cv2.fitEllipse(cnt)

      aspect_ratio = w/h
      extent = korea_area/korea_rect_area
      solidity = korea_area/hull_area

      print('Aspect Ratio: \t%.3f' % aspect_ratio)
      print('Extent:\t%.3f' % extent)
      print('Solidity:\t%.3f'%solidity)
      print('Orientation:\t%.3f' % ellipse[2])

      equivalent_diameter = np.sqrt(4*korea_area/np.pi)
      korea_radius = int(equivalent_diameter/2)

      cv2.circle(img, (cx, cy), 3, (0,0,255), -1)
      cv2.circle(img, (cx, cy), korea_radius, (0,0,255), 2)
      cv2.rectangle(img, (x,y), (x+w, y+h), (0, 255, 0), 2)
      cv2.ellipse(img, ellipse, (50, 50, 50), 2)

      cv2.imshow("Korea Features", img)
      cv2.waitKey(0)
      cv2.destroyAllWindows()

convex()
```

참고로 옛날 자료라 그런지 코드가 제대로 동작하지는 않는다..

## 출처
https://blog.naver.com/samsjang/220516697251