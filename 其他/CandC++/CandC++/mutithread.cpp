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


//查看当前线程id this_thread::get_id()比较单线程和多线程
double caculate(int v) {
	if (v <= 0) {
		return v;
	}
	//假设这个计算很慢
	this_thread::sleep_for(chrono::milliseconds(10));
	return sqrt((v*v + sqrt((v - 5)*(v + 2.5)) / 2.0) / v);
}

template<typename Iter,typename Fun>//类模板
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

//多线程多任务队列
/*
l 比如网游中数据库一般会创建连接池，用户的操作数据库都是有数据库线程池完成，在将结果投递给逻辑层。
对每个用户的数据增删改查操作都必须是有序的，
所以每个用户绑定一个固定的任务队列。而不同的用户的数据修改互不干扰，不同的用户分配不同的任务队列即可。

2 比如网络层中的多个socket的读写是互不干扰的，可以创建两个或更多线程，每个对应一个任务队列，
不同的socket的操作可以随机的分配一个任务队列（注意分配是随机的，一旦分配了，
单个socket的所有操作都会由这个任务队列完成，保证逻辑有序性）。
*/

//多线程多任务队列 多线程传参
#include<windows.h>
#define NAME_LINE 50
//线程运行函数

//定义线程函数传入参数
typedef struct _THREAD_DATA {
	int nMaxNum;
	char strThreadName[NAME_LINE];
	_THREAD_DATA() :nMaxNum(0) {
		memset(strThreadName, 0, NAME_LINE * sizeof(char));
	}
}THREAD_DATA;

//定义互斥量
HANDLE g_hMutex = NULL;//互斥量

//线程函数
DWORD WINAPI ThreadPro(LPVOID lpParameter) {
	THREAD_DATA *pThreadData = (THREAD_DATA*)lpParameter;
	for (int i = 0; i < pThreadData->nMaxNum; ++i) {
		//获取一个互斥量锁
		WaitForSingleObject(g_hMutex, INFINITE);

		cout << pThreadData->strThreadName << "---" << i << endl;
		//释放互斥量锁
		ReleaseMutex(g_hMutex);

		Sleep(100);
	}
	return 0L;//返回long型
}

DWORD WINAPI ThreadPro1(LPVOID lpParameter) {
	THREAD_DATA *pThreadData = (THREAD_DATA*)lpParameter;
	for (int i = 0; i < pThreadData->nMaxNum; ++i) {
		//获取互斥量
		WaitForSingleObject(g_hMutex,INFINITE);

		cout << pThreadData->strThreadName << "+++" << i << endl;
		Sleep(100);
		//释放互斥量
		ReleaseMutex(g_hMutex);
	}

	return 0L;
}
///上述例子创建成功  执行顺序混乱  利用CreatMutex，WaitForSingleObject，ReleaseMutex
//https://www.runoob.com/w3cnote/cpp-multithread-demo.html
//使用互斥量Mutex来使其同步--资源仅允许一个线程访问
//CreateMutex(同步处理)  WaitForSingleObject(等待一个指定对象) ReleaseMutex(HANDLE)


//例子 简单模拟购买火车票 有500张火车票，8个窗口出售票，保证系统稳定性
#include<string>
#include <strstream>

#define NAME_LINE 40

//定义线程函数传输参数的结构体
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

//基本类型转换成字符串
template<class T>//类模板
string converToString(const T val) {
	string s;
	std::strstream ss;
	ss << val;//输入
	ss >> s;//输出
	return s;
}

//售票程序
extern HANDLE hMutex;//创建互斥量
DWORD WINAPI SaleTicket(LPVOID lpParameter) {
	THD_DATA* pThreadData = (THD_DATA*)lpParameter;
	TICKET*pSaleData = pThreadData->pTicket;
	while (pSaleData->nCount > 0) {
		//获取一个互斥量
		WaitForSingleObject(hMutex, INFINITE);
		if (pSaleData->nCount > 0) {
			cout << pThreadData->strThreadName << "出售第" << pSaleData->nCount-- << "的票，";
			if (pSaleData->nCount >= 0) {
				cout << "出票成功！剩余" << pSaleData->nCount << "张票." << endl;
			}
			else {
				cout << "出售失败！票售完" << endl;
			}
		}
		Sleep(10);
		//释放互斥量
		ReleaseMutex(hMutex);
	}
	return 0L;
}
//test售票系统
void test() {
	//创建互斥量
	hMutex = CreateMutex(NULL, FALSE, NULL);
	//初始化火车票
	TICKET ticket;
	ticket.nCount = 100;
	strcpy_s(ticket.strTicketName, "北京->杭州");


	const int THREAD_NUMM = 8;
	THD_DATA threadSale[THREAD_NUMM];
	HANDLE hThread[THREAD_NUMM];
	for (int i = 0; i < THREAD_NUMM; ++i) {
		threadSale[i].pTicket = &ticket;
		string strThreadName = converToString(i);//转成字符串
		strThreadName = "窗口" + strThreadName;
		strcpy_s(threadSale[i].strThreadName, strThreadName.c_str());

		//创建线程
		hThread[i] = CreateThread(NULL, NULL, SaleTicket, &threadSale[i], 0, NULL);

		//请求一个互斥锁
		WaitForSingleObject(hMutex, INFINITE);
		cout << threadSale[i].strThreadName << "开始出售" << threadSale[i].pTicket->strTicketName
			<< "的票..." << endl;
		//释放互斥量
		ReleaseMutex(hMutex);

		//关闭线程
		CloseHandle(hThread[i]);
	}
	system("pause");
}

int main() {
	/*
	auto mainThreadId = std::this_thread::get_id();
	//开启一个线程
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

	//多线程
	auto iterMid = v.begin() + (v.size() / 2);//指向整个vector前半部分
	//计算后半部
	double anotherv = 0.0;
	auto iterEnd = v.end();
	st = clock();

	std::thread s([&anotherv, mainThreadId, iterMid, iterEnd]() {
	
		anotherv = visitRange(mainThreadId, iterMid, iterEnd, caculate);
	});
	//计算前半部分
	auto halfv = visitRange(mainThreadId, v.begin(), iterMid, caculate);

	//关闭线程
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
		thr.join();//关闭线程
	}
	//输出为5000，若使用try_lock 则可能会<5000
	std::cout << counter << std::endl;
	*/

//多线程例子，火车票
	test();


//多线程互斥量编写
/*
	//创建一个互斥量
	g_hMutex = CreateMutex(NULL, FALSE, NULL);

	//初始化线程数据
	THREAD_DATA threadData1, threadData2;
	threadData1.nMaxNum = 5;
	strcpy_s(threadData1.strThreadName, "thread1");
	threadData2.nMaxNum = 5;
	strcpy_s(threadData2.strThreadName, "thread2");
	//创建线程
	HANDLE hThread1 = CreateThread(NULL, 0, ThreadPro, &threadData1, 0, NULL);
	HANDLE hThread2 = CreateThread(NULL, 0, ThreadPro1, &threadData2, 0, NULL);

	//关闭线程
	CloseHandle(hThread1);
	CloseHandle(hThread2);

	//主线程执行路径
	for (int i = 0; i < 5; i++) {
		//获取一个互斥锁
		WaitForSingleObject(g_hMutex, INFINITE);

		cout << "主线程==" << i << endl;
		Sleep(100);
		//释放互斥量
		ReleaseMutex(g_hMutex);
	}
*/

	system("pause");
	return 0;
}