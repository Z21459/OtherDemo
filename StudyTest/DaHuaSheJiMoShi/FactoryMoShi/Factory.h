#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>
using namespace std;

/*
��ʵ����������Ĵ����Ӧ���г��룬���߷�װ��ʹ���ǲ������Ӧ�õ���������
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
	list<int>a_list;//����

public:
	Base(){}
	~Base(){}
public://����  ����ʵ�� Ҳ���������า��
	virtual void prepare(){} //����ʵ������
	virtual void back(){}
	virtual void cut() {}
	virtual void box() {}
	string getName() {
		return _name;
	}
};

//������̳�
//�൱�ڲ�ͬζ���Ĳ�Ʒ
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

//client  �򵥹����ͻ�
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
	//��������
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

//��������  ��Base ���ǳ���� ƽ����ϵ
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
	virtual Base *creatBase(int type) { return nullptr; }//���󹤳�
};
//ÿһ������ ��ȥ�̳���������baseBase1
class NewBaseStore1 :public BaseStore1//���󹤳�����
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
//������������������󴴽�
//client����������  
//BaseStore1 ->orderBase->creatBase(�ɾ����store���������Ǹ�����ķ���)
void factoryWay()
{
	BaseStore1 *b1 = new NewBaseStore1();
	Base *base = b1->orderBase(ENUMA);
	cout << base->getName();
}


