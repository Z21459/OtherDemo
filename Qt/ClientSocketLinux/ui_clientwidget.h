/********************************************************************************
** Form generated from reading UI file 'clientwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QLineEdit *lineEditIP;
    QLineEdit *lineEditPort;
    QTextEdit *textEditWrite;
    QTextEdit *textEditRead;
    QPushButton *c_btn1;
    QPushButton *c_btn2;
    QPushButton *c_btn3;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QString::fromUtf8("ClientWidget"));
        ClientWidget->resize(400, 300);
        lineEditIP = new QLineEdit(ClientWidget);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));
        lineEditIP->setGeometry(QRect(30, 50, 113, 20));
        lineEditPort = new QLineEdit(ClientWidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));
        lineEditPort->setGeometry(QRect(30, 80, 113, 20));
        textEditWrite = new QTextEdit(ClientWidget);
        textEditWrite->setObjectName(QString::fromUtf8("textEditWrite"));
        textEditWrite->setGeometry(QRect(30, 140, 104, 71));
        textEditRead = new QTextEdit(ClientWidget);
        textEditRead->setObjectName(QString::fromUtf8("textEditRead"));
        textEditRead->setGeometry(QRect(200, 140, 104, 71));
        c_btn1 = new QPushButton(ClientWidget);
        c_btn1->setObjectName(QString::fromUtf8("c_btn1"));
        c_btn1->setGeometry(QRect(200, 30, 75, 23));
        c_btn2 = new QPushButton(ClientWidget);
        c_btn2->setObjectName(QString::fromUtf8("c_btn2"));
        c_btn2->setGeometry(QRect(200, 60, 75, 23));
        c_btn3 = new QPushButton(ClientWidget);
        c_btn3->setObjectName(QString::fromUtf8("c_btn3"));
        c_btn3->setGeometry(QRect(200, 90, 75, 23));

        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QCoreApplication::translate("ClientWidget", "Form", nullptr));
        c_btn1->setText(QCoreApplication::translate("ClientWidget", "connet", nullptr));
        c_btn2->setText(QCoreApplication::translate("ClientWidget", "send", nullptr));
        c_btn3->setText(QCoreApplication::translate("ClientWidget", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
