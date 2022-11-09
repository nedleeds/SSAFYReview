# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file '08_sensehat_lamp.ui'
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
from PySide2.QtWidgets import (QAbstractItemView, QApplication, QFormLayout, QHeaderView,
    QMainWindow, QMenuBar, QPushButton, QSizePolicy,
    QSlider, QStatusBar, QTableWidget, QTableWidgetItem,
    QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(320, 487)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.formLayoutWidget = QWidget(self.centralwidget)
        self.formLayoutWidget.setObjectName(u"formLayoutWidget")
        self.formLayoutWidget.setGeometry(QRect(10, 10, 301, 441))
        self.formLayout = QFormLayout(self.formLayoutWidget)
        self.formLayout.setObjectName(u"formLayout")
        self.formLayout.setContentsMargins(0, 0, 0, 0)
        self.sliderR = QSlider(self.formLayoutWidget)
        self.sliderR.setObjectName(u"sliderR")
        self.sliderR.setMaximum(255)
        self.sliderR.setValue(120)
        self.sliderR.setOrientation(Qt.Horizontal)

        self.formLayout.setWidget(1, QFormLayout.SpanningRole, self.sliderR)

        self.sliderG = QSlider(self.formLayoutWidget)
        self.sliderG.setObjectName(u"sliderG")
        self.sliderG.setMaximum(255)
        self.sliderG.setValue(120)
        self.sliderG.setOrientation(Qt.Horizontal)

        self.formLayout.setWidget(2, QFormLayout.SpanningRole, self.sliderG)

        self.sliderB = QSlider(self.formLayoutWidget)
        self.sliderB.setObjectName(u"sliderB")
        self.sliderB.setMaximum(255)
        self.sliderB.setValue(120)
        self.sliderB.setOrientation(Qt.Horizontal)

        self.formLayout.setWidget(3, QFormLayout.SpanningRole, self.sliderB)

        self.btn_flash = QPushButton(self.formLayoutWidget)
        self.btn_flash.setObjectName(u"btn_flash")

        self.formLayout.setWidget(4, QFormLayout.SpanningRole, self.btn_flash)

        self.btn_clear = QPushButton(self.formLayoutWidget)
        self.btn_clear.setObjectName(u"btn_clear")

        self.formLayout.setWidget(5, QFormLayout.SpanningRole, self.btn_clear)

        self.table = QTableWidget(self.formLayoutWidget)
        if (self.table.columnCount() < 8):
            self.table.setColumnCount(8)
        if (self.table.rowCount() < 8):
            self.table.setRowCount(8)
        self.table.setObjectName(u"table")
        sizePolicy = QSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.table.sizePolicy().hasHeightForWidth())
        self.table.setSizePolicy(sizePolicy)
        self.table.setEditTriggers(QAbstractItemView.NoEditTriggers)
        self.table.setSelectionMode(QAbstractItemView.SingleSelection)
        self.table.setRowCount(8)
        self.table.setColumnCount(8)
        self.table.horizontalHeader().setVisible(False)
        self.table.horizontalHeader().setDefaultSectionSize(36)
        self.table.verticalHeader().setVisible(False)
        self.table.verticalHeader().setDefaultSectionSize(36)

        self.formLayout.setWidget(0, QFormLayout.SpanningRole, self.table)

        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 320, 22))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        self.btn_flash.clicked.connect(MainWindow.flash)
        self.btn_clear.clicked.connect(MainWindow.clear)
        self.sliderB.valueChanged.connect(MainWindow.bslide)
        self.sliderG.valueChanged.connect(MainWindow.gslide)
        self.sliderR.valueChanged.connect(MainWindow.rslide)
        self.table.cellEntered.connect(MainWindow.click)
        self.table.cellPressed.connect(MainWindow.click)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.btn_flash.setText(QCoreApplication.translate("MainWindow", u"Flash", None))
        self.btn_clear.setText(QCoreApplication.translate("MainWindow", u"Clear", None))
    # retranslateUi

