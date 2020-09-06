#include <stdio.h>
#include <iostream>

#define wLo(xxx)((byte)((word)(xxx)&255))//取低8位
#define Arr_Size(a) (sizeof(a))/((sizeof(a[0]))) 

int main(){
	int a =1,b=2;
	a = a^b;
	b= a^b;
	a = a^b;
	printf("%d%d",a,b);
	 
	printf("%d",int(2e3));//2e3代表2*10的3次方 
	
	system("pause");
	return 0;
} 

