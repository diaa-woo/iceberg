import numpy as np
import cv2
from matplotlib import pyplot as plt

# 그림 불러오기
img1 = cv2.imread("images/road.jpg", cv2.IMREAD_GRAYSCALE)

# 클릭한 순서대로 입력받을 변수 선언
arrayX = []
arrayY = []

def onMouse(event, x, y, flags, param):
    if event == cv2.EVENT_LBUTTONDOWN:
        globalX = x
        globalY = y
        arrayX.append(x)
        arrayY.append(y)
        # number of click
        print('# of clicked point = ', len(arrayX))

cv2.imshow('image', img1)

cv2.setMouseCallback('image', onMouse)

while(1):
    cv2.waitKey(30)
    if len(arrayX) == 4:
        cv2.destroyAllWindows()        
        break


h, w = img1.shape
point1_src = np.float32([[arrayX[0], arrayY[0]], [arrayX[1], arrayY[1]], [arrayX[2], arrayY[2]], [arrayX[3], arrayY[3]]])
point1_dst = np.float32([[min(arrayX[0], arrayX[1]), max(arrayY[0], arrayY[3])], [min(arrayX[0], arrayX[1]), min(arrayY[1], arrayY[2])], [max(arrayX[2], arrayX[3]), min(arrayY[1], arrayY[2])], [max(arrayX[2], arrayX[3]), max(arrayY[0], arrayY[3])]])
per_mat = cv2.getPerspectiveTransform(point1_src, point1_dst)
res = cv2.warpPerspective(img1, per_mat, (w, h))

ress = [];
ress.append(img1); ress.append(res)

for i in range(2):
    plt.subplot(2, 2, i+1)
    plt.imshow(ress[i], cmap='gray')
    plt.xticks([]), plt.yticks([])
plt.show()