#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>

#include <QtNetwork/QTcpServer> //监听套接字
#include <QtNetwork/QTcpSocket> //通信套接字
class QTcpSocket;//引用类使用
class QUdpSocket;//数据报文
class QTcpServer;//字节流数据

namespace Ui {
class ServerWidget;
}

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ServerWidget(QWidget *parent = nullptr);
    ~ServerWidget();

private slots:
    void on_Send();
    void on_Close();

private:
    Ui::ServerWidget *ui;

    QTcpServer *tcpServer; //监听套接字
    QTcpSocket *tcpSocket; //通信套接字
};

#endif // SERVERWIDGET_H
