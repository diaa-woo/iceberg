# 자르기

자르기(`slice`)는 영상이나 이미지에서 특정 영역을 잘라내는 연산을 의미한다.

특정 영역을 잘라내는 것을 **관심 영역(`Region Of Interest, ROI`)**이라 하며, 이미지 상에서 관심 있는 영역을 의미한다.

이미지를 처리할 때 **객체를 탐지하거나 검출하는 영역**을 명확하게 관심 영역이라 볼 수 있다.

관심 영역에만 알고리즘을 적용하면, 불필요한 연산이 줄어들고 정확도가 늘어나는 효과를 얻을 수 있다.

## 코드 (1)

```python
import cv2

src = cv2.imread("image.jpg", cv2.IMREAD_COLOR)
dst = src[100:600, 200:700].copy()

cv2.imshow("src", src)
cv2.imshow("dst", dst)
cv2.waitKey()
cv2.destroyAllWindows()
```

### 코드 분석

```python
dst = src[100:600, 200:700].copy()
```

OpenCV의 이미지는 `numpy` 배열 형식과 동일하다.

`src` 이미지에 `src[높이(행), 너비(열)]`로 **관심 영역을 설정한다.**

자르는 방식은 리스트(`list`), 배열(`Array`)에서 특정 영역을 자르는 방식과 동일하다.

다만, 이미지를 자르거나 복사할 때, `dst=src`의 형태를 사용할 경우, **얕은 복사(Shallow Copy)**가 되어 원본도 영향을 받게 된다.

그러므로, `*.copy()`을 통해 **깊은 복사(Deep Copy)**를 진행한다.

## 코드 (2)

```python
import cv2

src = cv2.imread("image.jpg", cv2.IMREAD_COLOR)

dst = src.copy()
roi = src[100:600, 200:700]
dst[0:500, 0:500] = roi

cv2.imshow("src", src)
cv2.imshow("dst", dst)
cv2.waitKey()
cv2.destroyAllWindows()
```

### 코드 분석

```python
dst = src.copy()
```

`dst` 이미지를 생성할 때, `dst = src.copy()`가 아닌 `dst=src`로 적용한다면, 깊은 복사가 적용되지 않는다.

얕은 복사로 이미지를 복사할 경우, `dst` 이미지와 `src` 이미지는 동일한 결과로 반환된다.

```python
roi = src[100:600, 200:700]
dst[0:500, 0:500] = roi
```

`roi` 이미지를 생성하여 `src[높이(행), 너비(열)]`로 **관심 영역을 설정한다.**

이후, `dst[높이(행), 너비(열)] = roi`를 이용하여 `dst` 이미지에 해당 영역을 붙여넣을 수 있다.

잘라낸 이미지와 붙여넣을 이미지의 크기가 다를 시 유용하게 써먹을 수 있다.

