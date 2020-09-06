#pragma once
#include <iostream>
#include <string>
using namespace std;

//����� һ��Ҫд��ǰ��   ��Ȼ����

//�������õ����� ǰ��һ������������  ����ᱨ����
class Gril
{
public:
	Gril() {}
	~Gril() {}
public:
	string name;
};


class GiveGift
{
public:
	GiveGift(){}
	~GiveGift()
	{

	}
	virtual void giveA() =0 ;
	virtual void giveB() = 0;
};

class Prusui:public GiveGift
{
public:
	Prusui(){}
	~Prusui(){}
	Prusui(Gril *m) {
		this->mm = m;
	}
	void giveA()
	{
		cout << mm->name << "AA" << endl;
	}
	void giveB()
	{
		cout <<mm->name << "BB" << endl;
	}
private:
	Gril* mm;
};
//������ ��������
class Proxy:public GiveGift
{
public:
	Proxy(){}
	~Proxy(){}
	Prusui *pr;
	Proxy(Gril *gril)
	{
		pr = new Prusui(gril);
	}
	void giveA()
	{
		cout << "A" << endl;
	}
	void giveB()
	{
		cout << "B" << endl;
	}
};


