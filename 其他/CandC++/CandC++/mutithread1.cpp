#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <windows.h>//windows库 API
#include <process.h>//进程库

using namespace std;
//并发线程库和消息队列多线程 c++11
//并发(一个处理器)：两个或多个独立活动在同一时间段内发生；并行(多个处理器)：是同时执行

void task1() {
	cout << "1:" << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::milliseconds(10));
}
void task2() {
	cout << "2:" << this_thread::get_id() << endl;
	this_thread::sleep_for(chrono::milliseconds(2));
}
//多线程创建执行 挂起终止
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

	t1.join();//阻塞当前线程
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
			ResumeThread(hand1);//恢复
			ResumeThread(hand2);
		}
		else if (input == 2) {
			SuspendThread(hand1);//挂起
			SuspendThread(hand2);
		}
	}
	TerminateThread(hand1,1);//退出
	TerminateThread(hand2,2);
	system("pause");
	return 0;
}