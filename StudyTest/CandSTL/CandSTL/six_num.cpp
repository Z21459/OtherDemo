#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <complex>//��������
#include <valarray>//��������
#include <numeric>//ͨ����ֵ����
#include <cmath>//ȫ������ֵ����
using namespace std;


/*
STL ��ֵ����
�ݺ��� pow(x,y) xΪ�� yΪָ��
exp(2) ��eΪ�׵��ݺ���
sqrt() ƽ����
log() ����


6.2���� ��������
valarray  ʵ����ֵ����ļ���
���� size() max() sum() min() resize() resize()��
shfit--�߼���λ��cshiftʵ��ѭ����λ

slice  �и�--��ʼ ���� ��� ����һ���µ�����

slice_array ��ͬһ��ֵ����ÿһ��Ԫ�� ��ֵ��һ��valarray �����κ�һ����ֵ��������


numeric�����ĸ��㷨 accumulate��� inner_product �ڻ� 
					partial_sum����Ԫ��֮�� adjacement_difference Ԫ�ص����ڲ�

cmath�� pow() exp() sqrt()  log() log() �� 

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
	slice myslice(0, 4, 3);//��ʼλ�� Ԫ�ظ���  ���
	v2 = v1[myslice];
	cout << "�ָ�" << endl;
	printV(v2);




	system("pause");
	return 0;
}