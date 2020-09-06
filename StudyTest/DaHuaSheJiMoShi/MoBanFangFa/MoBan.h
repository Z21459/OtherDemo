#pragma once
#include <iostream>
using namespace std;
class MoBan
{
public:
	MoBan();
	~MoBan();

	//一些抽象行为 放到子类中实现
	virtual void ab1() {};
	virtual void ab2() {};

	//模板方法 给出逻辑框架，而逻辑组成是一些相应的操作

	void TempMethod()
	{
		ab1();
		ab2();
	}
};

//子类 实现父类所定义的一个或者多个方法

class Con1 :public MoBan
{
public:
	//继承父类 实现父类的方法
	void ab1()
	{
		cout << "c1";
	}
	void ab2()
	{
		cout << "c2";
	}
};
//多个Con分别实现功能
class Con2 :public MoBan
{
public:
	//继承父类 实现父类的方法
	void ab1()
	{
		cout << "b1";
	}
	void ab2()
	{
		cout << "b2";
	}
};

//client







