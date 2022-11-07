from PySide6.QtWidgets import *

app = QApplication()
win = QWidget()
form = QFormLayout()
alert = QMessageBox()
btn = {
    '회원가입': QPushButton('회원가입'),
    '나이확인': QPushButton('나이확인')
}

lay = {
    'main': QVBoxLayout(),
    'name': QHBoxLayout(),
    'age': QHBoxLayout()
}

line = {
    'name': QLineEdit(),
    'age': QLineEdit()
}


def age_check():
    if int(age.text()) > 30:
        alert.setText("경고: 나이가 너무 많습니다")
        alert.exec()
    else:
        pass


def sign():
    length = len(line['name'].text())
    if (length < 1 or length > 4):
        alert.setText("이름은 1~4글자 필수")
    else:
        alert.setText("회원가입 성공!")
    alert.exec()


# layout 설정
lay['age'].addWidget(line['age'])
lay['age'].addWidget(btn['나이확인'])

# form 설정
form.addRow('name', line['name'])
form.addRow('age', lay['age'])
form.addWidget(btn['회원가입'])

# 입력 받아오기
name = line['name']
age = line['age']

# 버튼 콜백 설정
btn['회원가입'].clicked.connect(sign)
btn['나이확인'].clicked.connect(age_check)

win.setLayout(form)
win.show()
app.exec()
