#include <QApplication>
#include "mywindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    myWindow *myWin = new myWindow();
    myWin->show();
    return app.exec();
}
