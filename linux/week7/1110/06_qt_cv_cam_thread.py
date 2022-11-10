from PySide2.QtWidgets import *
from design.design_06 import Ui_MainWindow
from PySide2.QtGui import *
from PySide2.QtCore import *
import cv2
import numpy as np
from time import *


class MyThread(QThread):
    # mySignal = Signal(QPixmap)
    mySignal = Signal(QPixmap, QPixmap)

    def __init__(self):
        super(MyThread, self).__init__()
        self.cam = cv2.VideoCapture(0)
        self.cam.set(3, 480)
        self.cam.set(4, 320)
        self.mode = 'edge'

    def run(self):
        while True:
            ret, self.img = self.cam.read()
            if ret:
                self.printImage(self.img)
            sleep(0.1)

    def printImage(self, imgBGR):
        imgRGB = cv2.cvtColor(imgBGR, cv2.COLOR_BGR2RGB)
        h, w, byte = imgRGB.shape
        img = QImage(imgRGB, w, h, byte * w, QImage.Format_RGB888)
        pix_img = QPixmap(img)

        if self.mode is not 'og':
            img_after = self.processingImage(imgBGR, self.mode)
            img2 = QImage(img_after, w, h, img_after.strides[0], QImage.Format_Grayscale8)
            pix_img2 = QPixmap(img2)
        else:
            pix_img2 = pix_img

        self.mySignal.emit(pix_img, pix_img2)   

    def processingImage(self, img, mode='edge'):
        if mode == 'edge':
            img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
            img = cv2.Canny(img, 80, 80)

        if mode == 'blur':
            img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
            img = cv2.blur(img, (15, 15))

        if mode == 'morph':
            img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
            kernel = np.ones((3, 3))
            img = cv2.morphologyEx(img, cv2.MORPH_GRADIENT, kernel)

        return img


class MyApp(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(MyApp, self).__init__()
        self.setupUi(self)
        self.main()

    def main(self):
        self.th = MyThread()
        self.th.mySignal.connect(self.setImage)

    def setImage(self, img, img2):
        self.pic1.setPixmap(img)
        self.pic2.setPixmap(img2)

    def mode(self):
        pass

    def play(self):
        self.th.start()
        self.th.mode = 'og'

    def edge(self):
        self.th.mode = 'edge'

    def blur(self):
        self.th.mode = 'blur'

    def morph(self):
        self.th.mode = 'morph'

    def closeEvent(self, event):
        self.th.terminate()
        self.th.wait(3000)
        self.close()


app = QApplication()
win = MyApp()
win.show()
app.exec_()