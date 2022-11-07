from PySide6.QtWidgets import *
from PySide6.QtGui import *

app = QApplication()
win = QMainWindow()

menu = win.menuBar()
menuFile = menu.addMenu("File")
menuEdit = menu.addMenu("Edit")

open = QAction("Open", win)
find = QAction("Find", win)
close = QAction("Close", win)

menuFile.addAction(open)
menuFile.addAction(find)
menuFile.addAction(close)

win.show()
app.exec()