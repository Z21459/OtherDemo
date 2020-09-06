#include <iostream>
#include <cstdio>

#define Max(a,b) (((a)>(b))?(a):(b))

using namespace std;
template<class T>
//c++是c的超集，面向对象。泛型编程-基于模板，有效将算法和数据结构分离，降低了模块间的耦合度  

//函数模板 和类模板：前者是一种抽象的函数定义，代表一类同构函数，后者是一种更高层次的抽象类定义。前者的实例化是由编译程序在处理函数调用时自动完成，后者实例化必须由程序员在代码中显示指出

//模板优缺点：节省时间，避免重用。不当使用会使代码膨胀，影响程序运行效率。 将与参数无关的代码分离
 
//模板特化：当模板对某些类型进行特别处理时，称为特化。

//函数模板泛化
const T*find1(const T*arr, int n, T x) {
	const T* p = arr;
	for (int i = 0; i < n; i++) {
		if (*p == x) {
			return p;
		}
		++p;
	}
	return 0;
}


//例如  增大了代码的重用性
template<class T>
T max(T a, T b) {//输入不同类型  选择不同的输出
	return a > b ? a : b;//输出最大值
}



int main10() {

	cout << max(1, 2) << endl;
	cout << max(1.2, 1.4) << endl;

	system("pause");
	return 0;
}