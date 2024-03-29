## 이미지 출력
OpenCV는 **래스터 그래픽스 이미지 파일 포맷(Raster Graphics Image File Format)**을 쉽게 불러올 수 있는 별도의 함수를 제공한다.

여기서 래스터 그래픽스 포맷이란 맵 화상 디스플레이 포맷으로 이미지 데이터를 저장하기 위해 사용된다. 각 화소가 하나 개의 작은 부분에 대응하는 직사각형 픽셀 그리드를 사용하여 이미지를 사용하는 도트 매트릭스 구조를 사용한다. 자세한 내용은 <a href="https://www.solvusoft.com/ko/file-extensions/type/raster-image-files/"> 여기</a>를 참조하면 된다.

이 함수는 이미지를 불러올 때 압축 해제된 이미지 데이터 구조에 필요한 메모리 할당 등의 복잡한 작업을 처리하며, **파일 시그니처(File Signature)**를 읽어 적절한 코덱을 결정한다. -> 여기서 적절한 래스터 그래픽스 포맷으로 변환된다.

OpenCV에서 이미지를 불러올 때는 확장자를 확인하는 방식이 아닌 파일 시그니처를 읽어 파일의 포맷을 분석한다.

파일 시그니처는 `파일 매직 넘버(File Magic Number)`라고도 하며, 각 파일 형식마다 몇 개의 바이트가 지정되어 있다. 

예를 들어, **PNG** 확장저의 경우 **89 50 4E 47 ...** 형태로 파일 헤더에 포함되어 있다.

이 이미지 입력함수는 OS의 Codec을 사용해 OS 별로 픽셀값이 다를 수 있다.

### 메인 코드 

```python
import cv2

image = cv2.imread("Image/lunar.jpg", cv2.IMREAD_ANYCOLOR)
cv2.imshow("Moon", image)
cv2.waitKey()
cv2.destoryAllWindows()
```

### 세부 코드 & 코드 분석

```python
image = cv2.imread("Image/lunar.jpg", cv2.IMREAD_ANYCOLOR)
```

이미지 입력 함수 `cv2.imread`를 통해 **로컬 경로**의 이미지 파일을 읽어올 수 있다.

`image = cv2.imread(fileName, flags)`는 파일 경로(`fileName`)의 이미지 파일을 `flags` 설정에 따라 불러온다.

파일 경로(`fileName`)는 **상대 경로** 또는 **절대 경로**를 사용해 이미지를 불러온다.

`flags`는 이미지를 초기에 불러올 때 적용할 `초기 상태`를 의미한다.

|FLAGS|속성값|
|-----|-----|
|`cv2.IMREAD_UNCHANGED`| 원본 사용 |
|`cv2.IMREAD_GRAYSCALE`| 1채널, 그레이스케일 적용  |
|`cv2.IMREAD_COLOR`| 3채널, BGR 이미지 사용 |
|`cv2.IMREAD_ANYDEPTH`| 이미지에 따라 정밀도를 16/32비트 또는 8비트로 사용 |
|`cv2.IMREAD_ANYCOLOR`| 가능한 3채널, 색상 이미지로 사용 |
|`cv2.IMREAD_REDUCED_GRAYSCALE_2`| 1채널, 1/2 크기, 그레이스케일 적용 |
|`cv2.IMREAD_REDUCED_GRAYSCALE_4`| 1채널, 1/4 크기, 그레이스케일 적용 |
|`cv2.IMREAD_REDUCED_GRAYSCALE_8`| 1채널, 1/8 크기, 그레이스케일 적용 |
|`cv2.IMREAD_REDUCED_COLOR_2`| 3채널, 1/2 크기, BGR 이미지 사용 |
|`cv2.IMREAD_REDUCED_COLOR_4`| 3채널, 1/4 크기, BGR 이미지 사용 |
|`cv2.IMREAD_REDUCED_COLOR_8`| 3채널, 1/8 크기, BGR 이미지 사용 |

여기서 그레이스케일이란 사진을 흑백 명암 처리해준다는 것이다.

```python 
cv2.imshow("Moon", image)
cv2.waitKey()
cv2.destoryAllWindows()
```

이미지 표시 함수(`cv2.imshow`)와 키 입력 대기 함수(`cv2.waitkey`)로 윈도우 창에 이미지를 띄울 수 있다.

키 입력 대기 함수를 사용하지 않을 경우, **윈도우 창이 유지되지 않고** 프로그램이 종료된다.

키 입력 이후, 모든 윈도우 창 제거 함수(`cv2.destoryAllWindows`)를 이용하여 모든 윈도우 창을 닫게 해준다.

### 추가 정보

```python3
height, width, channel = image.shape
print(height, width, channel)
```

**결과: 1920 1280 3**

`height, width, channel = image.shape`를 이용하여 해당 이미지의 높이, 너비, 채널 값을 확인할 수 있다!

이미지의 속성은 **크기, 정밀도, 채널**을 주요한 속성으로 사용한다.

- 크기: 이미지의 **높이**와 **너비**를 의미한다.
- 정밀도: 이미지의 처리 결과의 **정밀성**을 의미한다.
- 채널: 이미지의 **색상 정보**를 의미한다.
- Tip들
  - **유효 비트가 많을수록 더 정밀해진다!**
  - 채널이 3인 경우, **다색 이미지**이다. 반면 채널이 1인 경우, **단색 이미지**이다.
