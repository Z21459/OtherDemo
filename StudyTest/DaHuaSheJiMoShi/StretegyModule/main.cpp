#include <iostream>
#include "ShopDaZhe.h"
using namespace std;

/*
策略模式 定义了算法家族，分别封装，他们之间可以互相替换
此模式让算法的变化，不会影响到使用算法的客户

封装变化点--面向对象重要思维

将策略模式和工厂模式结合使用



**********不同时间用不同业务的时候  就可以考虑策略模式
*/

int main()
{
	//典型发 子类当父类使用
	Context *context = nullptr;
	
	//策略
	//int way;
	//switch (way)//这个尽量在服务端判断   
	//{
	//case MANJIAN:
	//	context = new Context(new StrategyA);//根据传入的参数 不同 调用对应的继承子类
	//	if(context) context->ContextInfeace();
	//	break;
	//case YOUHUISONG:
	//	context = new Context(new StretegyB);
	//	if (context) context->ContextInfeace();
	//	break;
	//default:
	//	break;
	//}

	cout << endl;
	//工厂和策略结合  策略模式封装了变化
	int w = 0;
	cin >> w;
	context = new Context(w);//通过不同的w 执行不同
	if (context) context->ContextInfeace();



	system("pause");
	return 0;
}