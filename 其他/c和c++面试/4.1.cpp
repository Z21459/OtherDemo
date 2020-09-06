#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>
using namespace std;


//数子转成字符串
	//把各个数字后面+‘0’存到char类型数组中
void int2char(int a,char *str){
	char b[1024] = " ";
	int temp = a<0 ?-a:a;
	int len = 0;
	int i = 0;
	while(temp){
		b[i++] = (temp%10)+'0';//取最后一位 
		temp = temp/10;//去除最后一位 
	} 
	//如果为负数 多一位存储
	len = a<0?++i :i;
	str[i] = 0;//末尾结束符 
	while(1){
		i--;
		if(b[len-i-1] == 0){
			break;
		}
		str[i] = b[len-i-1];//复制给str 从后向前 
		if(i==0){
			str[i]='-';//添加符号 
		} 
	}
	
}


int char2int(const char *str){
	int temp = 0;
	const char *ptr =str;
	if(*str == '-'||*str == '+'){
		str++;//如果第一个是符号 移动到下一位 
	}
	while(*str!=0)//遍历不到最后一位
	{
		if(*str <'0'||*str >'9'){
			break;
		} 
		//无果是数字 计算
		temp = temp *10 +(*str-'0');
		str++;//移动一位 
		if(*ptr =='-'){
			temp = -temp;
		} 
	} 
	return temp;
} 


int leng(const char* str){
	int len = 0;
	while(*str){//*str++!='0'
		len++;
	}
	return len;
	/*const char *temp = str;
	while(*str){
		*str++;
	} 
	return(str-temp-1);//更高效*/ 
}

char *strcpy1(char *dest,const char*str){//返回char* 方便链式操作 
	if(str == NULL){
		return NULL;
	}
	char *temp = dest;
	while(*str){
		
		*dest++ = *str++; 
	} 
	return temp;
} 

void *memcpy1(void *menTo,const void *menFrom,size_t size){
	//报错机制
	assert(menTo != NULL); 
	//首地址保存
	char *tempto = (char*)menTo;
	char *tempfrom = (char*)menFrom;
	while(size-- >0){
		*tempTo++ = *tempFrom++;//复制到临时变量 
	} 
	return tempto;
}

const char* findstr(const char* dest,const char *sub){
	int temp;
	if(dest == NULL){
		temp =0;
	}
	const char *de；
	const char* su; 
	while(*dest){
		//外部不动，实现内部遍历
		de = dest;
		su = sub;
		do{
			if(!*sp){
				return dest;
			}
		}
		while(*de++ == *su++);
		dest+=1;//指向下一个  当内不循环不满足的时候 
	}
	return temp;
} 

//字符串翻转 
void  Revstr(char *str){
	char *beg = str, *end = str, *ptr = str;
	//全部翻转
	while(*ptr++ != '0'){
		if(*ptr ==''||*ptr =='\0'){
			//找到第一个单词，并且end指向第一个单词尾部
			end = ptr -1;
			while(start <end){
				swap(*start++,*end--);//交换 
			} 
			//指向下一个单词
			start = end = ptr+1; 
		}
	} //经过这一步之后，ptr已经指向最后一个单词的尾部 
	//start指向头，end指向尾
	start = str,end = ptr-2;
	while(start<end){
		swap(*start++,*end--);//整个字符串逆 
	} 
} 

//回文
int found(char *str){
	int result;
	if(str == NULL){
		result = 0;
	}
	int len = strlen(str);
	int i = 0;
	while(i<len/2){
		if(str[i++] = str[len-i-1]){//*(str+i)!=*(str+len-i-1)
			result = 1;
		}
		else{
			result = 0;
			break;
		}
	}
	return result;
} 

int result(const char *str1,const char*str2){//1和2比    while(!(ret = *(unsigned char*)str1 -*(unsigned char*)str2 && *str2
	int fonund;
	if(str1 ==NULL){
		found = -1; 
	}
	else if(str2==NULL){
		found = 1; 
	}
	else if(str1 ==NULL &&str2 ==NULL){
		found = 0;
	}
	while(*str1++ || *str2++){
		if(*str1 > *str2){
			found = 1;
		} 
		else if(*str1 < *str2){
			found = -1;
		}
		else{
			found =0;
		}
	} 
	
	return 0;
	
}

//查找最大共有串  使用内部循环
char *findmax(char* str1,char *str2) 
{
	char * s1,*s2;
	char *shorte,longe;	
	int i,j,m,n,k;
	//先找到最小 最大串 
	if(strlen(str1) < strlen(str2)){
		shorte = str1;
		longe = str2;
	} 
	else{
		shorte = str2;
		longe = str1;
	}
	int len1 = strlen(longe);
	int len2 = strlen(shorte)
	for(i =0;i<len1;i++){
		for(j =0;j<len2;j++){
			n =i;
			m = j
			for(;;){
				if(srt1[n] == str2[m])
				{
					n++;
					m++;
					s1[k++] = str1[n];
				}
			}
			k = 0;
		}
	}
	if(strlen(s1)>strlen(s2)){
		//拷贝最大串 
		for(int a = 0,b =0,a<strlen(s1);) {
			s2[b++] = s1[a++];
		}
	}
	return s2;
}


//十进制转成2进制 和16 进制 1


//翻转字符串 指定子串不翻转  利用栈 


//翻转字符串
char *RevStr(const char*str){//异或 自加减 
	int len =strlen(str);
	char * temp = new char[len+1];
	strcpy(temp,str);
	for(int i = 0;i<len/2;i++){
		int t = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = t;
	}
	return temp;
} 
//4.23


char *strcat1(char *str1,char *str2){
	char *temp  = new char[strlen(str1)+strlen(str2)+1];
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i =0;i<len1;i++){
		*(temp+i) = *(str1+i); 
	}
	for(int j = 0;j<len2;j++){
		*(temp+len1 + j) = *(str2+j);
	}
	return temp;
}  

//出现 连续 0和1的最大值 4.30 

int main(){

	/*int a;
	char t[1024];
	cin >> a;
	int2char(a,t);
	cout << t; */
	
	/*int n=0;
	char p[10] = "";
	cin.getline(p,20);//从键盘获取字符串*/ 
	/*char p[20];
	const char s[] ="adada";
	strcpy1(p,s);
	cout << p;*/
	
	
	
	
	return 0;
} 
