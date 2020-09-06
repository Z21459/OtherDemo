#include <iostream>
#include <cstdio>
using namespace std;
//1
// &(两个1为1，其余为0) |(有1就为1) ^(相同为0，不同为1)
// &&(两个表达式都是true就是true)  ||(其中一个为true)  ！(反转 true变false)

//2
//::作用域操作符  在c++中通过::来直接操作全局变量

//3 4
//i++和++i效率  基本相同在内部数据类型，不是内部数据类型的时候++i更好

//5
//良好编程风格

//6
//有符号变量和无符号变量 --有符号和无符号变量时，所有变量都会转变成无符号。

//7 
//不使用中间变量进行a、b值交换   --异或 自加减  中间变量
void swap1(int &a, int &b) {
	a = a ^ b; 
	b = a ^ b;
	a = a ^ b;
}

void swap2(int &a, int &b) {
	a = a + b;
	b = a - b;
	a = a - b;
}
void swap3(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

//8 9  c++和c异同
//c是结构化语言，重点在于算法和数据结构，c是c++子集。
//c面向过程化，c++面向对象。c++可以写出c一样过程化的程序、

//10 11 头文件结构
//#ifndef #define #endif 防止头文件重复
//#include<head.h>文件是一个工程或标准头文件；#include "head.h"用户提供的头文件。

//12
//c++main函数执行完之后 自动调用atexit()函数来注册程序正常终止时要被调用



int main1() {
	//12 2  2 3 1 5 5   5 3  1 2
	//      1 2 1 6 1  1 2 2 1
	//100   010 110

	system("pause");
	return 0;
}