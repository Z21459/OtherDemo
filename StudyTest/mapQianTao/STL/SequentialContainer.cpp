#include <iostream>
#include <vector>
#include <list>
#include <deque>//双向对列
using namespace std;
/*
顺序容器--线性表  线性结构 
vector 相当于数组 从后面快速插入和删除   直接访问元素
deque  从前面和后面快速插入和删除   直接访问任何元素
list 双链表 从任何地方快速插入和删除

如果关心随机存取和两端数据的插入和删除  deque最好的选择
*/


int mains()
{
	vector<int>vec;
	vec.push_back(1);
	vec.push_back(2);

	vector<int>vec1;
	vec1.push_back(3);
	vec1.push_back(2);

	vector<int>vec2;
	vec2.push_back(5);
	vec2.push_back(6);

	vec.insert(vec.end(), vec1.begin(), vec1.end());
	vec.insert(vec.end(), vec2.begin(), vec2.end());

	deque<int>de;
	de.push_back(1);//尾插入
	de.push_back(2);
	de.push_front(3);//头插入

	//cout << vec.at(1);查找位置

	list<int>m_list;
	m_list.push_back(1);
	m_list.push_back(2);
	m_list.push_front(3);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
		//cout << de[i] << endl;
	}
	/*list<int>::iterator it = m_list.begin();

	for (; it!=m_list.end();it++) 
	{
		cout << *it << endl;
	}*/
	system("pause");
	return 0;
}