#include <stdlib.h>
#include <stdio.h>

/*int StrToInt(const char*Src){
	int number;
	if(Src == NULL){
		number = 0;
	} 
	while(*Src++!=0){
		number = number*10+*Src-'0';
		++Src;//��ַ��1 
	}
	return number;
}*/

//���ҵ�����k���ڵ�
/*
ListNode *Findknode(ListNode *pListHead,unsigned int k){
	if(pListHead == NULL){
		return NULL;
	}
	ListNode *pHead = pListHead;
	ListNode *pLast = NULL;
	for(unsigned int i = 0;i<k-1;i++){
		pHead = pHead->next;
	}
	pList = pListHead;
	while(pHead->next!=NULL){
		pHead = pHead->next;
		pList = pList->next;//����һ������k-1�󣬵ڶ�����ʼ��   Ȼ���һ������  �ڶ����պ��ߵ�k 
	}
	return pList;
} */

/*
class Mystring{
	public:
		Mystring(char * data = NULL);
		Mystring(const Mystring&str);
		~Mystring(void);
		Mystring& operator = (const Mystring&str);
	private:
		char* data;
}; 

Mystring::Mystring(char *data){
	if(data == NULL){
		data = new char[1];
		data = '\0';
	}
}
Mystring::Mystring(const Mystring&str){//�������� 
	if(data!=NULL){
		data = NULL;
		data = new char[strlen(str.data)+1];
		strcpy(data,str.data);
	}
}
Mystring::~Mystring(void){
	if(data!=NULL){
		delete[]data;
		data = NULL;
	}
}
Mystring::operator =(const Mystring&str){//��ֵ���� 
	if(this == &str){
		return NULL;
	}
	delete[]data;
	data = new char(strlen(str.data)+1);
	strcpy(data,str.data);
	return *this;
}*/

//һά��������ظ���ֵ

int FindDul(int a[]){//������ �ٲ��� 
	int result=0;
	for(int i = 0;i<sizeof(a)/sizeof(int);i++){
		for(int j = i+1;j<sizeof(a)/sizeof(int);j++){
			if(a[i] == a[j]){
				//d.push_back(a[i]);
				result++;
				break;
			}
		}
	}
	return result;
} 
 
int main()
{
	//const char*a= "abc";
	//int c = StrToInt(a);
	//printf("%d",c);
	int c[] = {1,2,3,2,4,1};
	int w = FindDul(c);
	printf("%d",w);
	
	return 0;
 } 
