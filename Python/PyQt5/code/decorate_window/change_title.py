import sys
from PyQt5.QtWidgets import *

class MyWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        
        self.setWindowTitle("My Windows Title!")
        
app = QApplication(sys.argv)
window = MyWindow()
window.show()
app.exec_()