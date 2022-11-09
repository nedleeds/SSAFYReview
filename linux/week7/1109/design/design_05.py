# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file '05_qt_raspi_led.ui'
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
from PySide2.QtWidgets import (QApplication, QPushButton, QSizePolicy, QWidget)

class Ui_Form(object):
    def setupUi(self, Form):
        if not Form.objectName():
            Form.setObjectName(u"Form")
        Form.resize(358, 199)
        self.btn_on = QPushButton(Form)
        self.btn_on.setObjectName(u"btn_on")
        self.btn_on.setGeometry(QRect(20, 30, 151, 91))
        font = QFont()
        font.setPointSize(28)
        self.btn_on.setFont(font)
        self.pushButton_3 = QPushButton(Form)
        self.pushButton_3.setObjectName(u"pushButton_3")
        self.pushButton_3.setGeometry(QRect(180, 30, 151, 91))
        self.pushButton_3.setFont(font)

        self.retranslateUi(Form)
        self.btn_on.clicked.connect(Form.led_on)
        self.pushButton_3.clicked.connect(Form.led_off)

        QMetaObject.connectSlotsByName(Form)
    # setupUi

    def retranslateUi(self, Form):
        Form.setWindowTitle(QCoreApplication.translate("Form", u"Form", None))
        self.btn_on.setText(QCoreApplication.translate("Form", u"ON", None))
        self.pushButton_3.setText(QCoreApplication.translate("Form", u"OFF", None))
    # retranslateUi

