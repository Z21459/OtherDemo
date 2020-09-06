#include <iostream>
#include "ShiPeiQi.h"
using namespace std;

/*
适配器模式：将一个类的接口转换成客户希望的另外一个接口
Adapter模式使得原来由于接口不兼容而不能一起工作的那些类可以一起工作

分两种：类适配器   对象适配器 模式

//使用一个已经存在的类，但如果他们的接口(方法)和你要求不相同，就应该考虑适配器模式
两个类所做的事情相同或者相似，但是具有不同的接口时使用


*/



int main()
{

	Target *target = new Adapter;//子类当父类使用  通过多态实现
	target->Request();
	cout << endl;

	Player *p = new Forwards("wang");
	p->Attach();
	p->Defend();

	Player *ym = new Translator("yao");
	ym->Attach();
	ym->Defend();

	system("pause");
	return 0;
}