import cv2

src = cv2.imread('images.jpeg', flags=cv2.IMREAD_COLOR)
dst = cv2.flip(src, 45)

cv2.imshow("src", src)
cv2.imshow("dst", dst)
cv2.waitKey()
cv2.destroyAllWindows()