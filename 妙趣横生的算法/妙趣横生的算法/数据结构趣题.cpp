#include"allHead.h"
#include<conio.h>
#include <windows.graphics.h>

/*
多用数据结构 提高编程水平 和解决问题的能力
1.顺序表逆置
2.动态数组排序  选择方式 --链表   --链表指针交换 可以多设置几个指针  用以交换使用
3.原表空间 进行归并
4.约瑟夫问题  创建一个循环链表
5.二进制 转八进制
6.判断回文 ---可以用一个链表 一个队列
7.括号匹配问题 
8.判断二叉树是否是完全二叉树
9.打印特殊三角形
10.使用字符串来计算任意长度的整数相加  使用栈 两个输入的栈(加法从低位开始)  一个输出的栈


*/

//顺序表逆置
void onShunXuResever()
{
	int arr[5] = { 1,2,3,4,5 };
	int temp = 0;
	int len = (sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < len /2; i++)
	{
		temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
	}
	for (int i = 0; i < len ; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
//动态数组排序  链表
struct ListNode
{
	int data;
	ListNode *next;
};
void onSortList(ListNode *head);
void onCreateList()
{
	//带头结点的
	ListNode *head = new ListNode;
	ListNode *p = head;
	head->next = NULL;
	//尾插入
	int i = 0;
	for (i = 1; i < 5; i++)
	{
		ListNode *newNode = new ListNode;
		if (newNode)
		{
			newNode->data = rand()%4 + 1;
			newNode->next = NULL;
		}
		head->next = newNode;
		head = newNode;
	}
	onSortList(p);
	//p = p->next;//先指向第一个节点  尾部添加
	//while (p != NULL)
	//{
	//	cout << p->data << endl;
	//	p = p->next;
	//}

	////头部插入

	//for (i = 1; i < 5; i++)
	//{
	//	ListNode *newNode = new ListNode;
	//	if (head->next == NULL)
	//	{
	//		if (newNode)
	//		{
	//			newNode->data = i;
	//			newNode->next = NULL;
	//		}
	//		head->next = newNode;
	//	}
	//	else
	//	{
	//		ListNode * p = head->next;//指向第一个
	//		if (newNode)
	//		{
	//			newNode->data = i;
	//		}
	//		newNode->next = p;
	//		head->next = newNode;
	//	}
	//}
	//p = p->next;//先指向第一个节点  尾部添加
	//while (p != NULL)
	//{
	//	cout << p->data << endl;
	//	p = p->next;
	//}

	//中间插入 //先循环找到这个值，声明两个指针，记录当前插入的前一个节点 和后一个节点


}
//对链表进行排序 改变指针的指向
void onSortList(ListNode *head)
{
	ListNode *p, *q, *tail;
	tail = NULL;
	while ((head->next->next) != tail)
	{
		p = head;
		q = head->next;//第一个节点
		while (q->next != tail)//第二个节点不为NULL
		{
			if ((q->data) > (q->next->data))//第一个节点和第二个节点比较  2431
			{
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = q;
				q = p->next;
			}
			q = q->next;
			p = p->next;
		}
		tail = q;
	}
	p = head->next;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}
//合并两个链表 --主要思路是将一个链表的每个值 插入到另一个链表中
ListNode *onInsertList(ListNode *head, ListNode *insert)
{
	//insert 只有一个节点  看节点插入的位置  头 尾 中间
	ListNode *p = head->next;
	ListNode *q = NULL;
	while (p->data < insert->data && p!=NULL)
	{
		q = p;//记录插入前一个节点
		p = p->next;
	}
	if (p == NULL)//头插入
	{
		head->next = insert;
		insert->next = NULL;
		return head;
	}
	//插入p q中间
	q->next = insert;
	insert->next = p;
	return head;

}
void onMergeTwoList(ListNode *lsh1, ListNode *lsh2)
{
	ListNode *l1 = lsh1;
	ListNode *l2 = lsh2;
	ListNode *head,*nextHead;
	int count1 = 0, count2 = 0;
	if (l1->next == NULL) return;//返回不为空的链表
	if (l2->next == NULL) return;
	while (l1->next!=NULL)
	{
		count1++;
		l1 = l1->next;
	}
	while (l2->next != NULL)
	{
		count2++;
		l2 = l2->next;
	}
	if (count1 > count2)
	{
		head = lsh1;
		nextHead = lsh2;
	}
	else
	{
		head = lsh2;
		nextHead = lsh1;
	}
	//短的往长的进行插入
	//循环插入
	//ListNode *p = head->next;
	//ListNode *q = nextHead->next;//分别指向第一个节点
	ListNode *nextP;
	while(nextHead != NULL)
	{
		nextP = nextHead->next;
		head = onInsertList(head, nextP);
		nextHead = nextP;
		//if (p->data > q->data)//第一个节点比较
		//{
		//	//p->next = q->next;
		//	//q->next = p;
		//	//q = p;
		//	//p = p->next;
		//}
		//else
		//{
		//	//q->next = p->next;
		//	//p->next = q;
		//	//p = q;
		//	//q = q->next;
		//}
	}

	//返回head
}
//创建循环链表
void onCreateCricleList()
{
	ListNode *head = new ListNode;
	head->next = NULL;
	ListNode *newNode,*p = head;
	int i = 0; 
	for (i = 1; i < 5; i++)
	{
		newNode = new ListNode;
		newNode->data = i;
		head->next = newNode;
		head = newNode;
	}
	head->next = p->next;
	int m = 3;
	ListNode *q = NULL, *r = NULL;
	for (int i = 0; i < 20; i++)
	{
		if (!m--)
		{
			q = p;
			cout << p->data;
			r->next = p->next;
			p = r->next;
			delete q;
			m = 3;
		}
		//cout << p->next->data;
		else
		{
			r = p;//记住要删除的前一个
			p = p->next;
			if (p == r)
			{
				cout << " 最后剩余： " << p->data;
				break;
			}
		}
		
	}
}
//二进制转八进制  最简单利用栈的技术
void onTwoToEight()
{
	string str = "1010";//10 换成八进制 12  先转10进制 再转8进制
	int len = str.length();//字符串长度
	int i = 0, sum = 0;
	for (i = 0; i < len; i++)//2->10
	{
		sum = sum + (int)pow(2, i) * (str[len - i - 1]-'0');//字符转数字 -‘0’
	}
	cout << str << " -> "<< sum << endl;
	//10->8
	stack<char> st;
	while (sum)
	{
		st.push((sum % 8) + '0');
		sum /= 8;
	}
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}
//括号匹配问题--栈数据结构 最内层开始
bool onIsMatch(char l, char r)
{
	if (l == '(' && r == ')') return true;
	if (l == '['&&r == ']')return true;
	return false;
}
void onKuoHao()
{
	string str = "[((])])";//"[[()][]()]"
	stack<char> st;
	int len = str.length();
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (str[i] != '(' || str[i] == ')' ||
			str[i] != '['&&str[i] != ']')
		{
			cout << "Error \n";
			return;
		}
		if (st.empty())
		{
			st.push(str[i]);
		}
		else
		{
			char temp = st.top();
			st.pop();
			if (!onIsMatch(temp, str[i]))
			{
				st.push(temp);
				st.push(str[i]);
			}
		}
	}
	if (st.empty()) cout << "匹配\n";
	else cout << "不匹配\n";
}
//打印特殊三角形
void onSize(string &str, int &len)
{
	string temp = "";
	for (int i = 0; i < len - 1; i++)
	{
		if (str[i] == str[i + 1])
		{
			temp += '+';
		}
		else
		{
			temp += '-';
		}
	}
	int t_len = temp.length();
	str = temp;
	len = t_len;
}
void onPrintTri(string str)
{
	//string str = "++-+-++";
	int len = str.length();
	vector<char> vec;
	for (int i = 0; i < len; i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;
	while (len >1)
	{
		onSize(str, len);
		for (int i = 0; i < len; i++)
		{
			cout << str[i] << " ";
		}
		cout << endl;
	}
	cout << str[0];
	/*if(len == 1)
	for (int i = 0; i < len-1; i++)
	{
		if (str[i] == str[i + 1])
		{
			vec.push_back('-');
		}
		else
		{
			vec.push_back('+');
		}
	}
	if (vec.size() == 1)//只有一个了  退出
		cout << vec[0];*/

}




int mainq()
{

	//onShunXuResever();
	//onCreateList();
	//onCreateCricleList();

	//onTwoToEight();
	//onKuoHao();
	//string str;//
	//cin >> str;
	//onPrintTri(str);


	system("pause");
	return 0;
}