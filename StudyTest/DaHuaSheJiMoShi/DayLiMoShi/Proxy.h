#pragma once
#include <iostream>
#include <string>
using namespace std;

//这个类 一定要写在前面   不然报错

//后面所用到的类 前面一定进行了声明  否则会报错误
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
//代理者 代理礼物
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


