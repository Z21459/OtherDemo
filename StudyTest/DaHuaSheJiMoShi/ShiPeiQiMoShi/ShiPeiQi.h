#pragma once
#include<iostream>
#include <string>
using namespace std;

class ShiPeiQi
{
public:
	ShiPeiQi();
	~ShiPeiQi();
};
//客户期待的接口
class Target
{
public:
	virtual void Request() { cout << "re"; }
};

//适配
class Adaptee
{
public:
	void SpecificRequest() { cout << "sp"; }
};


//包装一个Adaptee对象  把原接口转成目标接口
class Adapter :public Target
{
private:
	Adaptee *ee = new Adaptee;
public:
	void Request()
	{
		ee->SpecificRequest();
	}
};



//example
class Player
{
protected:
	string name;
public:
	Player(string name) {
		this->name = name;
	}
	virtual void Attach(){}
	virtual void Defend(){}
};

//子类继承
class Forwards :public Player
{
public:
	Forwards(string name) :Player(name)
	{

	}
	void Attach() { cout << name << "F\n"; }
	void Defend() { cout << name << "D\n"; }
};
//其他子类相同



//适配器 
class ForeginCenter
{
private:
	string name;
public:
	string setName(string name) { return name; }
	void Att() { cout << name << "att\n"; }
	void Def() { cout << name << "def\n"; }
};

//翻译者
class Translator :public Player
{
private:
	ForeginCenter* foregin = new ForeginCenter;

public:
	Translator(string name) :Player(name)
	{
		foregin->setName(name);
	}
	//重载方法
	void Attach()
	{
		foregin->Att();
	}
	void Defend()
	{
		foregin->Def();
	}
};





















