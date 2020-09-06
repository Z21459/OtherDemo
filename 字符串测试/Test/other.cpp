#include <iostream>
#include <string>
using namespace std;

/*
���д�С�˲�������
little ����Ǹ�λ���ݴ�ŵ�λ��ַ
С���Ǹ�λ���ݴ�Ÿ�λ��ַ
*/


/*
��new�����ĸ�ֵ������ָ��  auto_ptr  share_ptr(�ڲ����ü���)  unique_ptr   ģ���������ռ�std����
#include <memory>
auto_ptr<double> ap(new double);  //��������һ���ĵ���  ���԰�����ָ�뵱����ָͨ��ʹ��
*ap = 25;
return;//�Զ��ͷ�

share_ptr<double> pd;
dpuble *p = new double;
1.pd = share_ptr<double>(p);
2.share_ptr<double>ps(p);
���ַ�ʽ������ȷ�ģ������������ǲ������ھֲ���������
*/


/*
it1��it2���ǵ�����  �൱��{it1,it2) ����ҿ�

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
		while (first < last)	//�Ӻ���С�ڵĽ��н���
		{
			if (arr[last] < mid)  break;
			last--;
		}
		if (first < last)
			arr[first++] = arr[last];

		while(first < last)	//��ǰ�Ҵ��ڵĽ��н���
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
//���̶������б�
template <typename T,typename... Args>
//���õݹ� ÿ�ζ���ʾһ��ֵ  //���չ��������
void show(const T& value,const Args&... args)
{
	cout << value << endl;
	show(args...);
}

//����ָ��
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


//��������
void quick_sort(int s[], int l, int r)
{
	if (l < r)
	{
		//Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ�������� �μ�ע1
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // ���������ҵ�һ��С��x����
				j--;
			if (i < j)
				s[i++] = s[j];

			while (i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quick_sort(s, l, i - 1); // �ݹ���� 
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
	while (cur != NULL)//ʣ���Ҳ���ں���
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