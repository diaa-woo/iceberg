import sys
from PyQt5.QtWidgets import *

app = QApplication(sys.argv)

'''
Just Label

label = QLabel("Label")
label.show()
'''

'''
Just Button

button = QPushButton("Button")
button.show()
'''

'''
Just Window

win = QWidget()
win.show()   # 화면에 보여지게 함
'''

app.exec_()  # 이벤트 루프 시작 -> 닫기 버튼 누를때까지 지속