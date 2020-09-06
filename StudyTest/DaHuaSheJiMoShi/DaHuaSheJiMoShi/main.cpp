#include<iostream>
#include"OperatorFactory.h"
#include"OperatorItem.h"

/*
简单工厂模式 是写一个父类，定义虚函数，子类分别继承父类的方法
通过工厂类，传入参数不同，new出想对应的子类，来调用子类重载父类虚函数的方法。
*/
int main()
{
	//OperatorItem *oper = new OperatorItem;
	//OperatorFactory * factor = new OperatorFactory;
	OperatorItem *oper = OperatorFactory::createOperate(1);
	//oper->setA(1);
	//oper->setB(2);
	//oper->getA();
	//oper->getB();
	//cout << oper->getA();
	if (oper)
	{
		int result = oper->getResult(1, 2);
		cout << result;
	}
	system("pause");
	return 0;
}
