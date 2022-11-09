# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file '04_design.ui'
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
from PySide6.QtWidgets import (QApplication, QFrame, QGridLayout, QLabel,
    QLineEdit, QMainWindow, QMenuBar, QPushButton,
    QSizePolicy, QStatusBar, QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(549, 578)
        MainWindow.setStyleSheet(u"background-color: rgb(50, 50, 50);")
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.gridLayout_2 = QGridLayout(self.centralwidget)
        self.gridLayout_2.setObjectName(u"gridLayout_2")
        self.gridLayout = QGridLayout()
        self.gridLayout.setObjectName(u"gridLayout")
        self.btn_color = QPushButton(self.centralwidget)
        self.btn_color.setObjectName(u"btn_color")
        font = QFont()
        font.setFamilies([u"\uad81\uc11c\uccb4"])
        font.setPointSize(36)
        self.btn_color.setFont(font)
        self.btn_color.setStyleSheet(u"color: rgb(255, 255, 255);")

        self.gridLayout.addWidget(self.btn_color, 2, 1, 1, 1)

        self.btn_name_2 = QPushButton(self.centralwidget)
        self.btn_name_2.setObjectName(u"btn_name_2")
        self.btn_name_2.setFont(font)
        self.btn_name_2.setStyleSheet(u"color: rgb(255, 255, 255);")

        self.gridLayout.addWidget(self.btn_name_2, 2, 0, 1, 1)

        self.frame = QFrame(self.centralwidget)
        self.frame.setObjectName(u"frame")
        self.frame.setStyleSheet(u"background-color: qradialgradient(spread:repeat, cx:0.5, cy:0.5, radius:0.077, fx:0.5, fy:0.5, stop:0 rgba(0, 169, 255, 147), stop:0.497326 rgba(0, 0, 0, 147), stop:1 rgba(0, 169, 255, 147));")
        self.frame.setFrameShape(QFrame.StyledPanel)
        self.frame.setFrameShadow(QFrame.Raised)
        self.label = QLabel(self.frame)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(230, 220, 81, 16))
        self.label.setStyleSheet(u"color: rgb(255, 255, 255);\n"
"background-color: rgb(29, 29, 29);")

        self.gridLayout.addWidget(self.frame, 0, 0, 1, 2)

        self.frame_2 = QFrame(self.centralwidget)
        self.frame_2.setObjectName(u"frame_2")
        self.frame_2.setFrameShape(QFrame.StyledPanel)
        self.frame_2.setFrameShadow(QFrame.Raised)
        self.label_2 = QLabel(self.frame_2)
        self.label_2.setObjectName(u"label_2")
        self.label_2.setGeometry(QRect(20, 10, 91, 31))
        font1 = QFont()
        font1.setFamilies([u"\uad81\uc11c\uccb4"])
        font1.setPointSize(26)
        self.label_2.setFont(font1)
        self.label_2.setStyleSheet(u"color: rgb(255, 255, 255);\n"
"color: rgb(255, 170, 0);")
        self.cntEdit = QLineEdit(self.frame_2)
        self.cntEdit.setObjectName(u"cntEdit")
        self.cntEdit.setGeometry(QRect(130, 0, 121, 51))
        font2 = QFont()
        font2.setFamilies([u"\uad81\uc11c\uccb4"])
        font2.setPointSize(28)
        self.cntEdit.setFont(font2)
        self.cntEdit.setStyleSheet(u"color: rgb(255, 170, 0);")

        self.gridLayout.addWidget(self.frame_2, 1, 0, 1, 1)

        self.btn_reset = QPushButton(self.centralwidget)
        self.btn_reset.setObjectName(u"btn_reset")
        font3 = QFont()
        font3.setFamilies([u"\uad81\uc11c\uccb4"])
        font3.setPointSize(32)
        self.btn_reset.setFont(font3)
        self.btn_reset.setStyleSheet(u"color: rgb(255, 255, 255);")

        self.gridLayout.addWidget(self.btn_reset, 1, 1, 1, 1)


        self.gridLayout_2.addLayout(self.gridLayout, 0, 0, 1, 1)

        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 549, 22))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        self.btn_color.clicked.connect(MainWindow.show_diagram)
        self.btn_reset.clicked.connect(MainWindow.show_diagram)
        self.cntEdit.textEdited.connect(MainWindow.show_diagram)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.btn_color.setText(QCoreApplication.translate("MainWindow", u"\uceec\ub7ec \ubcc0\uacbd", None))
        self.btn_name_2.setText(QCoreApplication.translate("MainWindow", u"\uc774\ub984 \ubcc0\uacbd", None))
        self.label.setText(QCoreApplication.translate("MainWindow", u"\ub098 \uc7a1 \uc544 \ubd10 \ub78d", None))
        self.label_2.setText(QCoreApplication.translate("MainWindow", u"Count", None))
        self.btn_reset.setText(QCoreApplication.translate("MainWindow", u"Count Reset", None))
    # retranslateUi

