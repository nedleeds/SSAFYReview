from PySide6.QtWidgets import *
from PySide6.QtGui import *

app = QApplication()
win = QMainWindow()

menu = win.menuBar()
menuFile = menu.addMenu("파일(F)")
menuBye = menu.addMenu("편집(E)")

bar = win.statusBar()
bar.showMessage("9개 항목")

new = QAction("NEW", win)
menuFile.addAction(new)

def run():
    bar.showMessage("버튼을 눌렀다")

new.triggered.connect(run)

win.show()
app.exec()