#include "mainwindow.h"
#include <QApplication>


/*
 * @brief main
 * @param argc
 * @param argv
 * @return
 * 多线程 子线程和主线程之间传递数据
 *
 *在子线程包含头文件  声明信号函数 在构造函数中注册数据
 * 在主线程中包含子线程头文件 声明槽函数
 * 在主线程连接信号和槽函数
 * 在子线程包装数据 emit信号 QVariant
 * 在主线程槽函数下面还原数据
 *
 * //线程两种方式  直接继承QThread  继承QObject 然后moveToFrom到对应子类中
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
