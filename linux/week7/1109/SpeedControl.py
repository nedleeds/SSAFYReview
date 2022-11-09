# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file '03_speedControl.ui'
##
## Created by: Qt User Interface Compiler version 6.4.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QLabel, QProgressBar, QPushButton,
    QSizePolicy, QSlider, QWidget)

class Ui_Form(object):
    def setupUi(self, Form):
        if not Form.objectName():
            Form.setObjectName(u"Form")
        Form.resize(665, 483)
        Form.setLayoutDirection(Qt.LeftToRight)
        Form.setStyleSheet(u"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 0, 120), stop:0.166 rgba(255, 255, 0, 255), stop:0.333 rgba(0, 255, 0, 255), stop:0.5 rgba(0, 255, 255, 255), stop:0.666 rgba(0, 0, 255, 255), stop:0.833 rgba(255, 0, 255, 255), stop:1 rgba(255, 0, 0, 255));")
        self.progressBar = QProgressBar(Form)
        self.progressBar.setObjectName(u"progressBar")
        self.progressBar.setGeometry(QRect(40, 20, 181, 381))
        font = QFont()
        font.setFamilies([u"\uad81\uc11c\uccb4"])
        font.setPointSize(72)
        self.progressBar.setFont(font)
        self.progressBar.setAcceptDrops(False)
        self.progressBar.setLayoutDirection(Qt.RightToLeft)
        self.progressBar.setAutoFillBackground(False)
        self.progressBar.setStyleSheet(u"selection-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 0, 255), stop:0.166 rgba(255, 255, 0, 255), stop:0.333 rgba(0, 255, 0, 255), stop:0.5 rgba(0, 255, 255, 255), stop:0.666 rgba(0, 0, 255, 255), stop:0.833 rgba(255, 0, 255, 255), stop:1 rgba(255, 0, 0, 255));")
        self.progressBar.setValue(0)
        self.progressBar.setTextVisible(True)
        self.progressBar.setOrientation(Qt.Vertical)
        self.progressBar.setInvertedAppearance(False)
        self.speedCtrl = QSlider(Form)
        self.speedCtrl.setObjectName(u"speedCtrl")
        self.speedCtrl.setGeometry(QRect(230, 360, 391, 41))
        self.speedCtrl.setOrientation(Qt.Horizontal)
        self.btnUp = QPushButton(Form)
        self.btnUp.setObjectName(u"btnUp")
        self.btnUp.setGeometry(QRect(240, 20, 381, 111))
        self.btnUp.setFont(font)
        self.btnUp.setStyleSheet(u"color: rgb(255, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.05 rgba(14, 8, 73, 255), stop:0.36 rgba(28, 17, 145, 255), stop:0.6 rgba(126, 14, 81, 255), stop:0.75 rgba(234, 11, 11, 255), stop:0.79 rgba(244, 70, 5, 255), stop:0.86 rgba(255, 136, 0, 255), stop:0.935 rgba(239, 236, 55, 255));")
        self.btnDown = QPushButton(Form)
        self.btnDown.setObjectName(u"btnDown")
        self.btnDown.setGeometry(QRect(240, 140, 381, 101))
        self.btnDown.setFont(font)
        self.btnDown.setStyleSheet(u"color: rgb(255, 255, 255);\n"
"background-color: qlineargradient(spread:reflect, x1:0, y1:1, x2:0, y2:0, stop:0.0960452 rgba(239, 236, 55, 255), stop:0.163842 rgba(255, 136, 0, 255), stop:0.282486 rgba(244, 70, 5, 255), stop:0.350282 rgba(234, 11, 11, 255), stop:0.6 rgba(126, 14, 81, 255), stop:0.819209 rgba(28, 17, 145, 255), stop:0.943503 rgba(14, 8, 73, 255), stop:1 rgba(0, 0, 0, 255));")
        self.label_3 = QLabel(Form)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setGeometry(QRect(40, 410, 581, 61))
        font1 = QFont()
        font1.setFamilies([u"\uad81\uc11c\uccb4"])
        font1.setPointSize(36)
        self.label_3.setFont(font1)
        self.label_4 = QLabel(Form)
        self.label_4.setObjectName(u"label_4")
        self.label_4.setGeometry(QRect(240, 250, 381, 101))
        font2 = QFont()
        font2.setFamilies([u"\uad81\uc11c\uccb4"])
        font2.setPointSize(64)
        self.label_4.setFont(font2)
        self.label_4.setStyleSheet(u"color: qlineargradient(spread:reflect, x1:0, y1:1, x2:0, y2:0, stop:0.0960452 rgba(239, 236, 55, 255), stop:0.163842 rgba(255, 136, 0, 255), stop:0.282486 rgba(244, 70, 5, 255), stop:0.350282 rgba(234, 11, 11, 255), stop:0.6 rgba(126, 14, 81, 255), stop:0.819209 rgba(28, 17, 145, 255), stop:0.943503 rgba(14, 8, 73, 255), stop:1 rgba(0, 0, 0, 255));\n"
"background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));")

        self.retranslateUi(Form)
        self.btnUp.clicked.connect(Form.up)
        self.btnDown.clicked.connect(Form.down)
        self.speedCtrl.actionTriggered.connect(Form.speed_control)

        QMetaObject.connectSlotsByName(Form)
    # setupUi

    def retranslateUi(self, Form):
        Form.setWindowTitle(QCoreApplication.translate("Form", u"Form", None))
        self.btnUp.setText(QCoreApplication.translate("Form", u"\uc62c\ub824", None))
        self.btnDown.setText(QCoreApplication.translate("Form", u"\ub0b4\ub824", None))
        self.label_3.setText(QCoreApplication.translate("Form", u"  MADE BY KOREA - DHL", None))
        self.label_4.setText(QCoreApplication.translate("Form", u"\uc18d\ub3c4 \uc870\uc815", None))
    # retranslateUi

