import cv2
from matplotlib import pyplot as plt

img1 = cv2.imread('./images/image1.jpg')
img2 = cv2.imread('./images/image2.jpg')

img3 = cv2.subtract(img1, img2)  # 픽셀 제거 (ex: 200-250 = 0)

img4 = cv2.absdiff(img1, img2)  # 픽셀 제거(절댓값) (ex: |200-250| = 50)

titles = ['src', 'map', 'sub', 'absDiff']
imgs   = [img1, img2, img3, img4]

for i in range(4):
    plt.subplot(2,2,i+1)
    plt.imshow(imgs[i])
    plt.title(titles[i])
    plt.xticks([])
    plt.yticks([])
plt.show()

# 이 제거 연산을 통해 영상 처리 중 특정 구역만 검출 및 학습 등의 활동을 진행할 수 있다.