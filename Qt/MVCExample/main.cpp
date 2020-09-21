#include "widget.h"
#include <QApplication>
#include <QIcon>
/*
*架构框架
视图--界面类的编写和展示  Dialog
控制--负责处理逻辑，将UI界面和模型层的功能有机结合起来  所有类采用单例，保证全局唯一一个接口 Control   单例模式
模型--主要负责实现业务逻辑功能  Model

view->(视图点击，发送信号)->control(连接到控制,控制住根据信号，发送对应的信号)->model(接收控制发送的信号，new一个线程，在线程中执行操作)
    ->(线程执行完成后，发送信号通知)control->control发送对应的信号给view(执行刷新)
model发生改变后->通知control->发送信号给view->使view刷新
*/

//这个例子必需使用 mingw debug才可以正常运行     看下修改成vs2017

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*Widget w;
    w.show();*/

    Widget mainWidget;
    mainWidget.resize(960,640);
    mainWidget.setWindowTitle(QString::fromUtf8("Qt/C++架构工程demo版本V1.0.0"));
    mainWidget.setWindowIcon(QIcon(":/resource/main_ico.ico"));
    mainWidget.setStyleSheet("font: bold 12px;");
    mainWidget.show();

    /*QPushButton *btn = new QPushButton("222");
    btn->setObjectName("2222");
    btn->show();*/



    return a.exec();
}
