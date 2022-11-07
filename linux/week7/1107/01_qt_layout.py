from PySide6.QtWidgets import *

app = QApplication()
win = QWidget()
lay = {
        'main': QVBoxLayout(),
        'head': QHBoxLayout(),
        'body': QVBoxLayout()
       }

btn = {
    '1': QPushButton("ONE"),
    '2': QPushButton("TWO"),
    '3': QPushButton("THREE"),
    '4': QPushButton("FOUR"),
    '5': QPushButton("FIVE"),
    '6': QPushButton("SIX"),
}

lay['head'].addWidget(btn['1'])
lay['head'].addWidget(btn['2'])
lay['head'].addWidget(btn['3'])

lay['body'].addWidget(btn['4'])
lay['body'].addWidget(btn['5'])
lay['body'].addWidget(btn['6'])

lay['main'].addLayout(lay['head'])
lay['main'].addLayout(lay['body'])

win.setLayout(lay['main'])
win.show()
app.exec()