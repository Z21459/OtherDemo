#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include <QInputDialog>
#include <QStringList>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readSettings();
    writeSettings();

    //设置系统对话框
    /*QStringList ho,ye;
    ho<<"a"<<"b"<<"c"<<"d";
    ye<<"yes"<<"no";
    QString outcome,more("yes"),title("hoob");
    QString query("pick hoob");

    while(more == "yes")
    {
        QString pick = QInputDialog::getItem(0,title,query,ho);
        outcome = QString("you pick %1").arg(pick);
        more = QInputDialog::getItem(0,"pock hoob",outcome,ye,1,false);

    }*/

}

MainWindow::~MainWindow()
{
    delete ui;
}
//保存上一次状态
void MainWindow::readSettings()
{
    QSettings settings("objectlearning.net","Qt4");
    QPoint pos = settings.value("pos",QPoint(200,200)).toPoint();
    QSize size = settings.value("size",QSize(400,400)).toSize();
    QByteArray state = settings.value("state",QByteArray()).toByteArray();
    restoreState(state);
    resize(size);
    move(pos);
}

void MainWindow::writeSettings()
{
    QSettings settings("objectlearning.net","Qt4");
    settings.setValue("pos",pos());
    settings.setValue("size",size());
    settings.setValue("state",saveState());
}
