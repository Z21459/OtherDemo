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
	void slotInitItems();//初始化
	void slotInsertItem();

	void slotCurrentIndex(int value);//索引
	void slotCurrentIndex(const QString &val);//值
};
