# encoding: utf-8

import sys
from PyQt4 import QtGui

from HelloWidget import HelloWidget

def main():
    app = QtGui.QApplication(sys.argv)
    
    widget = HelloWidget()
    widget.show()
    
    sys.exit(app.exec_())

if __name__ == "__main__":
    main()
