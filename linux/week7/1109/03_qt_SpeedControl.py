from PySide6.QtWidgets import *
from PySide6.QtCore import *
from SpeedControl import Ui_Form


class myapp(QWidget, Ui_Form):
    def __init__(self):
        super(myapp, self).__init__()
        self.setupUi(self)
        self.tm = QTimer()
        self.pb = self.progressBar
        self.main()
        self.step = 1

    def main(self):
        self.pb.setValue(0)

    def callback(self):
        self.pb.setValue()

    def up(self):
        self.pb.setValue(self.get_value('up'))

    def down(self):
        self.pb.setValue(self.get_value('down'))

    def speed_control(self):
        self.step = self.speedCtrl.value()

    def get_value(self, mode):
        if mode == 'up':
            val = self.pb.value() + self.step
            val = val if val < 100 else 100
        else:
            val = self.pb.value() - self.step
            val = val if val > 0 else 0
        return val

app = QApplication()
win = myapp()
win.show()
app.exec()
