# 크기 조절(Resize)

영상이나 이미지를 확대하거나 축소하는 연산에서 알 수 있듯 이미지의 크기를 변형하는 건 단순한 연산이 아니다.

이미지를 확대하는 경우에는 **픽셀에 대한 보간법**, 이미지를 축소하는 경우에는 **픽셀에 대한 병합법**이 수행된다.

이미지 피라미드는 2배로 확대하거나 축소하는 경우만 가능한데, 이로 인해 원하는 크기로 변환하기 위해선 이미지 크기 조절 함수를 사용해야 한다.

이미지를 변환하는 두 가지 방법
1. 이미지의 크기를 **사용자가 요구하는 절대 크기**로 변경하는 방법. -> 임의의 크기로 변환하는 것
2. 이미지의 크기를 **비율에 맞게 상대 크기**로 변경하는 방법. -> 입력 이미지의 크기와 비례

## 메인 코드

```python
import cv2

src = cv2.imread("image.jpg", cv2.IMREAD_COLOR)

dst = cv2.resize(src, dsize=(640, 480), interpolation=cv2.INTER_AREA)
dst2 = cv2.resize(src, dsize=(0, 0), fx=0.3, fy=0.7, interpolation=cv2.INTER_LINEAR)

cv2.imshow("src", src)
cv2.imshow("dst", dst)
cv2.imshow("dst2", dst2)
cv2.waitKey()
cv2.destroyAllWindows()
```

## 세부 설명

```python
dst = cv2.resize(src, dsize=(640, 480), interpolation=cv2.INTER_AREA)
dst2 = cv2.resize(src, dsize=(0, 0), fx=0.3, fy=0.7, interpolation=cv2.INTER_LINEAR)
```

**이미지 크기 조절 함수(`cv2.resize`)**로 이미지의 크기를 변경할 수 있다.

`cv2.resize(src, dstSize, fx, fy, interpolation)`는 입력 이미지(`src`), 절대 크기(`dstSize`), 상대 크기(`fx, fy`), 보간법(`interpolation`)으로 출력 이미지(`dst`)를 생성한다.

### 절대 크기

튜플(Tuple) 형식으로, **(너비, 높이)**의 값을 할당해 사용한다.

다음과 같은 수식을 통해 계산된다.

$$ 
dsize.width = round(fx \times src.cols)  \\
dsize.height = round(fy \times src.rows)
$$

### 상대 크기

절대 크기에 **(0, 0)**을 할당한 다음, 상대 크기의 값을 할당해 사용한다. (0,0)을 할당하는 이유로는 `fx`와 `fy`에서 계산된 크기가 `dsize`에 할당되기 때문이다.

다음과 같은 수식을 통해 계산된다.

$$
fx = dsize.width / src.cols \\
fy = dsize.height / src.rows
$$

### 보간법

이미지의 크기를 변경하는 경우, 변형된 이미지의 픽셀은 `추정`해서 값을 할당해야 한다.

즉, 이미지의 비율을 변경하려면 존재하지 않는 영역에 **새로운 픽셀값을 매핑하거나 존재하는 픽셀들을 압축해서 새로운 값을 할당해야 한다.**

이를 이미지 상에 존재하는 픽셀 데이터 $(x_i, y_i)$ 들에 대해 근사 함수 $ f(x,y) $ 를 적용해서 새로운 픽셀 값을 구하는 것으로 이해할 수 있다.

## 추가 정보
**Interpolation 속성**

|속성|의미|
|----|----|
|`cv2.INTER_NEAREST`| 이웃 보간법 |
|`cv2.INTER_LINEAR`| 쌍 선형 보간법 |
|`cv2.INTER_LINEAR_EXACT`| 비트 쌍 선형 보간법 |
|`cv2.INTER_CUBIC`| 바이큐빅 보간법 |
|`cv2.INTER_AREA`| 영역 보간법 |
|`cv2.INTER_LANCZOS4`| Lanczos 보간법 |