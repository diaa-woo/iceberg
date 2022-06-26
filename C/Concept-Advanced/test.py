from microbit import *
import radio
radio.config(group=7)
radio.on()

modeCount = 1   # modeCount 1: 기기들의 위경도 파악, modeCount 2: 가까운 로봇의 신호 강도 파악
localeModeCount = 1

def checkRobotLocale():
    while True:
        display.show(localeModeCount)
        if button_a.was_pressed():
            if localeModeCount == 3 :
                localeModeCount = 1
            else:
                localeModeCount += 1
        elif button_b.was_pressed():
            if localeModeCount == 1 :
                display.show("hello")
                break
    
    
#def checkSignalStrength():
    

while True:
    display.show(modeCount)
    message = radio.receive()
    '''if message:
        if message == 'yes':
            display.show(Image.YES)
            sleep(500)
            display.clear()
        elif message == 'no':
            display.show(Image.NO)
            sleep(500)
            display.clear()
    if button_a.was_pressed():
        radio.send('yes')
        display.show(Image.YES)
        sleep(500)
        display.clear()
    if button_b.was_pressed():
        radio.send('no')
        display.show(Image.NO)
        sleep(500)
        display.clear()'''
    if button_a.was_pressed():
        if modeCount == 2 :
            modeCount = 1
        else:
            modeCount += 1
    elif button_b.was_pressed():
        if(modeCount == 1):
            checkRobotLocale()
        else:
            checkSignalStrength()
            
        
