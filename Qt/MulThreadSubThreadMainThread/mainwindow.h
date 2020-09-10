#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "subthread.h"


//主线程
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void startThread(QVariant);
private slots://接收子线程处理的数据
    void getSubData(QVariant data1,QVariant data2);
    void closeAll();//关闭主线程和子线程
    void btnEmit();//触发信号 传递给子线程

private:
    QThread *thread;
    SubThread *myThread;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
