#include <iostream>
#include <cstdio>

using namespace std;

//i++和++i区别：前者先运算后++，后者先++后运算；内建数据类型没有什么变化，自定义数据类型++i更快
//有符号和无符号混合运算--自动转成无符号运算

//不适用任何变量交换a和b
void Sw(int &a, int &b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	
}
void Sw1(int &a, int &b) {
	a = a + b;
	b = a - b;
	a = a - b;
	
}

//c和c++区别：c是结构化语言，重点在于算法和结构。c是c++的子集。c++首先要考虑如何构建一个对象模型，使这个模型能够配合对应的问题。
//c实现了c++过程化控制及其它相关功能，c++扩展了面向对象设计的内容，在c++中的c相对于加强，引入了重载、内联、异常处理。
//c++不仅需要考虑数据封装、还要考虑对象接口的设计和继承、组合等使用问题。

//理解c++面向对象和c面向过程：c是面向过程化，c++是不完全面向对象化的，在c++中可以写出c一样的程序。

//   #ifndef  #define  #endif防止头文件重复   #ifdef _cplusplus表示当前使用的c++编译器   extern"C"是c++编译器提供与c连接交换指定的符号，用来解决明子匹配问题。

//include <file> 和include "file":前者表示一个工程或标准头文件，查找首先从预定义目录查找。后者表示用户提供的头文件，查找从当前目录开始查找，然后从标准位置寻找文件。

int main1() {
	int a = 1, b = 2;
	Sw(a, b);
	cout << a << b;

	system("pause");
	return 0;
}