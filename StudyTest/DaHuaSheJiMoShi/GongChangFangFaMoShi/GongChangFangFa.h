#pragma once
#include <iostream>
using namespace std;

class GongChangFangFa
{
public:
	GongChangFangFa();
	~GongChangFangFa();
};
//���������ӿ�
class IFactor
{
public:
	virtual void CreateOperation() {};
};

//���ֲ������� �̳�ʵ��  ����

class AddFactor :public IFactor
{
public:
	void CreateOpertation()
	{
		return;//new OperatorAdd;
	}
};



//�򵥹���
class LeiFeng
{
public:
	LeiFeng(){}
	~LeiFeng(){}
	virtual void do1(){}
	virtual void do2(){}
};

//�̳�
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
//�ͻ���
//void client()
//{
//	simpleFactor *sm = new simpleFactor;
//	LeiFeng *sta = sm->CreateLeiFeng(1);
//	sta->do1();
//}


//��������
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
		return (new Student);//��������ģʽ����
	}
};
//��������־Ը��

///����-���ԭ��   ���ڿ���  ������

//client
//void fun1()
//{
//	IFactory1 *fac = new Stu;
//	LeiFeng *s = fac->createLef();
//	s->do1();
//	s->do2();
//}


