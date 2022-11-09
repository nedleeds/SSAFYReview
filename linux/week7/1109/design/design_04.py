# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file '04_thread.ui'
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
from PySide6.QtWidgets import (QApplication, QProgressBar, QPushButton, QSizePolicy,
    QVBoxLayout, QWidget)

class Ui_Form(object):
    def setupUi(self, Form):
        if not Form.objectName():
            Form.setObjectName(u"Form")
        Form.resize(537, 278)
        Form.setStyleSheet(u"background-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:0, stop:0.141243 rgba(0, 0, 0, 237), stop:0.297753 rgba(32, 25, 102, 249), stop:0.516854 rgba(5, 13, 21, 238), stop:0.651685 rgba(32, 26, 103, 244), stop:0.780899 rgba(51, 39, 180, 255), stop:0.910112 rgba(12, 9, 41, 255));")
        self.btn_play_1 = QPushButton(Form)
        self.btn_play_1.setObjectName(u"btn_play_1")
        self.btn_play_1.setGeometry(QRect(30, 20, 51, 41))
        font = QFont()
        font.setFamilies([u"Cascadia Mono SemiBold"])
        font.setPointSize(28)
        font.setBold(True)
        self.btn_play_1.setFont(font)
        self.btn_play_1.setStyleSheet(u"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));\n"
"border-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));\n"
"")
        self.verticalLayoutWidget = QWidget(Form)
        self.verticalLayoutWidget.setObjectName(u"verticalLayoutWidget")
        self.verticalLayoutWidget.setGeometry(QRect(150, 20, 381, 241))
        self.verticalLayout = QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.pb1 = QProgressBar(self.verticalLayoutWidget)
        self.pb1.setObjectName(u"pb1")
        font1 = QFont()
        font1.setFamilies([u"D2Coding"])
        font1.setPointSize(22)
        font1.setBold(True)
        self.pb1.setFont(font1)
        self.pb1.setStyleSheet(u"color: rgb(255, 255, 255);")
        self.pb1.setValue(0)

        self.verticalLayout.addWidget(self.pb1)

        self.pb2 = QProgressBar(self.verticalLayoutWidget)
        self.pb2.setObjectName(u"pb2")
        self.pb2.setFont(font1)
        self.pb2.setStyleSheet(u"color: rgb(255, 255, 255);")
        self.pb2.setValue(0)

        self.verticalLayout.addWidget(self.pb2)

        self.pb3 = QProgressBar(self.verticalLayoutWidget)
        self.pb3.setObjectName(u"pb3")
        self.pb3.setFont(font1)
        self.pb3.setStyleSheet(u"color: rgb(255, 255, 255);")
        self.pb3.setValue(0)

        self.verticalLayout.addWidget(self.pb3)

        self.pb4 = QProgressBar(self.verticalLayoutWidget)
        self.pb4.setObjectName(u"pb4")
        self.pb4.setFont(font1)
        self.pb4.setStyleSheet(u"color: rgb(255, 255, 255);")
        self.pb4.setValue(0)

        self.verticalLayout.addWidget(self.pb4)

        self.pb5 = QProgressBar(self.verticalLayoutWidget)
        self.pb5.setObjectName(u"pb5")
        self.pb5.setFont(font1)
        self.pb5.setStyleSheet(u"color: rgb(255, 255, 255);")
        self.pb5.setValue(0)

        self.verticalLayout.addWidget(self.pb5)

        self.btn_stop_1 = QPushButton(Form)
        self.btn_stop_1.setObjectName(u"btn_stop_1")
        self.btn_stop_1.setGeometry(QRect(90, 20, 51, 41))
        self.btn_stop_1.setFont(font)
        self.btn_stop_1.setStyleSheet(u"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));\n"
"border-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));")
        self.btn_play_2 = QPushButton(Form)
        self.btn_play_2.setObjectName(u"btn_play_2")
        self.btn_play_2.setGeometry(QRect(30, 70, 51, 41))
        self.btn_play_2.setFont(font)
        self.btn_play_2.setStyleSheet(u"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));\n"
"border-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));\n"
"")
        self.btn_stop_2 = QPushButton(Form)
        self.btn_stop_2.setObjectName(u"btn_stop_2")
        self.btn_stop_2.setGeometry(QRect(90, 70, 51, 41))
        self.btn_stop_2.setFont(font)
        self.btn_stop_2.setStyleSheet(u"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));\n"
"border-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));")
        self.btn_play_3 = QPushButton(Form)
        self.btn_play_3.setObjectName(u"btn_play_3")
        self.btn_play_3.setGeometry(QRect(30, 120, 51, 41))
        self.btn_play_3.setFont(font)
        self.btn_play_3.setStyleSheet(u"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));\n"
"border-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));\n"
"")
        self.btn_stop_3 = QPushButton(Form)
        self.btn_stop_3.setObjectName(u"btn_stop_3")
        self.btn_stop_3.setGeometry(QRect(90, 120, 51, 41))
        self.btn_stop_3.setFont(font)
        self.btn_stop_3.setStyleSheet(u"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));\n"
"border-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));")
        self.btn_stop_4 = QPushButton(Form)
        self.btn_stop_4.setObjectName(u"btn_stop_4")
        self.btn_stop_4.setGeometry(QRect(90, 170, 51, 41))
        self.btn_stop_4.setFont(font)
        self.btn_stop_4.setStyleSheet(u"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));\n"
"border-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));")
        self.btn_play_4 = QPushButton(Form)
        self.btn_play_4.setObjectName(u"btn_play_4")
        self.btn_play_4.setGeometry(QRect(30, 170, 51, 41))
        self.btn_play_4.setFont(font)
        self.btn_play_4.setStyleSheet(u"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));\n"
"border-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));\n"
"")
        self.btn_play_5 = QPushButton(Form)
        self.btn_play_5.setObjectName(u"btn_play_5")
        self.btn_play_5.setGeometry(QRect(30, 220, 51, 41))
        self.btn_play_5.setFont(font)
        self.btn_play_5.setStyleSheet(u"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));\n"
"border-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));\n"
"")
        self.btn_stop_5 = QPushButton(Form)
        self.btn_stop_5.setObjectName(u"btn_stop_5")
        self.btn_stop_5.setGeometry(QRect(90, 220, 51, 41))
        self.btn_stop_5.setFont(font)
        self.btn_stop_5.setStyleSheet(u"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));\n"
"border-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.331, fx:0.49965, fy:0.5, stop:0 rgba(10, 21, 31, 91));")

        self.retranslateUi(Form)
        self.btn_play_1.clicked.connect(Form.start)
        self.btn_stop_1.clicked.connect(Form.stop)
        self.btn_play_2.clicked.connect(Form.start)
        self.btn_play_3.clicked.connect(Form.start)
        self.btn_play_4.clicked.connect(Form.start)
        self.btn_play_5.clicked.connect(Form.start)
        self.btn_stop_2.clicked.connect(Form.stop)
        self.btn_stop_3.clicked.connect(Form.stop)
        self.btn_stop_4.clicked.connect(Form.stop)
        self.btn_stop_5.clicked.connect(Form.stop)

        QMetaObject.connectSlotsByName(Form)
    # setupUi

    def retranslateUi(self, Form):
        Form.setWindowTitle(QCoreApplication.translate("Form", u"Form", None))
        self.btn_play_1.setText(QCoreApplication.translate("Form", u"\u25b6", None))
        self.btn_stop_1.setText(QCoreApplication.translate("Form", u"\u25a0", None))
        self.btn_play_2.setText(QCoreApplication.translate("Form", u"\u25b6", None))
        self.btn_stop_2.setText(QCoreApplication.translate("Form", u"\u25a0", None))
        self.btn_play_3.setText(QCoreApplication.translate("Form", u"\u25b6", None))
        self.btn_stop_3.setText(QCoreApplication.translate("Form", u"\u25a0", None))
        self.btn_stop_4.setText(QCoreApplication.translate("Form", u"\u25a0", None))
        self.btn_play_4.setText(QCoreApplication.translate("Form", u"\u25b6", None))
        self.btn_play_5.setText(QCoreApplication.translate("Form", u"\u25b6", None))
        self.btn_stop_5.setText(QCoreApplication.translate("Form", u"\u25a0", None))
    # retranslateUi

