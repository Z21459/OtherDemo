#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;
#pragma comment(lib, "ws2_32.lib")
#define Port 8000//8866  8866�������� �ͷ����ͨ�� server ����ͨ��
#define IP_ADDRESS "192.168.223.128"     //��������ַ �ڷ����ͨ��ifconfig -a�鿴����˵�ip��ַ

#define MaxBufSize 1024

//������������Ϣ
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


int mainw() // argc���������ܵĲ�������
{	
	WSADATA s; // �����������AfxSocketInitȫ�ֺ������ص�Windows Sockets��ʼ����Ϣ
	SOCKET ClientSocket;
	struct sockaddr_in ClientAddr; // һ��sockaddr_in�͵Ľṹ�����
	int ret = 0;
	char SendBuffer[MAX_PATH]; // Windows��MAX_PATHĬ����260

	// ��ʼ��Windows Socket
	// WSAStartup������Winsock����ĳ�ʼ��
	if (WSAStartup(MAKEWORD(2, 2), &s) != 0) // ͨ�����������������޷��Ų���,�׸�����Ϊ���ֽ�
	{
		printf("Init Windows Socket Failed! Error: %d\n", GetLastError());
		getchar();
		return -1;
	}
	while (1)
	{
		// ����һ���׽ӿ�
		// �������һ���׽ӿ���connect()��һ��ָ���˿�����
		// �����send()��recv()��ö˿ڽ������ݱ��ķ��������
		// ���Ự�����󣬵���closesocket()
		ClientSocket = socket(AF_INET, // ֻ֧��ARPA Internet��ַ��ʽ
			SOCK_STREAM, // ���׽ӿڵ���������
			IPPROTO_TCP); // �׽ӿ����õ�Э��
		if (ClientSocket == INVALID_SOCKET)
		{
			printf("Create Socket Failed! Error: %d\n", GetLastError());
			getchar();
			return -1;
		}
		ClientAddr.sin_family = AF_INET;
		ClientAddr.sin_addr.s_addr = inet_addr(IP_ADDRESS); // ����IP��ַ
		ClientAddr.sin_port = htons(Port); // ���������޷��Ŷ�������ת���������ֽ�˳��
		memset(ClientAddr.sin_zero, 0X00, 8); // ����ͨ��Ϊ��������ڴ�����ʼ������
		// ����Socket
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
		//�����߳�  ������Ϣ
		//CreateThread(NULL, 0, &recvFromServer, &ClientSocket, 0, NULL);
		//char info[1024], SendBuffer[MaxBufSize], RecvBuff[MaxBufSize];
		
		while (1)
		{//��ͻ��˺ͷ����ͨ��   �����Ϊdserver
			scanf("%s", &SendBuffer);
			send(ClientSocket, SendBuffer, (int)strlen(SendBuffer), 0);
			int recvLen = recv(ClientSocket, SendBuffer, MaxBufSize, 0);
			if(recvLen == 0) printf("Message form server:\n");
			else printf("Message form server: %s\n", SendBuffer);
			// ����������������
			//ret = send(ClientSocket,
			//	SendBuffer,
			//	(int)strlen(SendBuffer), // ���ط��ͻ��������ݳ���
			//	0);
			//if (ret == SOCKET_ERROR)
			//{
			//	printf("Send Information Failed! Error:%d\n", GetLastError());
			//	getchar();
			//	break;
			//}
			////���շ���˷�����Ϣ
			//char bufRecv[MaxBufSize] = { 0 };
			//int recvLen = recv(ClientSocket, bufRecv, MaxBufSize, 0);
			//printf("Message form server: %s\n", bufRecv);
			////Sleep(500);
			////memset(RecvBuff, 0, sizeof(RecvBuff));
			////break;
		}
		// �ر�socket
		closesocket(ClientSocket);
		if (SendBuffer[0] == 'q') // �趨�����һ���ַ�Ϊqʱ�˳�
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