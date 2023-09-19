import cv2

img = cv2.imread('image.jpeg')

x_pos, y_pos, width, height = cv2.selectROI("location", img, False)
print("x position, y position : ", x_pos, y_pos)
print("width, height : ", width, height)

cv2.destroyAllWindows()