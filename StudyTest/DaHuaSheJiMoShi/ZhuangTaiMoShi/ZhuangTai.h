#pragma once
#include <iostream>
using namespace std;

class ZhuangTai
{
public:
	ZhuangTai();
	~ZhuangTai();
};

//抽象状态类

//维护一个具体状态 ConcreteState子类的实例，这个实例定义当前状态
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
//	State *state()//可读写当前状态
//	{
//		return nullptr;
//	}
//	//对请求处理 设置下一个状态
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
//具体状态  每一个子类实现一个Context的一个状态相关的行为
class ConcreteStateA :public State
{
public:
	void Handle(Context *context)
	{
		//设置A的下一个状态
		//context->state = new ConcreteStateB();	
	}
};

class ConcreteStateB :public State
{
public:
	void Handle(Context *context)
	{
		//设置B的下一个状态
	}
};