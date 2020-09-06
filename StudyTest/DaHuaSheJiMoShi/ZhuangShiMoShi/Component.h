#pragma once
#include <iostream>
#include <string>
using namespace std;

class Component//Person
{
public:
	Component();
	~Component();
	virtual void Operator() { cout << "show" << name << endl; };

	Component(string name)
	{
		this->name = name;
	}
private:
	string name;
};

//装饰基类
class DeInit :public Component
{
protected:
	Component *com;
public:
	void setDec(Component *com)
	{
		this->com = com;
	}
	void Operator()//重载Component
	{
		if (com) com->Operator();
	}
};

//具体装饰
class JuTiDec :public DeInit
{
public:
	void Operator()
	{
		cout << "a" << endl;
		Component * c = new Component;
		c->Operator();
	}
};

class JuTiDec1 :public DeInit
{
public:
	void Operator()
	{
		cout << "a1" << endl;
		Component * c = new Component;
		c->Operator();
	}
};

//class Component
//{
//public:
//	Component();
//	~Component();
//	virtual void Operator() {};
//};
////具体对象继承
//class Com1 :public Component
//{
//	virtual void Operator()
//	{
//		cout << "具体对象操作" <<endl;
//	}
//};
//
////装饰类  基类
//class Decorator :public Component
//{
//protected:
//	Component *com;
//public:
//	void SetCom(Component *com)
//	{
//		this->com = com;
//	}
//	void Operator()//重写Component的方法 实际执行Component
//	{
//		if (com) com->Operator();
//	}
//};
//
////装饰子类
//class DecoratorA : public Decorator
//{
//private:
//	string addState;//该类独有工
//public:
//	void Operator()
//	{
//		//先运行 Component的Operator 
//		Component *c = new Com1;
//		c->Operator();
//		cout << "aaa" << endl;
//		//cout << "具体";
//	}
//};
//
//class DecoratorB :public Decorator
//{
//public:
//	void Operator()
//	{
//		Component *c = new Com1;
//		c->Operator();
//		addB();
//		cout << "bbb" << endl;
//	}
//	void addB()//独有
//	{
//
//	}
//};




