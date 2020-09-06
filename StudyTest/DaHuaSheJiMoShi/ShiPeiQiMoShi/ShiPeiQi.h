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
//�ͻ��ڴ��Ľӿ�
class Target
{
public:
	virtual void Request() { cout << "re"; }
};

//����
class Adaptee
{
public:
	void SpecificRequest() { cout << "sp"; }
};


//��װһ��Adaptee����  ��ԭ�ӿ�ת��Ŀ��ӿ�
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

//����̳�
class Forwards :public Player
{
public:
	Forwards(string name) :Player(name)
	{

	}
	void Attach() { cout << name << "F\n"; }
	void Defend() { cout << name << "D\n"; }
};
//����������ͬ



//������ 
class ForeginCenter
{
private:
	string name;
public:
	string setName(string name) { return name; }
	void Att() { cout << name << "att\n"; }
	void Def() { cout << name << "def\n"; }
};

//������
class Translator :public Player
{
private:
	ForeginCenter* foregin = new ForeginCenter;

public:
	Translator(string name) :Player(name)
	{
		foregin->setName(name);
	}
	//���ط���
	void Attach()
	{
		foregin->Att();
	}
	void Defend()
	{
		foregin->Def();
	}
};





















