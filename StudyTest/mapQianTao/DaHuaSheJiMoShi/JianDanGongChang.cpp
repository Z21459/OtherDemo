#pragma once
#include <iostream>
using namespace std;

class SetGetValue//���ò���
{
public:
	SetGetValue() {}
	~SetGetValue() {}
	void setAB(double a, double b)
	{
		_numA = a;
		_numB = b;
	}

	double getA() {
		//_numA = value; set get��ʽ
		return _numA;
	}
	double getB() {
		return _numB;
	}

	virtual double getResult() {
		double result = 0;
		return result;
	}
private:
	double _numA = 0;
	double _numB = 0;
};

// �̳����ò�����ʽ
class CaluAdd : public SetGetValue//�̳� �����麯���ķ���
{
public:
	CaluAdd() {}
	~CaluAdd() {}
	double getResult()
	{
		double result = 0;
		result = getA() + getB();
		return result;
	}
};

//��������

class JianDanGongChang
{
public:
	JianDanGongChang() {}
	~JianDanGongChang() {}
	static SetGetValue creatCalu(int oper)//����ʵ�ַ���
	{
		SetGetValue op;
		switch (oper)
		{
		case 0:
			//op = new CaluAdd();//ִ�в���
			break;
		default:
			break;
		}
		return op;
	}
};

/*SetGetValue oper;
oper = JianDanGongChang::creatCalu(0);
oper.setAB(1, 2);//������ ��õ�  Ȼ����÷���
oper.numA();
oper.numB();
double result = oper.getResult;*/

