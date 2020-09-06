#ifndef HTTP_H
#define HTTP_H

#endif // HTTP_H
/*
HTTP(HyperText Transfer Protocol，超文本传输协议）是一个客户端和服务器端之间进行请求和应答的标准。
HTTP的C/S交互过程：
通常由HTTP客户端发起一个请求，建立一个到服务器指定端口（默认是80端口）的TCP连接；
HTTP服务器在指定端口（80端口）监听客户端发过来的请求，一旦收到请求，服务器端就会向客户端发回一个应答。


在Qt中，高层协议的应用就是用好这三个类：
QNetworkAccessManager、QNetworkRequest、QNetworkReply；
*/

#include <QMainWindow>
#include <QtNetwork/QtNetwork>
class QNetworkReply;
class QNetworkAccessManager;


class HttpEx:public QMainWindow
{
public:
    HttpEx();
    ~HttpEx();
private slots:
    void replyFinish(QNetworkReply*);
private:
    QNetworkAccessManager *manager;
};

HttpEx::HttpEx()
{
    manager = new QNetworkAccessManager(this);
    /*这里首先创建了一个QNetworkAccessManager类的实例，用它来发送网络请求和接受应答*/
    /*将QNetworkAccessManager的finished信号和自定义的槽函数replyFinished相关联，
     * 每当网络请求结束时，都会收到finished信号并触发执行槽函数replyFinished*/

    connect(manager,&QNetworkAccessManager::finished,
            this,&HttpEx::replyFinish);
    manager->get(QNetworkRequest(QUrl("http://www.yangbo.pro")));

    /*用get方法发送一个网络请求，网络请求使用QNetworkRequest()表示，
     * get()函数返回一个QNetworkReply对象
     信号函数的参数和槽函数的参数是对应的！
    管理器还提供了发送HTTP POST请求的：post()函数
    HTTP PUT请求的put()函数
    HTTP DELETE请求的deleteResource()请求
*/

}


void HttpEx::replyFinish(QNetworkReply *reply)
{
    QString all = reply->readAll();
    //ui->textBrowser->setText(all);//显示文本
    reply->deleteLater();
}
