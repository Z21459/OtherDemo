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

//װ�λ���
class DeInit :public Component
{
protected:
	Component *com;
public:
	void setDec(Component *com)
	{
		this->com = com;
	}
	void Operator()//����Component
	{
		if (com) com->Operator();
	}
};

//����װ��
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
////�������̳�
//class Com1 :public Component
//{
//	virtual void Operator()
//	{
//		cout << "����������" <<endl;
//	}
//};
//
////װ����  ����
//class Decorator :public Component
//{
//protected:
//	Component *com;
//public:
//	void SetCom(Component *com)
//	{
//		this->com = com;
//	}
//	void Operator()//��дComponent�ķ��� ʵ��ִ��Component
//	{
//		if (com) com->Operator();
//	}
//};
//
////װ������
//class DecoratorA : public Decorator
//{
//private:
//	string addState;//������й�
//public:
//	void Operator()
//	{
//		//������ Component��Operator 
//		Component *c = new Com1;
//		c->Operator();
//		cout << "aaa" << endl;
//		//cout << "����";
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
//	void addB()//����
//	{
//
//	}
//};




