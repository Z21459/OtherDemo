#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>
using namespace std;

/*
将实例化具体类的代码从应用中抽离，或者封装，使他们不会干扰应用的其他部分
*/
enum TypeSet
{
	ENUMA = 0,
	ENUMB = 1
};

class Base
{
private:
	string _name;
	string _dough;
	string _such;
	list<int>a_list;//其他

public:
	Base(){}
	~Base(){}
public://操作  可以实现 也可以有子类覆盖
	virtual void prepare(){} //基础实现设置
	virtual void back(){}
	virtual void cut() {}
	virtual void box() {}
	string getName() {
		return _name;
	}
};

//具体类继承
//相当于不同味道的产品
class ABase :public Base
{
public:
	ABase(){}
	~ABase(){}
public:
	void prepare() { cout << "a"; }
	void back(){}
	void cut(){}
	void box(){}
};

class BBase :public Base
{
public:
	BBase(){}
	~BBase(){}
public:
	void prepare() { cout << "b"; }
	void back(){}
	void cut(){}
	void box(){}
};

class BaseFactory
{
public:
	BaseFactory() {};
	~BaseFactory() {};
public:
	Base *createTypeBase(int type)
	{
		Base *base = nullptr;
		switch (type)
		{
		case 0:
			base = new ABase();
			break;
		case 1:
			base = new BBase();
			break;
		default:
			break;
		}
		return base;
	}
};

//client  简单工厂客户
class BaseStore
{
private:
	BaseFactory *basefactoy;
public:
	BaseStore(BaseFactory *basefactoy)
	{
		this->basefactoy = basefactoy;
	 }
	Base *orderBase(int type)
	{
		Base *base = nullptr;
		base = basefactoy->createTypeBase(type);
		base->prepare();
		base->cut();
		base->box();
		base->back();
		return base;
	}
	//其他方法
};
void clientOperator()
{
	BaseFactory *basefactoy = new BaseFactory();
	BaseStore *basestore = new BaseStore(basefactoy);
	Base *base = basestore->orderBase(ENUMA);
	if (base)
	{
		base->prepare();
		base->cut();
		base->box();
		base->back();
	}
	return;
}

//工厂方法  和Base 都是抽象的 平级关系
class BaseStore1
{
public:
	Base *orderBase(int type)
	{
		Base *base = nullptr;
		base = creatBase(type);
		if (base)
		{
			base->prepare();
			base->cut();
			base->box();
			base->back();
		}
		return base;
	}
	virtual Base *creatBase(int type) { return nullptr; }//抽象工厂
};
//每一个工厂 都去继承这个抽象的baseBase1
class NewBaseStore1 :public BaseStore1//抽象工厂方法
{
	Base *createBase(int type)
	{
		if (type == ENUMA)
			return new ABase();
		else if (type == ENUMB)
			return new BBase();
		else
			return nullptr;
	}
};
//工厂方法用来处理对象创建
//client处理工厂方法  
//BaseStore1 ->orderBase->creatBase(由具体的store决定创建那个具体的方法)
void factoryWay()
{
	BaseStore1 *b1 = new NewBaseStore1();
	Base *base = b1->orderBase(ENUMA);
	cout << base->getName();
}


