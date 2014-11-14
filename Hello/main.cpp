#include <QApplication>

#include "HelloWidget.h"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    HelloWidget widget;
    
    widget.setAttribute(Qt::WA_QuitOnClose);
    widget.show();
    
    app.exec();
    
    return 0;
}
