#include <iostream>
#include <stdio.h>
using namespace std;


//��λ �ж��Ƿ�Ϊ��λ  0123   2301  ǰһ��ͨ����λ ���Եõ��Ƿ��ƶ�

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
	
	
	int w[n],p = 1,i=0;//��ʱ�����λ���� 
	
	for(;p<n;p++){
		for(i=0;i<p;i++)w[i]=a1[i];
		for(;i<n;i++)a1[i-p]=a1[i];
		for(i=0;i<p;i++)a1[n-p+i]=w[i];//��λ  ÿ���ƶ�һλ  Ȼ�����´λ����� �ڽ�����λ 
		
		for(int m =0; m < n;m++){//�ж� 
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
	cout << "ѡ���������";
	cin >> n ; 
	for(int i = 0;i<n;i++){
		cin >> x >> y;
		a[i] = x;
		b[i] = y;
	}*/
	int a[4] = {1,2,3,4};
	int b[4] = {3,4,1,1};
	int n = 4;
	
	bool result= Rev(a,b,n) ;//��ָ�� 
	if(result){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	
	return 0;
} 
