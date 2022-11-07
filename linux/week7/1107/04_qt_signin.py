from PySide6.QtWidgets import *

app = QApplication()
win = QWidget()
form = QFormLayout()
btn = QPushButton('회원가입')

lay = {
    'main': QVBoxLayout(),
    'name': QHBoxLayout(),
    'age': QHBoxLayout()
}

line = {
    'name': QLineEdit(),
    'age': QLineEdit()
}

for (k, v) in line.items():
    form.addRow(k, v)

## 회원가입란의 길이가 딱 맞음
form.addWidget(btn)

## 회원가입란의 길이가 길어짐
# lay['main'].addLayout(form)
# lay['main'].addWidget(btn)


win.setLayout(form)
win.show()
app.exec()
