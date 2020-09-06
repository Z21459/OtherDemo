#ifndef TESTQTHREAD_H
#define TESTQTHREAD_H

#endif // TESTQTHREAD_H


#include <QThread>
#include <QObject>
#include<iostream>
using namespace std;
class Counter:public QObject
{
    Q_OBJECT
private:
    int value;
signals:
    void sendValue(int value);
public slots:
    void setValue(int val)
    {
        int i = val;
        value = val;
        emit sendValue(value);
        cout << i << "counter" << endl;
    }
public:
    Counter(int val):value(val){}
    Counter():value(0){}
    friend ostream &operator<<(ostream &os,const Counter &c)
    {
        return os << c.value;
    }
};

class Counter1:public QObject
{
    Q_OBJECT
private:
    int value;
public slots:
    void getValueFun1(int val)
    {
       value = val;
       cout << value << "Counter1" << endl;
    }
public:
    Counter1(int val):value(val){}
    Counter1():value(0){}
};

class Counter2:public QObject
{
    Q_OBJECT
private:
    int value;

public slots:
    void getValueFunc2(int val)
    {
        int i = val;
        value = val;
        cout << i << "Counter2" << endl;
    }

public:
    Counter2(int val):value(val){}
    Counter2():value(0){}
};

class Produce:public QThread
{
private:
    Counter1 *m_c1;
public:
    void run(){
        Counter Producer;
        QObject::connect(&Producer,SIGNAL(sendValue(int)),m_c1,
                         SLOT(getValueFun1(int)));
        Producer.setValue(12);
    }
    void SetCount(Counter1 *c1){
        m_c1 = c1;
    }
};
