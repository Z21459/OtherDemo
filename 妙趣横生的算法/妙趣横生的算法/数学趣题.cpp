#define _CRT_SECURE_NO_WARNINGS
#include"allHead.h"


/*
1.输入字符串 将连续多个空格合并成1个
2.输出一组数的最大值 和次大值
3.翻转字符串
4.字符串连接
5.递归返回数组中最大值
6.根据输入的小写字母  交替输出大小写 abc AaBaCc
7.五中水果，每个果盘3中水果 ，总共多少种，穷举法
8.求整数 加100 加168 完全平方
9.整数转字符串
10.字符串拷贝
11.字符串移动
12.统计一个字符串中的单词数
13.一个字节多少位被置成1  用位运算符号&和1进行计算 ，如果是1结果为1 ，反之为0；也利用>>
*/
//消除连续空
void inputString()
{
	char c, last = 'a';
	c = getchar();
	while (c!=EOF)//结束符
	{
		if (c != ' ')
		{
			putchar(c);//输出
			last = c;
			c = getchar();//再次输入
		}
		else
		{
			if (last != ' ')
				putchar(c);
			last = c;//上一个字符串的值
			c = getchar();
		}
	}
}
//最大和次大 ---边输入便判断
void onFindValue()
{
	int a, max = -1000, min = -1000, i;//设置成-1000 保证绝对小的值
	for (i = 0; i <= 10; i++)
	{
		scanf_s("%d", &a);
		if (a > max)
		{
			min = max;
			max = a;
		}
		else
		{
			if (a > min)
				min = a;
		}
	}
}
//翻转字符串
void reverse(char *str)
{
	if (str == NULL) return;
	char* start = str;
	char* end = str;
	while (*end !='\n')
	{
		end++;
	}
	end--;//指向单词的最后一个字符
	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++, end--;
	}
	//int len = strlen(str) - 1,i=0,char t;
	//for (;i != len && i < len;i++,len--)
	//{
	//	t = str[i];
	//	str[i] = str[len];
	//	str[len] = t;
	//}
}
//字符换连接
char* strcont(char *s1, char *s2)
{
	if (s1 == nullptr)  return s2;
	if (s2 == nullptr)return s1;
	char *tmp = new char[strlen(s1) + strlen(s2) + 1];
	strcpy_s(tmp, strlen(s1),s1);
	int i = 1;
	while (*s2 != '\n')
	{
		tmp[strlen(s1) + i] = *s2;
		i++,s2++;
	}
	tmp[i] = '\n';
	return tmp;
}
//递归返回数组中最大值
int rMaxValue(int arr[],int n)
{
	if (n == 0) return 0;
	if (n == 1) return arr[0];
	if (arr[0] >= rMaxValue(arr + 1,n-1)) return arr[0];
	else
		return rMaxValue(arr + 1,n-1);
}
//交替输出大小写
char* writeBigSmall(const char *str)
{
	char *result = new char[2 * strlen(str) + 1];
	int i = 0;
	while (*str != '\n')
	{
		result[i++] = *str -'a'+'A';
		//printf("%c", *str - 'a' + 'A');
		result[i++] = *str;
		str++;
	}
	result[i] = '\n';
	//printf("%s", result);
	return result;
}
//求整数 完全平方
int resSqre()//穷举法 在范围内查找
{
	double x, y;
	for (int i = 1; i < 65535; i++)
	{
		x = sqrt(i + 100);
		y = sqrt(i + 168);
		if (x*x == i + 100 && y*y == i + 168)
			return i;
	}
	return -1;
}
//整数转字符串
char *intTOstr(int a)
{
	bool flagFu = false;
	if (a < 0)
	{
		a = abs(a);
		flagFu = true;
	}
	char temp;
	char *res = new char[5];//申请空间 要根据位数
	int i = 0;
	if (flagFu)res[i++] = '-';
	while (a)
	{
		temp = a % 10 + '0';//转字符串
		res[i++] = temp;
		a = a / 10;
	}
	res[i] = '\0';
	printf("%s", res);
	return res;
}
//字符串复制
void copyStr(char *des, const char *ori)//不修改原字符串
{
	if (ori == nullptr) return;
	int i = 0;
	while (*ori != '\0')
	{
		des[i++] = *ori;
		ori++;
	}
	des[i] = '\0';//添加结束标识符
}
//字符串移动
void moveStr(const char *str, int n)
{
	char *tmp = new char[strlen(str) + 1];
	int j = 0;
	for (int i = n; i < strlen(str); i++)
	{
		tmp[j++] = str[i];
	}
	for (int i = 0; i < n; i++)
	{
		tmp[j++] = str[i];
	}
	tmp[j] = '\0';
	printf("%s", tmp);
}
//统计一个字符串的单词数
int latNumber(const char *str)
{
	int i, count = 0, flag;
	char *p = const_cast<char*>(str);//强制转换
	while (*p!='\0')
	{
		if ((*p >= 'A'&&*p <= 'Z') || *p >= 'a'&&*p <= 'z')//区间字母
			flag = 1;
		else
			flag++;
		if (flag == 2)//刚好为1个单词
			count++;
		p++;
	}
	return count;
}
//计算一个字节多少倍置成1
int oneCount(unsigned char c)
{
	int count = 0;
	int i = 0;
	unsigned char tmp = (0x1 << 7);//一个字节8位  最高位置成1
	for (int i = 0; i < 8; i++)
	{
		if ((c&tmp) != 0)
			count++;
		tmp = tmp >> 1;//次高位为1 
	}
	return count;
}

class A
{
public:
	virtual void f() { cout << "a"; }
	~A() { cout << "~A"; }
};
class B :public A
{
public:
	void f() { cout << "b"; }
	virtual ~B() { cout << "~B"; }
};
class C :public A
{
public:
	void f() { cout << "c"; }
	~C() { cout << "~C"; }
};

class MyString
{
public:
	MyString(const char *str = NULL);//赋值
	~MyString(void);
	MyString(const MyString &other);//复制
	MyString &operator=(const MyString &other);
private:
	char *m_data;
};
MyString::MyString(const char *str)
{
	if (str == NULL)
	{
		m_data = new char[1];//只复制1个值
		*m_data = '\0';
	}
	else
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}

}
MyString::~MyString(void)
{
	if (m_data != NULL)
		delete []m_data;
	m_data = NULL;//防止成为野指针
}
MyString::MyString(const MyString&other)
{
	if (other.m_data == NULL)
	{
		return;
	}
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);
}

MyString& MyString::operator=(const MyString &other)
{
	if (&other == this) return *this;
	delete[]m_data;
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);
	return *this;
}

//二叉树的遍历  前 中  后  层
struct Tree
{
	int value;
	Tree *left;
	Tree *right;
};
//前
void pre(Tree *root)
{
	if (root == NULL) return;
	cout << root->value;
	pre(root->left);
	pre(root->right);
}
void feiPre(Tree *root)
{
	if (root == NULL) return;
	stack<Tree*>s;
	Tree *cur, *top;
	cur = root;
	while (cur!=nullptr || !s.empty())
	{
		while (cur!=NULL)
		{
			cout << cur->value;
			s.push(cur);
			cur = cur->left;
		}
		top = s.top();//访问右孩子
		s.pop();
		cur = top->right;
	}
}
//中
void mid(Tree *root)
{
	if (root == NULL) return;
	mid(root->left);
	cout << root->value;
	mid(root->right);
}
void feiMid(Tree *root)
{
	if (root == NULL) return;
	stack<Tree*>s;
	//左根右
	Tree *cur ,*top;
	cur = root;
	while (cur != NULL||!s.empty())
	{
		while (cur!=nullptr)
		{
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		s.pop();
		cout << cur->value;
		cur = cur->right;
	}
}
//后
void hou(Tree *root)
{
	if (root == NULL) return;
	mid(root->left);
	mid(root->right);
	cout << root->value;
}
void feiHou(Tree *root)
{
	if (root == NULL) return;
	stack<Tree*>s;
	Tree *cur, *top, *last = NULL;
	cur = root;
	while (cur!=nullptr || !s.empty())
	{
		while (cur!=NULL)
		{
			s.push(cur);
			cur = cur->left;
		}
		top = s.top();
		if (top->right == NULL || top->right == last)
		{
			s.pop();
			cout << top->value;
			last = top;
		}
		else
		{
			cur = top->right;
		}
	}
}
//层
void ceng(Tree *root)
{
	if (root == NULL) return;
	queue<Tree *> q;
	Tree *cur;
	q.push(root);
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		if (cur->left != NULL)
			q.push(cur->left);
		if (cur->right != NULL)
			q.push(cur->right);
		cout << cur->value;
	}
}

//写一个多态 
class Squre
{
public:
	virtual void Area() = 0;
	void fun1(int a){}
};
class Cricl :public Squre
{
public:
	Cricl(int a, int b) { m_a = a, m_b = b; }
	void Area() { cout << m_a * m_b; }
	void fun1(double a) {}//编译时多态  重载 函数名相同 参数不同  根据输入自动选择
private:
	int m_a;
	int m_b;
};
class Rect :public Squre
{
public:
	Rect(int a, int b) :m_a(a), m_b(b){}
	void Area() { cout << 2 * m_a*m_b; }
private:
	int m_a;
	int m_b;
};

void setString()
{
	typedef set<string*> SetStr;
	SetStr set_str;
	set_str.insert(SetStr::value_type(new string("wang")));
	set_str.insert(SetStr::value_type(new string("li")));
	set_str.insert(SetStr::value_type(new string("zhao")));
	for (SetStr::iterator it = set_str.begin(); it != set_str.end(); it++)
	{
		cout << *(*it);//取二级指向
	}
}

bool resver(const char *str)
{
	if (str == NULL) return false;
	char *temp = new char[strlen(str)];
	strcpy(temp,str);
	char *begin = temp;
	char *end;
	int i = 0;
	//while (*temp !='\0')
	//{
	//	cout << *temp++;//[i++]
	//}
	//cout << endl;
	/*"abcde"*/
	int len = strlen(str);
	for (int i = 0; i < len/2; i++)
	{
		int t = temp[i];
		temp[i] = temp[len - i - 1];
		temp[len - i - 1] = t;
	}
	while (*temp !='\0')
	{
		cout << *temp++;//[i++]
	}
	
	return true;
}

int mainb()
{
	//char* res = writeBigSmall("abc");
	//while (*res!='\n')
	//{
	//	cout << *res;//输出字符
	//	res++;
	//}

	//intTOstr(-123);
	//moveStr("abcd", 2);

	//B b;
	//A &a = b;
	//a.f();
	//b.f();
	//A *a1 = new A;
	//B *b1 = new B;
	//C *c1 = new C;
	//delete a1;
	//delete b1;// 析构b a
	//delete c1; //析构c a

	//Rect rect(1, 2);
	//Cricl cri(1, 2);
	//Squre *s[2];
	//s[0] = &rect;
	//s[1] = &cri;
	//s[0]->Area();
	//s[1]->Area();

	//setString();
	//char a[] = { 'a','b' };
	//const char a[] = "aaa";
	//cout << strlen(a) << " " << sizeof(a);//strlen不带\0  sizeof带\0 3 4

	resver("abcde");

	system("pause");
	return 0;
}