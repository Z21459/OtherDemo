#include <iostream>
#include <thread>//管理线程和类
#include <vector>
#include <list>
#include <algorithm>
#include <mutex>
#include <shared_mutex>
#include <memory>
#include <condition_variable>
#include <future>
#include <exception>//异常处理

using namespace std;

/*
启动一个线程  等待线程结束  放在后台运行
给已经启动线程传参 将一个线程所有权从当前对象转交到另一个
确定线程数和识别特殊线程
*/
void hello()
{
	cout << "hello nihao" << endl;
}

//计算最大线程运行数
template <typename Iterator,typename T>
struct accumulate_block
{
	void operator()(Iterator first, Iterator last, T& result)
	{
		result = std::accumulate(first, last, result);
	}
};

template<typename Iterator,typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
	unsigned long const length = std::distance(first, last);
	if (!length) return init;
	unsigned long const min_per_thread = 25;
	unsigned long const max_thread =
		(length + min_per_thread - 1) / min_per_thread;

	unsigned long const hardware_threads =
		std::thread::hardware_concurrency();
	unsigned long const num_threads =
		std::min(hardware_threads != 0 ? hardware_threads : 2, max_thread);

	unsigned long const block_size = length / num_threads;

	std::vector<T> results(num_threads);
	std::vector<std::thread> threads(num_threads - 1);

	Iterator block_start = first;
	for (unsigned long i = 0; i < (num_threads - 1); i++)
	{
		Iterator block_end = block_start;
		std::advance(block_end, block_size);
		threads[i] = std::thread(
			accumulate_block<Iterator, T>(),
			block_start, block_end, std::ref(results[i])
		);
		block_start = block_end;
	}
	accumulate_block<Iterator, T>()(
		block_start, last, results[num_threads - 1]
		);
	std::for_each(threads.begin(), threads.end(),
		std::mem_fn(&std::thread::join));

	return std::accumulate(results.begin(), results.end(), init);
}


/*
互斥锁 mutex 保证数据的共享 不会出现问题
 std::mutex  lock()上锁  unlock()解锁

 现实编程中 通过模板类std::lack_guard 提供锁机制
 */

//定义宏定义 使用变量 --乐港学到的 加锁机制
#define MutexLock std::mutex  

inline void AutoLock(MutexLock &s_mutex)
{
	std::lock_guard<MutexLock> guard(s_mutex);
}

std::list<int>some_list;
//std::mutex some_mutex;
MutexLock some_mutex;
void add_list(int new_vlaue)
{
	AutoLock(some_mutex);
	//std::lock_guard<MutexLock> guard(some_mutex);
	some_list.push_back(new_vlaue);
}

bool list_container(int find_value)
{
	std::lock_guard<MutexLock> guard(some_mutex);
	return std::find(some_list.begin(), some_list.end(), find_value)!=some_list.end();
}

/*
同步并发操作  条件变量 condition variables  futures

condition_variable    condition_variable_any

*/


////当任务不着急时，启动一个异步任务
//int find_the_answer() { return 0; };
//void do_something() {};
//
//void cure()
//{
//	std::future<int> the_answer = std::async(find_the_answer);
//	do_something();
//	cout << the_answer.get() << endl;
//}

/*
基于锁的并发数据结构设计

数据结构的选择是解决方案的重要组成部分

互斥量提供互斥特性 在互斥量保护下 同一时间只有一个线程可以获得互斥锁
互斥量为了保护数据 显示的阻止了线程对数据结构的并发访问

设计并发需要考虑：1.确保访问时安全 2.真正并发访问
***   避免嵌套锁的出现

最简单的线程安全结构，通常使用的是互斥量和锁  对数据进行保护

std::move 会无条件将自己的参数转换为右值。
在对象拷贝的时候，在运行时，它们不会产生一行代码， 可以减少资源创建和释放。




*/


int main1()
{
	//thread t(hello);//每个线程都需要一个初始函数
	//t.join();

	system("pause");
	return 0;
}