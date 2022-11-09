from PySide6.QtWidgets import *
# from test import Ui_MainWindow
from .design.design_02 import Ui_MainWindow

class MyApp(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.age = ""
        self.msg = QMessageBox()

    def show_message(self, s):
        print(s)
        self.msg.setText(s)
        self.msg.exec()

    def set_age(self):
        self.age = int(self.ui.ageEdit.text())

    def age_gf(self):
        self.show_message(f"당신 여자친구 나이는 {self.age - 4}에서 {self.age + 4} 정도")

    def age_wife(self):
        self.show_message(f"당신 부인 나이 역시 {self.age - 4}에서 {self.age + 4} 정도")

    def age_firstLove(self):
        self.show_message(f"당신 첫사랑은 현재 {self.age - 2}살")

    def age_expected(self):
        self.show_message(f"당신 기대수명은 {self.age + 50} 정도")

    def print_aminie(self):
        self.show_message(f"애미나이!")

app = QApplication()
win = MyApp()
win.show()
app.exec()