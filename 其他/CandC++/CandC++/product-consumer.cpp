#include <iostream>
#include <vector>
#include <windows.h>
#include <process.h>

using namespace std;

//ȷ��������
#define LENGTH 5
//���ʱ��
#define GETMYRAND()(int)(((double)rand()/(double)RAND_MAX)*300)

//�ٽ���ͬ���߳�
CRITICAL_SECTION _cr;
//���ź���
HANDLE emptySemaphore = NULL;
//���ź���
HANDLE fullSemaphore = NULL;
//������buffer
vector<int>buffer;

//�������߳�
DWORD  WINAPI Consumer(void *lp) {
	while (true) {
		//�жϻ��������ź���
		WaitForSingleObject(fullSemaphore, 0xFFFFFFFF);
		//�����ٽ��� �߳�ͬ��
		EnterCriticalSection(&_cr);
		//�����ߴ��߳�ȡ��һ��
		buffer.pop_back();
		//��ӡ��ǰ������������Դ
		std::cout << "����һ������ǰ���ã�" << buffer.size() << endl;
		//�뿪�ٽ�
		LeaveCriticalSection(&_cr);
		//�ͷ��жϻ��������ź���
		ReleaseSemaphore(emptySemaphore, 1, NULL);
		//�߳�˯��
		Sleep(GETMYRAND()+500);
	}
	return 0;
}
//������
DWORD WINAPI Product(void *lp) {
	while (true) {
		//�жϻ������ź�
		WaitForSingleObject(emptySemaphore, 0xFFFFFFFF);
		//�����ٽ��� ͬ��
		EnterCriticalSection(&_cr);
		//�������򻺳�������һ����Դ
		buffer.push_back(1);
		//��ӡ��ǰ������������Դ
		std::cout << "����һ����Դ����ǰʣ����ã�" << buffer.size() << endl;
		//�뿪�ٽ���
		LeaveCriticalSection(&_cr);
		//�ͷ��жϻ��������ź���
		ReleaseSemaphore(fullSemaphore, 1, NULL);
		//�߳�˯��
		Sleep(GETMYRAND()+200);
	}
	return 0;
}

int mainp() {
	//�����ź���
	emptySemaphore = CreateSemaphore(NULL, LENGTH, LENGTH, NULL);
	fullSemaphore = CreateSemaphore(NULL,0,LENGTH,NULL);

	//��ʼ���ٽ���
	InitializeCriticalSection(&_cr);
	//�������߳�
	HANDLE threads[2];
	threads[0] = CreateThread(0, 0, &Product, 0, 0, 0);
	threads[1] = CreateThread(0, 0, &Consumer, 0, 0, 0);

	//�ȴ����߳����
	WaitForMultipleObjects(2, threads, true, INFINITE);//join threads
	//�ͷ����߳�
	CloseHandle(threads[0]);
	CloseHandle(threads[1]);

	//�ͷ��ٽ���
	DeleteCriticalSection(&_cr);
	return 0;

}