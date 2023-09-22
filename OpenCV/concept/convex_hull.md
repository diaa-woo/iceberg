[상위 문서로 이동](../README.md)

# 블록 껍질

윤곽선(points, contours)의 **경계면을 둘러싸는 다각형** 을 구하는 알고리즘이다.

반환되는 결과는 윤곽선 검출 결과와 동일한 형식을 띄며, *스크랜스키(Sklansky) 알고리즘* 을 이용해 입력된 좌표들의 볼록한 외곽을 찾는다.

## 메인 코드

```py
import cv2

src = cv2.imread("img.jpg")
dst = src.copy()

gray = cv2.cvtColor(src, cv2.COLOR_RGB2GRAY)
ret, binary = cv2.threshold(gray, 150, 255, cv2.THRESH_BINARY_INV)

contours, hierarchy = cv2.findContours(binary, cv2.RETR_CCOMP, cv2.CHAIN_APPROX_NONE)

for i in contours:
      hull = cv2.convexHull(i, clockwise=True)
      cv2.drawContours(dst, [hull], 0, (0, 0, 255), 2)

cv2.imshow("dst", dst)
cv2.waitKey(0)
cv2.destroyAllWindows()
```

### 세부코드

```py
for i in contours:
      hull = cv2.convexHull(i, clockwise=True)
      cv2.drawContours(dst, [hull], 0, (0, 0, 255), 2)
```

`cv2.convexHull(contour(윤곽선), clockwise(방향))`를 활용해 윤곽선에서 **블록 껍질** 을 검출한다.
- `contour` : 윤곽선 검출 함수에서 반환되는 구조를 사용한다.
- `clockwise` : 검출된 블록 껍질의 볼록점들의 인덱스 순서를 의미한다.

블록 껍질 함수는 단일 형태에서만 검출이 가능하기에, 반복문을 활용해 단일 형태의 윤곽선 구조에서 블록 껍질을 검출한다.
- `contour` 구조는 윤곽선 검출 함수의 반환값과 형태가 동일하다면, 임의의 배열에서도 검출이 가능하다.
- `clockwise`가 True라면 *시계 방향* , False라면 *반시계 방향* 으로 정렬된다.

## Addition

경계 사각형의 **정점(Vertex)** 을 검출한다. 경계면을 둘러싸는 다각형은 경계 사각형 내부에 포함되며, 해당 정점을 블록점으로 사용한다. 영역 내부에도 다양한 윤곽점들이 존재하므로 여기 블록 껍질을 이루는 **블록점들을 선별해서 선택한다.**

## 출처
https://076923.github.io/posts/Python-opencv-24/