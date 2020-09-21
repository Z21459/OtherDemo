#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVariant>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QPainter>
#include <QtDebug>
#include <QString>
#include <QtOpenGL>//3D视图渲染

#include <QMainWindow>
#include <QWebEngineView>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();


private slots:
    void onShowText();
public:
    void onPlainText(const QString &fileName);

public:
    //重绘
    void paintEvent(QPaintEvent *event);

    //动画
    void onSetAnimat();

protected://
    void resizeEvent(QResizeEvent *);
private:
    Ui::Widget *ui;

    //QWebEngineView* view;//
};

#endif // WIDGET_H
