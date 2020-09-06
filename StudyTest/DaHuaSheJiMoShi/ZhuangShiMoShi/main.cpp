#include <iostream>
#include"Component.h"
using namespace std;


/*
装饰者模式
动态的给一个对象添加一些额外的职责
就功能来说，比生成子类更为灵活

*/
int main()
{
	//装饰方法 
	/*
	1.用 Com1实例化c
	2.用实例化对象a1包装c
	3.用实例化对象b1包装a1
	最后执行b1的operator；
	*/
	//Com1 *c = new Com1;
	//DecoratorA *a1 = new DecoratorA;
	//DecoratorB *b1 = new DecoratorB;

	//a1->SetCom(c);
	//b1->SetCom(a1);
	//b1->Operator();


	Component *c = new Component("111");
	JuTiDec *j1 = new JuTiDec;
	JuTiDec1 * j2 = new JuTiDec1;
	j1->setDec(c);
	j2->setDec(j1);
	j2->Operator();

	system("pause");
	return 0;
}