#include "IPGwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IPGwidget w;
    w.show();
    return a.exec();
}
