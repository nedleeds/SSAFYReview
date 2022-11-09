from PySide2.QtWidgets import *
from .design.design_08 import Ui_MainWindow
# from sense_emu import SenseHat
from sense_hat import SenseHat
from time import *

class MyApp(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        Ui_MainWindow.setupUi(self, self)
        self.r = 125
        self.g = 125
        self.b = 0
        self.brush = None
        self.main()

    def main(self):
        self.sense = SenseHat()

    def flash(self):
        for row in range(8):
            for col in range(8):
                self.sense.set_pixel(col, row, self.r, self.g, self.b)
        print("flash")

    def clear(self):
        print("clear")
        self.sense.clear()

    def click(self, row, col):
        print("cell has been clicked")

        self.sense.set_pixel(col, row, self.r, self.g, self.b)
    
    def rslide(self, val):
        self.r = val
        print(f"R:{val}")
    
    def gslide(self, val):
        self.g = val
        print(f"G:{val}")
    
    def bslide(self, val):
        self.b = val
        print(f"B:{val}")


app = QApplication()
win = MyApp()
win.show()
app.exec_()
