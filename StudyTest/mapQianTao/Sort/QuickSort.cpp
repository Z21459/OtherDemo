#include <iostream>
#include <vector>
using namespace std;

// �汾һ ��䷨
int partition(vector<int> &v, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key = v[end];          // ѡ��׼

	while (begin < end)
	{
		while (begin < end && v[begin] <= key)//���Ҵ�
			begin++;
		if (begin < end)
			v[end--] = v[begin];
		while (begin < end && v[end] >= key)//����С
			end--;
		if (begin < end)
			v[begin++] = v[end];
	}
	v[end] = key;
	return end;
}//һ�˺�Ļ�׼

void QuickSort(vector<int>& v, int left, int right)
{
	if (left < right)
	{
		int boundary = partition(v, left, right);
		QuickSort(v, left, boundary);
		QuickSort(v, boundary + 1, right);
	}
}


int mains()
{
	vector<int>vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(2);
	vec.push_back(4);

	QuickSort(vec, 0, 5);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i];
	}
	system("pause");
	return 0;
}