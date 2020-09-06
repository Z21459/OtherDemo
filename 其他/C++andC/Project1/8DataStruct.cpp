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
//单链表创建
ListNode *CreatListNode() {
	int i = 0, x = 0;
	ListNode *head, *p, *q;
	head = new ListNode;
	while (1) {
		cout << "请输入：";
		cin >> x;
		if (x == 0)
			break;
		p = new ListNode;
		p->data = x;
		if (++i == 1) {
			head->next = p;//如果之后一个节点 在头结点之后
		}
		else
		{
			q->next = p;//连接到链表尾部
		}
		q = p;//q指向末尾节点
	}
	q->next = NULL;//最后一个指针为空
	return head;
}
//测试链表长度
int length(ListNode* head) {
	int len = 0;
	ListNode *p;
	p = head->next;//头指针一般是空
	while (p != NULL) {//遍历链表
		len++;
		p = p->next;
	}
	return len;
}
//单链表打印
void PrintListNode(ListNode*head) {
	if (head->data == NULL) {
		return;
	}
	int index = 0;
	ListNode *p = new ListNode;
	p = head->next;
	while (p != NULL) {//遍历链表
		++index;
		cout << index << ":" << p->data;
		p = p->next;
	}
}
//单链表查找
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
//单链表插入  在某个位置进行插入  首尾 中间
ListNode *InsertListNode(ListNode *head, int value, int pos) {
	ListNode *p;
	ListNode *newNode = new ListNode;
	newNode->data = value;
	
	if (pos == 0) {
		head->next = newNode;//插入在尾部
		return head;
	}
	p = FindListNode(head, pos);//查找位置
	if (p != NULL) {
		newNode->next = p->next;//新节点指向原pos节点后面的一个节点
		p->next = newNode;//将新节点插入到pos后面
	}
	return head;
}
//删除节点
ListNode *DeleteListNode(ListNode* head, int pos) {
	ListNode *item = NULL;
	ListNode *p = head->next;
	if (p == NULL) {
		return NULL;
	}
	p = FindListNode(head, pos - 1);//获得位置pos的节点指针
	if (p != NULL && p->next != NULL) {
		item = p->next;
		p->next = item->next;
		delete item;
	}
	return head;
}
//单链表逆置
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
//单链表中间元素
ListNode *FindMiddle(ListNode*head) {
	int i = 0, j = 0;
	ListNode *cur = NULL;
	ListNode *mid = NULL;
	cur = mid = head->next;
	while (cur != NULL) {
		if (i / 2 > j) {//中间数据
			j++;
			mid = mid->next;
		}
		i++;
		cur = cur->next;
	}
	return mid;
}
//单链表正向排序
ListNode* InsertSort(void) {
	int value = 0;
	ListNode *head = NULL, *New, *Cur, *Pre;
	while (1) {
		cout << "输入：";
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
			//head前插入
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
//单链表是否存在环-- 设置两个指针，一个走一步，一个走两步，看看有没有相等的时候

//有序单链表合并1-3-5   2-4-6  合并成1-2-3-4-5-6  因为链表有序 就将一个链表插入到另一个链表中
ListNode* Insert_node(ListNode* head, ListNode* item) {
	ListNode *p = head;
	ListNode *q = NULL;//一直指向p前面的节点
	while (p->data < item->data&&p != NULL) {
		q = p;
		p = p->next;
	}
	if (p == head) {
		item->next = p;
		return item;
	}
	//插入到 p q之间
	q->next = item;
	item->next = p;
	return head;
}
//合并
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
		p = head2;//选取较短的链表 插入次数少
	}
	else {
		head = head2;
		p = head1;
	}
	while (p != NULL) {//选择比较短的做一个循环
		nextp = p->next;//循环调用输入的两个节点进行排序
		head = Insert_node(head, p);
		p = nextp;
	}
	return head;
}

//队列和栈 queue和stack
//区别：先进先出，现今后出。入队和出队，进栈和出栈。
//编程实现队列
typedef struct Queue1 {
	int value;
	Queue1 *next;
}Queue1;
typedef struct _Queue {
	Queue1 *front;
	Queue1 *rear;
}MyQueue;
//创建队列 入队
MyQueue *CreateQueue() {
	MyQueue *p = new MyQueue;
	p->front = NULL;
	p->rear = NULL;
	return p;//创建空队列
}
MyQueue *InputQueue(MyQueue *q,int value) {
	Queue1 *p = new Queue1;
	p->value = value;
	p->next = NULL;
	if (q->rear == NULL) {
		q->front = q->rear = p;
	}
	else {
		q->rear->next = p;//新节点插入到队列尾部
		q->rear = p;
	}
	return q;
}
//队头删除
MyQueue *DeleteQueue(MyQueue *p){
	Queue1 *q = NULL;
	q = p->front;//指向队头
	if (q == NULL) {
		cout << "empty";
	}
	else {
		p->front = p->front->next;//新头结点
		if (p->front == NULL) {
			p->rear = NULL;//如果只有一个节点 则删除后尾结点被置成NULL
		}
		free(q);//删除原来头结点
	}
	return p;
}
//队列长度
int leng(MyQueue* q) {
	Queue1 *p = NULL;
	p = q->front;
	int len = 0;
	if (p == NULL) {
		len = 1;
	}
	while (p!=q->rear)//不等于尾
	{
		++len;
		p = p->next;
	}
	return len;
}
//打印
void PrintQueue(MyQueue *p) {
	Queue1 *q = NULL;
	q = p->front;
	while (q != p->rear) {
		cout << q->value;
		q = q->next;
	}
	cout << q->value;//打印尾部节点的值
}

//队列和栈的区别
//两种不同的数据结构 --操作名入队出队，进栈出栈；操作方式不同--队头队尾都可以操作，只能对栈顶操作；操作方法不同--FIFO和FIRO

//队列实现栈 和栈实现队列
//队列实现栈--q1进元素-》q1出进入q2直到q1只剩一个元素输出，q2中有n-1元素-》q2出进入q1只剩一个元素，然后输出。反复判断操作。
//栈实现队列--s1进栈-》s1顺序出栈。进入s2-》s2出栈。实现先进先出

//队列实现栈
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
//进--单链表首部插入
void MyStack::push(MyData data) {
	MyData *pData = NULL;
	pData = new MyData(data.data);//生成新节点
	pData->next = top;//与原先栈顶节点连接
	top = pData;//栈顶节点为新节点
}
//出--单链表首部删除
void MyStack::pop(MyData *data) {
	if (IsEmpty()) {
		return;
	}
	data->data = top->data;
	MyData *p = top;//临时保存头节点
	top = top->next;
	delete p;
}
//判断是否空
bool MyStack::IsEmpty() {
	return(top == NULL);
}

//二叉树 前序-根左右    中序-左根右   后续-左右根
//二叉树建立 插入 删除 查找   前-中-后遍历 递归与非递归
class Node {
public:
	int data;
	Node *parent;
	Node *left;
	Node *right;
	int tag;//标志位
public:
	Node() :data(0), parent(NULL), left(NULL), right(NULL) {}
	Node(int num) :data(num), parent(NULL), left(NULL), right(NULL) {}
};
class Tree {
public:
	Tree(int num[], int len);//插入数组前len个元素
	void insertNode(int data);
	void deleteNode(int data);
	Node *searchNode(int data);
	//二叉树遍历
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
//初始化构造树
Tree::Tree(int num[], int len) {
	root = new Node(num[0]);
	for (int i = 0; i < len; i++) {
		insertNode(num[i]);
	}
}
//插入
void insertNode(Node* cur, int data) {
	return;
}
void Tree::insertNode(int data) {
	Node *p, *par;
	Node *NewNode = new Node(data);
	p = par = root;
	while (p != NULL) {//查找插入那个节点下面
		par = p;
		if (data > p->data) {
			p = p->right;
		}
		else if (data < p->data) {
			p = p->left;
		}
		else if (data = p->data) {//不能有重复节点
			delete NewNode;
			return;
		}
	}
	NewNode->parent = par;
	if (par->data > NewNode->data) {//比根节点大
		par->left = NewNode;//插入正确位置
	}
	else {
		par->right = NewNode;
	}
}
//查找 递归
Node *Tree::searchNode(int data) {
	return NULL;
}
Node *Tree::searchNode(Node* cur, int data) {
	//如果小于 递归左子树
	if (data < cur->data) {
		if (cur->left == NULL)
			return NULL;
		return searchNode(cur->left, data);
	}
	else if (data > cur->data) {
		if (cur->right == NULL) {//如果不存在右子树 返回NULL
			return NULL;
		}
		return searchNode(cur->right, data);
	}
	//如果相等 返回cur
	return cur;
}
//删除
void Tree::deleteNode(int data) {
	Node * cur = NULL;
	cur = searchNode(data);
	if (cur != NULL) {
		deleteNode(cur);
	}
}
//删除节点以及子树所有节点
void Tree::deleteNode(Node* cur) {
	if (cur->left != NULL) {
		deleteNode(cur->left);
	}
	if (cur->right != NULL) {
		deleteNode(cur->right);//删除左右子树
	}
	if (cur->parent == NULL) {
		delete cur;
		root = NULL;
		return;
	}
	//将cur父节点相应指针置空
	if (cur->parent->data > cur->data)
		cur->parent->left = NULL;
	else
		cur->parent->right = NULL;
	delete cur;
}

//二叉树非递归遍历
void Tree::InOrderTree() {
	stack<Node *> s;
	Node *p = root;
	while (p != NULL || !s.empty()) {
		while (p != NULL) {
			s.push(p);
			p = p->left;
		}
		if (!s.empty()) {
			p = s.top();//得到栈顶
			s.pop();//弹出栈顶
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
void Tree::LastOrderTree() {//tag标志位 为0 表示遍历左子树前的保护，1为遍历右子树保护
	stack<Node*>s;
	Node*p = root;
	while (p != NULL || !s.empty()) {
		while (p != NULL) {
			//压栈
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
				p->tag = 1;//修改tag 指向右边 下次遍历其左子树
				p = p->right;
			}
		}
	}
}
//层次遍历使用队列
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
//判断一个二叉树是否为二叉排序树  对树进行中序 是否有序就可以

int main8() {
	//ListNode *head = CreatListNode();
	//cout << length(head);
	//head = InsertListNode(head, 2, 5);

	system("pause");
	return 0;
}