# encoding: utf-8

from PyQt4 import QtGui

class HelloWidget(QtGui.QWidget):

    def __init__(self, parent = None):
        super(QtGui.QWidget, self).__init__(parent)
        mainLayout = QtGui.QVBoxLayout(self)
        nameLayout = QtGui.QHBoxLayout()
        
        self.nameLabel = QtGui.QLabel('Name:')
        self.nameLineEdit = QtGui.QLineEdit()
        nameLayout.addWidget(self.nameLabel)
        nameLayout.addWidget(self.nameLineEdit)
        mainLayout.addLayout(nameLayout)
        
        self.logTextEdit = QtGui.QTextEdit()
        self.logTextEdit.setReadOnly(True)
        mainLayout.addWidget(self.logTextEdit)
        
        self.helloButton = QtGui.QPushButton('Say hello:')
        mainLayout.addWidget(self.helloButton)
        
        self.helloButton.clicked.connect(self.sayHello)
        
    def sayHello(self):
        if self.nameLineEdit.text():
            self.logTextEdit.append("Hello " + self.nameLineEdit.text() + "!")

