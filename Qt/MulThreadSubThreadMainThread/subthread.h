#ifndef SUBTHREAD_H
#define SUBTHREAD_H

#include <QObject>
#include <QVariant>//通用类型变量
#include <QVector>
#include <QtDebug>
#include <QThread>
//子线程
class SubThread:public QObject
{
    Q_OBJECT
public:
    SubThread(QObject *parent = nullptr);
public slots:
    void processData(QVariant);//处理主线程发送的数据
signals:
    void sendMag(QVariant,QVariant);//发送信号给主线程 处理完了，返回结果给主线程显示

private:
    QVector<int>vec1,vec2;

};

#endif // SUBTHREAD_H
