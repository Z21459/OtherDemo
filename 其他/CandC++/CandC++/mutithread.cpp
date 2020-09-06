#include <iostream>
#include <thread>
#include <algorithm>
#include <chrono>
#include<future>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;


//�鿴��ǰ�߳�id this_thread::get_id()�Ƚϵ��̺߳Ͷ��߳�
double caculate(int v) {
	if (v <= 0) {
		return v;
	}
	//��������������
	this_thread::sleep_for(chrono::milliseconds(10));
	return sqrt((v*v + sqrt((v - 5)*(v + 2.5)) / 2.0) / v);
}

template<typename Iter,typename Fun>//��ģ��
double visitRange(thread::id id, Iter iterBegin, Iter iterEnd, Fun fun) {
	auto curId = this_thread::get_id();
	if (id == this_thread::get_id()) {
		cout << curId << "main thread";
	}
	else {
		cout << curId << "work thred";
	}
	double v = 0;
	for (auto iter = iterBegin; iter != iterEnd; ++iter) {
		v += fun(*iter);
	}
	return v;
}

#include <mutex>
void inc(std::mutex &mutex, int loop, int &counter)
{
	for (int i = 0; i < loop; i++) {
		mutex.lock();
		++counter;
		mutex.unlock();
	}
}

//���̶߳��������
/*
l �������������ݿ�һ��ᴴ�����ӳأ��û��Ĳ������ݿⶼ�������ݿ��̳߳���ɣ��ڽ����Ͷ�ݸ��߼��㡣
��ÿ���û���������ɾ�Ĳ����������������ģ�
����ÿ���û���һ���̶���������С�����ͬ���û��������޸Ļ������ţ���ͬ���û����䲻ͬ��������м��ɡ�

2 ����������еĶ��socket�Ķ�д�ǻ������ŵģ����Դ�������������̣߳�ÿ����Ӧһ��������У�
��ͬ��socket�Ĳ�����������ķ���һ��������У�ע�����������ģ�һ�������ˣ�
����socket�����в���������������������ɣ���֤�߼������ԣ���
*/

//���̶߳�������� ���̴߳���
#include<windows.h>
#define NAME_LINE 50
//�߳����к���

//�����̺߳����������
typedef struct _THREAD_DATA {
	int nMaxNum;
	char strThreadName[NAME_LINE];
	_THREAD_DATA() :nMaxNum(0) {
		memset(strThreadName, 0, NAME_LINE * sizeof(char));
	}
}THREAD_DATA;

//���廥����
HANDLE g_hMutex = NULL;//������

//�̺߳���
DWORD WINAPI ThreadPro(LPVOID lpParameter) {
	THREAD_DATA *pThreadData = (THREAD_DATA*)lpParameter;
	for (int i = 0; i < pThreadData->nMaxNum; ++i) {
		//��ȡһ����������
		WaitForSingleObject(g_hMutex, INFINITE);

		cout << pThreadData->strThreadName << "---" << i << endl;
		//�ͷŻ�������
		ReleaseMutex(g_hMutex);

		Sleep(100);
	}
	return 0L;//����long��
}

DWORD WINAPI ThreadPro1(LPVOID lpParameter) {
	THREAD_DATA *pThreadData = (THREAD_DATA*)lpParameter;
	for (int i = 0; i < pThreadData->nMaxNum; ++i) {
		//��ȡ������
		WaitForSingleObject(g_hMutex,INFINITE);

		cout << pThreadData->strThreadName << "+++" << i << endl;
		Sleep(100);
		//�ͷŻ�����
		ReleaseMutex(g_hMutex);
	}

	return 0L;
}
///�������Ӵ����ɹ�  ִ��˳�����  ����CreatMutex��WaitForSingleObject��ReleaseMutex
//https://www.runoob.com/w3cnote/cpp-multithread-demo.html
//ʹ�û�����Mutex��ʹ��ͬ��--��Դ������һ���̷߳���
//CreateMutex(ͬ������)  WaitForSingleObject(�ȴ�һ��ָ������) ReleaseMutex(HANDLE)


//���� ��ģ�⹺���Ʊ ��500�Ż�Ʊ��8�����ڳ���Ʊ����֤ϵͳ�ȶ���
#include<string>
#include <strstream>

#define NAME_LINE 40

//�����̺߳�����������Ľṹ��
typedef struct _TICKET {
	int nCount;
	char strTicketName[NAME_LINE];

	_TICKET() :nCount(0) {
		memset(strTicketName, 0, NAME_LINE * sizeof(char));
	}
}TICKET;

typedef struct _THD_DATA {
	TICKET *pTicket;
	char strThreadName[NAME_LINE];
	_THD_DATA() :pTicket(NULL) {
		memset(strThreadName, 0, NAME_LINE*sizeof(char));
	}
}THD_DATA;

//��������ת�����ַ���
template<class T>//��ģ��
string converToString(const T val) {
	string s;
	std::strstream ss;
	ss << val;//����
	ss >> s;//���
	return s;
}

//��Ʊ����
extern HANDLE hMutex;//����������
DWORD WINAPI SaleTicket(LPVOID lpParameter) {
	THD_DATA* pThreadData = (THD_DATA*)lpParameter;
	TICKET*pSaleData = pThreadData->pTicket;
	while (pSaleData->nCount > 0) {
		//��ȡһ��������
		WaitForSingleObject(hMutex, INFINITE);
		if (pSaleData->nCount > 0) {
			cout << pThreadData->strThreadName << "���۵�" << pSaleData->nCount-- << "��Ʊ��";
			if (pSaleData->nCount >= 0) {
				cout << "��Ʊ�ɹ���ʣ��" << pSaleData->nCount << "��Ʊ." << endl;
			}
			else {
				cout << "����ʧ�ܣ�Ʊ����" << endl;
			}
		}
		Sleep(10);
		//�ͷŻ�����
		ReleaseMutex(hMutex);
	}
	return 0L;
}
//test��Ʊϵͳ
void test() {
	//����������
	hMutex = CreateMutex(NULL, FALSE, NULL);
	//��ʼ����Ʊ
	TICKET ticket;
	ticket.nCount = 100;
	strcpy_s(ticket.strTicketName, "����->����");


	const int THREAD_NUMM = 8;
	THD_DATA threadSale[THREAD_NUMM];
	HANDLE hThread[THREAD_NUMM];
	for (int i = 0; i < THREAD_NUMM; ++i) {
		threadSale[i].pTicket = &ticket;
		string strThreadName = converToString(i);//ת���ַ���
		strThreadName = "����" + strThreadName;
		strcpy_s(threadSale[i].strThreadName, strThreadName.c_str());

		//�����߳�
		hThread[i] = CreateThread(NULL, NULL, SaleTicket, &threadSale[i], 0, NULL);

		//����һ��������
		WaitForSingleObject(hMutex, INFINITE);
		cout << threadSale[i].strThreadName << "��ʼ����" << threadSale[i].pTicket->strTicketName
			<< "��Ʊ..." << endl;
		//�ͷŻ�����
		ReleaseMutex(hMutex);

		//�ر��߳�
		CloseHandle(hThread[i]);
	}
	system("pause");
}

int main() {
	/*
	auto mainThreadId = std::this_thread::get_id();
	//����һ���߳�
	std::vector<double>v;
	for (int i = 0; i < 1000; i++) {
		v.push_back(rand());
	}
	cout << v.size() << endl;
	double value = 0.0;
	auto st = clock();
	for (auto&info : v) {
		value += caculate(info);
	}
	auto ed = clock();
	cout << "signal thread:" << value << " " << ed - st << "time" << endl;

	//���߳�
	auto iterMid = v.begin() + (v.size() / 2);//ָ������vectorǰ�벿��
	//�����벿
	double anotherv = 0.0;
	auto iterEnd = v.end();
	st = clock();

	std::thread s([&anotherv, mainThreadId, iterMid, iterEnd]() {
	
		anotherv = visitRange(mainThreadId, iterMid, iterEnd, caculate);
	});
	//����ǰ�벿��
	auto halfv = visitRange(mainThreadId, v.begin(), iterMid, caculate);

	//�ر��߳�
	s.join();
	ed = clock();

	cout << "mthread" << (halfv + anotherv) << " " << ed - st << "time" << endl;
*/

	/*
	std::thread threads[5];
	std::mutex mutex;
	int counter = 0;
	for (std::thread &thr : threads) {
		thr = std::thread(inc, std::ref(mutex), 1000, std::ref(counter));
	}
	for (std::thread &thr : threads) {
		thr.join();//�ر��߳�
	}
	//���Ϊ5000����ʹ��try_lock ����ܻ�<5000
	std::cout << counter << std::endl;
	*/

//���߳����ӣ���Ʊ
	test();


//���̻߳�������д
/*
	//����һ��������
	g_hMutex = CreateMutex(NULL, FALSE, NULL);

	//��ʼ���߳�����
	THREAD_DATA threadData1, threadData2;
	threadData1.nMaxNum = 5;
	strcpy_s(threadData1.strThreadName, "thread1");
	threadData2.nMaxNum = 5;
	strcpy_s(threadData2.strThreadName, "thread2");
	//�����߳�
	HANDLE hThread1 = CreateThread(NULL, 0, ThreadPro, &threadData1, 0, NULL);
	HANDLE hThread2 = CreateThread(NULL, 0, ThreadPro1, &threadData2, 0, NULL);

	//�ر��߳�
	CloseHandle(hThread1);
	CloseHandle(hThread2);

	//���߳�ִ��·��
	for (int i = 0; i < 5; i++) {
		//��ȡһ��������
		WaitForSingleObject(g_hMutex, INFINITE);

		cout << "���߳�==" << i << endl;
		Sleep(100);
		//�ͷŻ�����
		ReleaseMutex(g_hMutex);
	}
*/

	system("pause");
	return 0;
}