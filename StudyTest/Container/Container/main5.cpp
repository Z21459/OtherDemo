#include <iostream>     // std::cout
#include <algorithm>    // std::unique_copy, std::sort, std::distance
#include <vector>       // std::vector
#include <string>
#include <map>
#include<functional>
using namespace std;

class A {
public:
	A(){}
	~A() {}
	int a;
	int b;
	const string func();
};
const string A::func()
{
	return "aa";
}

class B {
public:
	string s;
};
//仿函数  类中单个查找  设计成多个条件 查找
bool priceComparision(A* lef,  int y,int flag)
{
	if (flag == 0)
	{
		if (lef->a == y)
			return true;
		else
			return false;
	}
	if (flag == 1)
	{
		if (lef->b == y)
			return true;
		else
			return false;
	}

}

bool cmpString(B *left, B *right)
{
	if (left->s < right->s) return true; //升
	else if (left->s > right->s) return false;//降
	else return false;
}

int main()
{
	A x;
	string w = x.func();
	cout << w << endl;
	A *a1 = new A;
	a1->a = 2;
	a1->b = 1;
	A *a2 = new A;
	a2->a = 2;
	a2->b = 2;
	A *a3 = new A;
	a3->a = 1;
	a3->b = 3;
	vector<A*> Avec;
	Avec.push_back(a1);
	Avec.push_back(a2);
	Avec.push_back(a3);

	int len3 = Avec.size();
	std::reverse(Avec.begin(), Avec.end());

	std::random_shuffle(Avec.begin(), Avec.end());//vector 乱序

	cout << endl;
	//std::placeholders::_1, std::placeholders::_2, 绑定第几个参数
	//find 要是参数 固定    find_if 可以不定参数  并且 参数是const  
	vector<A*>::iterator avec = Avec.begin();
	static int a = (*avec)->a;
	vector<A*>::reverse_iterator avec_it = std::find_if(Avec.rbegin(), Avec.rend(),
		std::bind(priceComparision, std::placeholders::_1, (*avec)->a, 0)); ///正向迭代也是一样

	vector<A*>::reverse_iterator avec_itb = std::find_if(Avec.rbegin(), Avec.rend(),
		std::bind(priceComparision, std::placeholders::_1, (*avec)->b, 1));

	cout << distance(avec_it, Avec.rend()); //反向遍历  是几就有几个重复
	int lena = distance(avec_it, Avec.rend());
	int lenb = distance(avec_itb, Avec.rend());

	vector<A*> Avec1;
	Avec1.assign(avec, avec + lena);

	B *b1 = new B;
	B *b2 = new B;
	B *b3 = new B;
	B *b4 = new B;
	vector<B*>vecb;
	b1->s = "abc";
	b2->s = "aac";
	b3->s = "aad";
	b4->s = "acd";
	vecb.push_back(b1);
	vecb.push_back(b2);
	vecb.push_back(b3);
	vecb.push_back(b4);
	std::sort(vecb.begin(), vecb.end(), cmpString);

	vector<string>vec;
	vec.push_back("aca");
	vec.push_back("abb");
	vec.push_back("ccc");
	vec.push_back("cdd");

	//字符串 排序 比较大小
	//std::sort(vec.begin(), vec.end());

	map<string, int>Map;
	Map["aaa||"] = 1;
	Map["bbb"] = 1;
	Map["aaa"] = 1;
	Map["ccc"] = 1;
	vector<string>::iterator beg_it1 = vec.begin();

	vector<string>::iterator beg_it = std::find(vec.begin(), vec.end(), *beg_it1);
	vector<string>::reverse_iterator end_it = std::find(vec.rbegin(), vec.rend(),*beg_it1);
	
	cout << distance(beg_it1, beg_it);//vector 查找相同元素的初始位置 一直是0
	cout << endl;
	cout << distance(end_it, vec.rend()); //反向遍历  是几就有几个重复
	int len = distance(end_it, vec.rend());
	vector<string>vec2;
	vec2.insert(vec2.begin(),vec.begin(), vec.begin() + len);

	vector<int> vect;

	cout << endl;
	int k = 10;
	while (k)
	{
		std::random_shuffle(vec.begin(), vec.end());
		std::random_shuffle(vec.begin(), vec.end());
		//vector<string>::iterator it = vec.begin();
		for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			//vec.push_back(*it);//循环里面不能对size进行修改  否则迭代器失效 报错
			if (*it == "bbb")
			{
				vec.push_back("sss");
				break;
			}
			cout << *it << " ";
		}
		cout << endl;
		k--;
		//string s;
		//cin >> s;
		//if (std::find(vec.begin(), vec.end(),s) == vec.end())
		//{
		//	cout << "no find";
		//}
		//else
		//{
		//	cout << "find";
		//}

		//if (Map.find(s) == Map.end())
		//{
		//	cout << "no find";
		//}
		//else
		//{
		//	cout << "find";
		//}
	}

	system("pause");
	return 0;
}




//using namespace std;
//class Point3d {
//	double x, y, z;
//public:
//	Point3d(double x, double y, double z) :x(x), y(y), z(z) {}
//	bool operator == (const Point3d &p) {
//		return (this->x == p.x) && (this->y == p.y);
//	}
//};
//
//int main() {
//
//	vector<Point3d> p{ {0,0,0},{1,2,3},{1.1,2.1,3.1},{10,11,11} };
//	vector<Point3d>::iterator result = find(p.begin(), p.end(), Point3d(10, 11, 10));
//	if (result == p.end())
//		cout << "没找到" << endl;
//	else
//		cout << "找到" << endl;
//	system("pause");
//	return 0;
//}