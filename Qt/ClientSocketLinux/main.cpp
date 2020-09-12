#include "mainwindow.h"
#include <QApplication>

#include <QCoreApplication>
#include <QtWidgets>
#include <QtGui>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>

#include "serverwidget.h"
#include "clientwidget.h"

/*
 *Qt里面提供的Socket都是非阻塞的
 * QTextStream – 文本流, 操作轻量级数据(int, double, QString),
 * 数据写入文件中之后以文本的方式呈现。
 * QDataStream – 数据流, 通过数据流可以操作各种数据类型, 包括类对象, 存储到文件中数据可以还原到内存。
 * QTextStream, QDataStream可以操作磁盘文件, 也可以操作内存数据, 通过流对象可以将数据打包到内存, 进行数据的传输.

 */
int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/


    //单线程的
    QApplication a(argc, argv);
    ServerWidget w;
    w.show();

    ClientWidget w2;
    w2.show();//显示另外一个窗口

    return a.exec();


}
