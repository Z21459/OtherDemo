#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

//�����ǹ���������


//��������� �ķº���
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
//swap ����ͬ����Ԫ��
//swap_ranges ��������Ԫ�� ��һ���͵ڶ��������ƶ���һ�����������ķ�Χ ��x��ʾ
//�ڶ������� �Ե�����xΪ��ʼλ�õ�Ԫ�ر�����
/*
1. �滻replace
2. ��ֵ fill_n  generate_n
3. ��ת reverse_copy
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