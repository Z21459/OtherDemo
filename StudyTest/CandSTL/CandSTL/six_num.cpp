#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <complex>//复数计算
#include <valarray>//数组运算
#include <numeric>//通用数值计算
#include <cmath>//全局性数值函数
using namespace std;


/*
STL 数值计算
幂函数 pow(x,y) x为底 y为指数
exp(2) 以e为底的幂函数
sqrt() 平方根
log() 对数


6.2数组 向量运算
valarray  实现数值数组的计算
其有 size() max() sum() min() resize() resize()等
shfit--逻辑移位和cshift实现循环移位

slice  切割--起始 个数 间距 生成一个新的数组

slice_array 将同一个值赋予每一个元素 赋值另一个valarray 调用任何一个赋值复合运算


numeric包括四个算法 accumulate求和 inner_product 内积 
					partial_sum部分元素之和 adjacement_difference 元素的相邻差

cmath： pow() exp() sqrt()  log() log() 等 

*/


void printV(valarray<int> &v)
{
	int size = v.size();
	for (int i = 0; i < size; i++)
	{
		std::cout << v[i] << ",";
	}
	cout << endl;
}

int main6()
{

	valarray<int> v1(12), v2;

	for (int i = 0; i < 12; i++)
	{
		v1[i] = i;
	}
	printV(v1);
	cout << endl;
	slice myslice(0, 4, 3);//起始位置 元素个数  间隔
	v2 = v1[myslice];
	cout << "分割" << endl;
	printV(v2);




	system("pause");
	return 0;
}