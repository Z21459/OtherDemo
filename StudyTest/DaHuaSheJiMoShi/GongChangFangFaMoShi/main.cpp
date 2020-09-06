#include<iostream>
#include "GongChangFangFa.h"
using namespace std;

/*
简单工厂：工厂类中包含了必要的逻辑判断 根据客户端的选择条件动态实例化相关类
工厂方法：定义一个用于创建对象 接口，让子类决定实例化哪个类。使一个类的实例化延迟到子类


*/
int main()
{
	IFactory1 *fac = new Stu;
	LeiFeng *s = fac->createLef();
	s->do1();
	s->do2();


	system("pause");
	return  0;
}