# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file '03_design.ui'
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
from PySide6.QtWidgets import (QApplication, QLabel, QLineEdit, QMainWindow,
    QMenuBar, QPushButton, QSizePolicy, QStatusBar,
    QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(336, 477)
        MainWindow.setAutoFillBackground(False)
        MainWindow.setStyleSheet(u"background-color: rgb(40, 40, 40);")
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.label = QLabel(self.centralwidget)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(30, 20, 181, 71))
        font = QFont()
        font.setFamilies([u"\uad81\uc11c\uccb4"])
        font.setPointSize(26)
        font.setUnderline(False)
        self.label.setFont(font)
        self.label.setStyleSheet(u"color: rgb(255, 255, 255);")
        self.label_2 = QLabel(self.centralwidget)
        self.label_2.setObjectName(u"label_2")
        self.label_2.setGeometry(QRect(30, 90, 181, 71))
        self.label_2.setFont(font)
        self.label_2.setStyleSheet(u"color: rgb(255, 255, 255);")
        self.label_3 = QLabel(self.centralwidget)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setGeometry(QRect(30, 150, 181, 71))
        self.label_3.setFont(font)
        self.label_3.setStyleSheet(u"color: rgb(255, 255, 255);")
        self.btn_result = QPushButton(self.centralwidget)
        self.btn_result.setObjectName(u"btn_result")
        self.btn_result.setGeometry(QRect(30, 240, 271, 81))
        font1 = QFont()
        font1.setFamilies([u"\uad81\uc11c\uccb4"])
        font1.setPointSize(26)
        self.btn_result.setFont(font1)
        self.btn_result.setStyleSheet(u"color: rgb(255, 255, 255);")
        self.btn_clear = QPushButton(self.centralwidget)
        self.btn_clear.setObjectName(u"btn_clear")
        self.btn_clear.setGeometry(QRect(30, 340, 271, 81))
        self.btn_clear.setFont(font1)
        self.btn_clear.setStyleSheet(u"color: rgb(255, 255, 255);")
        self.myNameEdit = QLineEdit(self.centralwidget)
        self.myNameEdit.setObjectName(u"myNameEdit")
        self.myNameEdit.setGeometry(QRect(110, 20, 191, 61))
        self.myNameEdit.setFont(font1)
        self.myNameEdit.setStyleSheet(u"background-color: rgb(36, 36, 36);\n"
"color: rgb(255, 255, 255);")
        self.urNameEdit = QLineEdit(self.centralwidget)
        self.urNameEdit.setObjectName(u"urNameEdit")
        self.urNameEdit.setGeometry(QRect(110, 90, 191, 61))
        self.urNameEdit.setFont(font1)
        self.urNameEdit.setStyleSheet(u"background-color: rgb(36, 36, 36);\n"
"color: rgb(255, 255, 255);")
        self.urAgeEdit = QLineEdit(self.centralwidget)
        self.urAgeEdit.setObjectName(u"urAgeEdit")
        self.urAgeEdit.setGeometry(QRect(200, 160, 101, 61))
        self.urAgeEdit.setFont(font1)
        self.urAgeEdit.setStyleSheet(u"background-color: rgb(36, 36, 36);\n"
"color: rgb(255, 255, 255);")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 336, 22))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        self.btn_result.clicked.connect(MainWindow.print_result)
        self.btn_clear.clicked.connect(MainWindow.clear)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.label.setText(QCoreApplication.translate("MainWindow", u"\ubcf8\uc778", None))
        self.label_2.setText(QCoreApplication.translate("MainWindow", u"\uc0c1\ub300", None))
        self.label_3.setText(QCoreApplication.translate("MainWindow", u"\uc0c1\ub300 \ub098\uc774", None))
        self.btn_result.setText(QCoreApplication.translate("MainWindow", u"\uacb0\uacfc \ud655\uc778", None))
        self.btn_clear.setText(QCoreApplication.translate("MainWindow", u"\ud654\uba74 \uc815\ub9ac", None))
    # retranslateUi

