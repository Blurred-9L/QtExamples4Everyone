#include <QApplication>

#include "CalcWidget.h"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    CalcWidget widget;
    
    widget.setAttribute(Qt::WA_QuitOnClose);
    widget.show();
    
    return app.exec();
}
