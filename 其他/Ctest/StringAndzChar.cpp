#include<stdlib.h>
#include <stdio.h> 
#include <iostream>
#include <string.h>
using namespace std;

//�ַ���ת����
/*int  str2int(const char* str)
{
	int temp = 0;
	const char*ptr = str;
	if(*str == '-'||*str == '+'){
		str++;//��Ϊ���� ����һλ 
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

//�����Ӵ�---------�ڲ�ѭ��˼��    �ⲿѭ��һ��  ===�ڲ�ѭ����ֵ����ѭ��һ��    ѭ��ȡ�������Ӵ��Ƚ� 
 
/*const char*strstr1(const char* Dest,const char*Sub) {
	
	const char* bd;
	const char* sp;
	if(Dest == NULL || Sub == NULL){
		return NULL;
	}
	while(*Dest)//�Գ���Ϊѭ��
	{
		bd = Dest;
		sp = Sub; // ���ڱ���
		while(*bd++ == *sp++){
			if(*sp){
				return Dest;
			}
		}
		Dest+=1;
	} 
	 return NULL;
}*/


//�Ӵ����ʷ�ת   ��������ո����\0  �� 

/*void RevStr(char *src){
	char * start = src,*end = src,*ptr = src;
	while(*ptr++!='\0');
	end = ptr-2;//�ҵ��ַ���ĩβ
	while(start<end){
		swap(*start++,*end++);//�����ַ�����ת 
	} 
	
	start = src,end=ptr-2;
	ptr = start;
	while(*ptr++ != '\0'){
		if(*ptr == ' '||*ptr =='\n'){
			end = ptr-1;//�Ƶ���һ������
			while(start<end){
				swap(*start++,*end++);
			
			} 
		start = end = ptr-1;		
		}
	} 
} */
//������󹫹��Ӵ�   ���ҵ��̵��Ӵ� 
/*
char *FindMaxSub(const char*Dest,const char*Src){
	
	char *a = new char[1024];
	char *b = new char[1024];
	*a = '\0';
	*b = '\0';
	int i,j,p = 0; 
	int m,n;
	
	for(i = 0;i<strlen(Dest);i++){//�ⲿѭ�� һ�Σ��ڲ�����һ��   ��һ���ַ��� 
		for(j = 0;j<strlen(Src);j++){  //�ڶ����ַ���   
		
			m = i;
			n = j;
		 
			while(Dest[m] == Src[n]){//�ڲ�ѭ���ж� 
				a[m] = Src[n];
					m++;
					n++;
					p++;
			}
			//for(;m<strlen(Dest);){  //����һ���ַ����ĵ�һ�����и�ֵ   Ȼ���ڲ�ѭ�� 
				//if(Dest[m] == Src[n]){
					//a[p] = Src[n];
					//m++;
					//n++;
					//p++;
				//}
			//} 
			
			if(strlen(a)>strlen(b)){//��������Ӵ���  �������� 
				for(int k = 0;k<strlen(a);k++){
					b[k++]=a[k++];
				}
			} 
			p=0;
		}	
	}
	return b;
} */

//ʮ���� ת����2���ƻ���16����


char *get2String(long num){
	;
} 
char *get16String(long num){
	
	;
}
//����0 1��������������

void  Calu(const char*str,int *max0,int *max1){
	int len = strlen(str);
	int m0 = 0,m1=0;
	while(*str)//ѭ��һ��
	{
		if(*str == '0'){
			(*max0) ++;
			if(*(++str) == '1'){
				if(*max0 > m0){
					m0 = *max0;
				}
			*max0 = 0;//����������0��ʱ�򣬼�����0��ʼ 
			}
		}
		
		if(*str == '1'){
			(*max1) ++;
			if(*(++str) == '0'){
				if(*max1 > m1){
					m1 = *max1;
				}
			*max1 = 0;//����������0��ʱ�򣬼�����0��ʼ 
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
