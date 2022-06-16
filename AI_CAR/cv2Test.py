import cv2

def main():
    camera = cv2.VideoCapture(-1)
    camera.set(3,640) # width: 640 pixel
    camera.set(4,480) # height: 480 pixel
    
    while(camera.isOpened()):
        _, image = camera.read() # read camera frame and save in image variable, _ saves when image read value completely true, or failed save false. no use _
        cv2.imshow('camera test', image) # add windows name is 'camera test'
        image = cv2.flip(image, -1) # revelsal screen, default value is 1        
        if cv2.waitKey(1) == ord('q'): # cv2.waitkey input keyboard input. (1) means wait 1 milliseconds, If no read, return rime out. And when input 'q', run code
            break
        
    cv2.destroyAllWindows() # destory all opencv windows
    
if __name__ == '__main__' :
    main()
