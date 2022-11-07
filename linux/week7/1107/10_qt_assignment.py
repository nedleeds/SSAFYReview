from PySide6.QtWidgets import *


class QT_OBJ():
    def __init__(self):
        self.app = QApplication()
        self.win = QMainWindow()
        self.statusBar = self.win.statusBar()
        self.menu = {}

    def set_widget(self, title, pos):
        self.win.setWindowTitle(title)
        self.win.setGeometry(pos[0], pos[1], pos[2], pos[3])

    def set_menu_bar(self, mode="추가"):
        menu = self.win.menuBar()
        self.menu[mode] = menu.addMenu(mode)

    def set_status_bar(self, status):
        self.statusBar.showMessage(status)


    def set_center_menu(self):
        layer = {
            'menu': QVBoxLayout(),
            'button': QHBoxLayout()
        }

        # layout 설정
        main = QWidget()
        self.win.setCentralWidget(main)
        label = QLabel("\t인맥을 관리합시다.", main)
        label.adjustSize()

        form = QFormLayout()
        line1 = QLineEdit()


def main():
    qt = QT_OBJ()
    qt.set_widget(title="인맥 관리 프로그램", pos=(400, 150, 700, 450))
    qt.set_menu_bar("추가")
    qt.set_menu_bar("제거")
    qt.set_status_bar("인맥을 관리합니다")
    qt.set_center_menu()


    qt.win.show()
    qt.app.exec()


main()
