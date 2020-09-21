#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedLayout>
#include <QButtonGroup>
#include <QPushButton>
#include "view/firstpagewidget.h"
#include "view/secondpagewidget.h"
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    void setupUI();
    void initMenu();
    void initStackWidget();

    QVBoxLayout *mainLayout;

    QButtonGroup *buttonGroup;
    QStackedLayout *stackLayout;

//    QWidget *firstPageWidget;
//    QWidget *secondPageWidget;

    QPushButton *firstPageBtn;
    QPushButton *secondPageBtn;

    QFirstPageWidget *firstPageWidget;
    QSecondPageWidget *secondPageWidget;

    QHBoxLayout *menuLayout;

private slots:
    void buttonGroupSlot(int);
    void button1();
};

#endif // WIDGET_H
