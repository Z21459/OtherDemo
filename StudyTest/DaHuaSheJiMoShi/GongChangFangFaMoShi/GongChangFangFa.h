#pragma once
#include <iostream>
using namespace std;

class GongChangFangFa
{
public:
	GongChangFangFa();
	~GongChangFangFa();
};
//构建工厂接口
class IFactor
{
public:
	virtual void CreateOperation() {};
};

//各种操作方法 继承实现  返回

class AddFactor :public IFactor
{
public:
	void CreateOpertation()
	{
		return;//new OperatorAdd;
	}
};



//简单工厂
class LeiFeng
{
public:
	LeiFeng(){}
	~LeiFeng(){}
	virtual void do1(){}
	virtual void do2(){}
};

//继承
class Student:public LeiFeng
{
public:
	Student(){}
	~Student(){}
	void do1() { cout << "s1" << endl; }
	void do2() { cout << "s2" << endl; }
};

class simpleFactor
{
public:
	LeiFeng* CreateLeiFeng(int id)
	{
		LeiFeng *lei = nullptr;
		switch (id)
		{
		case 1:
		{
			lei = new Student;
			break;
		}
		default:
			break;
		}
		return lei;
	}
};
//客户端
//void client()
//{
//	simpleFactor *sm = new simpleFactor;
//	LeiFeng *sta = sm->CreateLeiFeng(1);
//	sta->do1();
//}


//工厂方法
class IFactory1
{
public:
	virtual LeiFeng *createLef() { return nullptr; };
};

class Stu :public IFactory1
{
public:
	LeiFeng *createLef()
	{
		return (new Student);//创建工厂模式方法
	}
};
//类似设置志愿者

///开放-封闭原则   对内开放  对外封闭

//client
//void fun1()
//{
//	IFactory1 *fac = new Stu;
//	LeiFeng *s = fac->createLef();
//	s->do1();
//	s->do2();
//}


