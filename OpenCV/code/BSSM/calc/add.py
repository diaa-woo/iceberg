import cv2
from matplotlib import pyplot as plt

img1 = cv2.imread('../images/img1.jpg')
img2 = cv2.imread('../images/img2.jpg')

img3 = cv2.add(img1, img2)

img4 = cv2.addWeighted(img1, 0.5, img2, 0.5, 0)  # 가중치 부여 합연산

titles = ['src', 'map', 'add', 'addWeight']
imgs   = [img1, img2, img3, img4]

for i in range(4):
    plt.subplot(2,2,i+1)
    plt.imshow(imgs[i])
    plt.title(titles[i])
    plt.xticks([])
    plt.yticks([])
plt.show()