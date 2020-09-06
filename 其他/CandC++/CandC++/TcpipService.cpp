#include<iostream>
#include <string.h>
#include <cstdio>
#include <WinSock2.h>
#include <Ws2tcpip.h>
using namespace std;

//TCP协议能够在网络通信中提供可靠的传输，主要依赖连接时的三次握手，断开时的四次挥手，以及超时重传，滑动窗口，拥塞控制

//进程之间通过socket通信--socket一种特殊的文件 包括读写 打开 关闭等
//流程
/*
1.服务端根据地址类型 ipv4等，socket类型，协议创建socket
2.服务器调用bind()函数为socket绑定端口
3.服务器socket调用listen()开始监听端口号请求，准备随时接受客户端发来的连接
4.创建客户端socket
5.客户端打开socket，根据服务端ip和port尝试connect服务端的socket
6.服务端收到请求，被动打开 开始接受客户端请求，直到客户端返回连接信息
7.客户端连接成功，并向服务端发送连接状态信息，服务端accept方法返回，连接成功

8.客户端调用write()向socket写入信息
9.服务端调用read()从socket读取消息
10.客户端和服务端进行关闭

三次握手发生在connect()调用时，而accept()发生在三次握手过程之后
*/

//socket：SOCK_STREAM流式套接字,SOCK_DGRAM数据报套接字,SOCK_RAW原始套接字


//运行 service  然后运行client  通过ip和port使客户端和服务端进行连接

//多线程实现服务端和客户端进行通信
//实现服务端和客户端都是多线程
/*
对于服务端：对于每个客户端连接，均新建一个服务线程，之后判断客户端发来的信息，并返回结果给客户端
对于客户端：主线程获得用户输入将输入发送给服务端；另一个线程监听服务器返回结果并打印到屏幕上
*/

//服务端代码
#pragma comment(lib,"ws2_32.lib")//添加外部动态链接库
const int PORT = 8000;
#define MaxClinet 10//最大客户端
#define MaxBufSize 1024//最大字节数
//#define _CRT_SECURE_NO_WARINGS//设置创建成功警告等

#define _WINSOCK_DEPRECATED_NO_WARNINGS


bool MathCalculate(char recvBuff[], char &resBuff);//计算数值，传入数值，并返回内存值

//服务线程
DWORD WINAPI ServerThread(LPVOID lpParameter) {
	SOCKET *ClientSocket = (SOCKET*)lpParameter;//客户端套接字  申请Socket套接字
	int receByt = 0;
	char RecvBuf[MaxBufSize];//收到和发送数据
	char SendBuf[MaxBufSize];

	//一直访问客户端，查看客户端是否有消息发送
	while (1) {
		receByt = recv(*ClientSocket, RecvBuf, sizeof(RecvBuf), 0);//收到数据
		if (receByt > 0) {
			cout << "接收消息：" << RecvBuf << "来自客户端：" << *ClientSocket << endl;
			char ResBuf[MaxBufSize];
			if (MathCalculate(RecvBuf, *SendBuf)) {
				int k = 0;
				k = send(*ClientSocket, SendBuf, sizeof(SendBuf), 0);
				if (k < 0) {
					cout << "发送失败" << endl;
				}
				//清空内存
				memset(SendBuf, 0, sizeof(SendBuf));//内存清空置零
			}
		}
		else {
			cout << "客户端：" << *ClientSocket << "接收消息结束！" << endl;
			break;
		}
		memset(RecvBuf, 0, sizeof(RecvBuf));//内存清空置零
	}
	//关闭并释放
	closesocket(*ClientSocket);
	free(ClientSocket);
	return 0;
}

int maints(int agrc, char *agrv) {

	WSAData wsd;//对象
	WSAStartup(MAKEWORD(2, 2), &wsd);
	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, 0);//流协议
	SOCKADDR_IN ListenAddr;
	ListenAddr.sin_family = AF_INET;
	ListenAddr.sin_addr.S_un.S_addr = INADDR_ANY;//表示添加本机IP
	ListenAddr.sin_port = htons(PORT);//端口
	int n;
	n = bind(ListenSocket, (PSOCKADDR)&ListenAddr, sizeof(ListenAddr));
	if (n == SOCKET_ERROR) {
		cout << "端口绑定失败！" << endl;
		return -1;
	}
	else {
		cout << "端口绑定成功：" << PORT << endl;
	}
	int l = listen(ListenSocket, 20);//开始监听
	cout << "服务端准备就绪，等待连接" << endl;

	while (1) {//一直访问客户端
		//循环接收客户端连接请求并创建服务线程
		SOCKET *ClienetSocket = new SOCKET;
		ClienetSocket = (SOCKET*)malloc(sizeof(SOCKET));
		//接收客户端连接请求
		int SockAddrlen = sizeof(sockaddr);
		*ClienetSocket = accept(ListenSocket, 0, 0);
		cout << "一个客户端已经连接服务器，socket是：" << *ClienetSocket << endl;

		CreateThread(NULL, 0, &ServerThread, ClienetSocket, 0, NULL);
	}

	closesocket(ListenSocket);//关闭套接字
	WSACleanup();

//	system("pause");
	return 0;
}



char startBuf[5] = { "MATH" };//字符串长度
bool MathCalculate(char recvBuff[], char &resBuff) {//MathCalculate(RecvBuf, *SendBuf)
	bool getTrue = false;
	for (int i = 0; i < 4; i++) {
		if (recvBuff[i] == startBuf[i]) {
			getTrue = true;
			continue;
		}
		else {
			getTrue = false;
			break;
		}
	}
	int equalIndex = 0;
	int mathflag = 0;
	int mathflagIndex = 0;
	if (getTrue) {
		getTrue = false;
		for (int i = 0; i < 50; i++) {
			if (recvBuff[i] == '=') {
				getTrue = true;
				equalIndex = i;
				break;
			}
		}
	}
	if (getTrue) {
		getTrue = false;
		for (int i = 0; i < equalIndex; i++) {
			switch (recvBuff[i]) {
			case '+':
				getTrue = true;
				mathflag = 1;
				mathflagIndex = i;
				break;
			case '-':
				getTrue = true;
				mathflag = 2;
				mathflagIndex = i;
				break;
			case '*':
				getTrue = true;
				mathflag = 3;
				mathflagIndex = i;
				break;
			case '\\':
			case '/':
				getTrue = true;
				mathflag = 4;
				mathflagIndex = i;
				break;
			}
			if (getTrue) {
				break;
			}
		}
		if (getTrue) {
			int a = 0, b = 0;
			for (int i = 4; i < mathflagIndex; i++) {
				a = a * 10 + recvBuff[i] - '0';//字符串转数字 传出去
			}
			for (int i = mathflagIndex + 1; i < equalIndex; i++) {
				b = b * 10 + recvBuff[i] - '0';
			}

			switch (mathflag) {
			case 1:
				printf("%d+%d=%d\n", a, b, a + b);
				sprintf_s(&resBuff, sizeof(resBuff), "Result:%d+%d=%d\n", a, b, a + b);
				break;
			case 2:
				printf("%d-%d=%d\n", a, b, a - b);
				sprintf_s(&resBuff, sizeof(resBuff), "Result:%d-%d=%d\n", a, b, a - b);
				break;
			case 3:
				printf("%d*%d=%d\n", a, b, a * b);
				sprintf_s(&resBuff, sizeof(resBuff), "Result:%d*%d=%d\n", a, b, a * b);
				break;
			case 4:
				printf("%d//%d=%d\n", a, b, a / b);
				sprintf_s(&resBuff, sizeof(resBuff), "Result:%d//%d=%d\n", a, b, a / b);
				break;
			default:
				printf("No Result");
				sprintf_s(&resBuff,sizeof(resBuff) ,"No Result");//sprintf()转字符串
				break;
			}
		}
	}
	return getTrue;
}
