//���� ����

//��ϣ��Ͷ�������������  

//��������  ð��  �鲢  ����
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
//QuickSort ��һ������  �ָ�  Ȼ��ݹ� ����
void QuickSort(int arr[],int bgn,int end){
	if (bgn >= end - 1) {
		return;
	}
	int lindex = bgn;
	int rindex = end - 1;
	int std = arr[lindex];
	while (lindex < rindex) {
		while (lindex < rindex) {//�Ӻ���ұ�ǰ��С��  �ȱ���һ�� 
			if (arr[rindex] < std) {
				arr[lindex++] = arr[rindex];
				break;
			}
			--rindex;
		}
		while (lindex < rindex)//��ǰ���ұȻ������ 
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

//����
void InsertSort(int arr[],int bgn,int end){
	for (int i = bgn + 1; i < end; i++) {
		/*
* ��Ϊ1,2�����ִ�����������j = beg - 1ʱ�����
* ����Ҫ��arr[i]���뵽��Ԫ��ǰ��λ�ã���ʹ��һ��for
* �����������֣�����ڷ����������ʱ�˳�
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
//ѡ������ 

void SelectSort(int arr[],int bgn,int end){
//��ѡ��С��Ԫ����Ϊ����
	for(int i = 0;i<end;i++){
		int minIndex = 0;
		for(int j = i+1;j<end;j++){
			if(arr[j]<arr[j+1]){
				minIndex =j;//��С����ֵλ��  �±� 
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

//�鲢 ��·�鲢 ����������  Ȼ���ĸ����� �����ϲ�
//  ʱ�临�Ӷ�  n2  �ռ临�Ӷ� n
void Merger(int a[], int bgn, int mid, int end) {//2,8,5,4,6    a  0  2  5  /*a 0 5 10
	int i, j, k = 0;
	int * temp = new int[end - bgn + 1];//����ռ�  ����ռ��СΪ6  
	for (i = bgn,j = mid+1; i <= mid && j< end;) {
			if (a[i] < a[j]) {
				temp[k++] = a[i++];//�ж������������� ���ǰ��С�ں��� ��С�Ĵ���������
				//�������������� ������һλ
			}
			else {
				temp[k++] = a[j++];//���ǰ�������棬����������ȥ��������һλ
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

void SortGui(int a[], int low,int high) {//������ֳ�������  �ݹ�ֱ��������
	//��ͷ�ͽ�β Ԫ�ظ���
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


 
