#include "QtComBox.h"
#include <qpushbutton.h>
#include<qcombobox.h>

QtComBox::QtComBox(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(slotInitItems()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(slotInsertItem()));

	connect(ui.comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotCurrentIndex(int)));
	connect(ui.comboBox_2, SIGNAL(currentIndexChanged(int)), this, SLOT(slotCurrentIndex(int)));
	connect(ui.comboBox_3, SIGNAL(currentIndexChanged(int)), this, SLOT(slotCurrentIndex(int)));
	connect(ui.comboBox_4, SIGNAL(currentIndexChanged(int)), this, SLOT(slotCurrentIndex(int)));
	//connect(ui.comboBox_2, SIGNAL(currentIndexChanged(const String &int)), this, SLOT(slotCurrentIndex(const String &)));
}

void QtComBox::loadConfig()
{
}

void QtComBox::slotInitItems()
{
	QMap<QString, int>map;//从map里面读取
	map.insert("aaa",22);
	map.insert("bbb", 20);
	map.insert("ccc", 88);
	map.insert("ddd", 44);
	QIcon icon("");
	foreach (const QString name,map.keys())
	{
		//if (ui.chkWithIcon->isChecked())
		//	ui.comboBox->addItem(icon, name, map.value(name));
		ui.comboBox->addItem(name, map.value(name));
		ui.comboBox_2->addItem(name, map.value(name));
		ui.comboBox_3->addItem(name, map.value(name));
		ui.comboBox_4->addItem(name, map.value(name));

	}

}
void QtComBox::chooseShow()
{
}

void QtComBox::slotInsertItem()
{
}

void QtComBox::slotCurrentIndex(int value)
{
	ui.plainTextEdit->appendPlainText(QString("Current index = %1").arg(value));
}

void QtComBox::slotCurrentIndex(const QString & val)
{
	ui.plainTextEdit->appendPlainText(QString("Current index = %1").arg(val));
}
