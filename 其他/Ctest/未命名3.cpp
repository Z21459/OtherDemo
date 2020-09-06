#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN


void deblack(char*s){
	char *dest;
	char *src;
	int ch;
	
	src=s;
	dest=s++;
	while((ch = *src++)!=NULL){
		if(is_white(ch)){
			if(src==s || is_white(dest[-1])){
				*dest++=' ';
			}
		}
		else{
			*dest++ = ch;
		}
	}
	*dest=NULL;
}

int main(void)
{

	char *p="abu de ";
	deblack(p);
	/*int i;
	int prime[100];
	for(i=0;i<100;i++){
		prime[i]=1;
	}
		
	int x= 2;
	while(x<100){
		for(i = 2;i*x<100;i++){
			if(prime[x]){
				prime[i*x]=0;
			}
		}
		x++;
	}
	for(i =2;i<100;i++){
		if(prime[i])
		{
			printf("%d",i);
		}
	}*/
	
	/*char input[MAX_LEN];
	int len;
	char longest[MAX_LEN];
	itn longest_len;
	
	longest_len=-1;
	
	while(gets(input)!=NULL){
		len = strlen(input);
		if(len>longest_len){
			longest_len = len;
			strcpy(longest,input);
		}
	}
	if(longest_len>=0){
		puts(longest);
	}*/
	
	/*int c;
	char sum = -1;
	while((c=getchar())!=EOF){
		putchar(c);
		sum+=c;
	} 
	printf("%d"\n,sum);*/
	return EXIT_SUCCESS;
 } 
