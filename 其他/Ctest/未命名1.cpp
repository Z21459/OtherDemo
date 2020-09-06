#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//输入一个数组和一个数   查找这个数是否在数组中
/*
bool FindNum(int *matrix,int rows,int columns,int number){
	bool found = false;
	if(matrix!=NULL&&rows>0&&columns>0){
		int row=0;
		int column = columns-1;//初始化查询行列
		while(row<rows&&column>=0){
			if(matrix[row*columns+column]==number){//第一行最后一个 
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


//替换字符串空格
/*void ReplaceBlack(char string[],int length){//两个指针 从后往前进行寻址
	if(string ==NULL||length<=0){
		return;
	} 
	int originaL=0;
	int numberB=0;
	int i =0;
	while(string[i]!='\0'){
		++originaL;
		if(string[i]=' ')
			++numberB;//查到总共多少个空格 
		++i;
	}
	//查找到有多少个空格  然后申请新的空间 进行替换存放
	int newL = originaL+numberB*2;//去掉原本的空格，然后添加3个子符，所以增加两个字符大小
	if(newL>length){
		return;
	} 
	int indexO = orignaL;//原始长度 
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
//链表
/*struct ListNode{
	int data；
	ListNode *next； 
};
//添加节点
void addNode(ListNode** pHead,int value){
	ListNode* newNode = new ListNode();
	newNode->data = value;
	newNode->next = NULL;
	if(*pHead==NULL){//判断原链表是否为空 
		*pHead = newNode;
	}
	else{
		ListNode *pNode = *pHead;//如不空  定义头结点   然后依次遍历 直到遇到最后一个节点 
		while(pNode->next!=NULL){
			pNode = pNode->next;
		}
		pNode->next = newNode;//将最后一个节点插入 
	}
} 

//反向打印  利用栈的特性  将链表进行反向输出 
void RevPrint(ListNode*pHead){
	std::stack<ListNode*>p;
	ListNode *head = pHead;
	while(head !=NULL){
		p.push(head);
	}
	while(!p.empty()){
		head = p.top();//弹出栈顶元素
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
