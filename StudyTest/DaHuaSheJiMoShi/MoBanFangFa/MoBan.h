#pragma once
#include <iostream>
using namespace std;
class MoBan
{
public:
	MoBan();
	~MoBan();

	//һЩ������Ϊ �ŵ�������ʵ��
	virtual void ab1() {};
	virtual void ab2() {};

	//ģ�巽�� �����߼���ܣ����߼������һЩ��Ӧ�Ĳ���

	void TempMethod()
	{
		ab1();
		ab2();
	}
};

//���� ʵ�ָ����������һ�����߶������

class Con1 :public MoBan
{
public:
	//�̳и��� ʵ�ָ���ķ���
	void ab1()
	{
		cout << "c1";
	}
	void ab2()
	{
		cout << "c2";
	}
};
//���Con�ֱ�ʵ�ֹ���
class Con2 :public MoBan
{
public:
	//�̳и��� ʵ�ָ���ķ���
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







