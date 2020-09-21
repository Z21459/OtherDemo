#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtAlgorithms>//算法库
#include <QErrorMessage>
#include <QLabel>
#include <QQueue>

typedef QQueue <QLabel*> QQueueLabel;



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
    void readSettings();
    void writeSettings();
    void onTestQueue()
    {
        q_label.push_back(new QLabel("11"));
        QLabel *top = q_label.dequeue();//返回list 的第一个并删除第一个
        q_label.enqueue(top);//插入对应值
    }
private:
    Ui::MainWindow *ui;
    QQueueLabel q_label;
};

#endif // MAINWINDOW_H
