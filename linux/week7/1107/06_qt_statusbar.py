from PySide6.QtWidgets import *

app = QApplication()
win = QMainWindow()
win.setGeometry(100, 100, 400, 300)

label = QLabel("BBQ 먹고싶다", win)
label.adjustSize()

bar = win.statusBar()
bar.showMessage("아임 헝그리")

win.show()
app.exec()