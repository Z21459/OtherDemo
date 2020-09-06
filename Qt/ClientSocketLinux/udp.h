#ifndef UDP_H
#define UDP_H

#endif // UDP_H
#include <QMainWindow>
#include <QtNetwork/QtNetwork>
class QTcpSocket;//引用类使用
class QUdpSocket;//数据报文
class QTcpServer;//字节流数据

//UDP通信

class Sender
{
public:
    Sender();
    ~Sender();
private slots:
    void on_button();

private:
    QUdpSocket *sender;

};
Sender::Sender()
{
    sender = new QUdpSocket(nullptr);
}
void Sender::on_button()
{
    QByteArray data = "aaa";
    sender->writeDatagram(data.data(),data.size(),QHostAddress::Broadcast,45454);
}


//接收端

class Receiver:public QMainWindow
{
public:
    Receiver();
    ~Receiver();
private slots:
    void getData();
private:
    QUdpSocket *receiver;
};
Receiver::Receiver()
{
    receiver = new QUdpSocket(nullptr);
    receiver->bind(45454,QUdpSocket::ShareAddress);
    connect(receiver,&QUdpSocket::readyRead,this,&Receiver::getData);
}

void Receiver::getData()
{
    while(receiver->hasPendingDatagrams())
    {
        QByteArray data;
        // 让datagram的大小为等待处理的数据报的大小，这样才能接收到完整的数据
        data.resize(receiver->pendingDatagramSize());
        receiver->readDatagram(data.data(),data.size());
        //放在对应的控件上面
    }
}
