#pragma once
#include <iostream>
using namespace std;

enum ShopBuy
{
	DAZHE = 1,
	MANJIAN = 2,
	YOUHUISONG =3,
};
//基类 抽象算法
class ShopDaZhe
{
public:
	ShopDaZhe();
	~ShopDaZhe();
	virtual void JuTiWays() {};
};

//具体策略  具体算法
class StrategyA :public ShopDaZhe
{
public:
	void JuTiWays() {
		cout << "a";
	}
};

class StretegyB :public ShopDaZhe
{
public:
	void JuTiWays()
	{
		cout << "b";
	}
};

//上下文条件 管理类
class Context
{
public:
	ShopDaZhe *shop;

	//策略模式
	//Context(ShopDaZhe *shop)//初始化传入具体策略
	//{
	//	this->shop = shop;
	//}
	void ContextInfeace()//通过这个 调用方法  执行结果
	{
		shop->JuTiWays();//根据策略  调用方法
	}

	//策略和工厂结合
	Context(int id)
	{
		switch (id) 
		{
		case DAZHE:
		{   //case 里面定义 变量 一定要用{} 括起来  否者会报错 case标签问题
			StrategyA *A = new StrategyA;
			shop = A;
			break;
		}
		case MANJIAN:
			StretegyB *B = new StretegyB;
			shop = B;
			break;
		}
	}
};

