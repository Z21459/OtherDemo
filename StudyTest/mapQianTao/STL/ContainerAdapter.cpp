#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/*
����������
stack ջ  �Ƚ����
queue ����  �Ƚ��ȳ�
priority_queue ������ȼ����ǵ�һ������

������ �������Ľӿ�  ����ֱ�ӱ���Ԫ�� �䱣��Ԫ�ػ����ǵ�����һ��˳������ʵ��
���Կ����������Ǳ���һ������  �����ٱ���Ԫ��
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
	pr1.push(1);//Ĭ�ϴ�� �����������
	pr1.push(2);
	while (pr1.size())
	{
		std::cout << pr1.top() << endl;
		pr1.pop();
	}


	system("pause");
	return 0;
}