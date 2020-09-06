#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;
#pragma comment(lib, "ws2_32.lib")
#define Port 8000//8866  8866单项连接 和服务端通信 server 互相通信
#define IP_ADDRESS "192.168.223.128"     //服务器地址 在服务端通过ifconfig -a查看服务端的ip地址

#define MaxBufSize 1024

//监听服务器消息
DWORD WINAPI recvFromServer(LPVOID lpParam)
{
	char buf[MaxBufSize];
	SOCKET *ClientSocket = (SOCKET*)lpParam;
	while (1)
	{
		memset(buf, '\0', sizeof(buf));
		if (recv(*ClientSocket, buf, 1024, 0) <= 0)
		{
			printf("close\n");
			break;
			closesocket(*ClientSocket);
		}
		printf("%s\n", buf);
	}
	return 0;
}


int mainw() // argc是命令行总的参数个数
{	
	WSADATA s; // 用来储存调用AfxSocketInit全局函数返回的Windows Sockets初始化信息
	SOCKET ClientSocket;
	struct sockaddr_in ClientAddr; // 一个sockaddr_in型的结构体对象
	int ret = 0;
	char SendBuffer[MAX_PATH]; // Windows的MAX_PATH默认是260

	// 初始化Windows Socket
	// WSAStartup函数对Winsock服务的初始化
	if (WSAStartup(MAKEWORD(2, 2), &s) != 0) // 通过连接两个给定的无符号参数,首个参数为低字节
	{
		printf("Init Windows Socket Failed! Error: %d\n", GetLastError());
		getchar();
		return -1;
	}
	while (1)
	{
		// 创建一个套接口
		// 如果这样一个套接口用connect()与一个指定端口连接
		// 则可用send()和recv()与该端口进行数据报的发送与接收
		// 当会话结束后，调用closesocket()
		ClientSocket = socket(AF_INET, // 只支持ARPA Internet地址格式
			SOCK_STREAM, // 新套接口的类型描述
			IPPROTO_TCP); // 套接口所用的协议
		if (ClientSocket == INVALID_SOCKET)
		{
			printf("Create Socket Failed! Error: %d\n", GetLastError());
			getchar();
			return -1;
		}
		ClientAddr.sin_family = AF_INET;
		ClientAddr.sin_addr.s_addr = inet_addr(IP_ADDRESS); // 定义IP地址
		ClientAddr.sin_port = htons(Port); // 将主机的无符号短整形数转换成网络字节顺序
		memset(ClientAddr.sin_zero, 0X00, 8); // 函数通常为新申请的内存做初始化工作
		// 连接Socket
		ret = connect(ClientSocket,
			(struct sockaddr*)&ClientAddr,
			sizeof(ClientAddr));
		if (ret == SOCKET_ERROR)
		{
			printf("Socket Connect Failed! Error:%d\n", GetLastError());
			getchar();
			return -1;
		}
		else
		{
			printf("Socket Connect Succeed!");
		}
		printf("Input Data: ");
		//创建线程  发送消息
		//CreateThread(NULL, 0, &recvFromServer, &ClientSocket, 0, NULL);
		//char info[1024], SendBuffer[MaxBufSize], RecvBuff[MaxBufSize];
		
		while (1)
		{//多客户端和服务端通信   服务端为dserver
			scanf("%s", &SendBuffer);
			send(ClientSocket, SendBuffer, (int)strlen(SendBuffer), 0);
			int recvLen = recv(ClientSocket, SendBuffer, MaxBufSize, 0);
			if(recvLen == 0) printf("Message form server:\n");
			else printf("Message form server: %s\n", SendBuffer);
			// 发送数据至服务器
			//ret = send(ClientSocket,
			//	SendBuffer,
			//	(int)strlen(SendBuffer), // 返回发送缓冲区数据长度
			//	0);
			//if (ret == SOCKET_ERROR)
			//{
			//	printf("Send Information Failed! Error:%d\n", GetLastError());
			//	getchar();
			//	break;
			//}
			////接收服务端发的消息
			//char bufRecv[MaxBufSize] = { 0 };
			//int recvLen = recv(ClientSocket, bufRecv, MaxBufSize, 0);
			//printf("Message form server: %s\n", bufRecv);
			////Sleep(500);
			////memset(RecvBuff, 0, sizeof(RecvBuff));
			////break;
		}
		// 关闭socket
		closesocket(ClientSocket);
		if (SendBuffer[0] == 'q') // 设定输入第一个字符为q时退出
		{
			printf("Quit!\n");
			break;
		}
	}
	WSACleanup();
	getchar();
	system("pause");
	return 0;
}