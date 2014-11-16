#include "BasicCalc.h"

#define ADD 0
#define SUBSTRACT 1
#define MULT 2
#define DIV 3

BasicCalc::BasicCalc(QObject * parent) :
    QObject(parent), dataRegister(0), lastOperation(-1), registerEmpty(true)
{
}

//////////////////
// Public slots //
//////////////////

void BasicCalc::putDigit(int digit)
{
    operand += QString::number(digit);
    emit operandChanged(operand);
}

void BasicCalc::clear()
{
    operand = "";
    registerEmpty = true;
    operandChanged(operand);
}

void BasicCalc::saveOperation(int operation)
{
    if (registerEmpty) {
        dataRegister = operand.toLongLong();
        lastOperation = operation;
        registerEmpty = false;
    } else {
        dataRegister = doOperation(lastOperation);
        lastOperation = operation;
        operand.setNum(dataRegister);
    }
    emit operandChanged(operand);
    operand = "";
}

void BasicCalc::computeResult()
{
    if (!operand.isEmpty()) {
        dataRegister = doOperation(lastOperation);
    }
    lastOperation = -1;
    operand.setNum(dataRegister);
    emit operandChanged(operand);
    operand = "";
}

/////////////
// Private //
/////////////

long long BasicCalc::doOperation(int operation)
{
    long long result = dataRegister;
    
    switch (operation) {
    case ADD:
        result = dataRegister + operand.toLongLong();
        break;
    case SUBSTRACT:
        result = dataRegister - operand.toLongLong();
        break;
    case MULT:
        result = dataRegister * operand.toLongLong();
        break;
    case DIV:
        result = dataRegister / operand.toLongLong();
        break;
    }
    
    return result;
}
