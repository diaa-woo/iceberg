# 흐림 효과(Blur)

`흐림 효과(Blur)`는 **블러링(Blurring)**또는 **스무딩(Smoothing)**이라 불리며, 노이즈를 줄이거나 외부 영향을 최소화하는 데 사용된다.

흐림 효과는 영상이나 이미지를 번지게 하며, 해당 픽셀의 주변 값들과 비교하고 계산하여 픽셀들의 색상을 재조정한다.

단순히 이미지를 흐리게 만드는 것뿐만 아니라 **노이즈를 제거해서 연산 시 계산을 빠르고 정확하게 수행하는 데 도움을 준다.**

또한, 이미지의 해상도를 변경하는 경우에도 사용되는데 이미지의 크기를 변경하면 존재하지 않는 데이터를 생성하거나 존재하는 데이터를 줄여야 하므로 샘플링된 이미지를 재구성할 때 사용된다.

## 메인 코드

```python
import cv2

src = cv2.imread("image.jpg", cv2.IMREAD_COLOR)
dst = cv2.blur(src, (9, 9), anchor=(-1, -1), borderType=cv2.BORDER_DEFAULT)

cv2.imshow("dst", dst)
cv2.waitKey()
cv2.destroyAllWindows()
```

### 세부 코드

```python
dst = cv2.blur(src, (9, 9), anchor=(-1, -1), borderType=cv2.BORDER_DEFAULT)
```

단순 흐림 효과 함수(`cv2.blur`)로 입력 이미지에 흐림 효과를 적용할 수 있다.

단순 흐림 효과는 각 픽셀에 대해 커널을 적용해 모든 픽셀의 단순 평균을 구하는 연산이다.

`dst = cv2.blur(src, ksize, anchor, borderType)`는 입력 이미지(`src`)를 커널 크기(`ksize`), 고정점(`anchor`), 테두리 외삼법(`borderType`)으로 흐림 효과를 적용한 결과 이미지(`dst`)를 반환한다.

## 커널(kernel)

<img src="https://076923.github.io/assets/posts/Python/OpenCV/lecture-13/2.webp">

커널(`kernel`)은 이미지에서 **(x, y)의 픽셀과 해당 픽셀 주변을 포함한 작은 크기의 공간**을 의미한다.

이 영역 각각의 특정한 수삭이나 함수 등을 적용해 새로운 이미지를 얻는 알고리즘에서 사용된다.

커널은 영역의 형태와 요소가 결합되는 방식을 정의하는 템플릿을 의미하기도 하며, 신호 처리 분야에서는 커널을 필터(`filter`)라고도 한다.

위 이미지의 파란색 사각형 내부가 **커널**이 되며, 파란색 사각형 크기가 `3*3`이므로, 커널의 크기는 `3*3`이 된다.