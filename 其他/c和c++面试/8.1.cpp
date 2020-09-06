#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

//实现单链表
struct Node{
	int data;
	Node* next; 
}; 

void creatNode(Node* head){
	Node * p = head;
	for (int i =0;i<10;i++){
		Node *pNew = new Node;
		pNew->data =i;
		pNew->next = NULL;
		p->next = pNew;
		p = pNew;
	}
} 

int len(Node* head){
	int leng =0;
	Node *p = head;
	p = p->next;
	while(p!=NULL){
		leng++;
		p = p->next;
	}
	cout << leng;
	return leng;
}

void print(Node *head){
	Node *p =head;
	if(p == NULL){
		cout <<"noo";
	}
	p = p->next;
	while(p!=NULL){
		cout << p->data;
		p = p->next;
	}
	return;
}
Node *search(Node *head,int data){
	Node *p = head;
	if(head->next == NULL){
		cout << "nll";
		return NULL;
	}
	p = p->next;
	while(p!=NULL){
		if(p->data == data){
			cout <<"cc";
			break;
		}
		p = p->next;
	}	return p;
}

Node *insert(Node *head,int a){
	Node* p = head;
	p = p->next;
	Node *pNew = new Node;
	pNew->data = a;
	//pNew->next =NULL;
	if(head->next == NULL){
		head = pNew;//头结点 
	}
	while(p!=NULL){
		p = p->next;
	}
	p->next = pNew;//插入到尾部 
	p = pNew;
	return head;
}
void deletNode(Node* head,int a){
	Node*p = head;
	Node *temp = NULL;
	if(head->data == a){
		delete head;
		head = NULL;
	}
	else{
		while(p!=NULL){
			if(p->data == a){
				temp = p->next;
				p->next = temp->next; 
				delete temp;
				cout << "ok";
				break;
			}
			p = p->next;
		}
	}
} 
 Node* rev(Node*head) {//辅助指针
 	Node*p,*q,*r;
 	if(head->next == NULL){
 		return head;
	 }
	 p = head->next;
	 q = p->next;//保存第二个
	 p->next = NULL;//原来第一个是空
	 
	 while(q!=NULL){
	 	r = q->next;
	 	q->next = p;
	 	p = q;
	 	q =r;
	 } 
	 head->next =p;
	 return head;
}
//查找中间节点
Node *findMid(Node*head){
	int i =0,j =0;
	Node *cur = NULL,*mid =NULL;
	cur = mid =head->next;
	while(cur!=NULL){
		if(i/2>j){
			j++;
			mid = mid->next;
		}
		i++;
		cur = cur->next;
	}
	return mid;
} 

//单链表 循环设置两个指针 一个走一步 一个走两步
int finh(Node *head){
	int found;
	Node *p,*q;
	Node *start = NULL;
   	p = q = head;
   	p = p->next;//走一步 
   	q = q->next->next;//走两步 
   	while(p!=NULL && q!=NULL){
   		if(p->data == q->data){
   			start = p;
   			found =1;
		   }
		else{
			found =0;
		}
		p = p->next;
		q = q->next;
	   } 
	return 0;
} 
//两个链表连接 顺序
//递归
Node *Mer(Node* head1,Node *head2){
	Node*head =NULL;
	if(head1 ==NULL){
		return head2;
	}
	if(head2 ==NULL){
		return head1;
	}
	if(head1->data < head2->data){
		head =head1;
		head->next = Mer(head1->next,head2);
	}
	else{
		head =head2;
		head->next = Mer(head1,head2->next);
	}
	return head;
} 

//约瑟夫问题，循环链表 删除 单循环链表 

struct BTree{
	BTree *left;
	BTree *right;
	int value;
};

//二叉树遍历 递归
//前序
void PreOrderTree(){
	if(root == NULL)
		return;
	PreOrderTree(root)
}
void PreOrderTree(BTree *cur){
	if(cur != NULL){
		cout << cur->value;
		PreOrderTree(cur->left);
		preOrderTree(cur->right);
	}
} 
int main(){
	Node *head =NULL;
	head = new Node;
	head->data =0;
	head->next = NULL;
	creatNode(head);
	//len(head);
	print(head);
	print(rev(head));
	//Node*p = search(head,11);
	//deletNode(head,5);
	
	return 0;
} 
