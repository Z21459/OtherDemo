/********************************************************************************
** Form generated from reading UI file 'serverwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWIDGET_H
#define UI_SERVERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerWidget
{
public:
    QTextEdit *textEditRead;
    QTextEdit *textEditWrite;
    QPushButton *c_btn1;
    QPushButton *c_btn2;

    void setupUi(QWidget *ServerWidget)
    {
        if (ServerWidget->objectName().isEmpty())
            ServerWidget->setObjectName(QString::fromUtf8("ServerWidget"));
        ServerWidget->resize(400, 300);
        textEditRead = new QTextEdit(ServerWidget);
        textEditRead->setObjectName(QString::fromUtf8("textEditRead"));
        textEditRead->setGeometry(QRect(70, 80, 104, 71));
        textEditWrite = new QTextEdit(ServerWidget);
        textEditWrite->setObjectName(QString::fromUtf8("textEditWrite"));
        textEditWrite->setGeometry(QRect(200, 160, 104, 71));
        c_btn1 = new QPushButton(ServerWidget);
        c_btn1->setObjectName(QString::fromUtf8("c_btn1"));
        c_btn1->setGeometry(QRect(250, 20, 75, 23));
        c_btn2 = new QPushButton(ServerWidget);
        c_btn2->setObjectName(QString::fromUtf8("c_btn2"));
        c_btn2->setGeometry(QRect(250, 50, 75, 23));

        retranslateUi(ServerWidget);

        QMetaObject::connectSlotsByName(ServerWidget);
    } // setupUi

    void retranslateUi(QWidget *ServerWidget)
    {
        ServerWidget->setWindowTitle(QCoreApplication::translate("ServerWidget", "Form", nullptr));
        c_btn1->setText(QCoreApplication::translate("ServerWidget", "send", nullptr));
        c_btn2->setText(QCoreApplication::translate("ServerWidget", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerWidget: public Ui_ServerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWIDGET_H
