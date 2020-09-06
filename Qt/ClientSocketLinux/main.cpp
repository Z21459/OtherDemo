#include "mainwindow.h"
#include <QApplication>

#include <QCoreApplication>
#include <QtWidgets>
#include <QtGui>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
