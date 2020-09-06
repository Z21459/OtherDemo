#pragma once
#include <iostream>
using namespace  std;
class OperatorItem
{
public:
	OperatorItem();
	~OperatorItem();
	virtual int getResult(int a, int b)
	{
		int result = 0;
		return result;
	}
	int getA() { return a; }
	int getB() { return b; }
	void setA(int a) { a = a; /*cout << a; getA();*/ }
	void setB(int b) { b = b; getB(); }
private:
	int a;
	int b;
};
class AddClass:public OperatorItem
{
public:
	AddClass() {};
	~AddClass() {};
	int getResult(int a,int b)
	{
		return a + b;
	}
};
class W :public OperatorItem
{
public:
	W() {};
	~W() {};
	int getResult(int a, int b)
	{
		return a - b;
	}
};