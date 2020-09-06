#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

//1 32位平台 int  float 占4个字节，double占8个字节
//2  <<n相当于乘以2n和>>n相当于除以2n运算符
//3 设置或清除特定位 位操作符& |
//4 一个字节(byte)有8位
//7 c++4种运算符转换异同
//const_cast:调用应该使用却没有使用const关键字的函数
//dynamic_const:如果启动了支持运行时间类型消息RTTI ，其有助于判断运行时所指向对象的确切类型
//reinterpret_cast:一个指针转换成其他类型的指针，新类型和旧类型可以毫无关系
//static_cast:可以在相关的对象和指针类型之间进行类型转换。

//13 static作用
//函数体内：变量在这一个函数调用的过程中维持其值不变
//模块内函数体外：静态变量可以被模块内所有函数访问，相当于一个本地的全局变量
//模块内：静态函数，只能被本模块内的函数调用



#define YearSecond (365*24*60*60)UL//每年多少秒 UL表示无符号整型



int main5(int argc,char* argv[]) {

	system("pause");
	return 0; 
}