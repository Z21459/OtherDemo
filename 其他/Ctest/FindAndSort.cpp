//查找 排序

//哈希表和二叉排序树查找  

//插入排序  冒泡  归并  快排
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

void Swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
} 
//QuickSort 以一个基础  分割  然后递归 调用
void QuickSort(int arr[],int bgn,int end){
	if (bgn >= end - 1) {
		return;
	}
	int lindex = bgn;
	int rindex = end - 1;
	int std = arr[lindex];
	while (lindex < rindex) {
		while (lindex < rindex) {//从后查找比前面小的  先遍历一遍 
			if (arr[rindex] < std) {
				arr[lindex++] = arr[rindex];
				break;
			}
			--rindex;
		}
		while (lindex < rindex)//从前查找比基础大的 
		{
			if (arr[lindex] >= std)
			{
				arr[rindex--] = arr[lindex];
				break;
			}
			++lindex;
		}
	}
	arr[lindex] = std;
	QuickSort(arr, bgn, lindex);
	QuickSort(arr, rindex + 1, end);
	
	for(int i =0;i<end;i++){
		printf("%d",arr[i]);
	}
} 

void BuddleSort(int arr[],int bgn,int end){
	bool flag = true;
	for(int i = 0;i<end&&flag;i++){
		flag = false;
		for(int j = i;j<end;j++){
			if(arr[i]>arr[j]){
				Swap(arr[i],arr[j]);
				flag = true;
			}
		}
	}
	for(int i =0;i<end;i++){
		printf("%d",arr[i]);
	}
}

//插入
void InsertSort(int arr[],int bgn,int end){
	for (int i = bgn + 1; i < end; i++) {
		/*
* 分为1,2两部分处理，可以囊括j = beg - 1时的情况
* 即需要将arr[i]插入到首元素前的位置，若使用一个for
* 包括这两部分，则会在发生这种情况时退出
  */
    /*1*/
		int j = i - 1;
		for (; j > bgn; --j) {
			if (arr[j] <= arr[i])
				break;
		}
		/*2*/
		if (j != i - 1) {
			int temp = arr[i];
			for (int k = i; k > j + 1; --k) {
				arr[k] = arr[k - 1];
			}
			arr[j + 1] = temp;
		}
	 }
	for(int i =0;i<end;i++){
		printf("%d",arr[i]);
	}
}
//选择排序 

void SelectSort(int arr[],int bgn,int end){
//先选最小的元素作为索引
	for(int i = 0;i<end;i++){
		int minIndex = 0;
		for(int j = i+1;j<end;j++){
			if(arr[j]<arr[j+1]){
				minIndex =j;//最小索引值位置  下标 
			}
		}
		if(minIndex!=i){
			Swap(arr[i],arr[minIndex]);
		} 
	}
	for(int i =0;i<end;i++){
		printf("%d",arr[i]);
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
				Swap(a[i] , a[j]) 
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
int main(){
	
	int arr[4] = {2,3,1,4};
	//QuickSort(arr,0,4);
	//BuddleSort(arr,0,4);
	//InsertSort(arr,0,4);
	//SelectSort(arr,0,4);
	InsertSort(arr,0,4);
	system("pause");
	return 0;
} 


 
