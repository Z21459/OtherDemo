#include<iostream>
#include"JianZaoZhe.h"

using namespace std;

/*
将一个对象的构建和它的表示分离  使得同样的构建过程可以创建不同的表示

如果使用了建造者模式 用户只需要指定需要建造的类型就可以得到，而具体建造过程和细节就不需要

建造者模式   
基类：各个虚函数
子类：继承基类  具体实现
指挥者类：通过具体的子类进行实现  子类当父类使用 传递  构建一个使用JianZao接口的对象


建造者模式  当复杂对象的算法应该独立于该对象的组成部分以及他们的装配方式时适用
*/

int main()
{
	Penh *pen = new Penh();
	Graph *graph = new Graph();
	ThinPerson *jianzaoThin = new ThinPerson(graph, pen);
	PersonDirect *pdThin = new PersonDirect(jianzaoThin);//子类当父类使用
	pdThin->creatPerson();
	// 胖人同理

	system("pause");
	return 0;
}