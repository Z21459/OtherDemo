#include "mainwindow.h"
#include <QApplication>

#include "sliderlcd.h"
/*
解析QObject  槽和函数   元对象   值和对象
QSettings是一个持久的键/值对映射    保存此应用程序最近打开的文档

资源  视图  图像
QPixmap -- setPixmap(Qpixmap pm) ：针对在屏幕上绘制图形而设计和优化
QImage：针对输入输出操作和直接像素访问而设计
QPicture：针对可扩展性而设计


QAction QMenus  QMenuBar //菜单栏设置
QToolbars QActionGroups
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //SliderLCD slcd;
    //slcd.show();

    return a.exec();
}
