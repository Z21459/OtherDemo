#include <iostream>
#include <cstdio>
#include<string>
#include<WinSock2.h>
#include <Ws2tcpip.h>//ClientAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1") ���º��������滻


#pragma comment(lib,"ws2_32.lib")
using namespace std;
const int PORT = 8000;
#define MaxBufSize 1024
//#define _CRT_SECURE_NO_WARINGS

#define _WINSOCK_DEPRECATED_NO_WARNINGS

//�������Է���������Ϣ
DWORD WINAPI  recvFromServer(LPVOID lpParameter)
{
	char buf[MaxBufSize];
	SOCKET *ClientSocket = (SOCKET*)lpParameter;
	while (1) {
		memset(buf, '\0', sizeof(buf));//�ڴ����
		if (recv(*ClientSocket, buf, 1024, 0) <= 0)
		{
			printf("�ر�����!\n");
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
	//ClientAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//vs2017 ��socket���  �ͻ���ִ����滻������
	inet_pton(AF_INET, "127.0.0.1", &ClientAddr.sin_addr.s_addr);//�µ��滻�� #include <Ws2tcpip.h>
	ClientAddr.sin_port = htons(PORT);
	int n = 0;
	n = connect(SocketClient, (struct sockaddr*)&ClientAddr, sizeof(ClientAddr));//�������Ҫ�Ƚ���bindһ��addr�����ṩ����
	if (n == SOCKET_ERROR) {
		cout << "����ʧ��" << endl;
		return -1;
	}
	cout << "�Ѿ����ӵ��������������������������Ϣ�ˣ�" << endl;
	CreateThread(NULL, 0, &recvFromServer, &SocketClient, 0, NULL);
	char info[1024], SendBuff[MaxBufSize], RecvBuff[MaxBufSize];
	while (1) {
		cout << "������Ҫ���͵���Ϣ,���س��������ͣ�" << endl;
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
			cout << "����ʧ��" << endl;
		}
		Sleep(500);
		memset(RecvBuff, 0, sizeof(RecvBuff));
	}
	closesocket(SocketClient);
	WSACleanup();
	return 0;
}
