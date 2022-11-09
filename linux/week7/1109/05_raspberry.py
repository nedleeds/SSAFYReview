from gpiozero import LED, Button, PWMLED
from gpiozero import AngularServo
from time import *
from PySide2.QtWidgets import *
from .design.design_05 import Ui_Form

class MyApp(QWidget, Ui_Form):
    def __init__(self):
        super().__init__()
        Ui_Form.setupUi(self, self)
        self.led1 = PWMLED(16)
        self.led2 = PWMLED(20)

    def led_on(self):
        self.led1.value = 1
        self.led2.value = 1
    
    def led_off(self):
        self.led1.value = 0
        self.led2.value = 0
    
    def closeEvent(self, e):
        self.led1.value.close()
        self.led2.value.close()

    def set_dial(self, val):
        print(val)
        self.led1.value = val / 100
        self.led2.value = (100 - val) / 100


app = QApplication()

win = MyApp()
win.show()

app.exec_()
