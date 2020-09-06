// ThreadPool.cpp: �������̨Ӧ�ó������ڵ㡣
//

#include "ThreadPool.h"
#include <stdio.h>

class Task
{
public:
	static int Task1(PVOID p)
	{
		int i = 10;
		while (i >= 0)
		{
			printf("Task1��%d\n", i);
			Sleep(100);
			i--;
		}
		return i;
	}
};
//const  define  static  inline

class TaskCallback
{
public:
	static void TaskCallback1(int result)
	{
		printf("TaskCallback1��%d\n", result);
	}
};

int main()
{
	ThreadPool threadPool(2, 10);
	for (size_t i = 0; i < 10; i++)//�����޷����͵�
	{
		threadPool.QueueTaskItem(Task::Task1, NULL, TaskCallback::TaskCallback1);
	}
	threadPool.QueueTaskItem(Task::Task1, NULL, TaskCallback::TaskCallback1, TRUE);

	//getchar();//������ͣ
	system("pause");

	return 0;
}