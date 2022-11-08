from PySide6.QtWidgets import *
from PySide6.QtCore import *
from design04 import Ui_MainWindow
import random
import hashlib

class MyApp(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.speed = 2000
        self.main()
        self.label_x = None
        self.label_y = None
        self.cnt = 0


    def main(self):
        self.timer = QBasicTimer()
        self.timer.start(self.speed, self)

    def timerEvent(self, e):
        self.label_x = random.randint(0, self.frame.size().width() - self.label.width())
        self.label_y = random.randint(0, self.frame.size().height() - self.label.height())
        self.label.move(self.label_x, self.label_y)

    def change_color(self):
        color = QColorDialog.getColor()
        if (color.isValid()):
            self.label.setStyleSheet("background-color:%s" %color.name())

    def change_name(self):
        name, ok = QInputDialog.getText(self, '이름 입력', '키미노,, 나마에와,,?')
        if ok:
            self.label.setText(name)
            self.label.adjustSize()

    def show_diagram(self):
        sender = self.sender()
        if sender.text() == '이름 변경':
            self.change_name()
        elif sender.text() == '컬러 변경':
            self.change_color()
        elif sender.text() == 'Count Reset':
            self.count_reset()

    def speed_up(self):
        self.speed *= 0.5
        print(self.speed)

    def count_reset(self):
        self.cnt = 0
        self.print_cnt()

    def mousePressEvent(self, e) -> None:
        # 마우스 클릭 위치
        x = e.x()
        y = e.y()

        # self.label_x, self.label_y : 라벨 포지션
        if self.label_x <= x <= self.label_x + self.label.width():
            if self.label_y <= y <= self.label_y + self.label.height():
                msg = QMessageBox()
                msg.setText("잡았다 요놈")
                msg.exec()
                self.cnt += 1
                self.speed_up()
                self.main()
                self.print_cnt()


    def print_cnt(self):
        print(self.cnt)
        self.cntEdit.setText(str(self.cnt))

app = QApplication()
win = MyApp()
win.show()
app.exec()