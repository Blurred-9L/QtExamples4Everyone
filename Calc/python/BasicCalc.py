# encoding: utf-8

from PyQt4 import QtCore
from PyQt4.QtCore import pyqtSignal, pyqtSlot

class BasicCalc(QtCore.QObject):
    
    ADD = 0
    SUBS = 1
    MULT = 2
    DIV = 3
    
    operandChanged = pyqtSignal('QString')
    
    def __init__(self, parent = None):
        super(QtCore.QObject, self).__init__(parent)
        self.operand = ''
        self.dataRegister = 0
        self.lastOperation = -1
        self.registerEmpty = True
        
    @pyqtSlot(int)
    def putDigit(self, digit):
        self.operand += str(digit)
        self.operandChanged.emit(self.operand)
        
    @pyqtSlot()
    def clear(self):
        self.operand = ''
        self.registerEmpty = True
        self.operandChanged.emit(self.operand)
        
    @pyqtSlot(int)
    def saveOperation(self, operation):
        if self.registerEmpty:
            self.dataRegister = int(self.operand)
            self.lastOperation = operation
            self.registerEmpty = False
        else:
            self.dataRegister = self.doOperation(self.lastOperation)
            self.lastOperation = operation
            self.operand = str(self.dataRegister)
        self.operandChanged.emit(self.operand)
        self.operand = ''
        
    @pyqtSlot()
    def computeResult(self):
        if self.operand:
            self.dataRegister = self.doOperation(self.lastOperation)
        self.lastOperation = -1
        self.operand = str(self.dataRegister)
        self.operandChanged.emit(self.operand)
        self.operand = ''
        
    def doOperation(self, operation):
        result = self.dataRegister
        
        if operation == self.ADD:
            result = self.dataRegister + int(self.operand)
        elif operation == self.SUBS:
            result = self.dataRegister - int(self.operand)
        elif operation == self.MULT:
            result = self.dataRegister * int(self.operand)
        elif operation == self.DIV:
            result = self.dataRegister / int(self.operand)
            
        return result

