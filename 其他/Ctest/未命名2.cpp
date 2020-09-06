#include <stdlib.h>
#include <stdio.h>

/*int StrToInt(const char*Src){
	int number;
	if(Src == NULL){
		number = 0;
	} 
	while(*Src++!=0){
		number = number*10+*Src-'0';
		++Src;//地址加1 
	}
	return number;
}*/

//查找倒数第k个节点
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
		pList = pList->next;//当第一个走了k-1后，第二个开始走   然后第一个走完  第二个刚好走到k 
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
Mystring::Mystring(const Mystring&str){//拷贝构造 
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
Mystring::operator =(const Mystring&str){//赋值构造 
	if(this == &str){
		return NULL;
	}
	delete[]data;
	data = new char(strlen(str.data)+1);
	strcpy(data,str.data);
	return *this;
}*/

//一维数组查找重复数值

int FindDul(int a[]){//先排序 再查找 
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
