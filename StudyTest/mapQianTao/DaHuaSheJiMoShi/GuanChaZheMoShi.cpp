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
		cout << "�õ�֪ͨ";
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

//���ӳ����� ʹ����̳�
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

//�ͻ���
void func()
{
	Boss *hu = new Boss;
}
