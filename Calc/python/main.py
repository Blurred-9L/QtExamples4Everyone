# encoding: utf-8

import sys
from PyQt4 import QtGui

from CalcWidget import CalcWidget

def main():
    app = QtGui.QApplication(sys.argv)
    
    widget = CalcWidget()
    widget.show()
    
    sys.exit(app.exec_())

if __name__ == "__main__":
    main()
