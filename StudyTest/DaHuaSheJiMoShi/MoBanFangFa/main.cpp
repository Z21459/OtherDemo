#include <iostream>
#include"MoBan.h"
using namespace std;

/*
模板方法：
定义一个操作中的算法骨架，而将步骤延迟到子类中去，模板可以使子类不改变
一个算法的结构即可以重定义该算法的某些特定步骤


模板方法，把不变的搬移到父类中去，去除子类中的重复代码  体现优势
*/

int main()
{
	//客户端
	MoBan *m = new MoBan;
	m = new Con1();
	m->ab1();
	m->ab2();
	m = new Con2();
	m->ab1();
	m->ab2();

	system("pause");
	return 0;
}