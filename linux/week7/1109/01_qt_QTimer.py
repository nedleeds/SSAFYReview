from PySide6.QtWidgets import *
from PySide6.QtCore import *


class MyApp(QWidget):
    def __init__(self):
        super(MyApp, self).__init__()
        self.tm = None
        self.main()
        self.cnt = 1

    def main(self):
        self.tm = QTimer()
        self.tm.setInterval(500)
        self.tm.timeout.connect(self.callback)  # callback
        self.tm.start()

    def callback(self):
        print("#", end='')
        if self.cnt % 10 == 0:
            print()
        self.cnt += 1


app = QApplication()
win = MyApp()
win.show()
app.exec()
