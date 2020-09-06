#include <iostream>
#include <stdio.h>
using namespace std;


//移位 判断是否为移位  0123   2301  前一个通过移位 可以得到是否移动

bool Rev(const int *s1,const int *s2, int n){
	int a1[n] = {0};
	int b1[n] ={0};
	for(int i =0;i<n;i++){
		a1[i] = *(s1+i);
		b1[i] = *(s2+i);
		/*a1[i] = s1[i];
		b1[i] = s2[i];*/
	}
	bool flag = false;
	for(int i =0;i<n;i++){
		//cout << a1[i] <<"\n";
		//cout << b1[i] ;
		if(a1[i] != b1[i])
		{
			flag = false;
		}
		else{
			flag =true;
		}
	}
	
	
	int w[n],p = 1,i=0;//临时数组和位移数 
	
	for(;p<n;p++){
		for(i=0;i<p;i++)w[i]=a1[i];
		for(;i<n;i++)a1[i-p]=a1[i];
		for(i=0;i<p;i++)a1[n-p+i]=w[i];//移位  每次移动一位  然后在下次基础上 在进行移位 
		
		for(int m =0; m < n;m++){//判断 
			if(a1[m] == b1[m])
			{
				flag = true;
			}
			else{
				flag =false;
			}
		}
	} 
	
	return flag;
} 

int main(){
	
	

	/*int x,y;
	cout << "选择输入个数";
	cin >> n ; 
	for(int i = 0;i<n;i++){
		cin >> x >> y;
		a[i] = x;
		b[i] = y;
	}*/
	int a[4] = {1,2,3,4};
	int b[4] = {3,4,1,1};
	int n = 4;
	
	bool result= Rev(a,b,n) ;//传指针 
	if(result){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	
	return 0;
} 
