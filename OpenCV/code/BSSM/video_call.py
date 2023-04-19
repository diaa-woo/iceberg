import os
import cv2

cap = cv2.VideoCapture('images/video2.mp4')

while cap.isOpened():
    success, frame = cap.read()
    if success:
        cv2.imshow('image', frame)
        
        key = cv2.waitKey(30) & 0xFF
        
        # 시간을 늦춘다면 초당 프레임 수도 낮아지게 될 것임!
        if(key == 27) :
            break
    else:
        break
    
# 다 썼으면 release
cap.release()

# 모든 창 종료
cv2.destroyAllWindows()