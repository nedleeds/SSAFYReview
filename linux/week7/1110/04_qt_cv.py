from PySide6.QtWidgets import *
from design.design_04 import Ui_MainWindow
from PySide6.QtGui import *
from PySide6.QtCore import *
import cv2
import numpy as np


class MyApp(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(MyApp, self).__init__()
        self.setupUi(self)
        self.main()

    def main(self):
        self.img = cv2.imread('./design/chan.jpg')
        self.img = self.processingImage(self.img, 'morph')
        self.printImage(self.img, self.pic)

    def processingImage(self, img, mode='edge'):
        if mode == 'edge':
            img = cv2.Canny(img, 100, 100)

        if mode == 'blur':
            img = cv2.blur(img, (15, 15))

        if mode == 'morph':
            img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
            kernel = np.ones((3, 3))
            img = cv2.morphologyEx(img, cv2.MORPH_GRADIENT, kernel)

        return img

    def printImage(self, imgBGR, pic):
        imgRGB = cv2.cvtColor(imgBGR, cv2.COLOR_BGR2RGB)
        h, w, byte = imgRGB.shape
        img = QImage(imgRGB, w, h, byte*w, QImage.Format_RGB888)
        pic.setPixmap(QPixmap(img))


app = QApplication()
win = MyApp()
win.show()
app.exec()