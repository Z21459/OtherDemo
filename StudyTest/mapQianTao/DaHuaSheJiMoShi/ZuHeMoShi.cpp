#include <iostream>
#include <list>
using namespace std;

//组合模式  讲对象组合成树的形状

class Com
{
private:
	string name;
public:
	Com(string name)
	{
		this->name = name;
	}
	virtual void add(Com c);
	//...
	virtual void show(int depth);
};
class Left :public Com
{
public:
	Left(string name) :Com(name)
	{

	}
	void add(Com c)
	{

	}
};
class Comp :public Com
{
private:
	list<Com*> ch;
public:
	Comp(string name) :Com(name)
	{

	}
	void add(Com c)
	{
		Com* p = new Com("");
		ch.push_back(p);
		p->add(c);
	}
};
//client
void fun() {
	Comp *p = new Comp("1");
	Left *d = new Left("2");
	//p->add(d);
}