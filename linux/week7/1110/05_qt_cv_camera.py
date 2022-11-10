from PySide2.QtWidgets import *
from design.design_05 import Ui_MainWindow
from PySide2.QtGui import *
from PySide2.QtCore import *
import cv2
import numpy as np


class MyApp(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(MyApp, self).__init__()
        self.setupUi(self)
        self.img_path = {
            'before': { 'chan': './design/chan.jpg',
                        'jinuk': './design/jinuk.jpg'},

            'after' : { 'chan': './design/chan_after.jpg',
                        'jinuk': './design/jinuk_after.jpg'},
        }
        self.img = {
            'before': { 'chan': cv2.imread(self.img_path['before']['chan']),
                        'jinuk':cv2.imread(self.img_path['before']['jinuk'])},

            'after' : { 'chan':  None,
                        'jinuk': None}
        }
        self.main()

    def main(self):
        self.cam = cv2.VideoCapture(0)
        self.cam.set(3, 480)
        self.cam.set(4, 320)
        self.tm = QBasicTimer()

    def timerEvent(self, event):
        ret, self.img = self.cam.read()
        self.printImage(self.img, self.pic1)

    def play(self):
        self.printImage(self.img['before']['chan'], self.pic1)
        self.printImage(self.img['before']['jinuk'], self.pic2)

    def edge(self):
        self.process_image('edge')

    def morph(self):
        self.process_image('morph')

    def blur(self):
        self.process_image('blur')

    def process_image(self, mode='edge'):
        self.img['after']['chan'] = self.processingImage(self.img['before']['chan'], mode)
        self.img['after']['jinuk'] = self.processingImage(self.img['before']['jinuk'], mode)
        
        self.printImage(self.img['after']['chan'], self.pic1)
        self.printImage(self.img['after']['jinuk'], self.pic2)

    def printImage(self, imgBGR, pic):  
        imgRGB = cv2.cvtColor(imgBGR, cv2.COLOR_BGR2RGB)
        h, w, byte = imgRGB.shape
        img = QImage(imgRGB, w, h, byte*w, QImage.Format_RGB888)
        pic.setPixmap(QPixmap(img))

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



app = QApplication()
win = MyApp()
win.show()
app.exec_()