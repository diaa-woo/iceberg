import cv2
import numpy as np
from matplotlib import pyplot as plt

# 이미지 불러오기
img = cv2.imread('images/img8.jpg')
assert img is not None, "File could not be read, check with os.path.exists()"

# 이미지 흐림처리
img = cv2.medianBlur(img, 5)

# 이미지 이진화하기(Global & adaptive)
ret, th1 = cv2.threshold(img, 127,255,cv2.THRESH_BINARY)
th2 = cv2.adaptiveThreshold(img, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 11, 2)
th3 = cv2.adaptiveThreshold(img, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 11, 2)

# 결과 출력하기
titles = ['Original Image', 'Global Thresholding (v=127)', 'Adaptive Mean Thresholding', 'Adaptive Gaussian Thresholding']
images = [img, th1, th2, th3]
for i in range(4):
    plt.subplot(2,2,i+1), plt.imshow(images[i], 'gray')
    plt.title(titles[i])
    plt.xticks([]), plt.yticks([])
plt.show()