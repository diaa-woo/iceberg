[상위 문서로 이동](../README.md)

# HSV (Hue, Saturation, Value)

`HSV(Hue, Saturation, Value)` 공간은 색상을 표현하기에 간편한 색상 공간이다.

이미지에서 색상을 검출한다고 가정할 때 BGR이나 RGB 패턴으로는 **인간이 인지하는 영역의 색상을 구별하기에는 매우 어렵고 복잡하다.** 다만 HSV 색상 공간을 활용한다면 간편하고 빠르게 특정 색상을 검출하고 분리할 수 있다.

`색상(Hue)`은 빨간색, 노란색, 파란색 등으로 인식되는 색상 중 하나 또는 둘의 조합과 유사한 것처럼 보이는 **시각적 감각의 속성**을 의미한다. 0~360도의 범위로 표현되며, 파란색은 220~260도 사이에 있다. OpenCV에서는 0~179도의 범위로 표현된다.
  - 이 이유는 0~360의 범위는 **1 Byte(uint8)**의 범위를 벗어나게 되기 때문에 불필요한 메모리 사용을 줄이기 위하여 절반인 값인 0~179의 범위로 표현된다.

`채도(Saturation)`는 이미지의 색상 깊이로, 색상이 얼마나 선명한(순수한) 색인지를 의미한다. 아무것도 섞지 않아 맑고 깨끗하며 원색에 가까운 것을 채도가 높다고 표현한다. 0% ~ 100%의 비율로 표현되며, 0%에 가까울수록 무채색, 100%에 가까울수록 가장 **선명한(순수한) 색**이 된다. OpenCV에서는 0 ~ 255의 범위로 표현된다.

`명도(Value)`는 색의 밝고 어두운 정도를 의미한다. 명도가 높을수록 색상이 밝아지며, 명도가 낮을수록 색상이 어두워진다. 0%~100%의 비율로 표현되며, 0%에 가까울수록 검은색, 100%에 가까울수록 **가장 맑은색**이 된다. OpenCV에서는 0~255의 범위로 표현된다.

## Code 1 - H,S,V 각각의 채널 분리

```py
import cv2

src = cv2.imread("image.jpg", cv2.IMREAD_COLOR)
hsv = cv2.cvtColor(src, cv2.COLOR_BGR2HSV)      #  HSV 변환
h, s, v = cv2.split(hsv)

cv2.imshow("h", h)
cv2.imshow("s", s)
cv2.imshow("v", v)
cv2.waitKey()
cv2.destroyAllWindows()
```

*색상 공간 변환 함수* (`cv2.cvtColor(src, cv2.COLOR_BGR2HSV)`)로 이미지의 색상 공간을 `BGR`에서 `HSV`로 변경한다.

각각의 채널로 분리하기 위해 *채널 분리 함수* (`cv2.split`)을 적용한다. 이때 분리된 채널은 *단일 채널* 이므로 흑백의 색상으로만 표현한다.

## Code 2 - 색상 판별

```python
import cv2

src = cv2.imread("image.jpg", cv2.IMREAD_COLOR)
hsv = cv2.cvtColor(src, cv2.COLOR_BGR2HSV)
h, s, v = cv2.split(hsv)

h = cv2.inRange(h, 8, 20)
orange = cv2.bitwise_and(hsv, hsv, mask = h)
orange = cv2.cvtColor(orange, cv2.COLOR_HSV2BGR)

cv2.imshow("orange", orange)
cv2.waitKey()
cv2.destroyAllWindows()
```

`Hue`의 범위를 조정하여 **특정 색상의 범위만 출력**할 수 있다. 

이는 *배열 요소의 범위 설정 함수* (`cv2.inRange`)를 통해 조절이 가능하다. 해당 함수로 입력된 배열의 특정 범위 영역을 추출할 수 있다.

`dst = cv2.inRange(src, lowerb, upperb)`는 입력 이미지(`src`)의 낮은 범위(`lowerb`)에서 높은 범위(`upperb`) 사이의 요소를 추출한다. 참고로 주황색은 약 **8~20** 범위를 갖는다.

이후, 해당 추출한 영역을 *마스크*로 사용해 **이미지 위에 덧씌워 해당 부분만 출력한다.** *비트 연산 AND* (`cv2.bitwise_and`)로 간단하게 마스크를 덧씌울 수 있다. `dst = cv2.bitwise_and(src1, src2, mask)`는 입력 이미지1(`src1`)과 입력 이미지2(`src`)의 픽셀의 이진값이 동일한 영역만 AND 연산하여 반환한다. 이를 이용해 마스크의 영역이 존재한다면 그 영역만 AND 연산을 진행한다.

특정 영역(마스크)의 AND 연산이 완료됐다면 다시 *HSV* 색상 공간에서 *BGR* 색상 공간으로 변환한다.




