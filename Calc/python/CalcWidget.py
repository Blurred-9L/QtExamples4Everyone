# encoding: utf-8

from PyQt4 import QtGui
from BasicCalc import BasicCalc

class CalcWidget(QtGui.QWidget):

    ops = ['+', '-', '*', '/']
    N_NUM_BUTTONS = 10
    N_OP_BUTTONS = 4

    def __init__(self, parent = None):
        super(QtGui.QWidget, self).__init__(parent)
        mainLayout = QtGui.QVBoxLayout(self)
        calcLayout = QtGui.QGridLayout()
        
        self.calcLineEdit = QtGui.QLineEdit()
        self.calcLineEdit.setReadOnly(True)
        mainLayout.addWidget(self.calcLineEdit)
        
        numberGroup = QtGui.QButtonGroup(self)
        self.numberButtons = []
        for i in range(0, self.N_NUM_BUTTONS):
            self.numberButtons.append(QtGui.QPushButton(str(i)))
            numberGroup.addButton(self.numberButtons[i], i)
        calcLayout.addWidget(self.numberButtons[7], 0, 0)
        calcLayout.addWidget(self.numberButtons[8], 0, 1)
        calcLayout.addWidget(self.numberButtons[9], 0, 2)
        calcLayout.addWidget(self.numberButtons[4], 1, 0)
        calcLayout.addWidget(self.numberButtons[5], 1, 1)
        calcLayout.addWidget(self.numberButtons[6], 1, 2)
        calcLayout.addWidget(self.numberButtons[1], 2, 0)
        calcLayout.addWidget(self.numberButtons[2], 2, 1)
        calcLayout.addWidget(self.numberButtons[3], 2, 2)
        calcLayout.addWidget(self.numberButtons[0], 3, 0)
        
        self.clearButton = QtGui.QPushButton("C")
        calcLayout.addWidget(self.clearButton, 3, 1)
        
        self.resultButton = QtGui.QPushButton("=")
        calcLayout.addWidget(self.resultButton, 3, 2)
        
        opGroup = QtGui.QButtonGroup(self)
        self.opButtons = []
        for i in range(0, self.N_OP_BUTTONS):
            self.opButtons.append(QtGui.QPushButton(self.ops[i]))
            opGroup.addButton(self.opButtons[i], i)
            calcLayout.addWidget(self.opButtons[i], self.N_OP_BUTTONS - 1 - i, 4)
            
        mainLayout.addLayout(calcLayout)
        
        self.calc = BasicCalc(self)
        numberGroup.buttonClicked[int].connect(self.calc.putDigit)
        self.clearButton.clicked.connect(self.calc.clear)
        opGroup.buttonClicked[int].connect(self.calc.saveOperation)
        self.resultButton.clicked.connect(self.calc.computeResult)
        self.calc.operandChanged.connect(self.calcLineEdit.setText)

