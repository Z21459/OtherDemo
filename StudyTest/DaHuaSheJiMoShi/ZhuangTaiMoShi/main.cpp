#include<iostream>
#include"ZhuangTai.h"
using namespace std;


/*
面向对象设计 其实就是希望做到代码责任分解--单一职责原则

开放-封闭原则：对内开放，对外封闭

当一个对象的内在改变时允许改变其行为，这个对象看起来像改变了其类。

状态模式主要解决：当控制一个对象状态转换的条件表达式过于复杂时的情况。把状态的判断逻辑转移到表示不同状态的一系列类当中，可以把复杂的逻辑简化

消除庞大的条件分支



当一个对象的行为取决于他的状态，并且它必须在运行时刻根据状态改变它的行为时，可以考虑状态模式
*/

int main()
{
	//设置初始状态  然后不断请求
	//Context *context = new Context(new ConcreteStateA());
	//context->Request();

	system("pause");
	return 0;
}