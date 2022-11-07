from PySide6.QtWidgets import *
from PySide6.QtGui import *


def add_person():
    global people_list, name, win
    status = win.statusBar()
    person = name.text()

    if person in people_list:
        status.showMessage(f"{person}님은 동명이인이십니다")
    elif len(person) == 0:
        status.showMessage(f"이름을 입력하세요")
    else:
        people_list.append(person)
        status.showMessage(f"{person}님이 등록되셨습니다")
    return


def del_person():
    global people_list, name, win
    status = win.statusBar()
    person = name.text()

    if person not in people_list and len(people_list):
        status.showMessage(f"{person}님은 없습니다")
    elif len(person) == 0:
        status.showMessage(f"이름을 입력하세요")
    elif len(people_list) == 0:
        status.showMessage(f"당신은 현재 인맥이 없습니다만?")
    else:
        people_list.remove(person)
        status.showMessage(f"{person}님이 인맥에서 제외되셨습니다")
    return

# init
people_list = []
app = QApplication()
win = QMainWindow()
win.setGeometry(400, 380, 500, 400)

# QMainWindow - menuBar
menu = win.menuBar()
menu_menu = menu.addMenu("메뉴")
menu_exit = menu.addMenu("종료")

# QMainWindow - menuBar - action
do_add = QAction("추가", win)
do_del = QAction("제거", win)
menu_menu.addAction(do_add)
menu_menu.addAction(do_del)
do_add.triggered.connect(add_person)
do_del.triggered.connect(del_person)

# QMainWindow - CentralWidget
frame = QWidget()
win.setCentralWidget(frame)
form = QFormLayout()

# 1st element - label
label = QLabel()
label.setText("인맥을 관리합시다")
form.addWidget(label)

# 2nd element - label
name = QLineEdit()
form.addRow("name", name)

# 3rd element - buttons("add/del")
box = QHBoxLayout()
btn_add = QPushButton("추가", frame)
btn_del = QPushButton("제거", frame)
btn_add.clicked.connect(add_person)
btn_del.clicked.connect(del_person)
box.addWidget(btn_add)
box.addWidget(btn_del)
form.addRow(box)

frame.setLayout(form)

# QMainWindow - statusBar
bar = win.statusBar()
bar.showMessage("인맥을 관리합니다")

win.show()
app.exec()
