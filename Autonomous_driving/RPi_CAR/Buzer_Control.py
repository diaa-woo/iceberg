import RPi.GPIO as GPIO
import time

BUZZER = 12

GPIO.setwarnings(False) 
GPIO.setmode(GPIO.BCM)
GPIO.setup(BUZZER, GPIO.OUT)

p = GPIO.PWM(BUZZER, 261)
p.start(50)

try:
    while True:
        p.start(50)
        p.ChangeFrequency(261)  #C
        time.sleep(0.5)
        p.ChangeFrequency(293)  #D
        time.sleep(0.5)
        p.ChangeFrequency(329)  #E
        time.sleep(0.5)
        p.ChangeFrequency(349)  #F
        time.sleep(0.5)
        p.ChangeFrequency(391)  #G
        time.sleep(0.5)
        p.ChangeFrequency(440)  #A
        time.sleep(0.5)
        p.ChangeFrequency(493)  #B
        time.sleep(0.5)
        p.ChangeFrequency(523)  #5oc C
        time.sleep(0.5)
        p.stop()
        time.sleep(1.0)
        
except KeyboardInterrupt:
    pass

p.stop()
GPIO.cleanup()