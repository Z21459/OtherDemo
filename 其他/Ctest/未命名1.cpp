#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//����һ�������һ����   ����������Ƿ���������
/*
bool FindNum(int *matrix,int rows,int columns,int number){
	bool found = false;
	if(matrix!=NULL&&rows>0&&columns>0){
		int row=0;
		int column = columns-1;//��ʼ����ѯ����
		while(row<rows&&column>=0){
			if(matrix[row*columns+column]==number){//��һ�����һ�� 
				found =true;
				break; 
			}
			else if(matrix[row*columns+column]>number){
				--column;
			}
			else
			   ++row;
		} 
	}
	return found;
} */


//�滻�ַ����ո�
/*void ReplaceBlack(char string[],int length){//����ָ�� �Ӻ���ǰ����Ѱַ
	if(string ==NULL||length<=0){
		return;
	} 
	int originaL=0;
	int numberB=0;
	int i =0;
	while(string[i]!='\0'){
		++originaL;
		if(string[i]=' ')
			++numberB;//�鵽�ܹ����ٸ��ո� 
		++i;
	}
	//���ҵ��ж��ٸ��ո�  Ȼ�������µĿռ� �����滻���
	int newL = originaL+numberB*2;//ȥ��ԭ���Ŀո�Ȼ�����3���ӷ����������������ַ���С
	if(newL>length){
		return;
	} 
	int indexO = orignaL;//ԭʼ���� 
	int indexN = newL;
	while(indexO>=0&&indexN>indexO){
		if(strign[indexO]==' '){
			string[indexN--]='0';
			string[indexN--]='2';
			string[indexN--]='%';
		}
		else{
			string[indexN--]=string[indexO];
		}
		--indexO;
	}
	
} */
//����
/*struct ListNode{
	int data��
	ListNode *next�� 
};
//��ӽڵ�
void addNode(ListNode** pHead,int value){
	ListNode* newNode = new ListNode();
	newNode->data = value;
	newNode->next = NULL;
	if(*pHead==NULL){//�ж�ԭ�����Ƿ�Ϊ�� 
		*pHead = newNode;
	}
	else{
		ListNode *pNode = *pHead;//�粻��  ����ͷ���   Ȼ�����α��� ֱ���������һ���ڵ� 
		while(pNode->next!=NULL){
			pNode = pNode->next;
		}
		pNode->next = newNode;//�����һ���ڵ���� 
	}
} 

//�����ӡ  ����ջ������  ��������з������ 
void RevPrint(ListNode*pHead){
	std::stack<ListNode*>p;
	ListNode *head = pHead;
	while(head !=NULL){
		p.push(head);
	}
	while(!p.empty()){
		head = p.top();//����ջ��Ԫ��
		printf("%d\t",head->data);
		p.pop(); 
	}
} */
int main(){
    /*int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}}; 
	bool t = FindNum((int*)matrix,4,4,4);
	if(t == true){
		printf("22 ");
	} 
	else{
		printf("11");
	}*/
	
	
	
	
	return 0;
}
