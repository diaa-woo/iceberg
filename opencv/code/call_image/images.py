import cv2
import os

os.chdir('.\code\call_image\\')
image = cv2.imread('moon.jpg', flags=cv2.IMREAD_ANYCOLOR)
cv2.imshow("Moon", image)
cv2.waitKey()
cv2.destroyAllWindows()