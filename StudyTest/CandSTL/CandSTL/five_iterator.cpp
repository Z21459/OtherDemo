#include<iostream>
#include <map>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

/*
迭代器
 输入型  输出型 前向 双向  随机
 1. 输入型 只能够一次一次的往前读  * -> ++ == !=  TYPE(iter)复制迭代器
 2. 输出 只能一个一个赋值 * ++ 等操作
 3. 前向  ++ == iter!= iter1 具有输入和输出的绝大部分功能
 4. 双向 增加了回头遍历 --iter；
 5. 随机 可以支持的迭代器 有 vector deque string 普通数组arrar
 迭代器不能被实例化一般的指针类型

 流迭代器 是一种迭代器配接器 可以把流当成算法的原点和终点

 
 5.5 辅助迭代器
 advance:所有类型迭代器均可以方便的前进和后退
 distance:计算统一容器中两个迭代器之间的距离
 iter_swap:交换两个迭代器所指向元素的值 迭代器的类型可以不同，但是所指向的两个值必须可以交换
 
 */

void print_I(int &elm)
{
	cout << elm << " ";
}

int main7()
{
	/*vector<int> vec;
	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i);
	}
	while (!vec.empty())
	{
		vector<int>::iterator k = vec.begin();
		vec.erase(k);//删除第一个元素
	}*/

	list<int>ll;
	for (int i = 0; i < 7; i++)
	{
		ll.push_front(i);
	}
	for_each(ll.begin(), ll.end(), print_I);
	cout << endl;
	//for_each(ll.rbegin(), ll.rend(), print_I);
	cout << endl;

	vector<int>vec;
	for (int i = 0; i < 7; i++)
	{
		vec.push_back(i+1);
	}
	for_each(vec.begin(), vec.end(), print_I);
	cout << endl;
	cout << endl;
	list<int>::iterator it = ll.begin();
	vector<int>::iterator it1 = vec.begin();
	iter_swap(it, it1);
	for_each(vec.begin(), vec.end(), print_I);
	cout << endl;



	system("pause");
	return 0;
}