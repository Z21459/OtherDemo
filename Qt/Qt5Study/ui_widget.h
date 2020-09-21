/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPlainTextEdit *t_show_textedit;
    QPushButton *c_btn_open;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(700, 500);
        t_show_textedit = new QPlainTextEdit(Widget);
        t_show_textedit->setObjectName(QString::fromUtf8("t_show_textedit"));
        t_show_textedit->setGeometry(QRect(10, 10, 261, 131));
        c_btn_open = new QPushButton(Widget);
        c_btn_open->setObjectName(QString::fromUtf8("c_btn_open"));
        c_btn_open->setGeometry(QRect(20, 150, 75, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        c_btn_open->setText(QCoreApplication::translate("Widget", "OpenFile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
