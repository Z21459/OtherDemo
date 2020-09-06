#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

//宏定义 最大最小值
#define Max2(x,y) (((x)>(y))?(x):(y))//获得低位((byte)((word)(xxx)&255))
#define Min2(x,y) (((x)>(y))?(x):(y))//获得高位((byte)((word)(xxx)>>8))

#define Arr_Size(a) (sizeof((a))/sizeof((a[0])))//数组含有元素个数

//const和define：前者有数据类型，后者无数据类型。const存在于程序的数据段，并在堆栈上分配空间

//const用法：1.定义常量；2.修饰函数形参 void f(A const &s);3.修饰函数返回值 const char* f(void){ };4.修饰类成员函数 int f(void) const;
//static用法：1.函数体，一个被声明为静态变量在函数调用过程中不变；2.模块内(函数外)：可以被模块内所有函数访问。3.模块内：声明为静态函数可被这一模块其他函数调用

//static和普通函数区别：static函数在内存中只拷贝一份，普通函数在每个被调函数中维持一份复制。

//sizeof和strlen的区别：sizeof是操作符-返回结果size_t;strlen是函数-只能用char*做参数，且必须以‘\0’结尾。

//#pragma pack(n)  设置计算对其方式

//内联函数-inline：用其代替c语言中表达式形式的宏定义来解决程序中函数调用效率问题。调用内联函数，代码直接替换，无调用开销。其是函数，运行时编译器对其进行检测
// 消除隐患和局限性。可以作为某个类的成员函数，可以使用类中的所有私有和公有成员。
//内联是以代码膨胀(复制)为代价，仅省去调用开销，从而提高函数执行效率。如果代码量比较大，可能造成需求空间增加。


//inline和define区别：1.内联在编译的时候展开，宏在预编译展开。2.编译时内联可以直接嵌在目标代码中，宏定义只是简单文本替换。3.宏不是函数，内联是。
//						4.宏定义时候小心出现二义性。5.内联函数是函数，编译器会检测其语句语法等，宏就不会有这样的功能。

int main2() {


	system("pause");
	return 0;
}