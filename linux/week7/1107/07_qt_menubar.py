from PySide6.QtWidgets import *

app = QApplication()
win = QMainWindow()
win.setGeometry(100, 100, 400, 300)

menu = win.menuBar()
menu.addMenu("File")
menu.addMenu("Edit")

'''
# 아래 label을 추가하는 순간, menu bar 와 겹침
label = QLabel("BBQ 먹고싶다", win)
label.adjustSize()
'''
#label 은 setCentralWidget 에 위치 해야한다
main = QWidget()
win.setCentralWidget(main)
label = QLabel("BBQ 맛있어", main)
label.adjustSize()

bar = win.statusBar()
bar.showMessage("나는 지금도 배고프다")

win.show()
app.exec()