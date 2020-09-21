#include "firstpagecontroller.h"
#include <QDebug>

QFirstPageController *QFirstPageController::m_instance = new QFirstPageController();

QFirstPageController *QFirstPageController::GetInstance()
{
    return m_instance;
}

QFirstPageController::QFirstPageController()
{
    /*初始化*/
    initController();
}

void QFirstPageController::initController()
{
    /*绑定信号与槽函数*/
    connect(this,SIGNAL(startedCount_signal()),this,SLOT(startCountSlot()));
}

void QFirstPageController::startCountSlot()//放在这里 进行结果计算式
{
    /*启动一对一镜像线程*/
    threadCount = new QThread;
    firstPageFunction = new QFirstPageFunction();
    firstPageFunction->moveToThread(threadCount);
    connect(threadCount,SIGNAL(finished()),threadCount,SLOT(deleteLater()));
    connect(threadCount,SIGNAL(started()),firstPageFunction,SLOT(count_slot()));   /*多线程槽函数*/
    connect(this,SIGNAL(finishedCount_signal()),this,SLOT(quitCountThreadSlot()));
    connect(threadCount,SIGNAL(finished()),this,SLOT(finishedCountThreadSlot()));//当线程执行完成后   触发信号view信号  显示结果
    threadCount->start();
}

void QFirstPageController::quitCountThreadSlot()
{
    threadCount->quit();
    threadCount->wait();
}

void QFirstPageController::finishedCountThreadSlot()
{
    qDebug() << tr("完成计算逻辑功能!!");
    emit showFinishedCountUI_signal();
}
