#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
using namespace std;
//��������������������ֵ�ͽ���
int getMaxValue(const vector<int> &arr) {
	int max = 0;
	for (auto val : arr) {
		if (val > max) {
			max = val;
		}
	}
	return max;
}

void Swap(int &pa, int &pb) {
	int temp = pa;
	pa = pb;
	pb = temp;
}

//ֱ�Ӳ�������--�Ե�һ��Ϊ�������У���������������ȣ�Ȼ���Ԫ�����н�����λ����������Ԫ���ṩλ��
void InsertSort(int a[], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		j = i - 1;
		for (; j >= 0; --j) {//���ҵ�Ҫ�����λ��  Ч�ʸ���
			if (a[j] <= a[i]) {
				break;
			}
		}
		if (j != i - 1) {
			int temp = a[i];
			for (int k = i; k > j + 1; --k) {
				a[k] = a[k - 1];//���ƶ�һλ
			}
			a[j + 1] = temp;
		}
	}
	//int i, j, temp;
	//for (i = 0; i < n; i++) {
	//	temp = a[i];
	//	for (j = i - 1; j >= 0 && temp < a[j]; j--) {
	//		a[j + 1] = a[j];
	//	}
	//	a[j + 1] = temp;
	//}
}
//ð������--�����Ƚϣ����н���
void BubbleSort(int a[], int n) {
	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[i] >= a[j])//��С��������
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				
				flag = false;
			}
		}
		if (flag) {
			return;
		}
	}
}
//��������--�Ӻ���ǰ�ұȻ���С�Ľ�������ǰ�����ұȻ�����Ľ������Դ����ƣ����һ�ο��ţ��������Ի����ֳ������֡�Ȼ��ݹ������������
//һ�ַ���˼��
void QuickSort(int a[], int beg, int end) {
	if (beg >= end - 1) {
		return;
	}
	int left = beg;
	int right = end - 1;
	int mid = a[left];
	while (left < right) {
		while (left < right) {
			if (mid > a[right])//�Ӻ���ǰ�ұȻ���С��
			{
				a[left++] = a[right];
				break;
			}
			--right;
		}
		while (left < right) {
			if (mid <= a[left]) {//��ǰǰ�����Ҵ��
				a[right--] = a[left];
				break;
			}
			++left;
		}
	}
	a[left] = mid;
	QuickSort(a, beg, left);
	QuickSort(a, right+1, end);
}
//ѡ������-- ��һ��ѡ����Сֵ�����������һ�����н�����Ȼ��ڶ����Եڶ���Ϊ��׼������Сֵ������
void SelectSort(int a[], int n) {//���ȶ��������㷨
	int  i, j, x, k;
	for (int i = 0; i < n; i++) {//n-1�˱���    ÿ�ζ���ѡ��һ����С�ķ�����ǰ��
		x = a[i];
		k = i;//��ʼ����¼��Сֵ����Сֵ�±�����
		for (j = i; j < n; j++) {
			if (a[j] < x) {
				x = a[j];//������С
				k = j;//��¼��Сֵλ��
			}
		}
		//����
		a[k] = a[i];//��Сֵ���н��� ������ x = a[j] �γ���һ������
		a[i] = x;
		//cout << a[i];
	}
}
//ϣ������-- ÿ���Բ��� ���н�����ֱ������Ϊ1 ��ʱ�� ������� step
void ShellSort(int a[], int n) {
	for (int step = n / 2; step > 0; step /= 2) {
		for (int i = 0; i < step; ++i) {
			//�����ǲ�������
			for (int j = i + step; j < n; j += step) {
				int k = j - step;//ԭ��-1
				for (; k >= i; k-=step) {
					if (a[k] <= a[j]) {
						break;
					}
				}
				if (k != j - step) {
					int temp = a[j];
					for (int m = j; m > k + step; m -= step) {
						a[m] = a[m - step];
					}
					a[k + step] = temp;
				}
			}
		}
	}
	
	//int h, i, j, temp;
	//for (h = n / 2; h > 0; h=h/2) {//ÿ�ζ��Ǽ�ȥһ��
	//	//�ڲ�ѭ�������н��� --ϣ������ Ҳ�ǲ�������
	//	for (i = h; i < n; i++) {//ֱ�Ӳ�������
	//		temp = a[i];
	//		for (j = i - h; (j >= 0 && temp < a[j]); j -= h) {
	//			a[j + h] = a[j];

	//		}
	//		a[j + h] = temp;
	//	}
	//}
}
//�鲢���� - �����˷��κ͵ݹ��˼�룬�ݹ� & ���� - ��������������ͬ���������������У�����ִ���������ֱ������ĩ�˵�����Ԫ�أ�
//���������ϲ���������õ��������н�������ֱ����������������ȶ�������˼�룬from down to up����O(NlogN) �ȶ�
void mSortInOrder(int a[],int tmp[], int lPos, int rPos, int rEnd)
{
	int i, lEnd, NumEle, tmpPos;
	lEnd = rPos - 1;
	tmpPos = lPos;
	NumEle = rEnd - lPos + 1;
	while (lPos <= lEnd && rPos <= rEnd) {
		if (a[lPos] <= a[rPos]) {
			tmp[tmpPos++] = a[lPos++];
		}
		else {
			tmp[tmpPos++] = a[rPos++];
		}
	}
	while (lPos <= lEnd)
		tmp[tmpPos++] = a[lPos++];
	while (rPos <= rEnd)
		tmp[tmpPos++] = a[rPos++];
	for (i = 0; i < NumEle; i++, rEnd--) {
		a[rEnd] = tmp[rEnd];
	}
}
void mSort(int a[],int tmp[], int bgn, int end)
{
	//����arr��or����һ��Ԫ�����˳�
	if (bgn >= end - 1)
		return;

	int mid = (bgn + end) / 2;
	mSort(a, tmp, bgn, mid);
	mSort(a, tmp, mid+1, end);
	mSortInOrder(a, tmp, bgn, mid+1, end);
}
void MergeSort(int a[], int n) {
	int *tmp = NULL;
	tmp = new int[n];
	if (tmp != NULL) {
		mSort(a, tmp, 0, n - 1);
		delete[]tmp;
	}
}
//������-��С�Ѻ����� --�൱�ڶ�����
int heapSize = 0;
int Left(int index) { return ((index << 1) + 1); }
int Right(int index) { return ((index << 1) + 2); }
void maxHeapify(int arr[], int index) {
	int largest = 0;
	int left = Left(index);
	int right = Right(index);
	//��ֵ�����Ѷ� �����������ֵ
	if ((left <= heapSize) && (arr[left] > arr[index]))//��Ƚ�
		largest = left;
	else
		largest = index;
	if ((right <= heapSize) && (arr[right] > arr[largest]))//�ұȽ�
		largest = right;
	//largestΪ�Ѷ������ҽڵ����ֵ
	if (largest != index) {
		Swap(arr[index], arr[largest]);
		maxHeapify(arr, largest);
	}
}
void bulidMaxHeap(int a[], int length) {
	int i;
	heapSize = length;
	for (i = (length >> 1); i >= 0; i--) {
		maxHeapify(a, i);
	}
}
void HeadSort(int a[],int n) {
	int i;
	//��ʼ����
	bulidMaxHeap(a, n - 1);
	for (i = n - 1; i >= 1; i--) {
		Swap(a[0], a[i]);
		heapSize--;
		maxHeapify(a, 0);
	}
	return;
}
//Ͱ����-��������  ����0-9ʮ��Ͱ  ���ݸ� ʮ �� �������з��벻ͬ��Ͱ֮��
void countSort(int a[]) {
	return;
}



int main9() {

	int a[8] = { 1,5,2,3,6,9,1,2 };
	//InsertSort(a, 8);
	//BubbleSort(a, 8);
	//QuickSort(a, 0, 8);
	//SelectSort(a, 8);
	//ShellSort(a, 8);
	//MergeSort(a, 8);
	HeadSort(a, 8);


	for (int i = 0; i < 8; i++) {
		cout << a[i];
	}


	system("pause");
	return 0;
}

