# 이진화(Binary)

이진화(`Binary`)는 어느 지점을 기준으로 값이 높거나 낮은 픽셀의 값을 대상으로 특정 연산을 수행할 때 사용한다.

일반적으로 값이 높거나 낮은 픽셀을 `Black` or `white`의 값으로 변경함

기준값에 따라 이분법적으로 구분해 픽샐을 **참 또는 거짓으로 나누는 연산**이며, 이미지 행렬에서 모든 픽셀에 대해 연산이 수행된다.

## 메인 코드

```python
import cv2

src = cv2.imread('image.jpg', cv2.IMREAD_COLOR)

gray = cv2.cvtColor(src, cv2.COLOR_BGR2GRAY)
ret, dst = cv2.threshold(gray, 100, 255, cv2.THRESH_BINARY)

cv2.imshow('dst', dst)
cv2.waitKey()
cv2.destroyAllWindows()
```

### 세부 코드 분석

```python
gray = cv2.cvtColor(src, cv2.COLOR_BGR2GRAY)
ret, dst = cv2.threshold(gray, 100, 255, cv2.THRESH_BINARY)
```

이진화 함수(`cv2.threshold`)로 그레이스케일 이미지에 이진화를 적용할 수 있다.

`retval, dst = cv2.threshold(src, thresh, maxval, type)`는 입력 이미지(`src`)를 임곗값 형식(`type`)에 따라 임곗값(`thresh`)과 최댓값(`maxval`)을 매개변수로 받는다. 

리턴 값은 설정 임곗값(`retval`)과 결과 이미지(`dst`)를 반환한다.

입력 이미지는 **단일 채널 이미지(그레이스케일)**을 입력해 사용한다.

threshold 지정값을 초과하면 *최댓값*으로, 이하의 값은 *0*으로 바꾸어 준다.

설정 임곗값을 일반적으로 임곗값과 동일하지만, 임곗값 이