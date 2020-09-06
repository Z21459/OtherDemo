#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
using namespace std;

//c语言是面向过程的，而c++作为c语言的超集支持，它是面向对象的编程
//面向对象的概念：按照人们客观世界的系统思维，采用基于对象(实体)的概念建立模型
//模拟客观世界分析，设计，实现软件的办法。包括类，对象，消息以及类的特定等

//4 class和struct区别，主要分成c和c++
//c:c中没有class，struct只能定义成员变量，不能定义成员函数
//c++：class定义默认为私有类型，其可以当作模板类型，struct默认为公有类型，不能当作模板类型

//5 当构造函数不带参数时候，调用不带参数的构造函数不需要加小括号。。。类中先定义先初始化

//9 相较于全局对象，静态数据成员不存在程序中其他全局名字冲突，可以隐藏信息，其可以为private
//10 初始化列表--类中含有const reference成员变量和基类的构造函数时；赋值--

//13 执行main函数之前 还执行全局对象的构造函数

//14 15 c++空类默认执行--默认构造和复制构造，析构，赋值，取值。  构造函数可以重载，析构不可以

//20 虚析构函数的作用：当一个类被用来作为基类的时候，把析构函数写成虚函数，保证资源正常释放，避免内存泄漏
//21 析构函数执行顺序和构造函数执行顺序反过来
//复制构造--由编译器调用来完成一些基于同一类的其他对象的构件及初始化
//浅复制--让新旧两个对象指向同一个外部的内容；深复制--新对象制作了外部对象的独立复制。

//26 重写String类
class String1 {
public:
	String1(const char* str = NULL);//普通构造
	String1(const String1 &other);//复制构造
	~String1(void);
	String1&operator=(const String1 &other);//赋值函数
private:
	char *m_string;//私有成员
};
String1::~String1(void) {
	if (m_string != NULL) {
		delete[]m_string;
		m_string = NULL;//不为空释放
	}
}
String1::String1(const char *str) {
	if (str == NULL) {
		m_string = new char[1];
		*m_string = '\0';//分配一个字节
	}
	else {
		m_string = new char[strlen(str) + 1];//分配空间
		//strcpy(m_string, str);
	}
}
String1::String1(const String1&other) {
	m_string = new char[strlen(other.m_string) + 1];
	//strcpy(m_string, other.m_string);
}
String1& String1::operator=(const String1 &other) {
	if (this == &other) {
		return *this;
	}
	delete[]m_string;
	m_string = new char[strlen(other.m_string) + 1];
	//strcpy(m_string,other.m_string);
	return *this;
}

//32 函数重载 --描述同名函数具有相同或者相似的功能，但数据类型或者参数不同的函数管理操作
//函数名经过c++编译器处理后包含了原函数名、函数参数数量及返回类型信息，而c语言不对函数名进行处理

//34 重载和覆写
//重载--指子类改写父类；覆写--是指同一个函数的不同版本之间参数不同
//重载：编译一个与已有函数同名参数不同的方法(方法名相同，参数列表必不相同，返回类型可以不同)
//覆写：派生类重写基类虚函数(只有虚函数和抽象方法能够覆写、函数名，参数列表，返回值必需相同)
//重载一种语法规则，由编译器在编译阶段完成，不属于面向对象的编程；覆写由运行阶段决定，是面向对象编程的重要特征。




int main6(int argc, char *argv[]) {
	


	system("pause");
	return 0;
}
