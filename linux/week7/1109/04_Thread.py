from PySide6.QtWidgets import *
from PySide6.QtCore import *
from time import sleep
from Thread import Ui_Form


class pbThread(QThread):
    def __init__(self):
        super().__init__()
        QThread.mySignal = Signal(int)
        self.lay = None
        self.stop = None

    def run(self):
        for a in range(101):
            if self.stop:
                break
            self.mySignal.emit(a)
            sleep(0.01)

        for a in range(100, -1, -1):
            if self.stop:
                break
            self.mySignal.emit(a)
            sleep(0.01)


class MyApp(QWidget, Ui_Form):
    def __init__(self):
        super().__init__()
        self.ui = Ui_Form.setupUi(self, self)
        self.th = [ pbThread() for _ in range(5) ]

        self.main()

    def set_prog(self, a):
        self.pros.setValue(a)

    def main(self):
        self.pros = []

        for th in self.th:
            th.mySignal.connect(self.set_prog)

        lay = self.verticalLayout
        for i in range(lay.count()):
            self.pros.append(lay.itemAt(i).widget())
            self.pros[i].setValue(0)

    def start(self):
        while True:
            if self.btn_play_1.autoDefault():
                print(self.btn_play_1.autoDefault())
                self.th[0].stop = False
                self.th[0].start()
                break;
            elif self.btn_play_2.autoDefault():
                print(self.btn_play_2.autoDefault())
                self.th[1].stop = False
                self.th[1].start()
                break;
            elif self.btn_play_3.autoDefault():
                print(self.btn_play_3.autoDefault())
                self.th[2].stop = False
                self.th[2].start()
                break;
            elif self.btn_play_4.autoDefault():
                print(self.btn_play_4.autoDefault())
                self.th[3].stop = False
                self.th[3].start()
                break;
            elif self.btn_play_5.autoDefault():
                print(self.btn_play_5.autoDefault())
                self.th[4].stop = False
                self.th[4].start()
                break;

    def stop(self):
        if self.btn_stop_1.autoDefault():
            self.th[0].stop = True
        elif self.btn_stop_1.autoDefault():
            self.th[1].stop = True
        elif self.btn_stop_1.autoDefault():
            self.th[2].stop = True
        elif self.btn_stop_1.autoDefault():
            self.th[3].stop = True
        elif self.btn_stop_1.autoDefault():
            self.th[4].stop = True


app = QApplication()
win = MyApp()
win.show()
app.exec()