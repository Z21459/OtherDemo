#include<stdio.h>
#incldue <stdlib.h>
#incldue <string.h>

char *x = "sda";
char *y = "daf";
Swap(x,y)
void Swap(char*&x,char*&y){
	char *temp = x;
	x=y;
	y = temp;
}
 
