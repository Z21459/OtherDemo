#include<iostream>
#include"GuanCaZhe.h"
#include <algorithm>//使用模板里面的算法库函数
using namespace std;

/*
观察者模式：发布订阅模式
定义了一种一对多的依赖关系，让多个观察者对象同时监听某一个主题对象，
这个主题对象在发生变化时，会通知所有观察者对象

abstract sbject  --具体被观察者 NBA  股票等
abstract observe --具体观察者  boss security


//当一个对象的改变需要同时改变其他对象  而且不知道具体有多少对象待改变

//观察者模式 主要是解除耦合 让耦合的双方类依赖于抽象，不依赖于具体，使各自的拜年话都不会影响另一边的变化


委托：事件处理程序 ---一种引用方法的类型
如果委托分配了方法，该委托与该方法具有完全相同的行为

一个委托可以搭载多个方法，这些方法依次被唤醒，这些方法可以不属于同一个类

delegate void EventHandler();

*/


int main()
{
	Boss *boss = new Boss();
	//具体类
	GuanCaA *guancaA = new GuanCaA("name", boss);
	boss->Attach(guancaA);

	//通知后减去

	//boss->BossAction = "come";
	boss->Notify();//通知

	system("pause");
	return 0;
}