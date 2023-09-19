# 좌표 찾기

## 마우스 클릭 좌표값 찾기

파이썬 OpenCV 함수 중에 `selectROI` 함수는 이미지(image) 파일이나 그림 파일을 읽었을 때 마우스로 원하는 이미지를 클릭 및 드래그 하면 해당 위치(Location) 값을 return해 줌.

```python
cv2.selectROI(윈도우창 이름, 소스 이미지명, 격자형태 선택)
```

1. 표시되는 Windows창의 이름을 정할 수 있음
2. `imread`으로 읽은 이미지 파일의 `return` 값을 저장한 객체 명을 입력
3. 격자 형태의 사각형을 표시하는 지에 대한 유무

### 코드

```py
import cv2

img = cv2.imread('image.jpeg')

x_pos, y_pos, width, height = cv2.selectROI("location", img, False)
print("x position, y position : ", x_pos, y_pos)
print("width, height : ", width, height)

cv2.destroyAllWindows()
```

## 출처
https://scribblinganything.tistory.com/496