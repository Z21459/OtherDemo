#pragma once
#include <iostream>
using namespace std;

class ZhuangTai
{
public:
	ZhuangTai();
	~ZhuangTai();
};

//����״̬��

//ά��һ������״̬ ConcreteState�����ʵ�������ʵ�����嵱ǰ״̬
class Context
{
//private:
//	State *state;
//public:
//	Context(State *state)
//	{
//		this->state = state;
//	}
//
//	State *state()//�ɶ�д��ǰ״̬
//	{
//		return nullptr;
//	}
//	//�������� ������һ��״̬
//	void Request()
//	{
//		state->Handle(this);
//	}
};

class State
{
public:
	virtual void Handle(Context *context) {};
};
//����״̬  ÿһ������ʵ��һ��Context��һ��״̬��ص���Ϊ
class ConcreteStateA :public State
{
public:
	void Handle(Context *context)
	{
		//����A����һ��״̬
		//context->state = new ConcreteStateB();	
	}
};

class ConcreteStateB :public State
{
public:
	void Handle(Context *context)
	{
		//����B����һ��״̬
	}
};