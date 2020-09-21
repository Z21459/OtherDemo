#include "sliderlcd.h"
#include <QLCDNumber>
#include <QSlider>
#include <QErrorMessage>
#include <QDockWidget>

SliderLCD::SliderLCD(int min,int max)
    :m_minValue(min),m_maxValue(max)
{
    resize(500,500);
    initSliderLCD();
}

void SliderLCD::initSliderLCD()
{

    m_lcd = new QLCDNumber();
    m_lcd->setSegmentStyle(QLCDNumber::Filled);
    QDockWidget *lcdDock = new QDockWidget("LCD");
    lcdDock->setFeatures(QDockWidget::DockWidgetClosable);
    lcdDock->setWidget(m_lcd);
    addDockWidget(Qt::LeftDockWidgetArea,lcdDock);

    m_slider = new QSlider();
    QDockWidget *sDock = new QDockWidget("How");
    sDock->setWidget(m_slider);
    sDock->setFeatures(QDockWidget::DockWidgetMovable);
    addDockWidget(Qt::BottomDockWidgetArea,sDock);

    m_slider ->setRange(m_minValue,m_maxValue);
    m_slider->setValue(0);
    m_slider->setFocusPolicy(Qt::StrongFocus);
    m_slider->setSingleStep(1);//左右减1
    m_slider->setPageStep(20);//上下减一
    m_slider->setFocus();


    connect(m_slider,SIGNAL(valueChanged(int)),this,SLOT(checkValue(int)));
    connect(m_slider,SIGNAL(valueChanged(int)),m_lcd,SLOT(display(int)));

    connect(this,SIGNAL(tooMuch()),this,SLOT(showMessage()));
    m_errorMsg = nullptr;

}

void SliderLCD::checkValue(int newValue)
{
    if(newValue >120)
        emit tooMuch();
}

void SliderLCD::showMessage()
{
    if(m_errorMsg == nullptr)
        m_errorMsg = new QErrorMessage(this);
    if(!m_errorMsg->isVisible())
    {
        QString message("too much");
        m_errorMsg->showMessage(message);//直接调用
    }

}



