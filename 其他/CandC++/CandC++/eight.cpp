#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

//���ݽṹ
//���� --������--˫����--ѭ������
//ͷָ��head   βָ��rear  ��ǰָ��  ���ָ��next

//p1->p2->p3->NULL ������  p1->p2->p3->p1 ѭ������
//������ �ṹ
typedef struct node {
	int data;
	node *next;//��һ���ڵ�
}node;

node* create() {
	int i = 0;//���ݸ���
	node *head, *p, *q = NULL;
	int x = 0;
	head = (node*)malloc(sizeof(node));//ͷ���
	while (1) {
		cout << "��������";
		cin >> x;
		if (x == 0) {
			break;
		}
		p = (node*)malloc(sizeof(node*));//����һ���½ڵ�
		p->data = x;//�½ڵ㸳ֵ
		if (++i == 1) {//ֻ��һ��Ԫ��
			head->next = p;//��p��ֵ��ͷ����
		}
		else {
			q->next = p;//�������ӵ�����β��
		}
		q = p;//qָ��ĩβ
	}
	q->next = NULL;//���һ��Ϊ��
	return head;
}
//
int len1(node *head) {
	int ret = 0;
	node *p = head->next;
	while (p != NULL) {//��������
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
	return p;//���ʳ���ָ��������
}
node *insert1(node *head, int pos, int data) {
	node *item = NULL;
	node *p;
	item = (node*)malloc(sizeof(node));//�����½ڵ�
	item->data = data;
	if (pos == 0) {
		head->next = item;
		return head;
	}
	p = find1(head, pos);//���ҽڵ�
	if (p != NULL) {
		item->next = p->next;//itemָ��ԭpos�ڵ�ĺ�һ���ڵ�
		p->next = item;//��item���뵽pos��
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
	p = find1(head, pos-1);//���λ��pos�Ľڵ�ָ��
	if (p != NULL && p->next != NULL) {
		item = p->next;
		p->next = item->next;
		delete item;
	}
	return head;
}

//����������
node *rev(node *head) {
	node *p, *q, *r;
	if (head->next == NULL) {
		return head;
	}
	p = head->next;
	q = p->next;//����ڶ����ڵ�
	p->next = NULL;//ԭ��һ���ڵ�Ϊĩ�ڵ�

	while (q != NULL) {
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	head->next = p;//�µĵ�һ���ڵ�Ϊԭĩ�ڵ�
	return head;
}
//�����м�Ԫ��
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
//������������
//���϶������и�Ԫ��������뵽�ϳ���������
node *insert_node(node *head, node *item)//head!=NULL
{
	node*p = head;
	node *q = NULL;//ʼ��ָ��p֮ǰ�Ľڵ�
	while (p->data < item->data&&p != NULL) {
		q = p;
		p = p->next;
	}
	if (p == head) {//���뵽ԭͷ���
		item->next = p;
		return item;
	}
	//���뵽q��p֮��
	q->next = item;
	item->next = p;
	return head;
}
//�ϲ�����
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
		p = head2;//��ȡ�϶̵����� ������ٴ���
	}
	else {
		head = head2;
		p = head1;
	}
	while (p != NULL) {//ѭ�����������е����ݲ��뵽��������
		nextP = p->next;//����p����һ���ڵ�
		head = insert_node(head, p);//��p���뵽Ŀ����
		p = nextP;//ָ��Ҫ�������һ���ڵ�
	}
	return head;
}
int main8() {



	system("pause");
	return 0;
}