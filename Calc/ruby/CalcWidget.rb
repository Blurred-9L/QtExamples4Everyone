# encoding: utf-8

require 'Qt'
require './BasicCalc.rb'

class CalcWidget < Qt::Widget
    OPS = ['+', '-', '*', '/']
    N_NUM_BUTTONS = 10
    N_OP_BUTTONS = 4
    
public
    slots 'setText(const QString&)'

    def initialize(parent = nil)
        super(parent)
        mainLayout = Qt::VBoxLayout.new(self)
        calcLayout = Qt::GridLayout.new
        
        @calcLineEdit = Qt::LineEdit.new
        @calcLineEdit.setReadOnly(true)
        mainLayout.addWidget(@calcLineEdit)
        
        numberGroup = Qt::ButtonGroup.new
        @numberButtons = []
        N_NUM_BUTTONS.times do |i|
            @numberButtons.push(Qt::PushButton.new(i.to_s))
            numberGroup.addButton(@numberButtons[i], i)
        end
        calcLayout.addWidget(@numberButtons[7], 0, 0)
        calcLayout.addWidget(@numberButtons[8], 0, 1)
        calcLayout.addWidget(@numberButtons[9], 0, 2)
        calcLayout.addWidget(@numberButtons[4], 1, 0)
        calcLayout.addWidget(@numberButtons[5], 1, 1)
        calcLayout.addWidget(@numberButtons[6], 1, 2)
        calcLayout.addWidget(@numberButtons[1], 2, 0)
        calcLayout.addWidget(@numberButtons[2], 2, 1)
        calcLayout.addWidget(@numberButtons[3], 2, 2)
        calcLayout.addWidget(@numberButtons[0], 3, 0)
        
        @clearButton = Qt::PushButton.new('C')
        calcLayout.addWidget(@clearButton, 3, 1)
        
        @resultButton = Qt::PushButton.new('=')
        calcLayout.addWidget(@resultButton, 3, 2)
        
        opGroup = Qt::ButtonGroup.new(self)
        @opButtons = []
        N_OP_BUTTONS.times do |i|
            @opButtons.push(Qt::PushButton.new(OPS[i]))
            opGroup.addButton(@opButtons[i], i)
            calcLayout.addWidget(@opButtons[i], N_OP_BUTTONS - 1 - i, 4)
        end
        
        mainLayout.addLayout(calcLayout)
        
        @calc = BasicCalc.new(self)
        Qt::Object.connect(numberGroup, SIGNAL('buttonClicked(int)'),
                           @calc, SLOT('putDigit(int)'))
        Qt::Object.connect(@clearButton, SIGNAL('clicked()'),
                           @calc, SLOT('clear()'))
        Qt::Object.connect(opGroup, SIGNAL('buttonClicked(int)'),
                           @calc, SLOT('saveOperation(int)'))
        Qt::Object.connect(@resultButton, SIGNAL('clicked()'),
                           @calc, SLOT('computeResult()'))
        Qt::Object.connect(@calc, SIGNAL('operandChanged(const QString&)'),
                           @calcLineEdit, SLOT('setText(const QString&)'))
    end
    
    def setText(text)
        @calcLineEdit.setText(text)
    end
    
end
