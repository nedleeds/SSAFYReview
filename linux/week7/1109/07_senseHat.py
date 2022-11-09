from PySide2.QtWidgets import *
from .design.design_07 import Ui_MainWindow
# from sense_emu import SenseHat
from sense_hat import SenseHat
from time import *

class MyApp(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        Ui_MainWindow.setupUi(self, self)
        self.main()

    def main(self):
        self.sense = SenseHat()

    def show_text(self):
        txt = self.lineEdit.text()
        self.sense.show_message(txt)
        for y in range(8):
            for x in range(8):
                self.sense.set_pixel(x, y, 255, 0, 0)
                sleep(0.1)
        self.sense.clear()


app = QApplication()

win = MyApp()
win.show()

app.exec_()
