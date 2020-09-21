#include "secondpagewidget.h"
#include <QPushButton>
#include "controller/secondpagecontroller.h"
#include <QDebug>
#include <QMessageBox>
QSecondPageWidget::QSecondPageWidget(QWidget *parent) : QWidget(parent)
{
    setupUI();
}

void QSecondPageWidget::setupUI()
{
    QPushButton *firstPage = new QPushButton(tr("我是第二页的页面:点击我实现2*3计算功能(业务逻辑功能)"));
    mainLayout = new QVBoxLayout(this);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(firstPage);
    mainLayout->addStretch();
    connect(firstPage,SIGNAL(clicked()),this,SLOT(onStart()));
    connect(QSecondPageController::GetInstance(),SIGNAL(showFinishedCountUI_signal()),this,
            SLOT(onShowResult()));
}

void QSecondPageWidget::onStart()
{
    QSecondPageController::GetInstance()->startedCount_signal();
}

void QSecondPageWidget::onShowResult()
{
    qDebug() << tr("result");
    QMessageBox::warning(this,QStringLiteral("结果界面"),QStringLiteral("显示计算后界面!!!"),QMessageBox::Yes,QMessageBox::No);
}
