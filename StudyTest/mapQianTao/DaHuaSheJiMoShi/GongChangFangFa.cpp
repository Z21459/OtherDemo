#include <iostream>
using namespace std;

class Lei
{
public:
	void Sweep()
	{
		cout << "大少";
	}
	void Buy()
	{
		cout << "mai ";
	}
};
class daxuesheng :public Lei
{

};
class zhiyuanzhe :public Lei
{

};
//简单工场
class SimpleFactor
{
public:
	static Lei create(int type)
	{
		Lei *re = NULL;
		switch (type)
		{
		case 0:
			re = new daxuesheng();
			break;
		case 1:
			re = new zhiyuanzhe();
			break;
		}
		return *re;
	}
};
//工厂方法
class Ifacto
{
 public:
	virtual Lei createfeng();
};
class daxuesf :public Ifacto
{
public:
	Lei createfeng()
	{
		Lei * da = new daxuesheng();
		return *da;
	}
};
//client
void func()
{
	Ifacto *fac = new daxuesf();// 如果志愿者 只修改这里
	Lei feng = fac->createfeng();
	feng.Sweep();
}

