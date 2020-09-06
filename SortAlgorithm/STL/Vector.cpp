#include <iostream>
#include <fstream>//文件流操作
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
using namespace std;

class String {
public:
	String(char *str = NULL);
	String(const String& other);
	~String(void);
	String&operator=(const String& s);
private:
	char* m_data;
};
String::~String(void) {
	delete[]m_data;
	
}
String& String::operator=(const String&s) {
	if (this == &s)
		return *this;
	delete[]m_data;
	m_data = NULL;
	m_data = new char[strlen(s.m_data) + 1];
	strcpy(m_data, s.m_data);
	return *this;
}
//auto_ptr 智能指针 代替指针进行类似指针的操作

//顺序vector string deque list     关联set multiset map multimap    适配stack queue priority_queue

template <class T,int num>
class A {
public:
	void work() { cout << num; }
};
int main4(int argc, char *argv[]) {

	//vector<int> a;//数组  不在乎插入删除  收尾两端进行操作 选择deque(动态数组  find  for_each）
	//a.push_back(2);
	//list<int>b;//双向链表 不连续  不支持随机访问  在乎插入删除
	//b.push_back(1);

	//stack<int, vector<int>>s;//s.top()
	//queue<int, vector<int>>q;//q.front()
	//s.push(1);
	//q.push(2);
	//set<string>c;
	//c.insert("b");
	//map<int, string>mapstring;
	//mapstring.insert(pair<int, string>(1, "one"));//插入元素  //erase删除  

	//a.capacity();//容量

	//ifstream in("./a.txt");
	//if (!in) {
	//	cout << "error";
	//}
	//int tmp;
	//while (!in.eof())
	//{
	//	in >> tmp;
	//	a.push_back(tmp);
	//}
	//in.close();
	//ofstream out("./b.txt");
	//if (!out) {
	//	cout << "err";
	//}
	//out.close();

	A<int, 1>v1;
	v1.work();



	system("pause");
	return 0;
}

