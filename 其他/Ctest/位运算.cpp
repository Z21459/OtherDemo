//计算数组中元素出现个数    位运算操作

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int sum1(int n){
	int count;
	while(n){
		++count;
		n = (n-1)&n;
	} 
}


int main(){
	
	
	return 0;
} 
