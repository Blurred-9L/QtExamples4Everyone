# encoding: utf-8

require 'Qt'

class BasicCalc < Qt::Object
    ADD = 0
    SUBS = 1
    MULT = 2
    DIV = 3
    
private
    def doOperation(operation)
        result = @dataRegister
        
        if operation == ADD
            result = @dataRegister + @operand.to_i
        elsif operation == SUBS
            result = @dataRegister - @operand.to_i
        elsif operation == MULT
            result = @dataRegister * @operand.to_i
        elsif operation == DIV
            result = @dataRegister / @operand.to_i
        end
        
        return result
    end

public
    slots 'putDigit(int)', 'clear()', 'saveOperation(int)', 'computeResult()'
    signals 'operandChanged(const QString&)'

    def initialize(parent = nil)
        super(parent)
        @operand = ''
        @dataRegister = 0
        @lastOperation = -1
        @registerEmpty = true
    end
    
    def putDigit(digit)
        @operand += digit.to_s
        emit operandChanged(@operand)
    end
    
    def clear()
        @operand = ''
        @registerEmpty = true
        emit operandChanged(@operand)
    end
    
    def saveOperation(operation)
        if @registerEmpty
            @dataRegister = @operand.to_i
            @lastOperation = operation
            @registerEmpty = false
        else
            @dataRegister = doOperation(@lastOperation)
            @lastOperation = operation
            @operand = @dataRegister.to_s
        end
        emit operandChanged(@operand)
        @operand = ''
    end
    
    def computeResult()
        if @operand.empty?
            @dataRegister = doOperation(@lastOperation)
        end
        @lastOperation = -1
        @operand = @dataRegister.to_s
        emit operandChanged(@operand)
        @operand = ''
    end

end
