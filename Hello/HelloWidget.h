#ifndef HELLO_WIDGET_H
#define HELLO_WIDGET_H

#include <QWidget>

class QLineEdit;
class QLabel;
class QTextEdit;
class QPushButton;

class HelloWidget : public QWidget {
Q_OBJECT

private:
    ///
    QLabel * nameLabel;
    ///
    QLineEdit * nameLineEdit;
    ///
    QTextEdit * logTextEdit;
    ///
    QPushButton * helloButton;
    
public:
    ///
    HelloWidget(QWidget * parent = 0);
    ///
    virtual ~HelloWidget();
    
private slots:
    ///
    void sayHello();
};

#endif /// NOT HELLO_WIDGET_H
