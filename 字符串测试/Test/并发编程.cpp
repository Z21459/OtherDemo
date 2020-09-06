#include <iostream>
#include <thread>//�����̺߳���
#include <vector>
#include <list>
#include <algorithm>
#include <mutex>
#include <shared_mutex>
#include <memory>
#include <condition_variable>
#include <future>
#include <exception>//�쳣����

using namespace std;

/*
����һ���߳�  �ȴ��߳̽���  ���ں�̨����
���Ѿ������̴߳��� ��һ���߳�����Ȩ�ӵ�ǰ����ת������һ��
ȷ���߳�����ʶ�������߳�
*/
void hello()
{
	cout << "hello nihao" << endl;
}

//��������߳�������
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
������ mutex ��֤���ݵĹ��� �����������
 std::mutex  lock()����  unlock()����

 ��ʵ����� ͨ��ģ����std::lack_guard �ṩ������
 */

//����궨�� ʹ�ñ��� --�ָ�ѧ���� ��������
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
ͬ����������  �������� condition variables  futures

condition_variable    condition_variable_any

*/


////�������ż�ʱ������һ���첽����
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
�������Ĳ������ݽṹ���

���ݽṹ��ѡ���ǽ����������Ҫ��ɲ���

�������ṩ�������� �ڻ����������� ͬһʱ��ֻ��һ���߳̿��Ի�û�����
������Ϊ�˱������� ��ʾ����ֹ���̶߳����ݽṹ�Ĳ�������

��Ʋ�����Ҫ���ǣ�1.ȷ������ʱ��ȫ 2.������������
***   ����Ƕ�����ĳ���

��򵥵��̰߳�ȫ�ṹ��ͨ��ʹ�õ��ǻ���������  �����ݽ��б���

std::move �����������Լ��Ĳ���ת��Ϊ��ֵ��
�ڶ��󿽱���ʱ��������ʱ�����ǲ������һ�д��룬 ���Լ�����Դ�������ͷš�




*/


int main1()
{
	//thread t(hello);//ÿ���̶߳���Ҫһ����ʼ����
	//t.join();

	system("pause");
	return 0;
}