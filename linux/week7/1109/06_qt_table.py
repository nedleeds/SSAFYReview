from gpiozero import LED, Button, PWMLED
from gpiozero import AngularServo
from time import *
from PySide2.QtWidgets import *
from .design.design_06 import Ui_MainWindow

class MyApp(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        Ui_MainWindow.setupUi(self, self)
        self.main()

    def main(self):
        t = self.table
        for row in range(t.rowCount()):
            for col in range(t.columnCount()):
                data = t.item(row, col)
                if data:
                    print(f"{data.text():10}", end= ' ')
                else:
                    print()
                    t.setItem(row, col, QTableWidgetItem("HI"))


app = QApplication()

win = MyApp()
win.show()

app.exec_()
