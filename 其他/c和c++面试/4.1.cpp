#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>
using namespace std;


//����ת���ַ���
	//�Ѹ������ֺ���+��0���浽char����������
void int2char(int a,char *str){
	char b[1024] = " ";
	int temp = a<0 ?-a:a;
	int len = 0;
	int i = 0;
	while(temp){
		b[i++] = (temp%10)+'0';//ȡ���һλ 
		temp = temp/10;//ȥ�����һλ 
	} 
	//���Ϊ���� ��һλ�洢
	len = a<0?++i :i;
	str[i] = 0;//ĩβ������ 
	while(1){
		i--;
		if(b[len-i-1] == 0){
			break;
		}
		str[i] = b[len-i-1];//���Ƹ�str �Ӻ���ǰ 
		if(i==0){
			str[i]='-';//��ӷ��� 
		} 
	}
	
}


int char2int(const char *str){
	int temp = 0;
	const char *ptr =str;
	if(*str == '-'||*str == '+'){
		str++;//�����һ���Ƿ��� �ƶ�����һλ 
	}
	while(*str!=0)//�����������һλ
	{
		if(*str <'0'||*str >'9'){
			break;
		} 
		//�޹������� ����
		temp = temp *10 +(*str-'0');
		str++;//�ƶ�һλ 
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
	return(str-temp-1);//����Ч*/ 
}

char *strcpy1(char *dest,const char*str){//����char* ������ʽ���� 
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
	//�������
	assert(menTo != NULL); 
	//�׵�ַ����
	char *tempto = (char*)menTo;
	char *tempfrom = (char*)menFrom;
	while(size-- >0){
		*tempTo++ = *tempFrom++;//���Ƶ���ʱ���� 
	} 
	return tempto;
}

const char* findstr(const char* dest,const char *sub){
	int temp;
	if(dest == NULL){
		temp =0;
	}
	const char *de��
	const char* su; 
	while(*dest){
		//�ⲿ������ʵ���ڲ�����
		de = dest;
		su = sub;
		do{
			if(!*sp){
				return dest;
			}
		}
		while(*de++ == *su++);
		dest+=1;//ָ����һ��  ���ڲ�ѭ���������ʱ�� 
	}
	return temp;
} 

//�ַ�����ת 
void  Revstr(char *str){
	char *beg = str, *end = str, *ptr = str;
	//ȫ����ת
	while(*ptr++ != '0'){
		if(*ptr ==''||*ptr =='\0'){
			//�ҵ���һ�����ʣ�����endָ���һ������β��
			end = ptr -1;
			while(start <end){
				swap(*start++,*end--);//���� 
			} 
			//ָ����һ������
			start = end = ptr+1; 
		}
	} //������һ��֮��ptr�Ѿ�ָ�����һ�����ʵ�β�� 
	//startָ��ͷ��endָ��β
	start = str,end = ptr-2;
	while(start<end){
		swap(*start++,*end--);//�����ַ����� 
	} 
} 

//����
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

int result(const char *str1,const char*str2){//1��2��    while(!(ret = *(unsigned char*)str1 -*(unsigned char*)str2 && *str2
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

//��������д�  ʹ���ڲ�ѭ��
char *findmax(char* str1,char *str2) 
{
	char * s1,*s2;
	char *shorte,longe;	
	int i,j,m,n,k;
	//���ҵ���С ��� 
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
		//������� 
		for(int a = 0,b =0,a<strlen(s1);) {
			s2[b++] = s1[a++];
		}
	}
	return s2;
}


//ʮ����ת��2���� ��16 ���� 1


//��ת�ַ��� ָ���Ӵ�����ת  ����ջ 


//��ת�ַ���
char *RevStr(const char*str){//��� �ԼӼ� 
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

//���� ���� 0��1�����ֵ 4.30 

int main(){

	/*int a;
	char t[1024];
	cin >> a;
	int2char(a,t);
	cout << t; */
	
	/*int n=0;
	char p[10] = "";
	cin.getline(p,20);//�Ӽ��̻�ȡ�ַ���*/ 
	/*char p[20];
	const char s[] ="adada";
	strcpy1(p,s);
	cout << p;*/
	
	
	
	
	return 0;
} 
