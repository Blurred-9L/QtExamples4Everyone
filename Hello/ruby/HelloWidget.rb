# encoding: utf-8

require 'Qt'

class HelloWidget < Qt::Widget
    slots :sayHello

public
    def initialize(parent = nil)
        super(parent)
        mainLayout = Qt::VBoxLayout.new(self)
        nameLayout = Qt::HBoxLayout.new
        
        @nameLabel = Qt::Label.new('Name:')
        @nameLineEdit = Qt::LineEdit.new
        nameLayout.addWidget(@nameLabel)
        nameLayout.addWidget(@nameLineEdit)
        mainLayout.addLayout(nameLayout)
        
        @logTextEdit = Qt::TextEdit.new
        @logTextEdit.setReadOnly(true)
        mainLayout.addWidget(@logTextEdit)
        
        @helloButton = Qt::PushButton.new('Say hello')
        mainLayout.addWidget(@helloButton)
        
        @helloButton.connect(SIGNAL('clicked()'), self, :sayHello)
    end
    
    def sayHello()
        if not @nameLineEdit.text.empty?
            @logTextEdit.append('Hello ' + @nameLineEdit.text + '!')
        end
    end
end
        
