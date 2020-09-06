#include <iostream>
#include <set>
#include <map>
using namespace std;

/*关联容器是非线性树结构 
是二叉树结构 各元素之间没有严格意义上的逻辑结构
提供了迭代器 根据元素的特点 查找相应的元素
特点：根据键值对来保存数据 
set multiset map multimap 
set:集合，插入值唯一，按照顺序 键值对插入，是链表 查找慢
multiset：不要求插入值唯一
map：按照键值对  键不可重复 ；；；set可以看成特殊map，没有值只有键
multimap：允许键不唯一
默认插入是升序排列
查找复杂度log（N）
*/



int main1()
{
	set<int> set1;
	set1.insert(1);
	set1.insert(2);
	set1.insert(1);

	multiset<int>mutset1;
	mutset1.insert(1);
	mutset1.insert(2);
	mutset1.insert(1);

	//set<int>::iterator it = set1.begin();
	//multiset<int>::iterator it = mutset1.begin();
	//for (; it != mutset1.end(); it++)
	//{
	//	std::cout << *it << endl;
	//}


	map<int, int> map1;
	map1.insert(make_pair(1, 2));
	map1.insert(make_pair(2, 3));
	map1.insert(make_pair(1, 2));

	multimap<int, int>multmap;
	multmap.insert(make_pair(1, 2));
	multmap.insert(make_pair(2, 3));
	multmap.insert(make_pair(1, 2));//输出按照键值顺序 进行输出
	//map<int, int>::iterator it = map1.begin();
	map<int, int>::iterator it = multmap.begin();
	for (;it!= multmap.end();it++)
	{
		std::cout << it->second << endl;
	}

	system("pause");
	return 0;
}