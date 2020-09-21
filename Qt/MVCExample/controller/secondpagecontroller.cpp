#include "secondpagecontroller.h"
#include <QDebug>

QSecondPageController *QSecondPageController::m_instance = new QSecondPageController();

QSecondPageController *QSecondPageController::GetInstance()
{
    return m_instance;
}

QSecondPageController::QSecondPageController()
{
    onInit();
}
void QSecondPageController::onInit()
{
    connect(this,SIGNAL(startedCount_signal()),this,SLOT(onModel()));
}

void QSecondPageController::onModel()
{
    m_thread = new QThread;
    m_second_func = new QSecondPageFunction();
    m_second_func->moveToThread(m_thread);
    connect(m_thread,SIGNAL(finished()),m_thread,SLOT(deleteLater()));//启动线程  执行结果
    connect(m_thread,SIGNAL(started()),m_second_func,SLOT(count_slot()));
    connect(this,SIGNAL(finishedCount_signal()),this,SLOT(onQuitThread()));
    connect(m_thread,SIGNAL(finished()),this,SLOT(onSendSlot()));
    m_thread->start();//启动

}
void QSecondPageController::onQuitThread()
{
    m_thread->quit();
    m_thread->wait();
}
void QSecondPageController::onSendSlot()
{
    qDebug() << tr("计算结束");
    emit showFinishedCountUI_signal();
}
