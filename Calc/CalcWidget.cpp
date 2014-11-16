#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QButtonGroup>

#include "CalcWidget.h"
#include "BasicCalc.h"

const int CalcWidget::N_NUM_BUTTONS = 10;
const int CalcWidget::N_OP_BUTTONS = 4;

CalcWidget::CalcWidget(QWidget * parent) :
    QWidget(parent)
{
    const char * ops [] = {"+", "-", "*", "/"};
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    QGridLayout * calcLayout = new QGridLayout();
    
    calcLineEdit = new QLineEdit();
    calcLineEdit->setReadOnly(true);
    mainLayout->addWidget(calcLineEdit);
    
    QButtonGroup * numberGroup = new QButtonGroup(this);
    numberButtons = new QPushButton * [N_NUM_BUTTONS];
    for (int i = 0; i < N_NUM_BUTTONS; i++) {
        numberButtons[i] = new QPushButton(QString::number(i));
        numberGroup->addButton(numberButtons[i], i);
    }
    calcLayout->addWidget(numberButtons[7], 0, 0);
    calcLayout->addWidget(numberButtons[8], 0, 1);
    calcLayout->addWidget(numberButtons[9], 0, 2);
    calcLayout->addWidget(numberButtons[4], 1, 0);
    calcLayout->addWidget(numberButtons[5], 1, 1);
    calcLayout->addWidget(numberButtons[6], 1, 2);
    calcLayout->addWidget(numberButtons[1], 2, 0);
    calcLayout->addWidget(numberButtons[2], 2, 1);
    calcLayout->addWidget(numberButtons[3], 2, 2);
    calcLayout->addWidget(numberButtons[0], 3, 0);
    
    clearButton = new QPushButton("C");
    calcLayout->addWidget(clearButton, 3, 1);
    
    resultButton = new QPushButton("=");
    calcLayout->addWidget(resultButton, 3, 2);
    
    QButtonGroup * opGroup = new QButtonGroup(this);
    opButtons = new QPushButton * [N_OP_BUTTONS];
    for (int i = 0; i < N_OP_BUTTONS; i++) {
        opButtons[i] = new QPushButton(ops[i]);
        opGroup->addButton(opButtons[i], i);
        calcLayout->addWidget(opButtons[i], N_OP_BUTTONS - 1 - i, 4);
    }
    mainLayout->addLayout(calcLayout);
    
    calc = new BasicCalc(this);
    
    connect(numberGroup, SIGNAL(buttonClicked(int)), calc, SLOT(putDigit(int)));
    connect(clearButton, SIGNAL(clicked()), calc, SLOT(clear()));
    connect(opGroup, SIGNAL(buttonClicked(int)), calc, SLOT(saveOperation(int)));
    connect(resultButton, SIGNAL(clicked()), calc, SLOT(computeResult()));
    
    connect(calc, SIGNAL(operandChanged(const QString &)),
            calcLineEdit, SLOT(setText(const QString &)));
}

CalcWidget::~CalcWidget()
{
    if (numberButtons != 0) {
        delete [] numberButtons;
    }
    if (opButtons != 0) {
        delete [] opButtons;
    }
}
