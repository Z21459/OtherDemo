#include<iostream>
#include <string.h>
#include <cstdio>
#include <WinSock2.h>
#include <Ws2tcpip.h>
using namespace std;

//TCPЭ���ܹ�������ͨ�����ṩ�ɿ��Ĵ��䣬��Ҫ��������ʱ���������֣��Ͽ�ʱ���Ĵλ��֣��Լ���ʱ�ش����������ڣ�ӵ������

//����֮��ͨ��socketͨ��--socketһ��������ļ� ������д �� �رյ�
//����
/*
1.����˸��ݵ�ַ���� ipv4�ȣ�socket���ͣ�Э�鴴��socket
2.����������bind()����Ϊsocket�󶨶˿�
3.������socket����listen()��ʼ�����˿ں�����׼����ʱ���ܿͻ��˷���������
4.�����ͻ���socket
5.�ͻ��˴�socket�����ݷ����ip��port����connect����˵�socket
6.������յ����󣬱����� ��ʼ���ܿͻ�������ֱ���ͻ��˷���������Ϣ
7.�ͻ������ӳɹ����������˷�������״̬��Ϣ�������accept�������أ����ӳɹ�

8.�ͻ��˵���write()��socketд����Ϣ
9.����˵���read()��socket��ȡ��Ϣ
10.�ͻ��˺ͷ���˽��йر�

�������ַ�����connect()����ʱ����accept()�������������ֹ���֮��
*/

//socket��SOCK_STREAM��ʽ�׽���,SOCK_DGRAM���ݱ��׽���,SOCK_RAWԭʼ�׽���


//���� service  Ȼ������client  ͨ��ip��portʹ�ͻ��˺ͷ���˽�������

//���߳�ʵ�ַ���˺Ϳͻ��˽���ͨ��
//ʵ�ַ���˺Ϳͻ��˶��Ƕ��߳�
/*
���ڷ���ˣ�����ÿ���ͻ������ӣ����½�һ�������̣߳�֮���жϿͻ��˷�������Ϣ�������ؽ�����ͻ���
���ڿͻ��ˣ����̻߳���û����뽫���뷢�͸�����ˣ���һ���̼߳������������ؽ������ӡ����Ļ��
*/

//����˴���
#pragma comment(lib,"ws2_32.lib")//����ⲿ��̬���ӿ�
const int PORT = 8000;
#define MaxClinet 10//���ͻ���
#define MaxBufSize 1024//����ֽ���
//#define _CRT_SECURE_NO_WARINGS//���ô����ɹ������

#define _WINSOCK_DEPRECATED_NO_WARNINGS


bool MathCalculate(char recvBuff[], char &resBuff);//������ֵ��������ֵ���������ڴ�ֵ

//�����߳�
DWORD WINAPI ServerThread(LPVOID lpParameter) {
	SOCKET *ClientSocket = (SOCKET*)lpParameter;//�ͻ����׽���  ����Socket�׽���
	int receByt = 0;
	char RecvBuf[MaxBufSize];//�յ��ͷ�������
	char SendBuf[MaxBufSize];

	//һֱ���ʿͻ��ˣ��鿴�ͻ����Ƿ�����Ϣ����
	while (1) {
		receByt = recv(*ClientSocket, RecvBuf, sizeof(RecvBuf), 0);//�յ�����
		if (receByt > 0) {
			cout << "������Ϣ��" << RecvBuf << "���Կͻ��ˣ�" << *ClientSocket << endl;
			char ResBuf[MaxBufSize];
			if (MathCalculate(RecvBuf, *SendBuf)) {
				int k = 0;
				k = send(*ClientSocket, SendBuf, sizeof(SendBuf), 0);
				if (k < 0) {
					cout << "����ʧ��" << endl;
				}
				//����ڴ�
				memset(SendBuf, 0, sizeof(SendBuf));//�ڴ��������
			}
		}
		else {
			cout << "�ͻ��ˣ�" << *ClientSocket << "������Ϣ������" << endl;
			break;
		}
		memset(RecvBuf, 0, sizeof(RecvBuf));//�ڴ��������
	}
	//�رղ��ͷ�
	closesocket(*ClientSocket);
	free(ClientSocket);
	return 0;
}

int maints(int agrc, char *agrv) {

	WSAData wsd;//����
	WSAStartup(MAKEWORD(2, 2), &wsd);
	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, 0);//��Э��
	SOCKADDR_IN ListenAddr;
	ListenAddr.sin_family = AF_INET;
	ListenAddr.sin_addr.S_un.S_addr = INADDR_ANY;//��ʾ��ӱ���IP
	ListenAddr.sin_port = htons(PORT);//�˿�
	int n;
	n = bind(ListenSocket, (PSOCKADDR)&ListenAddr, sizeof(ListenAddr));
	if (n == SOCKET_ERROR) {
		cout << "�˿ڰ�ʧ�ܣ�" << endl;
		return -1;
	}
	else {
		cout << "�˿ڰ󶨳ɹ���" << PORT << endl;
	}
	int l = listen(ListenSocket, 20);//��ʼ����
	cout << "�����׼���������ȴ�����" << endl;

	while (1) {//һֱ���ʿͻ���
		//ѭ�����տͻ����������󲢴��������߳�
		SOCKET *ClienetSocket = new SOCKET;
		ClienetSocket = (SOCKET*)malloc(sizeof(SOCKET));
		//���տͻ�����������
		int SockAddrlen = sizeof(sockaddr);
		*ClienetSocket = accept(ListenSocket, 0, 0);
		cout << "һ���ͻ����Ѿ����ӷ�������socket�ǣ�" << *ClienetSocket << endl;

		CreateThread(NULL, 0, &ServerThread, ClienetSocket, 0, NULL);
	}

	closesocket(ListenSocket);//�ر��׽���
	WSACleanup();

//	system("pause");
	return 0;
}



char startBuf[5] = { "MATH" };//�ַ�������
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
				a = a * 10 + recvBuff[i] - '0';//�ַ���ת���� ����ȥ
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
				sprintf_s(&resBuff,sizeof(resBuff) ,"No Result");//sprintf()ת�ַ���
				break;
			}
		}
	}
	return getTrue;
}
