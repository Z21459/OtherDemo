#include <iostream>
#include "DanLi.h"
using namespace std;

/*
单例模式--线程安全

复制黏贴是最容易  但最没有价值的东西

所有类都有构造方法，不编码则系统默认生成空的构造方法，
若有显示定义的构造方法，默认构造方法就会失效

因此将类的构造函数方法写成private，外部方法就不能new

保证类只有一个实例，并提供一个访问它的全局访问点



*/

Signle* Signle::signle = nullptr;//静态变量初始化
int main()
{

	Signle::getInstance();
	Signle::getInstance();//只会初始化一次
	//if (sign == sign1)
	//{
	//	cout << "ok";
	//}
	system("pause");
	return 0;
}