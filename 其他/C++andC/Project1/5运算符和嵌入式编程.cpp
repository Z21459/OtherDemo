#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define YearMes (365*24*60*60)UL //无符号长整形
#define Max(x,y) (((x)>(y))?(x):(y))

//& 和| 位操作符   ^(异或)  << >> (左移和右移)

//  一个字节(byte) 有8位 1k= 1024bit

//当运算中存在有符号和无符号类型时，所有操作自动转转成无符号类型

//static: 函数体内（在这个函数调用过程中维持值不变）；在模块内-函数体外(在模块内被声明为静态变量，只能被模块内函数调用，不能被模块外其他函数调用)；
		//模块内（一个函数被声明为静态函数，只能被这一模块中的其他函数调用，这个函数被限制在声明的模块内）

//使用^实现交换
void Swap1(int &a,int &b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
int  main5() {
	int i = 5.01;
	float j = 5;
	//printf("%f\n", j);//64 中占有8位
	int a = 2;
	int b = 3;
	Swap1(a, b);
	cout << a << b;


	system("pause");
	return 0;
}