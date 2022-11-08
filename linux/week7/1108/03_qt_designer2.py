from PySide6.QtWidgets import *
from design03 import Ui_MainWindow
import hashlib

class MyApp(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.ui = Ui_MainWindow()
        self.msg = QMessageBox()
        self.ui.setupUi(self)
        self.my_name = ""
        self.ur_name = ""
        self.ur_age = 0

    def show_message(self, s):
        print(s)
        self.msg.setText(s)
        self.msg.exec()

    def print_result(self):
        '''
            • textBox1, 2 문자열을 특정 숫자로 만든다 .  Hash Function 사용
            • 두 숫자의 합 + ( 나이 x 777 ) 을 구한다
            • 이렇게 나온 값을 모듈러 연산을 통해 0 ~ 100 의 수치로 변환  '%'
        '''
        str1 = self.ui.myNameEdit.text()
        str2 = self.ui.urNameEdit.text()
        hashcode1 = hashlib.sha256(str1.encode()).hexdigest()
        hashcode2 = hashlib.sha256(str2.encode()).hexdigest()
        sum1 = int(hashcode1, 16) + int(hashcode2, 16)
        sum2 = int(self.ui.urAgeEdit.text()) * 777
        prob = (sum1 + sum2) % 101
        self.show_message(f"{str1}님과 {str2}님의 궁합은 {prob}%")

    def clear(self):
        print("clear")
        self.ui.myNameEdit.clear()
        self.ui.urNameEdit.clear()
        self.ui.urAgeEdit.clear()

app = QApplication()
win = MyApp()
win.show()
app.exec()