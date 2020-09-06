#include <stdio.h>
#include <iostream>
using namespace std;

void Swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	/*int a =1;
	int b = 2;
	int *p =&a;
	int *&pa = p;*/
	//(*pa)++;
	//out << *p;
	//cout <<a;
	//pa = &b;
	//(*pa)++;
	//cout << a  << b << *p;
	//Swap(a,b);
	/*a = a^b;
	b = a^b;
	a = a^b;*/
	
	/*Swap(a,b);
	cout << a<<b;*/
	char *a = "aaa";
	char *b = "bbb"; 
	
	
	
	
	return 0;
} 
