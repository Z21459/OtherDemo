#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initGL()
{

}
void MainWindow::resizeGL(int w,int h)
{


}
void MainWindow::paintGL()
{
    //清屏

}
