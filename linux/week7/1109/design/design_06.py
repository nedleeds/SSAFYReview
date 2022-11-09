# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file '06_table.ui'
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
from PySide2.QtWidgets import (QApplication, QHeaderView, QMainWindow, QMenuBar,
    QSizePolicy, QStatusBar, QTableWidget, QTableWidgetItem,
    QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(800, 596)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.table = QTableWidget(self.centralwidget)
        if (self.table.columnCount() < 2):
            self.table.setColumnCount(2)
        __qtablewidgetitem = QTableWidgetItem()
        self.table.setHorizontalHeaderItem(0, __qtablewidgetitem)
        __qtablewidgetitem1 = QTableWidgetItem()
        self.table.setHorizontalHeaderItem(1, __qtablewidgetitem1)
        if (self.table.rowCount() < 5):
            self.table.setRowCount(5)
        __qtablewidgetitem2 = QTableWidgetItem()
        self.table.setItem(0, 0, __qtablewidgetitem2)
        __qtablewidgetitem3 = QTableWidgetItem()
        self.table.setItem(0, 1, __qtablewidgetitem3)
        __qtablewidgetitem4 = QTableWidgetItem()
        self.table.setItem(1, 0, __qtablewidgetitem4)
        __qtablewidgetitem5 = QTableWidgetItem()
        self.table.setItem(1, 1, __qtablewidgetitem5)
        __qtablewidgetitem6 = QTableWidgetItem()
        self.table.setItem(2, 0, __qtablewidgetitem6)
        __qtablewidgetitem7 = QTableWidgetItem()
        self.table.setItem(2, 1, __qtablewidgetitem7)
        __qtablewidgetitem8 = QTableWidgetItem()
        self.table.setItem(3, 0, __qtablewidgetitem8)
        __qtablewidgetitem9 = QTableWidgetItem()
        self.table.setItem(3, 1, __qtablewidgetitem9)
        __qtablewidgetitem10 = QTableWidgetItem()
        self.table.setItem(4, 0, __qtablewidgetitem10)
        __qtablewidgetitem11 = QTableWidgetItem()
        self.table.setItem(4, 1, __qtablewidgetitem11)
        self.table.setObjectName(u"table")
        self.table.setGeometry(QRect(10, 10, 781, 541))
        self.table.setRowCount(5)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 800, 22))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        ___qtablewidgetitem = self.table.horizontalHeaderItem(0)
        ___qtablewidgetitem.setText(QCoreApplication.translate("MainWindow", u"ID", None));
        ___qtablewidgetitem1 = self.table.horizontalHeaderItem(1)
        ___qtablewidgetitem1.setText(QCoreApplication.translate("MainWindow", u"PASS", None));

        __sortingEnabled = self.table.isSortingEnabled()
        self.table.setSortingEnabled(False)
        ___qtablewidgetitem2 = self.table.item(0, 0)
        ___qtablewidgetitem2.setText(QCoreApplication.translate("MainWindow", u"mincoding", None));
        ___qtablewidgetitem3 = self.table.item(0, 1)
        ___qtablewidgetitem3.setText(QCoreApplication.translate("MainWindow", u"1234", None));
        ___qtablewidgetitem4 = self.table.item(1, 0)
        ___qtablewidgetitem4.setText(QCoreApplication.translate("MainWindow", u"lee", None));
        ___qtablewidgetitem5 = self.table.item(1, 1)
        ___qtablewidgetitem5.setText(QCoreApplication.translate("MainWindow", u"4321", None));
        ___qtablewidgetitem6 = self.table.item(2, 0)
        ___qtablewidgetitem6.setText(QCoreApplication.translate("MainWindow", u"dong", None));
        ___qtablewidgetitem7 = self.table.item(2, 1)
        ___qtablewidgetitem7.setText(QCoreApplication.translate("MainWindow", u"123", None));
        ___qtablewidgetitem8 = self.table.item(3, 0)
        ___qtablewidgetitem8.setText(QCoreApplication.translate("MainWindow", u"hyeong", None));
        ___qtablewidgetitem9 = self.table.item(3, 1)
        ___qtablewidgetitem9.setText(QCoreApplication.translate("MainWindow", u"321", None));
        ___qtablewidgetitem10 = self.table.item(4, 0)
        ___qtablewidgetitem10.setText(QCoreApplication.translate("MainWindow", u"kfc", None));
        ___qtablewidgetitem11 = self.table.item(4, 1)
        ___qtablewidgetitem11.setText(QCoreApplication.translate("MainWindow", u"111", None));
        self.table.setSortingEnabled(__sortingEnabled)

    # retranslateUi

