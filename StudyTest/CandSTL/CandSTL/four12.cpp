#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


template <class T>
void findValue(T& vect, int first, int last)
{
	if (last > first)
	{
		for (int i = first; i < last; i++)
		{
			vect.insert(vect.end(), i);
		}
	}
	else
	{
		cout << "index error";
	}
}

void print_d(int &elem)
{
	cout << elem << " ";
}
//仿函数 
template <class T>
class Mult
{
private:
	T theVal;
public:
	Mult(const T&v) :theVal(v)
	{

	}
	void operator()(T &elem) const
	{
		elem *= theVal;//添加成员函数
	}
};

//定义sum求和
class Sum
{
private:
	long sum;
public:
	Sum():sum(0){}
	void operator()(int elem)
	{
		sum += elem;
	}
	operator double() {
		return static_cast<double>(sum);//返回求和
	}
};

bool isEven(int elem)
{
	return elem % 2 == 0;//偶数返回true
}

bool AbsLess(int elem1, int elem2)
{
	return abs(elem1) < abs(elem2);
}

//bind2nd(greater<int>(),2) 表示数值大于2的条件表达式

int main12()
{
	vector<int>myvec;
	findValue(myvec, 1, 10);
	for_each(myvec.begin(), myvec.end(), print_d);
	cout << endl;

	/*//仿函数
	cout << endl;
	for_each(myvec.begin(), myvec.end(), Mult<int>(2));
	for_each(myvec.begin(), myvec.end(), print_d);
	cout << endl;*/

	//求和
	double sum = for_each(myvec.begin(), myvec.end(), Sum());
	cout << sum;
	cout << endl;

	int cont = count_if(myvec.begin(), myvec.end(), isEven);
	cout << cont;
	cout << endl;


	cout << "min " << *min_element(myvec.begin(), myvec.end(), AbsLess);
	cout << endl;


	vector<int>::iterator pos1;
	pos1 = find(myvec.begin(), myvec.end(), 5);
	cout << "等于5：" << distance(myvec.begin(), pos1) + 1 << endl;

	/*vector<int>::iterator pos3;
	pos1 = find_if(myvec.begin(), myvec.end(),2);
	cout << "dayu2" << distance(myvec.begin(), pos1) + 1 << endl;*/
	system("pause");
	return 0;
}