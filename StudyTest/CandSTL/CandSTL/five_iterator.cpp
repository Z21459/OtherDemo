#include<iostream>
#include <map>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

/*
������
 ������  ����� ǰ�� ˫��  ���
 1. ������ ֻ�ܹ�һ��һ�ε���ǰ��  * -> ++ == !=  TYPE(iter)���Ƶ�����
 2. ��� ֻ��һ��һ����ֵ * ++ �Ȳ���
 3. ǰ��  ++ == iter!= iter1 �������������ľ��󲿷ֹ���
 4. ˫�� �����˻�ͷ���� --iter��
 5. ��� ����֧�ֵĵ����� �� vector deque string ��ͨ����arrar
 ���������ܱ�ʵ����һ���ָ������

 �������� ��һ�ֵ���������� ���԰��������㷨��ԭ����յ�

 
 5.5 ����������
 advance:�������͵����������Է����ǰ���ͺ���
 distance:����ͳһ����������������֮��ľ���
 iter_swap:����������������ָ��Ԫ�ص�ֵ �����������Ϳ��Բ�ͬ��������ָ�������ֵ������Խ���
 
 */

void print_I(int &elm)
{
	cout << elm << " ";
}

int main7()
{
	/*vector<int> vec;
	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i);
	}
	while (!vec.empty())
	{
		vector<int>::iterator k = vec.begin();
		vec.erase(k);//ɾ����һ��Ԫ��
	}*/

	list<int>ll;
	for (int i = 0; i < 7; i++)
	{
		ll.push_front(i);
	}
	for_each(ll.begin(), ll.end(), print_I);
	cout << endl;
	//for_each(ll.rbegin(), ll.rend(), print_I);
	cout << endl;

	vector<int>vec;
	for (int i = 0; i < 7; i++)
	{
		vec.push_back(i+1);
	}
	for_each(vec.begin(), vec.end(), print_I);
	cout << endl;
	cout << endl;
	list<int>::iterator it = ll.begin();
	vector<int>::iterator it1 = vec.begin();
	iter_swap(it, it1);
	for_each(vec.begin(), vec.end(), print_I);
	cout << endl;



	system("pause");
	return 0;
}