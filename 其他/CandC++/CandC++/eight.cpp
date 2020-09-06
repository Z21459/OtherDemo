#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

//数据结构
//链表 --单链表--双链表--循环链表
//头指针head   尾指针rear  向前指针  向后指针next

//p1->p2->p3->NULL 单链表  p1->p2->p3->p1 循环链表
//单链表 结构
typedef struct node {
	int data;
	node *next;//下一个节点
}node;

node* create() {
	int i = 0;//数据个数
	node *head, *p, *q = NULL;
	int x = 0;
	head = (node*)malloc(sizeof(node));//头结点
	while (1) {
		cout << "输入数据";
		cin >> x;
		if (x == 0) {
			break;
		}
		p = (node*)malloc(sizeof(node*));//申请一个新节点
		p->data = x;//新节点赋值
		if (++i == 1) {//只有一个元素
			head->next = p;//将p赋值在头结点后
		}
		else {
			q->next = p;//否则连接到链表尾部
		}
		q = p;//q指向末尾
	}
	q->next = NULL;//最后一个为空
	return head;
}
//
int len1(node *head) {
	int ret = 0;
	node *p = head->next;
	while (p != NULL) {//遍历链表
		ret++;
		p = p->next;
	}
	return ret;
}
//
void printnode(node *head) {
	node *p = head->next;
	if (p == NULL) {
		cout << "node empty";
		return;
	}
	while (p != NULL) {
		cout << p->data;
		p = p->next;
	}
}

node* find1(node*head, int pos) {
	node* p = head->next;
	if (p == NULL) {
		cout << "node empty";
		return NULL;
	}
	if (pos == 0) {
		return head;
	}
	while (--pos) {
		if ((p = p->next) == NULL) {
			cout << "incorrect";
			break;
		}
	}
	return p;//访问超过指定查找数
}
node *insert1(node *head, int pos, int data) {
	node *item = NULL;
	node *p;
	item = (node*)malloc(sizeof(node));//申请新节点
	item->data = data;
	if (pos == 0) {
		head->next = item;
		return head;
	}
	p = find1(head, pos);//查找节点
	if (p != NULL) {
		item->next = p->next;//item指向原pos节点的后一个节点
		p->next = item;//吧item插入到pos后
	}
	return head;
}
//
node *delete1(node *head, int pos) {
	node* item;
	node *p = head->next;
	if (p == NULL) {
		cout << "node empty";
		return NULL;
	}
	p = find1(head, pos-1);//获得位置pos的节点指针
	if (p != NULL && p->next != NULL) {
		item = p->next;
		p->next = item->next;
		delete item;
	}
	return head;
}

//单链表逆置
node *rev(node *head) {
	node *p, *q, *r;
	if (head->next == NULL) {
		return head;
	}
	p = head->next;
	q = p->next;//保存第二个节点
	p->next = NULL;//原第一个节点为末节点

	while (q != NULL) {
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	head->next = p;//新的第一个节点为原末节点
	return head;
}
//查找中间元素
node * findmid(node *head) {
	int i = 0, j = 0;
	node*cur = NULL;
	node*mid = NULL;
	cur = mid = head->next;
	while (cur != NULL) {
		if (i / 2 > j) {
			j++;
			mid = mid->next;
		}
		i++;
		cur = cur->next;
	}
	return mid;
}
//有序单链表排序
//将较短链表中各元素有序插入到较长的链表中
node *insert_node(node *head, node *item)//head!=NULL
{
	node*p = head;
	node *q = NULL;//始终指向p之前的节点
	while (p->data < item->data&&p != NULL) {
		q = p;
		p = p->next;
	}
	if (p == head) {//插入到原头结点
		item->next = p;
		return item;
	}
	//插入到q和p之间
	q->next = item;
	item->next = p;
	return head;
}
//合并两个
node *merge1(node*head1, node*head2) {
	node*head;
	node*p;
	node*nextP;
	if (head1 == NULL) {
		return head2;
	}
	if (head2 == NULL) {
		return head1;
	}
	if (len1(head1) >= len1(head2)) {
		head = head1;
		p = head2;//获取较短的链表 插入较少次数
	}
	else {
		head = head2;
		p = head1;
	}
	while (p != NULL) {//循环将短链表中的数据插入到长链表当中
		nextP = p->next;//保存p的下一个节点
		head = insert_node(head, p);//将p插入到目标连
		p = nextP;//指向将要插入的下一个节点
	}
	return head;
}
int main8() {



	system("pause");
	return 0;
}