#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

typedef struct ListNode {
	int data;
	ListNode *next;
}ListNode;
//��������
ListNode *CreatListNode() {
	int i = 0, x = 0;
	ListNode *head, *p, *q;
	head = new ListNode;
	while (1) {
		cout << "�����룺";
		cin >> x;
		if (x == 0)
			break;
		p = new ListNode;
		p->data = x;
		if (++i == 1) {
			head->next = p;//���֮��һ���ڵ� ��ͷ���֮��
		}
		else
		{
			q->next = p;//���ӵ�����β��
		}
		q = p;//qָ��ĩβ�ڵ�
	}
	q->next = NULL;//���һ��ָ��Ϊ��
	return head;
}
//����������
int length(ListNode* head) {
	int len = 0;
	ListNode *p;
	p = head->next;//ͷָ��һ���ǿ�
	while (p != NULL) {//��������
		len++;
		p = p->next;
	}
	return len;
}
//�������ӡ
void PrintListNode(ListNode*head) {
	if (head->data == NULL) {
		return;
	}
	int index = 0;
	ListNode *p = new ListNode;
	p = head->next;
	while (p != NULL) {//��������
		++index;
		cout << index << ":" << p->data;
		p = p->next;
	}
}
//���������
ListNode *FindListNode(ListNode* head, int pos) {
	ListNode *p = new ListNode;
	p = head->next;
	if (pos < 0) {
		return NULL;
	}
	if (pos == 0) {
		return head;
	}
	if (p == NULL) {
		return NULL;
	}
	while (--pos) {
		if ((p = p->next) == NULL) {
			cout << "findcorr";
			break;
		}
	}
	return p;
}
//bool FindListNode(ListNode* head,int value) {
//	bool flag = false;
//	if (head->next == NULL) {
//		flag = false;
//	}
//	ListNode *p = new ListNode;
//	p = head->next;
//	while (p!= NULL)
//	{
//		if (p->data == value) {
//			flag = true;
//		}
//		p = p->next;
//	}
//	return flag;
//}
//���������  ��ĳ��λ�ý��в���  ��β �м�
ListNode *InsertListNode(ListNode *head, int value, int pos) {
	ListNode *p;
	ListNode *newNode = new ListNode;
	newNode->data = value;
	
	if (pos == 0) {
		head->next = newNode;//������β��
		return head;
	}
	p = FindListNode(head, pos);//����λ��
	if (p != NULL) {
		newNode->next = p->next;//�½ڵ�ָ��ԭpos�ڵ�����һ���ڵ�
		p->next = newNode;//���½ڵ���뵽pos����
	}
	return head;
}
//ɾ���ڵ�
ListNode *DeleteListNode(ListNode* head, int pos) {
	ListNode *item = NULL;
	ListNode *p = head->next;
	if (p == NULL) {
		return NULL;
	}
	p = FindListNode(head, pos - 1);//���λ��pos�Ľڵ�ָ��
	if (p != NULL && p->next != NULL) {
		item = p->next;
		p->next = item->next;
		delete item;
	}
	return head;
}
//����������
ListNode *ReverseListNode(ListNode *head) {
	ListNode *p, *q, *r;
	p = head->next;
	q = p->next;
	p->next = NULL;
	while (q!=NULL) {
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	head->next = p;
	return head;
}
//�������м�Ԫ��
ListNode *FindMiddle(ListNode*head) {
	int i = 0, j = 0;
	ListNode *cur = NULL;
	ListNode *mid = NULL;
	cur = mid = head->next;
	while (cur != NULL) {
		if (i / 2 > j) {//�м�����
			j++;
			mid = mid->next;
		}
		i++;
		cur = cur->next;
	}
	return mid;
}
//��������������
ListNode* InsertSort(void) {
	int value = 0;
	ListNode *head = NULL, *New, *Cur, *Pre;
	while (1) {
		cout << "���룺";
		cin >> value;
		if (value == 0) {
			break;
		}
		New = new ListNode;
		New->data = value;
		New->next = NULL;
		if (head == NULL) {
			head = New;
			continue;
		}
		if (New->data <= head->data) {
			//headǰ����
			New->next = head;
			head = New;
			continue;
		}
		Cur = head;
		while (New->data > Cur->data&&Cur->next != NULL) {
			Pre = Cur;
			Cur = Cur->next;
		}
		if (Cur->data >= New->data) {
			Pre->next = New;
			New->next = Cur;
		}
		else {
			Cur->next = New;
		}
	}
	return head;
}
//�������Ƿ���ڻ�-- ��������ָ�룬һ����һ����һ����������������û����ȵ�ʱ��

//��������ϲ�1-3-5   2-4-6  �ϲ���1-2-3-4-5-6  ��Ϊ�������� �ͽ�һ��������뵽��һ��������
ListNode* Insert_node(ListNode* head, ListNode* item) {
	ListNode *p = head;
	ListNode *q = NULL;//һֱָ��pǰ��Ľڵ�
	while (p->data < item->data&&p != NULL) {
		q = p;
		p = p->next;
	}
	if (p == head) {
		item->next = p;
		return item;
	}
	//���뵽 p q֮��
	q->next = item;
	item->next = p;
	return head;
}
//�ϲ�
ListNode* merge(ListNode*head1, ListNode*head2) {
	ListNode *head, *p, *nextp;
	if (head1 == NULL) {
		return head2;
	}
	else if (head2 == NULL) {
		return head1;
	}
	if (length(head1) >= length(head2)) {
		head = head1;
		p = head2;//ѡȡ�϶̵����� ���������
	}
	else {
		head = head2;
		p = head1;
	}
	while (p != NULL) {//ѡ��Ƚ϶̵���һ��ѭ��
		nextp = p->next;//ѭ����������������ڵ��������
		head = Insert_node(head, p);
		p = nextp;
	}
	return head;
}

//���к�ջ queue��stack
//�����Ƚ��ȳ����ֽ�������Ӻͳ��ӣ���ջ�ͳ�ջ��
//���ʵ�ֶ���
typedef struct Queue1 {
	int value;
	Queue1 *next;
}Queue1;
typedef struct _Queue {
	Queue1 *front;
	Queue1 *rear;
}MyQueue;
//�������� ���
MyQueue *CreateQueue() {
	MyQueue *p = new MyQueue;
	p->front = NULL;
	p->rear = NULL;
	return p;//�����ն���
}
MyQueue *InputQueue(MyQueue *q,int value) {
	Queue1 *p = new Queue1;
	p->value = value;
	p->next = NULL;
	if (q->rear == NULL) {
		q->front = q->rear = p;
	}
	else {
		q->rear->next = p;//�½ڵ���뵽����β��
		q->rear = p;
	}
	return q;
}
//��ͷɾ��
MyQueue *DeleteQueue(MyQueue *p){
	Queue1 *q = NULL;
	q = p->front;//ָ���ͷ
	if (q == NULL) {
		cout << "empty";
	}
	else {
		p->front = p->front->next;//��ͷ���
		if (p->front == NULL) {
			p->rear = NULL;//���ֻ��һ���ڵ� ��ɾ����β��㱻�ó�NULL
		}
		free(q);//ɾ��ԭ��ͷ���
	}
	return p;
}
//���г���
int leng(MyQueue* q) {
	Queue1 *p = NULL;
	p = q->front;
	int len = 0;
	if (p == NULL) {
		len = 1;
	}
	while (p!=q->rear)//������β
	{
		++len;
		p = p->next;
	}
	return len;
}
//��ӡ
void PrintQueue(MyQueue *p) {
	Queue1 *q = NULL;
	q = p->front;
	while (q != p->rear) {
		cout << q->value;
		q = q->next;
	}
	cout << q->value;//��ӡβ���ڵ��ֵ
}

//���к�ջ������
//���ֲ�ͬ�����ݽṹ --��������ӳ��ӣ���ջ��ջ��������ʽ��ͬ--��ͷ��β�����Բ�����ֻ�ܶ�ջ������������������ͬ--FIFO��FIRO

//����ʵ��ջ ��ջʵ�ֶ���
//����ʵ��ջ--q1��Ԫ��-��q1������q2ֱ��q1ֻʣһ��Ԫ�������q2����n-1Ԫ��-��q2������q1ֻʣһ��Ԫ�أ�Ȼ������������жϲ�����
//ջʵ�ֶ���--s1��ջ-��s1˳���ջ������s2-��s2��ջ��ʵ���Ƚ��ȳ�

//����ʵ��ջ
class MyData {
public:
	MyData() :data(0), next(NULL) {}
	MyData(int value):data(value),next(NULL){}
	int data;
	MyData *next;
};
class MyStack
{
public:
	MyStack() :top() {}
	void push(MyData data);
	void pop(MyData *pData);
	bool IsEmpty();
	MyData *top;
};
//��--�������ײ�����
void MyStack::push(MyData data) {
	MyData *pData = NULL;
	pData = new MyData(data.data);//�����½ڵ�
	pData->next = top;//��ԭ��ջ���ڵ�����
	top = pData;//ջ���ڵ�Ϊ�½ڵ�
}
//��--�������ײ�ɾ��
void MyStack::pop(MyData *data) {
	if (IsEmpty()) {
		return;
	}
	data->data = top->data;
	MyData *p = top;//��ʱ����ͷ�ڵ�
	top = top->next;
	delete p;
}
//�ж��Ƿ��
bool MyStack::IsEmpty() {
	return(top == NULL);
}

//������ ǰ��-������    ����-�����   ����-���Ҹ�
//���������� ���� ɾ�� ����   ǰ-��-����� �ݹ���ǵݹ�
class Node {
public:
	int data;
	Node *parent;
	Node *left;
	Node *right;
	int tag;//��־λ
public:
	Node() :data(0), parent(NULL), left(NULL), right(NULL) {}
	Node(int num) :data(num), parent(NULL), left(NULL), right(NULL) {}
};
class Tree {
public:
	Tree(int num[], int len);//��������ǰlen��Ԫ��
	void insertNode(int data);
	void deleteNode(int data);
	Node *searchNode(int data);
	//����������
	void InOrderTree();
	void PreOrderTree();
	void LastOrderTree();
	void LeaveTree();
private:
	void insertNode(Node* cur, int data);
	void deleteNode(Node* cur);
	Node *searchNode(Node* cur, int data);
private:
	Node *root;
};
//��ʼ��������
Tree::Tree(int num[], int len) {
	root = new Node(num[0]);
	for (int i = 0; i < len; i++) {
		insertNode(num[i]);
	}
}
//����
void insertNode(Node* cur, int data) {
	return;
}
void Tree::insertNode(int data) {
	Node *p, *par;
	Node *NewNode = new Node(data);
	p = par = root;
	while (p != NULL) {//���Ҳ����Ǹ��ڵ�����
		par = p;
		if (data > p->data) {
			p = p->right;
		}
		else if (data < p->data) {
			p = p->left;
		}
		else if (data = p->data) {//�������ظ��ڵ�
			delete NewNode;
			return;
		}
	}
	NewNode->parent = par;
	if (par->data > NewNode->data) {//�ȸ��ڵ��
		par->left = NewNode;//������ȷλ��
	}
	else {
		par->right = NewNode;
	}
}
//���� �ݹ�
Node *Tree::searchNode(int data) {
	return NULL;
}
Node *Tree::searchNode(Node* cur, int data) {
	//���С�� �ݹ�������
	if (data < cur->data) {
		if (cur->left == NULL)
			return NULL;
		return searchNode(cur->left, data);
	}
	else if (data > cur->data) {
		if (cur->right == NULL) {//��������������� ����NULL
			return NULL;
		}
		return searchNode(cur->right, data);
	}
	//������ ����cur
	return cur;
}
//ɾ��
void Tree::deleteNode(int data) {
	Node * cur = NULL;
	cur = searchNode(data);
	if (cur != NULL) {
		deleteNode(cur);
	}
}
//ɾ���ڵ��Լ��������нڵ�
void Tree::deleteNode(Node* cur) {
	if (cur->left != NULL) {
		deleteNode(cur->left);
	}
	if (cur->right != NULL) {
		deleteNode(cur->right);//ɾ����������
	}
	if (cur->parent == NULL) {
		delete cur;
		root = NULL;
		return;
	}
	//��cur���ڵ���Ӧָ���ÿ�
	if (cur->parent->data > cur->data)
		cur->parent->left = NULL;
	else
		cur->parent->right = NULL;
	delete cur;
}

//�������ǵݹ����
void Tree::InOrderTree() {
	stack<Node *> s;
	Node *p = root;
	while (p != NULL || !s.empty()) {
		while (p != NULL) {
			s.push(p);
			p = p->left;
		}
		if (!s.empty()) {
			p = s.top();//�õ�ջ��
			s.pop();//����ջ��
			cout << p->data;
			p = p ->right;
		}
	}
}
void Tree::PreOrderTree() {
	stack<Node *>s;
	Node* p = root;
	while (p != NULL || !s.empty()) {
		while (p != NULL) {
			cout << p->data;
			s.push(p);
			p = p->left;
		}
		if (!s.empty()) {
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
}
void Tree::LastOrderTree() {//tag��־λ Ϊ0 ��ʾ����������ǰ�ı�����1Ϊ��������������
	stack<Node*>s;
	Node*p = root;
	while (p != NULL || !s.empty()) {
		while (p != NULL) {
			//ѹջ
			s.push(p);
			p = p->left;
		}
		if (!s.empty()) {
			p = s.top();
			if (p->tag) {
				cout << p->data;
				s.pop();
				p = NULL;
			}
			else {
				p->tag = 1;//�޸�tag ָ���ұ� �´α�����������
				p = p->right;
			}
		}
	}
}
//��α���ʹ�ö���
void Tree::LeaveTree() {
	queue<Node*>q;
	Node*ptr = NULL;
	q.push(root);
	while (!q.empty()) {
		ptr = q.front();
		q.pop();
		cout << ptr->data;
		if (ptr->left != NULL) {
			q.push(ptr->left);
		}
		if (ptr->right != NULL) {
			q.push(ptr->right);
		}
	}
}
//�ж�һ���������Ƿ�Ϊ����������  ������������ �Ƿ�����Ϳ���

int main8() {
	//ListNode *head = CreatListNode();
	//cout << length(head);
	//head = InsertListNode(head, 2, 5);

	system("pause");
	return 0;
}