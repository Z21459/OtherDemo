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
	cout << "**"<<b.size()<<"**";//默认第一个有序 
	for(int i = 1;i<b.size();i++){
		j = i-1;
		for(;j>=0;--j){//先找到位置 
			if(b[j] <= b[i]){
				break;
			}
		} 
		if(j!=i-1){
		int temp = b[i];
	    for(int k = i;k>j+1;--k){//所有元素后移动一位 
			       b[k] = b[k-1];//后移动一位 
		    }
	    	b[j+1] = temp;
    	}
	}
}
 
 //有问题 
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
	int mid = b[left];//标志位 
	while(left<right){
		while(left<right){
			if(mid > b[right]){//找后面小于标志 
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
	b[left] = mid;//以标志位中心  两边递归 
	QuickSort(b,beg,left);
	QuickSort(b,right+1,end);*/
	
	
	/*int len = b.size();	
	int mid;
	while(end > beg){
		int i;
		int j;
		for( i = end;i>0;i--){//从后往前找 小的交换 
			if(b[0]>b[i]){
				Swapv(b[0],b[i]);//找到之后 定下当前位置   
				
				break;
			}--end;
		}
		for(j =beg+1 ;j< end ;j++){//从前往后找大的交换 
			if(b[j]>b[i]){
				Swapv(b[j],b[i]);
				
				break;
			}++beg;
		}
			
	}
	mid = b[beg];//记录下当前中间位置 
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
		Swapv(a[i],a[sm]);	//最小索引和第一个交换，接下来从第二个开始找最小索引与第二个交换 
	}
} 

int main(){
	vector<int>a;
	a.push_back(2);
	a.push_back(5);
	a.push_back(1);
	a.push_back(3);
	a.push_back(4);
	cout << "排序前：";
		for(int i =0;i<a.size();i++){
		cout << a[i];
	}
	//BullddSort(a); 
	//InsertSort(a);
	QuickSort(a,0,a.size());
	//SelectSort(a);
	
	cout << "\n排序后：";
	for(int i =0;i<a.size();i++){
		cout << a[i];
	}
	
} 
