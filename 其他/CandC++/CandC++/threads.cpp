#include <iostream>
#include <thread>//直接创建一个线程
#include <chrono>//线程暂定
#include <windows.h>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>

using namespace std::chrono;

using namespace std;

void foo(const char* name)//线程传参
{
	cout << "hello" << name << endl;
}
//类成员函数作为线程入口
class Greet
{
public:
	void SayHello(const char* name) {
		std::cout << "Hello" << name << "from" << this->owner << endl;
	}
private:
	const char* owner = "Greet";

};
//join等待线程执行完成--即使当线程函数已经执行完成后，调用join仍然是有效的

//线程暂停  线程停顿一会sleep_for 和 sleep_until
void pausable() {
	//sleep500ms
	std::this_thread::sleep_for(milliseconds(500));
	//sleep到指定时间点
	std::this_thread::sleep_until(system_clock::now() + milliseconds(500));
}

//线程停止--线程执行完，自然停止 尽量在析构之前join下，确保线程成功结束


///////////////////多线程编程///////////////////
//windows提供HANDLE CreateThread(
//NULL,初始化栈大小，执行函数(回调函数)，执行函数参数或NULL，控制线程创建标志，传出参数用于获得线程ID)
//如果成功，得到线程句柄，失败返还NULL
//windows关闭对象句柄 BOOL WINAPI CloseHandle(HANDLE hObject);

//多线程编程实例      --多线程同步 利用互斥量(Mutex)来进行线程同步
//主要利用以下几个函数进行同步
//HANDLE WINAPI CreateMutex(NULL,创建当前线程是否拥有Mutex所有权，Mutex名称)
//DWORD WINAPI WaitForSingleObject(获得锁句柄，超时间隔)
//BOOL WINAPI ReleaseMute(HANDLE hMutex) 释放所拥有的互斥锁对象

HANDLE hMutex = NULL;//互斥量

DWORD WINAPI Fun(LPVOID lpParamter) {//回调函数线程函数
	for (int i = 0; i < 10; i++) {
		//请求一个互斥量锁
		WaitForSingleObject(hMutex,INFINITE);

		cout << "a thread" << endl;
		Sleep(200);
		//释放互斥量锁
		ReleaseMutex(hMutex);
	}
	return 0L;
}


int GetSum(vector<int>::iterator first, vector<int>::iterator last) {
	return accumulate(first, last, 0);//C++标准算法
}

//线程要做的事情就写在这个线程函数中
void GetSumT(vector<int>::iterator first, vector<int>::iterator last, int &result)
{
	result = accumulate(first, last, 0); //调用C++标准库算法
}


int maint(int argc,char *argv[]) {
	//启动线程
//	thread thread(foo,"C++11s");

//	Greet greet;
//	std::thread thread(&Greet::SayHello, &greet, "C++11");
//	std::thread thread(pausable);
//  thread.join();//等待线程执行完

/*
	HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);//创建线程
	hMutex = CreateMutex(NULL,FALSE,"screen");
	//关闭线程 句柄
	CloseHandle(hThread);
	//主线程执行路径
	for (int i = 0; i < 10; i++) {
		//请求获得互斥量
		WaitForSingleObject(hMutex, INFINITE);

		cout << "main thread" << endl;
		Sleep(500);
		//释放互斥锁
		ReleaseMutex(hMutex);
	}
*/
	//单线程实例
/*	vector<int> largArrays;
	for (int i = 0; i < 100000; i++) {
		if (i % 2 == 0)
			largArrays.push_back(i);
		else
			largArrays.push_back(i);
	}
	int res = GetSum(largArrays.begin(),largArrays.end());
	*/
	int result1, result2, result3, result4, result5;
	vector<int> largeArrays;
	for (int i = 0; i < 100000000; i++)
	{
		if (i % 2 == 0)
			largeArrays.push_back(i);
		else
			largeArrays.push_back(-1 * i);
	}
	//thread first(线程函数名，参数1，参数2，......)；每个线程有一个线程函数，线程要做的事情就写在线程函数中。
	thread first(GetSumT, largeArrays.begin(),
		largeArrays.begin() + 20000000, std::ref(result1)); //子线程1
	thread second(GetSumT, largeArrays.begin() + 20000000,
		largeArrays.begin() + 40000000, std::ref(result2)); //子线程2
	thread thrid(GetSumT, largeArrays.begin() + 40000000,
		largeArrays.begin() + 60000000, std::ref(result3)); //子线程3
	thread fouth(GetSumT, largeArrays.begin() + 60000000,
		largeArrays.begin() + 80000000, std::ref(result4)); //子线程4
	thread fifth(GetSumT, largeArrays.begin() + 80000000,
		largeArrays.end(), std::ref(result5)); //子线程5

	first.join(); //主线程要等待子线程执行完毕 join()是一个阻塞函数
	second.join();
	thrid.join();
	fouth.join();
	fifth.join();
	//first.detach()有时候我们需要建立一个暗中观察的线程，默默查询程序的某种状态，这种的称为守护线程。这种线程会在主线程销毁之后自动销毁。
	int resultSum = result1 + result2 + result3 + result4 + result5; //汇总各个子线程的结果
	//C++中一个标准线程函数只能返回void，因此需要从线程中返回值往往采用传递引用的方法
	
	system("pause");
	return 0;
}