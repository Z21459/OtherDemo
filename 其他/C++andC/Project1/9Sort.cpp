#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
using namespace std;
//常用两个函数，获得最大值和交换
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

//直接插入排序--以第一个为有序数列，后面插入的与其相比，然后该元素所有进行移位，给带插入元素提供位置
void InsertSort(int a[], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		j = i - 1;
		for (; j >= 0; --j) {//先找到要插入的位置  效率更高
			if (a[j] <= a[i]) {
				break;
			}
		}
		if (j != i - 1) {
			int temp = a[i];
			for (int k = i; k > j + 1; --k) {
				a[k] = a[k - 1];//后移动一位
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
//冒泡排序--两两比较，进行交换
void BubbleSort(int a[], int n) {
	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[i] >= a[j])//从小到大排序
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
//快速排序--从后往前找比基数小的交换，从前往后找比基数大的交换，以此类推，完成一次快排，将数据以基数分成两部分。然后递归继续进行排序
//一种分治思想
void QuickSort(int a[], int beg, int end) {
	if (beg >= end - 1) {
		return;
	}
	int left = beg;
	int right = end - 1;
	int mid = a[left];
	while (left < right) {
		while (left < right) {
			if (mid > a[right])//从后往前找比基数小的
			{
				a[left++] = a[right];
				break;
			}
			--right;
		}
		while (left < right) {
			if (mid <= a[left]) {//从前前往后找大的
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
//选择排序-- 第一趟选择最小值和索引，与第一个进行交换。然后第二趟以第二个为基准更新最小值的索引
void SelectSort(int a[], int n) {//不稳定的排序算法
	int  i, j, x, k;
	for (int i = 0; i < n; i++) {//n-1趟遍历    每次都会选择一个最小的放在最前面
		x = a[i];
		k = i;//初始化记录最小值和最小值下标索引
		for (j = i; j < n; j++) {
			if (a[j] < x) {
				x = a[j];//交换最小
				k = j;//记录最小值位置
			}
		}
		//交换
		a[k] = a[i];//最小值进行交换 和上述 x = a[j] 形成了一个交换
		a[i] = x;
		//cout << a[i];
	}
}
//希尔排序-- 每次以步长 进行交换，直到步长为1 的时候 交换完成 step
void ShellSort(int a[], int n) {
	for (int step = n / 2; step > 0; step /= 2) {
		for (int i = 0; i < step; ++i) {
			//以下是插入排序
			for (int j = i + step; j < n; j += step) {
				int k = j - step;//原本-1
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
	//for (h = n / 2; h > 0; h=h/2) {//每次都是减去一半
	//	//内不循环，进行交换 --希尔排序 也是插入排序
	//	for (i = h; i < n; i++) {//直接插入排序
	//		temp = a[i];
	//		for (j = i - h; (j >= 0 && temp < a[j]); j -= h) {
	//			a[j + h] = a[j];

	//		}
	//		a[j + h] = temp;
	//	}
	//}
}
//归并排序 - 采用了分治和递归的思想，递归 & 分治 - 排序整个数列如同排序两个有序数列，依次执行这个过程直至排序末端的两个元素，
//再依次向上层输送排序好的两个子列进行排序直至整个数列有序（类比二叉树的思想，from down to up）。O(NlogN) 稳定
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
	//数组arr空or仅有一个元素则退出
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
//堆排序-最小堆和最大堆 --相当于二叉树
int heapSize = 0;
int Left(int index) { return ((index << 1) + 1); }
int Right(int index) { return ((index << 1) + 2); }
void maxHeapify(int arr[], int index) {
	int largest = 0;
	int left = Left(index);
	int right = Right(index);
	//赋值最大给堆顶 或者左右最大值
	if ((left <= heapSize) && (arr[left] > arr[index]))//左比较
		largest = left;
	else
		largest = index;
	if ((right <= heapSize) && (arr[right] > arr[largest]))//右比较
		largest = right;
	//largest为堆顶和左右节点最大值
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
	//初始化堆
	bulidMaxHeap(a, n - 1);
	for (i = n - 1; i >= 1; i--) {
		Swap(a[0], a[i]);
		heapSize--;
		maxHeapify(a, 0);
	}
	return;
}
//桶排序-基数排序  建立0-9十个桶  根据个 十 百 。。进行放入不同的桶之中
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

