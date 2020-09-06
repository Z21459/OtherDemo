#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <windows.h>//windows�� API
#include <process.h>//���̿�

using namespace std;
//�����߳̿����Ϣ���ж��߳� c++11
//����(һ��������)�����������������ͬһʱ����ڷ���������(���������)����ͬʱִ��

void task1() {
	cout << "1:" << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::milliseconds(10));
}
void task2() {
	cout << "2:" << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::milliseconds(2));
}
//���̴߳���ִ�� ������ֹ
DWORD WINAPI func(LPVOID lpPrarmter) {
	while (true) {
		Sleep(100);
		cout << *((int*)lpPrarmter) << "hello" << endl;
	}
}

DWORD WINAPI func1(LPVOID param) {
	while (true) {
		Sleep(100);
		cout << "world" << endl;
	}
}
int mainm() {

	/*
	thread t1(task1);
	thread t2(task2);

	t1.join();//������ǰ�߳�
	t2.join();

	cout << "main:" << this_thread::get_id();
	*/

	int input = 0;
	HANDLE hand1 = CreateThread(NULL, 0, func, (void*)&input, CREATE_SUSPENDED, NULL);
	HANDLE hand2 = CreateThread(NULL, 0, func, (void*)&input, CREATE_SUSPENDED, NULL);
	while (input != 3) 
	{
		std::cin >> input;
		if (input == 1) {
			ResumeThread(hand1);//�ָ�
			ResumeThread(hand2);
		}
		else if (input == 2) {
			SuspendThread(hand1);//����
			SuspendThread(hand2);
		}
	}
	TerminateThread(hand1,1);//�˳�
	TerminateThread(hand2,2);
	system("pause");
	return 0;
}