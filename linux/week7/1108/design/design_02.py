# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'test.ui'
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
    QMenuBar, QPushButton, QSizePolicy, QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(305, 382)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.ageEdit = QLineEdit(self.centralwidget)
        self.ageEdit.setObjectName(u"ageEdit")
        self.ageEdit.setGeometry(QRect(160, 10, 131, 41))
        self.name = QLabel(self.centralwidget)
        self.name.setObjectName(u"name")
        self.name.setGeometry(QRect(20, 20, 151, 21))
        font = QFont()
        font.setFamilies([u"Cascadia Mono PL SemiBold"])
        font.setPointSize(18)
        font.setBold(True)
        self.name.setFont(font)
        self.pushButton = QPushButton(self.centralwidget)
        self.pushButton.setObjectName(u"pushButton")
        self.pushButton.setGeometry(QRect(20, 60, 151, 51))
        font1 = QFont()
        font1.setFamilies([u"\uad81\uc11c\uccb4"])
        font1.setPointSize(22)
        self.pushButton.setFont(font1)
        self.pushButton_2 = QPushButton(self.centralwidget)
        self.pushButton_2.setObjectName(u"pushButton_2")
        self.pushButton_2.setGeometry(QRect(20, 180, 191, 51))
        self.pushButton_2.setFont(font1)
        self.pushButton_3 = QPushButton(self.centralwidget)
        self.pushButton_3.setObjectName(u"pushButton_3")
        self.pushButton_3.setGeometry(QRect(20, 120, 191, 51))
        self.pushButton_3.setFont(font1)
        self.pushButton_4 = QPushButton(self.centralwidget)
        self.pushButton_4.setObjectName(u"pushButton_4")
        self.pushButton_4.setGeometry(QRect(20, 240, 271, 51))
        self.pushButton_4.setFont(font1)
        self.pushButton_5 = QPushButton(self.centralwidget)
        self.pushButton_5.setObjectName(u"pushButton_5")
        self.pushButton_5.setGeometry(QRect(20, 300, 271, 51))
        self.pushButton_5.setFont(font1)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 305, 22))
        MainWindow.setMenuBar(self.menubar)

        self.retranslateUi(MainWindow)
        self.pushButton.clicked.connect(MainWindow.age_gf)
        self.pushButton_2.clicked.connect(MainWindow.age_wife)
        self.pushButton_3.clicked.connect(MainWindow.age_firstLove)
        self.pushButton_4.clicked.connect(MainWindow.age_expected)
        self.pushButton_5.clicked.connect(MainWindow.print_aminie)
        self.ageEdit.textEdited.connect(MainWindow.set_age)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.name.setText(QCoreApplication.translate("MainWindow", u"\ub108\uc758 \ub098\uc774\ub294 ", None))
        self.pushButton.setText(QCoreApplication.translate("MainWindow", u"\uc560\uc778 \ub098\uc774", None))
        self.pushButton_2.setText(QCoreApplication.translate("MainWindow", u"\ubc30\uc6b0\uc790 \ub098\uc774", None))
        self.pushButton_3.setText(QCoreApplication.translate("MainWindow", u"\uccab\uc0ac\ub791 \ub098\uc774", None))
        self.pushButton_4.setText(QCoreApplication.translate("MainWindow", u"\ub2f9\uc2e0\uc758 \uae30\ub300 \uc218\uba85", None))
        self.pushButton_5.setText(QCoreApplication.translate("MainWindow", u"\uc560\ubbf8\ub098\uc774!", None))
    # retranslateUi

