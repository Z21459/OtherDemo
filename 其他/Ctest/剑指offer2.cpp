//�߳� ͬ����

//�������ظ����ֵ�����

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;


/*bool dulFind(int a[],int* dul){
	int len = sizeof(a)/sizeof(a[0]);
	for(int i = 0;i<len;i++){
		while(a[i]!=i){
			if(a[i] == a[a[i]]){
				*dup = a[i];
				return true;
			}
			int temp = a[i];
			a[i] = a[temp];
			a[temp] = temp;
		}
	}
	return false;
}*/
//Ҳ�������ö��ַ�  ������ظ�   �����߳���һ��������һ�������ظ� 


//�Ӷ�ά�����в���   �������ڲ�����
//  ����������˳���  �����Ͻ� ��ʼ ��������ڣ����м�һ  �����м�һ 



//�滻�ո� �������ز��ҿո� Ȼ�����׸��µĿռ� �����ո��� 
/*
char RsplNULL(const char*Dest){
	int NUllNum = 0;
	while(*Desp){
		if(*Dest++ == ' '){
			NULLNum++;
		}
	}
	int len = strlen(Dest)+NUllNum*2;//�¿ռ䳤�� 
	char *res = new char[len+1];
	int start=strlen(Dest),end=len;
	for(int i = 0;i<len;i++){
		if(Dest[start] == ' '){
			Dest[end--]='0';
			Dest[end--]='2';
			Dest[end--]='%';
		}
		else{
			Dest[end--]=Dest[start];
		}
		--start;
	} 
	 
}*/
/*
 struct ListNode{
 	int data;
	ListNode *next; 
 } ;
 //���
 void addTail(ListNode **pHead,int value){
 	
 	ListNode*New = new ListNode();
 	New->data = value;
 	New->next = NULL;
 	
 	if(*pHead == NULL){
 		*pHead = New;
	 }
	 else{
	 	while(*pHead){
	 		*pHead = *pHead->next;
		 }
	 	New = *pHead->next;
	 }
 } */
 
 class A{
 	public:
 		A() {dos();}
		 virtual void dos(){
		 	printf("aa1");
		 }
 };
 class B : public A{
 	public:
 		B(){dos();
		 }
 		virtual void dos(){
 			printf("bbb");
		 }
 };
 
  

int main()
{
	//int a[] = {1,2,3,2,1,4,1};

    /*char str[] = "hello";
    char *s = "hello";
    int a[] = {3, 5, 7};
    printf("%d\n%d\n%d\n", sizeof(str), sizeof(s), sizeof(a));//���6�� 4�� 12
    return 0;*/
    B b;
    b.dos();
    return 0;

 } 
