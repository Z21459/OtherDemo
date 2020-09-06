#include <stdio.h>
#include <stdlib.h>
#include <iostream>
struct{
	short a;
	char b;
	float c;
}cs;

union{
	char a[10];
	short b[4][5];
	long c[5];
}u;

enum list1{x1,x2,x3,x4=6,x5,x6
};

class Value{
	public:
		Value(int value){
			m_value = value;
			printf("Call value\n");
		}
		~Value(){
			printf("call ~value\n");
		}
		Value& operator=(int value){
			m_value = value;
			printf("call OPerator=\n");
		return *this;
		}
		void Dump(){
			printf("valueDUM = %d\n",m_value);
		}
		protected:
			int m_value;	
}; 

class Base{
	public:
		Base(){Init();
		}
		virtual ~Base(){Release();
		}
		virtual void Init(){
			printf("call base init\n");
		}
		virtual void Release(){
			printf("call base relesr\n");
		}
		virtual void Dump(){
			printf("call base dump\n");
		}
};

class Derive:public Base{
	public:
		Derive(){
			printf("call Der\n");
		}
		~Derive(){
			printf("call ~Der\n");
		}
		virtual void Init(){
			m_value = 2;
			printf("call Der init\n");
		}
		virtual void Release(){
			printf("Der relaed\n");
		}
		virtual void Dump(){
			m_value.Dump();
		}
		protected:
			static Value m_value;
};


//Value Derive::m_value = 0;
void DesObj(Base* pOb){
	pOb->Dump();
	delete pOb;
}

#include <vector>
using namespace std;
void InOrder(int a,int b,int c,int d,vector<int>&result){
	vector<int>s1,s2,temp;
	int S1small = a>b?b:a;
	int S2small = c>d?d:c;
	
	for(int i = a;i<=b;i++){
		s1.push_back(i);
	}
	for(int j = c;j<=d;j++){
		s2.push_back(j);
	}
	
	//将s1取出和s2进行对比

	for(int i = 0;i<s1.size();i++){
		for(int j = 0;j<s2.size();j++){
			if(s1[i] == s2[j]){
				temp.push_back(s1[i]);
				break;
			}
		}
	} 
	
	for(int m=0;m<temp.size();m++){
		result.push_back(temp[m]);
	}
	
		
}

int main(){
	
	int a=2,b=5,c=1,d=4;
	vector<int>s;
	InOrder(a,b,c,d,s);
	for(int m=0;m<s.size();m++){
		cout <<  s[m];
	}	

	
	/*char ch[] = {"abc\0def"},*p = ch;
	printf("%c",*p+4);
	
	std::cout << sizeof(short);
	std::cout << sizeof(char);
	std::cout << sizeof(float);
	std::cout << sizeof(cs);*/
	
	//printf("%d",sizeof(u));
	
	//printf("%d",x2);
	
	//printf("|%9.4f|\n",12345.67);//9位长度   小数点 后四位 
	
	//int a;
	//a = 2,4,a+1;
	//printf("%d",a); 
	
	
	///Derive *pOb = new Derive;
	//DesObj(pOb);
	
	//std::cout << (101%100/10);
	
	
	/*int k = 0;char c = 'A';
	do{
		switch(c++){
			case 'A':k++;break;
			case 'B':k--;
			case 'C':k+=2;break;
			case 'D':k = k%2;break;
			case 'E':k=k*10;break;
			default:k=k/3;
		}
		k++;
	}while(c<'G');
	printf("%d",k);*/
	
	/*int x = 20,y=40,*p;
	p = &x;
	//printf("%d",*p);
	*p = x+10;
	p = &y;
	//printf("%d",*p);
	*p = y+20;
	//printf("%d,%d\n",x,y);*/
	system("pause"); 
	return 0;
} 
