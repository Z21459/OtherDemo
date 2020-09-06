#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtComBox.h"
#include <iostream>
#include <fstream>
using namespace std;

class QtComBox : public QMainWindow
{
    Q_OBJECT

public:
    QtComBox(QWidget *parent = Q_NULLPTR);
	void loadConfig();
	void chooseShow();
private:
    Ui::QtComBoxClass ui;

private slots:
	void slotInitItems();//��ʼ��
	void slotInsertItem();

	void slotCurrentIndex(int value);//����
	void slotCurrentIndex(const QString &val);//ֵ
};
