import sys
from PyQt5.QtWidgets import *

class MyWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        
print("출력-1")
app = QApplication(sys.argv)

window = MyWindow()
window.show()

app.exec_()
print("출력-3")