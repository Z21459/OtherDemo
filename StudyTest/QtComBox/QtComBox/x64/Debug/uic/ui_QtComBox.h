/********************************************************************************
** Form generated from reading UI file 'QtComBox.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCOMBOX_H
#define UI_QTCOMBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtComBoxClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QTextEdit *textEdit;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtComBoxClass)
    {
        if (QtComBoxClass->objectName().isEmpty())
            QtComBoxClass->setObjectName(QStringLiteral("QtComBoxClass"));
        QtComBoxClass->resize(600, 400);
        centralWidget = new QWidget(QtComBoxClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 150, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 160, 75, 23));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(150, 40, 69, 22));
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(260, 40, 69, 22));
        comboBox_3 = new QComboBox(centralWidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(150, 100, 69, 22));
        comboBox_4 = new QComboBox(centralWidget);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(270, 100, 69, 22));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 250, 104, 71));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(260, 160, 241, 171));
        QtComBoxClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtComBoxClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        QtComBoxClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtComBoxClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtComBoxClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtComBoxClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtComBoxClass->setStatusBar(statusBar);

        retranslateUi(QtComBoxClass);

        QMetaObject::connectSlotsByName(QtComBoxClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtComBoxClass)
    {
        QtComBoxClass->setWindowTitle(QApplication::translate("QtComBoxClass", "QtComBox", nullptr));
        pushButton->setText(QApplication::translate("QtComBoxClass", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("QtComBoxClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtComBoxClass: public Ui_QtComBoxClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCOMBOX_H
