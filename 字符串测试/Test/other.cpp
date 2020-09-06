#include <iostream>
#include <string>
using namespace std;

/*
进行大小端测试数据
little 大端是高位数据存放低位地址
小段是高位数据存放高位地址
*/


/*
将new出来的赋值给智能指针  auto_ptr  share_ptr(内部引用计数)  unique_ptr   模板在命名空间std里面
#include <memory>
auto_ptr<double> ap(new double);  //其他两个一样的道理  可以把智能指针当作普通指针使用
*ap = 25;
return;//自动释放

share_ptr<double> pd;
dpuble *p = new double;
1.pd = share_ptr<double>(p);
2.share_ptr<double>ps(p);
两种方式都是正确的，，，，，但是不能用在局部变量上面
*/


/*
it1和it2都是迭代器  相当于{it1,it2) 左闭右开

*/


class Node
{
public:
	int data;
	Node* next;
};



//quickSort()

int provite(int arr[], int beg, int end)
{
	int first = beg;
	int last = end;
	int mid = arr[first];
	while (first < last)
	{
		while (first < last)	//从后找小于的进行交换
		{
			if (arr[last] < mid)  break;
			last--;
		}
		if (first < last)
			arr[first++] = arr[last];

		while(first < last)	//从前找大于的进行交换
		{
			if (arr[first] >= mid) break;
			first++;
		}
		if(first < last)
			arr[last--] = arr[first];
	}
	arr[first] = mid;
	return first;
}

void quickSort(int arr[], int beg, int end)
{
	if (beg < 0 || end < 0) return;
	if (beg > end)return;
	int mid = provite(arr, beg, end);
	quickSort(arr, beg, mid - 1);
	quickSort(arr, mid+1, end);
}


class Base
{
public:
	virtual void show() { cout << "base" << endl; }
	virtual void onShow() = 0;
};
class OneBase :public Base
{
public:
	void show() { cout << "oneBase" << endl; }
	void onShow(){}
};

void show(){}

template<typename T>
void show(const T&value)
{
	std::cout << value << endl;
}
//不固定参数列表
template <typename T,typename... Args>
//调用递归 每次都显示一个值  //如何展开参数包
void show(const T& value,const Args&... args)
{
	cout << value << endl;
	show(args...);
}

//函数指针
double bety(int);
double pam(int);

void estime(int lines, double(*pf)(int));

void fun()
{
	int a = 12;
	static int b = 12;
	a++;
	b++;
	printf("%d,%d\n", a, b);
}


//快速排序
void quick_sort(int s[], int l, int r)
{
	if (l < r)
	{
		//Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
				j--;
			if (i < j)
				s[i++] = s[j];

			while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quick_sort(s, l, i - 1); // 递归调用 
		quick_sort(s, i + 1, r);
	}
}
#define MAXSIZE 256
string onDelete(string Des, const string Ori)
{
	if (Des.size() == 0) return nullptr;
	if (Ori.size() == 0) return Des;
	string buf(MAXSIZE,0);
	for (int i = 0; i < Ori.size(); i++)
	{
		buf[Ori[i]]++;
	}
	string result;
	for (int j = 0; j < Des.size(); j++)
	{
		if (buf[Des[j]] == 0) result += Des[j];
	}
	return result;
}
#include <stack>
#include <queue>

void creat(Node *&L)
{
	Node *s;
	L = new Node;
	L->next = NULL;
	for (int i = 1; i <= 6; i++)
	{
		s = new Node;
		s->data = i;
		s->next = L->next;
		L->next = s;
	}
}

void Display(Node *L)
{
	Node *p = L->next;
	while (p!=NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

Node* resver(Node *L, int beg, int end)
{
	stack<Node*>sta;
	queue<Node*>que;
	if (beg > end || beg < 0 ||end < 0)return NULL;
	Node *cur = L->next;
	Node *newHead = L;
	que.push(cur);
	for (int i = 0; i < (beg-1) && cur; i++)
	{   
		que.push(cur->next);
		cur = cur->next;
	}
	for (int j = beg; j < end && cur; j++)
	{
		cur = cur->next;
		sta.push(cur);
	}
	while (!sta.empty())
	{
		Node *temp = sta.top();
		que.push(temp);
		sta.pop();
	}
	cout << endl;
	while (cur != NULL)//剩余的也放在后面
	{
		cur = cur->next;
		if(cur!=NULL)
			que.push(cur);
	}
	Node *node = new Node;
	node->next = NULL;
	while (!que.empty())
	{
		Node *p = new Node;
		p->data = que.front()->data;
		p->next = node->next;
		node->next = p;
		cout << que.front()->data << " ";
		que.pop();
	}
	return NULL;
}

int mainn()
{

	Node *L;
	creat(L);
	Display(L);

	Node* p = resver(L, 2, 4);
	//Display(p);
	
	cout << endl;
	
	string Des("iadafsf");
	string Ori("af");
	string ret = onDelete(Des, Ori);
	cout << endl;
	int arr[] = { 2,1,3,5,4 };
	//quick_sort(arr, 0, 4);
	quickSort(arr, 0, 4);
	cout << endl;
	
	Base *base = new OneBase;
	base->show();
	

	cout << endl;
	
	for (int i = 0; i < 3; i++)
	{
		fun();
	}

	int n = 4;
	double x = 4.4;
	std::string mr = "ssss";
	show(n, x);
	show(x*x, "f", 7, mr);

	cout << endl;

	estime(n, bety);
	estime(n, pam);

	system("pause");
	return 0;
}

double bety(int lns) {
	return 1.0;
}
double pam(int lns)
{
	return 1.0;
}

void estime(int lines, double(*pf)(int))
{
	cout << lines << endl;
	cout << (*pf)(lines) << endl;
}