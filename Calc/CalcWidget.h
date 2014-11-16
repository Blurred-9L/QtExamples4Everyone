#ifndef CALC_WIDGET_H
#define CALC_WIDGET_H

#include <QWidget>
#include <QString>

class QLineEdit;
class QPushButton;

class BasicCalc;

class CalcWidget : public QWidget {
private:
    ///
    QLineEdit * calcLineEdit;
    ///
    QPushButton ** numberButtons;
    ///
    QPushButton ** opButtons;
    ///
    QPushButton * resultButton;
    ///
    QPushButton * clearButton;
    ///
    BasicCalc * calc;

public:
    ///
    static const int N_NUM_BUTTONS;
    ///
    static const int N_OP_BUTTONS;

    ///
    CalcWidget(QWidget * parent = 0);
    ///
    virtual ~CalcWidget();
};

#endif /// NOT CALC_WIDGET_H
