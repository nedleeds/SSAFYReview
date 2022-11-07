from PySide6.QtWidgets import *

app = QApplication()
win = QWidget()

line_edit = QLineEdit(win)
btn = QPushButton("HUHU", win)

lay = QHBoxLayout()
lay.addWidget(line_edit)
lay.addWidget(btn)

win.setLayout(lay)
win.show()

app.exec()