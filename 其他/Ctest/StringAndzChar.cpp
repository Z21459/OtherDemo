#include<stdlib.h>
#include <stdio.h> 
#include <iostream>
#include <string.h>
using namespace std;

//字符串转数子
/*int  str2int(const char* str)
{
	int temp = 0;
	const char*ptr = str;
	if(*str == '-'||*str == '+'){
		str++;//若为符号 后移一位 
	}
	while(*str !='\0'){
		if(*str<'0'||*str>'9'){
			break;
		}
		temp = temp*10+(*str-'0');
		str++;
	} 
	if(*ptr =='-'){
		temp=-temp;
	}
	return temp;
}*/

//查找子串---------内部循环思想    外部循环一次  ===内部循环赋值可以循环一遍    循环取主串和子串比较 
 
/*const char*strstr1(const char* Dest,const char*Sub) {
	
	const char* bd;
	const char* sp;
	if(Dest == NULL || Sub == NULL){
		return NULL;
	}
	while(*Dest)//以长串为循环
	{
		bd = Dest;
		sp = Sub; // 用于遍历
		while(*bd++ == *sp++){
			if(*sp){
				return Dest;
			}
		}
		Dest+=1;
	} 
	 return NULL;
}*/


//子串单词翻转   如果碰到空格或者\0  则 

/*void RevStr(char *src){
	char * start = src,*end = src,*ptr = src;
	while(*ptr++!='\0');
	end = ptr-2;//找到字符串末尾
	while(start<end){
		swap(*start++,*end++);//整个字符串翻转 
	} 
	
	start = src,end=ptr-2;
	ptr = start;
	while(*ptr++ != '\0'){
		if(*ptr == ' '||*ptr =='\n'){
			end = ptr-1;//移到下一个单词
			while(start<end){
				swap(*start++,*end++);
			
			} 
		start = end = ptr-1;		
		}
	} 
} */
//查找最大公共子串   先找到短的子串 
/*
char *FindMaxSub(const char*Dest,const char*Src){
	
	char *a = new char[1024];
	char *b = new char[1024];
	*a = '\0';
	*b = '\0';
	int i,j,p = 0; 
	int m,n;
	
	for(i = 0;i<strlen(Dest);i++){//外部循环 一次，内部遍历一遍   第一个字符串 
		for(j = 0;j<strlen(Src);j++){  //第二个字符串   
		
			m = i;
			n = j;
		 
			while(Dest[m] == Src[n]){//内部循环判断 
				a[m] = Src[n];
					m++;
					n++;
					p++;
			}
			//for(;m<strlen(Dest);){  //将第一个字符串的第一个进行赋值   然后内不循环 
				//if(Dest[m] == Src[n]){
					//a[p] = Src[n];
					//m++;
					//n++;
					//p++;
				//}
			//} 
			
			if(strlen(a)>strlen(b)){//如果二次子串大  保存下来 
				for(int k = 0;k<strlen(a);k++){
					b[k++]=a[k++];
				}
			} 
			p=0;
		}	
	}
	return b;
} */

//十进制 转换成2进制或者16进制


char *get2String(long num){
	;
} 
char *get16String(long num){
	
	;
}
//计算0 1连续出现最大次数

void  Calu(const char*str,int *max0,int *max1){
	int len = strlen(str);
	int m0 = 0,m1=0;
	while(*str)//循环一遍
	{
		if(*str == '0'){
			(*max0) ++;
			if(*(++str) == '1'){
				if(*max0 > m0){
					m0 = *max0;
				}
			*max0 = 0;//当遇到不是0的时候，计数重0开始 
			}
		}
		
		if(*str == '1'){
			(*max1) ++;
			if(*(++str) == '0'){
				if(*max1 > m1){
					m1 = *max1;
				}
			*max1 = 0;//当遇到不是0的时候，计数重0开始 
			}
		}
	} 
	*max0 = m0;
	*max1 = m1; 
} 

int main(){
	
	const char* a1 = "asdsf";
	const char* b1 = "asxdsf";
	char c1[] = "wang li zhang";
	char d1[] = "01000111100010101";
	//const char *res = strstr1(a1,b1);
	//printf("%s",res);
	//RevStr(c1);
	//cout << c1;
	//char * c = FindMaxSub(a1,b1);
	//cout << c;
	int max0 = 0,max1=0;
	Calu(d1,&max0,&max1);
	cout << max0 <<max1;
	
	
	return 0;
}
