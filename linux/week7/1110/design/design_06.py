# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'design_05.ui'
##
## Created by: Qt User Interface Compiler version 6.4.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide2.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide2.QtWidgets import (QApplication, QGridLayout, QLabel, QMainWindow,
    QMenuBar, QPushButton, QSizePolicy, QStatusBar,
    QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(954, 597)
        MainWindow.setStyleSheet(u"background-color: rgb(43, 43, 43);")
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.gridLayoutWidget = QWidget(self.centralwidget)
        self.gridLayoutWidget.setObjectName(u"gridLayoutWidget")
        self.gridLayoutWidget.setGeometry(QRect(10, 10, 931, 541))
        self.gridLayout = QGridLayout(self.gridLayoutWidget)
        self.gridLayout.setObjectName(u"gridLayout")
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.pic1 = QLabel(self.gridLayoutWidget)
        self.pic1.setObjectName(u"pic1")
        self.pic1.setMaximumSize(QSize(460, 320))
        self.pic1.setBaseSize(QSize(460, 320))
        self.pic1.setStyleSheet(u"background-color: rgb(17, 17, 17);")

        self.gridLayout.addWidget(self.pic1, 0, 0, 1, 1)

        self.modeBtn_2 = QPushButton(self.gridLayoutWidget)
        self.modeBtn_2.setObjectName(u"modeBtn_2")
        self.modeBtn_2.setMaximumSize(QSize(960, 50))
        font = QFont()
        font.setPointSize(16)
        font.setBold(True)
        self.modeBtn_2.setFont(font)
        self.modeBtn_2.setStyleSheet(u"color: rgb(255, 255, 255);")

        self.gridLayout.addWidget(self.modeBtn_2, 3, 0, 1, 2)

        self.playBtn = QPushButton(self.gridLayoutWidget)
        self.playBtn.setObjectName(u"playBtn")
        self.playBtn.setMaximumSize(QSize(960, 50))
        self.playBtn.setFont(font)
        self.playBtn.setStyleSheet(u"color: rgb(255, 255, 255);")

        self.gridLayout.addWidget(self.playBtn, 1, 0, 1, 2)

        self.pic2 = QLabel(self.gridLayoutWidget)
        self.pic2.setObjectName(u"pic2")
        self.pic2.setEnabled(True)
        self.pic2.setMaximumSize(QSize(460, 320))
        self.pic2.setBaseSize(QSize(460, 320))
        self.pic2.setStyleSheet(u"background-color: rgb(8, 0, 30);")

        self.gridLayout.addWidget(self.pic2, 0, 1, 1, 1)

        self.modeBtn = QPushButton(self.gridLayoutWidget)
        self.modeBtn.setObjectName(u"modeBtn")
        self.modeBtn.setMaximumSize(QSize(960, 50))
        self.modeBtn.setFont(font)
        self.modeBtn.setStyleSheet(u"color: rgb(255, 255, 255);")

        self.gridLayout.addWidget(self.modeBtn, 2, 0, 1, 2)

        self.modeBtn_3 = QPushButton(self.gridLayoutWidget)
        self.modeBtn_3.setObjectName(u"modeBtn_3")
        self.modeBtn_3.setMaximumSize(QSize(960, 50))
        self.modeBtn_3.setFont(font)
        self.modeBtn_3.setStyleSheet(u"color: rgb(255, 255, 255);")

        self.gridLayout.addWidget(self.modeBtn_3, 4, 0, 1, 2)

        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 954, 22))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        self.playBtn.clicked.connect(MainWindow.play)
        self.modeBtn.clicked.connect(MainWindow.edge)
        self.modeBtn_2.clicked.connect(MainWindow.morph)
        self.modeBtn_3.clicked.connect(MainWindow.blur)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.pic1.setText("")
        self.modeBtn_2.setText(QCoreApplication.translate("MainWindow", u"Morphological Image", None))
        self.playBtn.setText(QCoreApplication.translate("MainWindow", u"Play", None))
        self.pic2.setText("")
        self.modeBtn.setText(QCoreApplication.translate("MainWindow", u"Edge Detection", None))
        self.modeBtn_3.setText(QCoreApplication.translate("MainWindow", u"Blurring", None))
    # retranslateUi

