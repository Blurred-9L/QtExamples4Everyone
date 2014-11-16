#ifndef BASIC_CALC_H
#define BASIC_CALC_H

#include <QObject>
#include <QString>

class BasicCalc : public QObject {
Q_OBJECT

private:
    ///
    QString operand;
    ///
    long long dataRegister;
    ///
    int lastOperation;
    ///
    bool registerEmpty;
    
    ///
    long long doOperation(int operation);
    
public:
    ///
    BasicCalc(QObject * parent = 0);
    
public slots:
    ///
    void putDigit(int digit);
    ///
    void saveOperation(int operation);
    ///
    void clear();
    ///
    void computeResult();
    
signals:
    ///
    void operandChanged(const QString & operand);
};

#endif /// NOT BASIC_CALC_H
