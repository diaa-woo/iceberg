import cv2
from matplotlib import pyplot as plt

def nothing():
    pass

img1 = cv2.imread('./images/image1.jpg', cv2.COLOR_GRAY2BGR)
img2 = cv2.imread('./images/image2.jpg', cv2.COLOR_GRAY2BGR)

img3 = cv2.absdiff(img1, img2)  

ret, img4 = cv2.threshold(img3, 30, 255, cv2.THRESH_BINARY)

img5 = cv2.bitwise_and(img4, img1)

titles = ['src', 'map', 'absDiff', 'mask']
imgs   = [img1, img2, img3, img5]

for i in range(4):
    plt.subplot(2,2,i+1)
    plt.imshow(imgs[i])
    plt.title(titles[i])
    plt.xticks([])
    plt.yticks([])
plt.show()
