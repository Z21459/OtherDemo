#include "QtComBox.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtComBox w;
    w.show();
    return a.exec();
}
