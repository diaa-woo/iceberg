import cv2
import numpy as np

def main():
    camera = cv2.VideoCapture(0)
    camera.set(3,160)  # set width 160 pixels
    camera.set(4,120)  # set height 120 pixels
    
    while(camera.isOpened() ):
        ret, frame = camera.read()
        frame = cv2.flip(frame, -1)
        cv2.imshow('normal', frame)
        
        crop_img = frame[60:120, 0:160]  # sequence is height, width, so height 60~120 pixels, width 0~160 px(all)

        gray = cv2.cvtColor(crop_img, cv2.COLOR_BGR2GRAY) # image change gray color
        
        blur = cv2.GaussianBlur(gray, (5,5), 0) # Gaussian Bluring is give high weight to the pixel in the center, setting size(5x5), and calculating sigma, do bluring
        
        ret, thresh1 = cv2.threshold(blur, 130, 255, cv2.THRESH_BINARY_INV)  # like Embedded threshold, if over 130, change 255, and under 130, chang 0, and cv2.THRESH_BINARY_INV is seperated black and white
        
        mask = cv2.erode(thresh1, None, iterations=2)  # image compression
        mask = cv2.dilate(mask, None, iterations=2)  # image expansion
        cv2.imshow(' mask ', mask)
        
        contours, hierarchy = cv2.findContours(mask.copy(), 1, cv2.CHAIN_APPROX_NONE)  # detection contour of image

        if len(contours) > 0:
            c = max(contours, key=cv2.contourArea)  # return max value of contour
            M = cv2.moments(c)  # calculating moments of contour
            
            cx = int(M['m10']/M['m00'])
            cy = int(M['m01']/M['m00'])
            
            cv2.line(crop_img,(cx,0),(cx, 720),(255,0,0),1)  # draw line(img, start_pot, end_pot, color(red), thickness
            cv2.line(crop_img,(0,cy),(1280,cy),(255,0,0),1)
            
            cv2.drawContours(crop_img, contours, -1, (0,255,0), 1)  # draw contours(image, contour, contourldx(if -1 set, draw all contours), color, thickness) 
            
        if cv2.waitKey(1) == ord('q'):
            break
        
    cv2.destroyAllWindows()
    
if __name__ == '__main__':
    main()