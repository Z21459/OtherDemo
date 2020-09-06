#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

//不能是关联性容器


//生成随机数 的仿函数
class myRand
{
	ptrdiff_t operator()(ptrdiff_t max)
	{
		double tmp;
		tmp = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
		return static_cast<ptrdiff_t>(tmp*max);
	}
};

void print_d3(int &ele)
{
	cout << ele << " ";
}
//swap 交换同类型元素
//swap_ranges 交换部分元素 第一个和第二个参数制动第一个交换容器的范围 用x表示
//第二个容易 以迭代器x为起始位置的元素被交换
/*
1. 替换replace
2. 赋值 fill_n  generate_n
3. 逆转 reverse_copy
*/
int main3()
{
	int dim[] = { 1,3,4,5,6,7,8,9,2,3 };
	int dim1[] = { 11,12,13,14,15 };
	vector<int>vec;
	vector<int>vec1;
	vec1.assign(dim1, dim1 + 4);
	vec.assign(dim, dim + 9);
	for_each(vec.begin(), vec.end(), print_d3);
	cout << endl;

	swap_ranges(vec.begin(), vec.begin() + 3, vec1.begin());
	for_each(vec.begin(), vec.end(), print_d3);

	system("pause");
	return 0;
}