#include "widget.h"
#include "ui_widget.h"



/*
QGraphicsView
QGraphicsScene
QGraphicsItem

*/

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //connect(ui->c_btn_open,&QPushButton::clicked,this,&Widget::onShowText);
    connect(ui->c_btn_open,&QPushButton::clicked,this,[this](){
        //lambda 表达式一样  ()里边表示带参数  []可以表示 按值传递  引用传递等都可以 =时才能使用本地函数
        QString fileName = QFileDialog::getOpenFileName();
        if(!fileName.isEmpty())
        {
           qDebug() << "aaa";
           onPlainText(fileName);
           //this->ui->t_show_textedit->setPlainText("aa");
        }
    });
    onSetAnimat();


    //view = new QWebEngineView(this);//显示网页
    //view->load(QUrl("http://www.baidu.com/"));
    //view->show();


}

Widget::~Widget()
{
    delete ui;
}


void Widget::resizeEvent(QResizeEvent *)
{
    //view->resize(this->size());
}

//动画
void Widget::onSetAnimat()
{
    QPushButton *btn = new QPushButton("Button",this);
    btn->setGeometry(130,10,100,30);

    QPropertyAnimation *animation;
    animation = new QPropertyAnimation(btn,"geometry",this);

    animation->setDuration(3000);
    animation->setStartValue(QRect(130,10,100,30));
    animation->setEndValue(QRect(200,150,100,30));


    animation->setEasingCurve(QEasingCurve::OutInBounce);//设置移动形式

    animation->start();
}

//重绘 绘制
void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter;
    painter.begin(this);
    painter.setPen(Qt::blue);
    painter.drawRect(120,10,80,80);
    painter.setFont(QFont("Arial",20));
    painter.setPen(Qt::black);
    QRect font_rect(10,150,220,180);
    painter.drawText(font_rect,Qt::AlignCenter,"iiiiii  you");

    painter.end();
}

//打开文件对话框  选择显示
void Widget::onShowText()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        onPlainText(fileName);
    }
}

void Widget::onPlainText(const QString &fileName)
{
    qDebug() << fileName;
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this,tr("Application"),
                             tr("not open file%1:\n%2").arg(
                                 fileName).arg(file.errorString()));
        return;
    }
    QTextStream in(&file);
    ui->t_show_textedit->setPlainText(in.readAll());

}

