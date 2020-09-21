#ifndef SECONDPAGECONTROLLER_H
#define SECONDPAGECONTROLLER_H

#include <QObject>
#include <QThread>
#include "model/secondpagefunction.h"

class QSecondPageController : public QObject
{
    Q_OBJECT
public:
    static QSecondPageController* GetInstance();

public:
    void count_signal();
signals:

    void startedCount_signal();
    void finishedCount_signal();
    void showFinishedCountUI_signal();

private:
    static QSecondPageController *m_instance;
    QSecondPageController();

    void onInit();

private slots:
    void onModel();

    void onQuitThread();
    void onSendSlot();

private:
    QThread *m_thread;
    QSecondPageFunction *m_second_func;
};

#endif // SECONDPAGECONTROLLER_H
