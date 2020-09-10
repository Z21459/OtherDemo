#include "subthread.h"

SubThread::SubThread(QObject *parent):
    QObject (parent)
{

}

void SubThread::processData(QVariant inputdata)//处理主线程发送的数据
{
    qDebug()<<"from thread slot:" <<QThread::currentThreadId();
    qDebug() << "SubThread";
    vec1.clear();
    vec2.clear();
    /*for (int i =0;i<5;i++) {
        vec1.push_back(i);
        vec2.push_back(i+1);
    }*/

    QVector<int> cc = inputdata.value<QVector<int>>();//得到数据
    for (int i =0;i<cc.size();i++) {
        vec1.push_back(cc[i]*2);
        vec2.push_back(cc[i]/2);
    }

    QVariant data1,data2;
    data1.setValue(vec1);
    data2.setValue(vec2);
    emit sendMag(data1,data2);
}
