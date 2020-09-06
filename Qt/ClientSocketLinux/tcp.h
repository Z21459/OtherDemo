#ifndef TCP_H
#define TCP_H

#endif // TCP_H

#include <QMainWindow>
#include <QtNetwork/QtNetwork>
#include <QtNetwork/QAbstractSocket>
class QTcpSocket;//引用类使用
class QUdpSocket;//数据报文
class QTcpServer;//字节流数据
//TCP：C/S模型，在数据传输之前、必须在C/S直接建立TCP连接。
//server
class Server:public QMainWindow
{
public:
    Server();
    ~Server();
private:
    QTcpServer *tcpServer;
private slots:
    void sendMsg();
};
Server::Server()
{
    tcpServer = new QTcpServer(nullptr);
    //使用本地ipv4
    if(tcpServer->listen(QHostAddress::LocalHost,8888))
    {
        qDebug() << tcpServer->errorString();
        close();
    }
    connect(tcpServer,&QTcpServer::newConnection,this,&Server::sendMsg);

}
void Server::sendMsg()
{
    //缓存数据
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);

    //设置数据流 客户端和服务端版本要一致
    out.setVersion(QDataStream::Qt_5_12);
    out <<(quint16)0;
    out << tr("AAA");
    out.device()->seek(0);
    out << (quint16)(block.size()-sizeof (quint16));


    //获取已经建立连接的套接字
    QTcpSocket *clientConn = tcpServer->nextPendingConnection();
    connect(clientConn,&QTcpSocket::disconnected,clientConn,&QTcpSocket::deleteLater);
    clientConn->write(block);
    clientConn->disconnectFromHost();

    //发送成功后提示
}

//客户端


class TcpClient:public QMainWindow
{
public:
    TcpClient();
    ~TcpClient();

private slots:
    void newConn();
    void readMsg();
    void disPlayErr(QAbstractSocket::SocketError);

    void connBtn();


private:
    QTcpSocket *tcpSocket;
    QString msg;
    quint16 blockSize;
};

TcpClient::TcpClient()
{
    tcpSocket = new QTcpSocket(nullptr);
    connect(tcpSocket,&QTcpSocket::readyRead,this,&TcpClient::readMsg);
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(disPlayErr(QAbstractSocket::SocketError)));
}

void TcpClient::newConn()
{
    //初始化信息
    blockSize = 0;
    tcpSocket->abort();
    //tcpSocket->connectToHost(ui->hostEdit->text,ui->portEdit->text().toInt());
}

void TcpClient::readMsg()
{
    QDataStream in(tcpSocket);
    //设置版本和服务器相同
    in.setVersion(QDataStream::Qt_5_12);

    //刚开始接受数据
    if(blockSize ==0)
    {
        //判断接收的数据是否大于两字节，也就是文件的大小信息所占的空间
        //如果是则保存到blockSize变量中，否则直接返回，继续接收数据
        if(tcpSocket->bytesAvailable() <(int)sizeof(quint16)) return;
        in >> blockSize;
    }
    //如果没有得到全部数据  返回
    if(tcpSocket->bytesAvailable()<blockSize) return;
    in>>msg;
    //显示接收数据
}

void TcpClient::disPlayErr(QAbstractSocket::SocketError)
{
    qDebug() << tcpSocket->errorString();
}
void TcpClient::connBtn()
{
    newConn();
}
















