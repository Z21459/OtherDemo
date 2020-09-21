#ifndef SLIDERLCD_H
#define SLIDERLCD_H

#include <QMainWindow>

class QSlider;
class QLCDNumber;
//class LogWindow;
class QErrorMessage;

class SliderLCD:public QMainWindow
{
    Q_OBJECT

public:
    SliderLCD(int minval =-273,int maxval = 360);
    void initSliderLCD();

public slots:
    void checkValue(int newValue);
    void showMessage();

signals:
    void tooMuch();
private:
    int m_minValue,m_maxValue;
    //LogWindow *m_logWin;
    QErrorMessage *m_errorMsg;
    QLCDNumber *m_lcd;
    QSlider *m_slider;
};

#endif // SLIDERLCD_H
