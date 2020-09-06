#include <iostream>
#include <cstdio>
#include<string>
#include<WinSock2.h>
#include <Ws2tcpip.h>//ClientAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1") 用新函数进行替换


#pragma comment(lib,"ws2_32.lib")
using namespace std;
const int PORT = 8000;
#define MaxBufSize 1024
//#define _CRT_SECURE_NO_WARINGS

#define _WINSOCK_DEPRECATED_NO_WARNINGS

//监听来自服务器的消息
DWORD WINAPI  recvFromServer(LPVOID lpParameter)
{
	char buf[MaxBufSize];
	SOCKET *ClientSocket = (SOCKET*)lpParameter;
	while (1) {
		memset(buf, '\0', sizeof(buf));//内存清空
		if (recv(*ClientSocket, buf, 1024, 0) <= 0)
		{
			printf("关闭连接!\n");
			break;
			closesocket(*ClientSocket);
		}
		std::cout << buf << "\n";
	}
	return 0;
}


int mainc() {
	WSADATA wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);
	SOCKET SocketClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN  ClientAddr;

	ClientAddr.sin_family = AF_INET;
	//ClientAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//vs2017 下socket编程  就会出现错误，替换成下面
	inet_pton(AF_INET, "127.0.0.1", &ClientAddr.sin_addr.s_addr);//新的替换成 #include <Ws2tcpip.h>
	ClientAddr.sin_port = htons(PORT);
	int n = 0;
	n = connect(SocketClient, (struct sockaddr*)&ClientAddr, sizeof(ClientAddr));//服务端需要先进行bind一个addr用于提供服务
	if (n == SOCKET_ERROR) {
		cout << "连接失败" << endl;
		return -1;
	}
	cout << "已经连接到服务器，可以向服务器发送消息了！" << endl;
	CreateThread(NULL, 0, &recvFromServer, &SocketClient, 0, NULL);
	char info[1024], SendBuff[MaxBufSize], RecvBuff[MaxBufSize];
	while (1) {
		cout << "请输入要发送的信息,按回车结束发送：" << endl;
		cin >> info;
		if (info[0] == '\0')
			break;

		sprintf_s(SendBuff, "MATH");
		strcat_s(SendBuff, info);
		memset(info, 0, sizeof(info));
		int k = 0;
		n = send(SocketClient, SendBuff, sizeof(SendBuff), 0);
		memset(SendBuff, 0, sizeof(SendBuff));
		if (k < 0) {
			cout << "发送失败" << endl;
		}
		Sleep(500);
		memset(RecvBuff, 0, sizeof(RecvBuff));
	}
	closesocket(SocketClient);
	WSACleanup();
	return 0;
}
