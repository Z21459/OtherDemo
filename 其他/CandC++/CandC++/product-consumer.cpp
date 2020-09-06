#include <iostream>
#include <vector>
#include <windows.h>
#include <process.h>

using namespace std;

//确定缓冲区
#define LENGTH 5
//随机时间
#define GETMYRAND()(int)(((double)rand()/(double)RAND_MAX)*300)

//临界区同步线程
CRITICAL_SECTION _cr;
//空信号量
HANDLE emptySemaphore = NULL;
//满信号量
HANDLE fullSemaphore = NULL;
//缓冲区buffer
vector<int>buffer;

//消费者线程
DWORD  WINAPI Consumer(void *lp) {
	while (true) {
		//判断缓冲区域信号量
		WaitForSingleObject(fullSemaphore, 0xFFFFFFFF);
		//进入临界区 线程同步
		EnterCriticalSection(&_cr);
		//消费者从线程取出一个
		buffer.pop_back();
		//打印当前缓冲区可用资源
		std::cout << "消费一个，当前可用：" << buffer.size() << endl;
		//离开临界
		LeaveCriticalSection(&_cr);
		//释放判断缓冲区的信号量
		ReleaseSemaphore(emptySemaphore, 1, NULL);
		//线程睡眠
		Sleep(GETMYRAND()+500);
	}
	return 0;
}
//生产者
DWORD WINAPI Product(void *lp) {
	while (true) {
		//判断缓冲区信号
		WaitForSingleObject(emptySemaphore, 0xFFFFFFFF);
		//进入临界区 同步
		EnterCriticalSection(&_cr);
		//生产者向缓冲区加入一个资源
		buffer.push_back(1);
		//打印当前缓冲区可用资源
		std::cout << "产生一个资源，当前剩余可用：" << buffer.size() << endl;
		//离开临界区
		LeaveCriticalSection(&_cr);
		//释放判断缓冲区满信号量
		ReleaseSemaphore(fullSemaphore, 1, NULL);
		//线程睡眠
		Sleep(GETMYRAND()+200);
	}
	return 0;
}

int mainp() {
	//创建信号量
	emptySemaphore = CreateSemaphore(NULL, LENGTH, LENGTH, NULL);
	fullSemaphore = CreateSemaphore(NULL,0,LENGTH,NULL);

	//初始化临界区
	InitializeCriticalSection(&_cr);
	//开启多线程
	HANDLE threads[2];
	threads[0] = CreateThread(0, 0, &Product, 0, 0, 0);
	threads[1] = CreateThread(0, 0, &Consumer, 0, 0, 0);

	//等待子线程完成
	WaitForMultipleObjects(2, threads, true, INFINITE);//join threads
	//释放子线程
	CloseHandle(threads[0]);
	CloseHandle(threads[1]);

	//释放临界区
	DeleteCriticalSection(&_cr);
	return 0;

}