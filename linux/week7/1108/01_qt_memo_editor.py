import os
from PySide6.QtWidgets import *
from PySide6.QtGui import *

class MyWindow(QMainWindow):
    def closeEvent(self, event):
        # overriding
        global file_path

        if not edit.document().isModified():
            return

        if file_path is None:
            file_path = os.getcwd() + "\\test.txt"

        ppath = file_path.split('/')[-1]
        msg = "변경 사항을 " + ppath + "에 저장하시겠습니까?"
        answer = QMessageBox.question(win,
                                      "하하호호메모장",
                                      msg,
                                      QMessageBox.Save |
                                      QMessageBox.Discard |
                                      QMessageBox.Cancel)

        if answer & QMessageBox.save:
            save()
        elif answer & QMessageBox.Cancel:
            event.ignore()

app = QApplication()

# 제목 표시줄
app.setApplicationName("하하호호 메모장")

# 메모 기능 추가
edit = QPlainTextEdit()

# central window 세팅
# win = QMainWindow()
win = MyWindow()
win.setCentralWidget(edit)

# 메뉴바 세팅
# &: 단축키 사용 가능(앞 글자로 자동 세팅)
file_menu = win.menuBar().addMenu("&File")

# 하위 메뉴 세팅
# QAction의 callback : triggered.connect()
# QMainWindow.close() 창 닫는 메서드
# 상위 메뉴바(menu) 에 action 추가
# 단축키 수동 설정 : QAction().setShortcut(QKeySequence("단축키"))
close = QAction("&Close")
close.triggered.connect(win.close)
file_menu.addAction(close)
close.setShortcut(QKeySequence("Ctrl+w"))


# 클릭 시 메세지 박스
# 메뉴바에 Help 메뉴 추가
# QAction 으로 Help 메뉴에 About 하위 메뉴 추가
# Help 시 QAction Callback 으로 QMessageBox 설정
help_menu = win.menuBar().addMenu("&Help")
about_action = QAction("&About")
help_menu.addAction(about_action)
def show_about_dialog():
    text = """<center>\
    <h1>Text Editor</h1>\
    </center>
    <p>Version 1.2.3<br>
    Copyright</p>
    """
    QMessageBox.about(win, "About", text)
about_action.triggered.connect(show_about_dialog)
close.setShortcut(QKeySequence("Ctrl+h"))

# 파일 열기: 선택된 파일 내용을 setPlainText 로 editor 에 표시
# 메뉴 바에 File 추가
# File 메뉴에 Open 서브 메뉴 추가
open_action = QAction("&Open")
def open_file():
    global file_path
    file_path = QFileDialog.getOpenFileName(win, "Open File")[0]
    if file_path:
        edit.setPlainText(open(file_path, encoding='UTF-8').read())

open_action.triggered.connect(open_file)
open_action.setShortcut(QKeySequence("Ctrl+O"))
file_menu.addAction(open_action)

# 파일 저장
save_action = QAction("&Save")
file_path = None
def save():
    global file_path
    if file_path is None:
        save_as()
    else:
        with open(file_path, "w") as f:
            f.write(edit.toPlainText())

save_action.triggered.connect(save)
save_action.setShortcut(QKeySequence("Ctrl+S"))
file_menu.addAction(save_action)


# 다른 이름으로 파일 저장
# File 메뉴에 Save 서브 메뉴 추가
save_as_action = QAction("Save &As...")
def save_as():
    global file_path
    file_path = QFileDialog.getSaveFileName(win, "Save As")[0]
    with open(file_path, "w") as f:
        f.write(edit.toPlainText())

save_as_action.triggered.connect(save_as)
save_as_action.setShortcut(QKeySequence("Ctrl+Shift+S"))
file_menu.addAction(save_as_action)




win.show()
app.exec()
