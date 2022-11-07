from PySide6.QtWidgets import *

class QT_OBJ():
    def __init__(self):
        self.app = QApplication()
        self.win = QWidget()
        self.alert = None
        self.btn = None
        self.text = None
        self.lay = {}

    def set_lay(self, direction):
        layout = QHBoxLayout() if direction == 'h' else QVBoxLayout()
        self.lay[direction] = layout


    def set_text(self):
        self.set_lay('h')
        self.text = QLineEdit(self.win).text()
        self.lay['h'].addWidget(self.text)


    def set_btn(self, name, callback):
        self.btn = QPushButton(name, self.win)
        self.btn.clicked.connect(callback)
        self.lay['h'].addWidget(self.btn)
        self.win.show()


    def get_message(self):
        self.alert.setText(self.text)
        self.alert.exec()
        self.win.show()
        self.app.exec()

    def callback(self):
        print(self.text)
        self.get_message()


def main():
    qt = QT_OBJ()
    qt.set_lay('h')
    qt.set_btn('PUSH', qt.callback())


main()
