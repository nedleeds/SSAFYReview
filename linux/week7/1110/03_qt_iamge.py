import os
os.sys.path.append('./design/design_03.py')

from PySide6.QtCore import *
from PySide6.QtGui import *
from PySide6.QtWidgets import *
from design.design_03 import Ui_MainWindow


class MyApp(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(MyApp, self).__init__()
        Ui_MainWindow.setupUi(self, self)
        self.main()

    def main(self):
        # img = self.resizing(img);
        img = QImage('./design/chan.jpg')
        pixmap_img = QPixmap(img)

        self.piclbl.setPixmap(pixmap_img)
        self.piclbl.adjustSize()
        self.piclbl.move(50, 50)

app = QApplication()
win = MyApp()
win.show()
app.exec()