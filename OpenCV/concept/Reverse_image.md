# 역상(Reverse Image)

역상(`Reverse Image`)은 영상이나 이미지를 **반전 된 색상**으로 변환하기 위해 사용된다.

픽셀 단위마다 비트 연산(`Bitwise Operation`)을 적용하는데, 그 중 **NOT 연산**을 적용한다.

## 메인 코드

```python
import cv2

src = cv2.imread('image.jpg', cv2.IMREAD_COLOR)
dst = cv2.bitwise_not(src)

cv2.imshow("src", src)
cv2.imshow("dst", dst)
cv2.waitKey()
cv2.destroyAllWindows()
```

### 코드 분석

```python
dst = cv2.bitwise_not(src)
```

`cv2.bitwise_not(src, mask)`는 입력 이미지(`src`), 마스크(`mask`)로 출력 이미지(`dst`)를 생성한다.

mask는 NOT 연산을 적용할 특정 영역을 의미하는데, 마스크 배열이 포함되어 있다면, 해당 영역만 반전 연산을 적용한다.

### Tip

bitwise 연산은 `and`, `or`,  `xor` 등 더 있음