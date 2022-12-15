import sys
from PyQt5.QtWidgets import *

class MyWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        
        btn = QPushButton(text="매수", parent=self)
        btn.move(10, 10)
        
app = QApplication(sys.argv)
window = MyWindow()
window.show()
app.exec_()