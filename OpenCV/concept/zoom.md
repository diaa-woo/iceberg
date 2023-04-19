# zoom - 확대/축소

## 이미지 피라미드(Image Pyramid)

입력 이미지는 항상 동일한 크기가 아닐 수 있는데, 알고리즘에서 요구하는 해상도가 있을 시 **이 이미지의 크기를 변경해 영상 처리를 진행해야 한다.** (또는 검출하려는 객체가 너무 작을 시, 입력 이미지가 너무 작을 때 등등)

이를 위해 이미지 확대/축소 작업이 필요한데, 이는 `이미지 피라미드(Image Pyramid)`를 활용하여 원하는 크기로 샘플링 시켜줄 수 있다. 이미지 피라미드란 이미지의 크기를 확대/축소 하였을 때 이미지들의 형태가 피라미드와 같이 표현되는 것이다. 이 이미지 피라미드는 `가우시안 피라미드(Gaussian Pyramid)` & `라플라시안 피라미드(Laplacian Pyramid)`를 사용한다.

용어 정리
- Up Sampling : 하위 단계의 이미지 생성 - 크기 확대
- Down Sampling : 상위 단계의 이미지 생성 - 크기 축소
  
## 코드

```python
import cv2

src = cv2.imread("image.jpg", cv2.IMREAD_COLOR)
height, width, channel = src.shape

dst = cv2.pyrUp(src, dstsize=(width * 2, height * 2), borderType=cv2.BORDER_DEFAULT)
dst2 = cv2.pyrDown(src)

cv2.imshow("src", src)
cv2.imshow("dst", dst)
cv2.imshow("dst2", dst2)
cv2.waitKey()
cv2.destroyAllWindows()
```

## 코드 분석

```python
dst = cv2.pyrUp(src, dstsize=(width * 2, height * 2), borderType =cv2.BORDER_DEFAULT)
```

`이미지 확대 함수(cv2.pyrUp)`로 이미지를 2배 확대할 수 있다.

`cv2.pyrUp` 함수는 `입력 이미지(src)`, `출력 이미지 크기(dstSize)`, `테두리 외삽법(borderType)`으로 출력된 이미지를 반환한다.

`dstSize`는 매우 세밀한 크기 조정을 필요로 할 때 사용하며, 다음과 같은 조건식에 충족해야 한다.

$$
\vert\,dstSize.width - src.cols \times 2\,\vert \leq ( dstSize.width \, mod \, 2 \,\vert  )\\
\vert\,dstSize.height - src.rows \times 2\,\vert \leq \vert dstSize.height \, mod \, 2 \,\vert
$$

`테두리 외삽법(borderType)`은 이미지를 확대/축소 할 경우, 이미지 영역 밖의 픽셀을 외삽하는데 사용되는 `테두리 모드`로, 이 `외삽 설정`을 결정한다.

```python
dst2 = cv2.pyrDown(src)
```

`이미지 축소 함수(cv2.pyrUp)`로 축소 가능. 키워딩은 똑같지만 dstSize 최소 사이즈가 다르다.

$$
\vert\,dstSize.width - src.cols \times 2\,\vert \leq 2 \\
\vert\,dstSize.height - src.rows \times 2\,\vert \leq 2
$$

## 픽셀 외삽법

|속성|의미|
|---|----|
|`cv2.BORDER_CONSTANT`| iiiiii;abcdefgh;iiiiiii |
|`cv2.BORDER_REPLICATE`| aaaaaa;abcdefgh;hhhhhhh |
|`cv2.BORDER_REFLECT`| fedcba;abcdefgh;hgfedcb |
|`cv2.BORDER_WRAP`| cdefgh;abcdefgh;abcdefg |
|`cv2.BORDER_REFLECT_101`| gfedcb;abcdefgh;gfedcba |
|`cv2.BORDER_REFLECT101`| gfedcb;abcdefgh;gfedba |
|`cv2.BORDER_DEFAULT`| gfedcb;abcdefgh;gfedcba |
|`cv2.BORDER_TRANSPARENT`| gfedcb;abcdefgh;gfedcba |
|`cv2.BORDER_ISOLATED`| 관심 영역(ROI) 밖은 고려하지 않음 |

확대/축소 함수는 `BORDER_DEFAULT`만 사용 가능함