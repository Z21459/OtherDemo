#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;


//�����ڲ�����  �Զ������
/*
1.sort()
2.stable_sort()//���������� vector deque 
//��������Ĭ������Ϊoperator<
3.partial_sort()   �ֲ�����
4. partial_sort_copy()

5.nth_element() ����ĳ��Ԫ������ --��ָ��������Ԫ������
��ʹ��=��n��λ�õ�Ԫ�ؾ�λ����������λ��n֮ǰ��Ԫ��С�ڵ�����

//��Ԫ�ж�ʽ�Զ������� ѧ��д��Ԫ�ж�ʽ

6. merge set_union set_difference set_intersection


�����㷨  binary_search ʹ��֮ǰ ԰�����Ѿ������ �ſ���
includes()
lower_bound()---���ص�һ������value��λ��
upper_bound()


ɾ������ 
1.remove  ָ����Χ��ɾ������val ***��������ֵɾ��֮����������ĩβ��
remove_if �Ƴ�ʹ����Ϊtrue��Ԫ��

//ɾ���ظ��� ���� vector list deque multiset multimap
   �ṩ��unique()  ����ʵ��������Ԫ��Ψһֵ
*/
template <class T>
bool DefineSort(T elem1, T elem2)
{
	if (elem1 > elem2) return true;//����
	else if (elem1 > 3 || elem2 > 3)
	{
		return true;
	}
	return false;
}


int main5()
{

	system("pause");
	return 0;
}