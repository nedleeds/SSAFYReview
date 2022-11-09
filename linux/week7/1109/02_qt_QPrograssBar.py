from PySide6.QtWidgets import *
from PySide6.QtCore import *
from QProgressBar import Ui_Form


class myapp(QWidget, Ui_Form):
    def __init__(self):
        super(myapp, self).__init__()
        self.setupUi(self)
        self.tm = QTimer()
        self.pb = self.progressBar
        self.main()

    def main(self):
        self.pb.setValue(0)
        self.tm.setInterval(10)
        self.tm.timeout.connect(self.callback)

    def callback(self):
        if self.pb.value() == 100:
            self.tm.stop()
        self.pb.setValue(self.pb.value() + 1)

    def go(self):
        if not self.tm.isActive():
            self.tm.start()

    def pause(self):
        if self.tm.isActive():
            self.tm.stop()

    def stop(self):
        self.pb.setValue(0)


app = QApplication()
win = myapp()
win.show()
app.exec()
