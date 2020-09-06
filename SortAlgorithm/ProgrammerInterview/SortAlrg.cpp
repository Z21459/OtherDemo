#include<iostream>
using namespace std;

//插入  选择 快排 归并  希尔

//插入
void InsertSort(int a[], int n) {
	////默认第一个有序，从第二个开始
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		//第一次不仅如此循环
		for (; j >= 0; --j) {//如果前面已经有序 则直接标志
			if (a[j] <= a[i])// 先查找到标志  之后进行移位操作
				break;
		}
		if (j != i - 1) {
			int temp = a[i];
			for (int k = i; k > j + 1; --k)//k后面的所有移位 即i后面的全部移位
			{
				a[k] = a[k - 1];
			}
			a[j + 1] = temp;
		}
	}
	//int temp,i,j; //5,8,2,6,4 
	//for (i = 1; i < n; i++) {
	//	temp = a[i];//暂存最小
	//	for (j = i - 1; j >=0&&temp<a[j]; j--) {
	//		a[j+1] = a[j];//往后能挪1位
	//	}
	//	a[j + 1] = temp;
	//}
}

//冒泡
void SortBoop(int a[], int n) {//两两比较 进行交换
	int f = 0;//标志是否交换
	for (int i = 0; i < n; i++) {
		//每次之前进行置零
		f = 0;
		for (int j = i + 1; j < n; j++) {
			if (a[i] < a[j]){
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
				f = 1;//发生交换值1
			}
		}
		if (f != 1)//若果没有交换 则f=0
			return;
	}
}

//快排
void SortQuick(int a[], int bgn,int end) {
	if (bgn >= end - 1) {
		return;
	}
	int left = bgn;
	int right = end - 1;
	int std = a[left];
	while (left < right) {
		while (left < right) {
			if(std > a[right]){//后面找比准值小的
				a[left++] = a[right];
				break;
			}
			--right;
		}
		while (left < right) {
			if (std <= a[left]) {//前面找比准值大的
				a[right--] = a[left];
				break;
			}
			++left;
		}
	}
	//分别对两边进行递归
	a[left] = std;
	SortQuick(a, bgn, left);
	SortQuick(a, right + 1, end);
}

//希尔  假设固定步长 每次减去一半  为插入排序的改进
void SortShell(int a[], int n) {
	//固定步长 进行交换  知道最后步长减到1 
	int i, j, gap;
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		//每组进行插入排序
		for (i = 0; i < n; i++)
		{
			for (j = i - gap; j >= 0; j -= gap)//前 gap第一次是5，相当于前6次都不进入这个循环   ；   第二次
			{
				if (a[i] > a[j])
					break;
			}
			if (j != i - gap) {//
				int temp = a[i];
				for (int k = i; k > j; k -= gap)
					a[k] = a[k - gap];
				a[j + gap] = temp;
			}
		}
		//打印当前的gap和序列状态
		cout << "\ngap=" << gap;
		cout << "\ncurrent list:";
		for (int h = 0; h < n; h++)
			cout << a[h] << "  ";
	}
}

//归并 二路归并 先两个排序  然后四个排序 两两合并
//  时间复杂度  n2  空间复杂度 n
void Merger(int a[], int bgn, int mid, int end) {//2,8,5,4,6    a  0  2  5  /*a 0 5 10
	int i, j, k = 0;
	int * temp = new int[end - bgn + 1];//申请空间  申请空间大小为6
	for (i = bgn,j = mid+1; i <= mid && j< end;) {
			if (a[i] < a[j]) {
				temp[k++] = a[i++];//判断两个有序数列 如果前面小于后面 将小的存入新数组
				//对其进行排序操作 并后移一位
			}
			else {
				temp[k++] = a[j++];//如果前面大雨后面，将后面存入进去，并后移一位
			}
	}
	if (i <= mid)
		temp[k++] = a[i++];
	if (j < end)
		temp[k++] = a[j++];
	for (i = 0, k = 0; i < end; i++, k++) {
		a[i] = temp[k];
	}
	delete[]temp;
}

void SortGui(int a[], int low,int high) {//将数组分成两部分  递归分别进行排序
	//开头和结尾 元素个数
	int mid = (high-low) / 2;
	for (int i = low; i <= mid; i++) {
		for (int j = i + 1; j <= mid; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int j = mid + 1; j < high; j++) {
		for (int k = j + 1; k < high; k++) {
			if (a[j] > a[k]) {
				int temp = a[j];
				a[j] = a[k];
				a[k] = temp;
			}
		}
	}
	cout << endl << "SortGui";
	for (int i = 0; i < high; i++) {
		cout << a[i];
	}
	//SortGui(a, low, mid);
	//SortGui(a, mid + 1, high);
	Merger(a, low, mid, high);
}

//堆排序 最大最小堆  还没有成
void HeadSort(int a[], int len) {//
	//排序 选择最小或者最大 放在顶端 以最大堆为例 二叉树 求最大值为堆顶值
	int max;
	for (int i = 0; i < len;i++) {
		if (a[i] > a[i + 1])
			max = a[i];//找到最大堆的定点
	}
	cout << "max" << max;
}
int main3(int argc, char *argv[]) {
	int a[10] = { 5,8,2,6,4,8,1,3,10,7};
	for (int i = 0; i < 10; i++) {
		cout << a[i];
	}
	HeadSort(a, 10);
	//InsertSort(a, 10);
	//SortBoop(a, 10);
	//SortQuick(a, 0, 10);
	//SortShell(a, 10);
	//SortGui(a, 0, 10);
	cout  << endl << "SortLat";
	for (int i = 0; i < 10; i++) {
		cout <<  a[i];
	}
	system("pause");
	return 0;
}