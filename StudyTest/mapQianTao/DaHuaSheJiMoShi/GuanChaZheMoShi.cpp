#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Ob
{
private:
	string name;
	Sec *sub;
public:
	Ob(string name, Sec *sub)
	{
		this->name = name;
		this->sub = sub;
	}
	void Update()
	{
		cout << "得到通知";
	}
};
class Sec
{
private:
	list<Ob*> ob;
public:
	void Att(Ob o) 
	{
		ob.push_back(&o); 
	}
	string SecA()
	{

	}
};

//增加抽象类 使子类继承
class Subject
{
	virtual void Attach(Ob ob);
	virtual void Detch(Ob ob);
	virtual void Notify();
};
class Boss :public Subject
{
public:
	void Attach(){}
	//..
};

class Ob
{
private:
	string name;
	Subject su;
public:
	Ob(string name, Subject su)
	{
		this->name = name;
		this->su = su;
	}
	virtual void Update();
};

class Stock :public Ob
{
public:
	Stock(string name, Subject su):Ob(name,su)
	{

	}
	void Update(){}
};

//客户端
void func()
{
	Boss *hu = new Boss;
}
