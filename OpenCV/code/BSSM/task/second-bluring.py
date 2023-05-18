import cv2
import numpy as np

def nothing():
    pass

cv2.namedWindow('kernel size bar') 
cv2.createTrackbar('ksize1', 'kernel size bar', 1, 21, nothing)
cv2.createTrackbar('ksize2', 'kernel size bar', 1, 21, nothing)

cv2.setTrackbarPos('ksize1', 'kernel size bar', 1)
cv2.setTrackbarPos('ksize2', 'kernel size bar', 1)

img = cv2.imread("../images/img8.jpg", cv2.IMREAD_GRAYSCALE)

while(1):
    ksize1  = cv2.getTrackbarPos('ksize1', 'kernel size bar')
    ksize2  = cv2.getTrackbarPos('ksize2', 'kernel size bar')
   
   
    img2 = cv2.boxFilter(img, -1, (ksize1, ksize2))
    cv2.imshow('kernel size bar', img2)
    
    if cv2.waitKey(30) & 0xFF == 27 :
        break