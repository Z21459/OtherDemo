#include <iostream>
using namespace std;

class Lei
{
public:
	void Sweep()
	{
		cout << "����";
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
//�򵥹���
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
//��������
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
	Ifacto *fac = new daxuesf();// ���־Ը�� ֻ�޸�����
	Lei feng = fac->createfeng();
	feng.Sweep();
}

