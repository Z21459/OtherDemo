#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int FindMax(int a,int b){
	return a>b?a:b; 
}

void Swapv(int &a,int &b){
	int temp =a;
	a =b;
	b=temp;
	/*a = a^b;
	a = a^b;
	b =a^b;*/
}


void BullddSort(vector<int>&b){
		//cout << "**";
	bool flag = true;
	for(int i = 0;i<b.size()&& flag;i++){
		for(int j =0;j<b.size();j++){
			if(b[i]>b[j]) {
					/*int temp =b[i];
					b[i] =b[j];
					b[j]=temp;*/
					Swapv(b[i],b[j]);
					flag == false;
			}
		}
	}
}

void InsertSort(vector<int>&b){
	int i,j,k;
	cout << "**"<<b.size()<<"**";//Ĭ�ϵ�һ������ 
	for(int i = 1;i<b.size();i++){
		j = i-1;
		for(;j>=0;--j){//���ҵ�λ�� 
			if(b[j] <= b[i]){
				break;
			}
		} 
		if(j!=i-1){
		int temp = b[i];
	    for(int k = i;k>j+1;--k){//����Ԫ�غ��ƶ�һλ 
			       b[k] = b[k-1];//���ƶ�һλ 
		    }
	    	b[j+1] = temp;
    	}
	}
}
 
 //������ 
void QuickSort(vector<int>&arr,int beg, int end){
	if (beg >= end - 1) {
		return;
	}
	int lindex = beg;
	int rindex = end - 1;
	int std = arr[lindex];
	while (lindex < rindex) {
		while (lindex < rindex) {
			if (arr[rindex] < std) {
				arr[lindex++] = arr[rindex];
				break;
			}
			--rindex;
		}
		while (lindex < rindex)
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
	QuickSort(arr, beg, lindex);
	QuickSort(arr, rindex + 1, end);
	
	/*int left = beg;
	int right = end -1;
	int mid = b[left];//��־λ 
	while(left<right){
		while(left<right){
			if(mid > b[right]){//�Һ���С�ڱ�־ 
				b[left++] = b[right];
				break;
			}
			--right;
		}
		while(left<right){
			if(mid<=b[left]){
				  b[right--]=b[left];
				break;
			}
			++left;
		}
	}
	b[left] = mid;//�Ա�־λ����  ���ߵݹ� 
	QuickSort(b,beg,left);
	QuickSort(b,right+1,end);*/
	
	
	/*int len = b.size();	
	int mid;
	while(end > beg){
		int i;
		int j;
		for( i = end;i>0;i--){//�Ӻ���ǰ�� С�Ľ��� 
			if(b[0]>b[i]){
				Swapv(b[0],b[i]);//�ҵ�֮�� ���µ�ǰλ��   
				
				break;
			}--end;
		}
		for(j =beg+1 ;j< end ;j++){//��ǰ�����Ҵ�Ľ��� 
			if(b[j]>b[i]){
				Swapv(b[j],b[i]);
				
				break;
			}++beg;
		}
			
	}
	mid = b[beg];//��¼�µ�ǰ�м�λ�� 
	QuickSort(b,beg,mid);
	QuickSort(b,mid+1,end); */
} 


void SelectSort(vector<int>&a){
	int len = a.size();
	int sm=0;
	int j; 
	for(int i =0;i<len;i++){
		j = i;
		sm =i; 
		for(;j<len;j++){
			if(a[sm]>a[j]){
				sm =j;
			}
		}
		Swapv(a[i],a[sm]);	//��С�����͵�һ���������������ӵڶ�����ʼ����С������ڶ������� 
	}
} 

int main(){
	vector<int>a;
	a.push_back(2);
	a.push_back(5);
	a.push_back(1);
	a.push_back(3);
	a.push_back(4);
	cout << "����ǰ��";
		for(int i =0;i<a.size();i++){
		cout << a[i];
	}
	//BullddSort(a); 
	//InsertSort(a);
	QuickSort(a,0,a.size());
	//SelectSort(a);
	
	cout << "\n�����";
	for(int i =0;i<a.size();i++){
		cout << a[i];
	}
	
} 
