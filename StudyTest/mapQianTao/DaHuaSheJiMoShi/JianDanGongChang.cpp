#pragma once
#include <iostream>
using namespace std;

class SetGetValue//设置参数
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
		//_numA = value; set get方式
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

// 继承设置操作方式
class CaluAdd : public SetGetValue//继承 调用虚函数的方法
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

//创建操作

class JianDanGongChang
{
public:
	JianDanGongChang() {}
	~JianDanGongChang() {}
	static SetGetValue creatCalu(int oper)//返回实现方法
	{
		SetGetValue op;
		switch (oper)
		{
		case 0:
			//op = new CaluAdd();//执行操作
			break;
		default:
			break;
		}
		return op;
	}
};

/*SetGetValue oper;
oper = JianDanGongChang::creatCalu(0);
oper.setAB(1, 2);//先设置 后得到  然后调用方法
oper.numA();
oper.numB();
double result = oper.getResult;*/

