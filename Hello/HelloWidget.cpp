#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "HelloWidget.h"

HelloWidget::HelloWidget(QWidget * parent) :
    QWidget(parent)
{
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    QHBoxLayout * nameLayout = new QHBoxLayout();
    
    nameLabel = new QLabel("Name: ");
    nameLayout->addWidget(nameLabel);
    
    nameLineEdit = new QLineEdit();
    nameLayout->addWidget(nameLineEdit);
    mainLayout->addLayout(nameLayout);
    
    logTextEdit = new QTextEdit();
    logTextEdit->setReadOnly(true);
    mainLayout->addWidget(logTextEdit);
    
    helloButton = new QPushButton("Say hello!");
    mainLayout->addWidget(helloButton);
    
    connect(helloButton, SIGNAL(clicked()), this, SLOT(sayHello()));
}

HelloWidget::~HelloWidget()
{
}

///////////////////
// Private slots //
///////////////////

void HelloWidget::sayHello()
{
    if (!nameLineEdit->text().isEmpty()) {
        logTextEdit->append("Hello " + nameLineEdit->text());
    }
}
