#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/*
容器适配器
stack 栈  先进后出
queue 队列  先进先出
priority_queue 最高优先级总是第一个出列

适配器 是容器的接口  本身不直接保存元素 其保存元素机制是调用另一种顺序容器实现
可以看做适配器是保存一个容器  容器再保存元素
*/

int main2()
{
	stack<int>s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	
	while (s1.size()>0)
	{
		std::cout << s1.top() << endl;
		s1.pop();
	}
	queue<int>q1;
	q1.push(1);
	q1.push(2);

	while (q1.size())
	{
		std::cout << q1.front() << endl;
		q1.pop();
	}

	priority_queue<int>pr1;
	pr1.push(1);//默认大堆 就是逆向输出
	pr1.push(2);
	while (pr1.size())
	{
		std::cout << pr1.top() << endl;
		pr1.pop();
	}


	system("pause");
	return 0;
}