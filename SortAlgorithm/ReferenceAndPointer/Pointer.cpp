//指针和引用
//& 和 *
//引用是别名 指针是地址，引用的本质也是指针，但两者又不相同;初始化要求不同 可修改性不同，不存在NULL引用，测试需要区别
//1）注释：组合键“Ctrl + K + C”； ...
///2）取消注释：组合键“Ctrl + K + U” ...
#include <iostream>
#include <cstring>
using namespace std;


int main2() {

	//int a = 10;
	//int z = 20;
	//int &b = a;
	//int c;
	//b = z;
	//c = (&a == &b) ? 1 : 0;

	//int a = 1;
	//int b = 10;
	//int *p = &a;
	//int *&pa = p;
	//(*pa)++;
	//cout << a << b << *p << endl;
	//pa = &b;
	//(*pa)++;
	//cout << a << b << *p;

	//char w[] = "abcdefgh";
	//char *u = w;
	//cout << *(u + 4) << u[4] << w[4] << *(w + 4) << *(u+4)+1;

	int a = 4, b = 3;
	int m = a % b;
	int n = a / b;
	int x = (2 * m >= n) ? (n + 1) : n;
	cout << x;

	system("pause");
	return 0;
}

//交换字符串  输入char * p = "aaaa"
void swap(char*&x, char*&y) {
	char *temp;
	temp = x;
	x = y;
	y = temp;
}

