#define _CRT_SECURE_NO_WARNINGS
#include"allHead.h"


/*
1.�����ַ��� ����������ո�ϲ���1��
2.���һ���������ֵ �ʹδ�ֵ
3.��ת�ַ���
4.�ַ�������
5.�ݹ鷵�����������ֵ
6.���������Сд��ĸ  ���������Сд abc AaBaCc
7.����ˮ����ÿ������3��ˮ�� ���ܹ������֣���ٷ�
8.������ ��100 ��168 ��ȫƽ��
9.����ת�ַ���
10.�ַ�������
11.�ַ����ƶ�
12.ͳ��һ���ַ����еĵ�����
13.һ���ֽڶ���λ���ó�1  ��λ�������&��1���м��� �������1���Ϊ1 ����֮Ϊ0��Ҳ����>>
*/
//����������
void inputString()
{
	char c, last = 'a';
	c = getchar();
	while (c!=EOF)//������
	{
		if (c != ' ')
		{
			putchar(c);//���
			last = c;
			c = getchar();//�ٴ�����
		}
		else
		{
			if (last != ' ')
				putchar(c);
			last = c;//��һ���ַ�����ֵ
			c = getchar();
		}
	}
}
//���ʹδ� ---��������ж�
void onFindValue()
{
	int a, max = -1000, min = -1000, i;//���ó�-1000 ��֤����С��ֵ
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
//��ת�ַ���
void reverse(char *str)
{
	if (str == NULL) return;
	char* start = str;
	char* end = str;
	while (*end !='\n')
	{
		end++;
	}
	end--;//ָ�򵥴ʵ����һ���ַ�
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
//�ַ�������
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
//�ݹ鷵�����������ֵ
int rMaxValue(int arr[],int n)
{
	if (n == 0) return 0;
	if (n == 1) return arr[0];
	if (arr[0] >= rMaxValue(arr + 1,n-1)) return arr[0];
	else
		return rMaxValue(arr + 1,n-1);
}
//���������Сд
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
//������ ��ȫƽ��
int resSqre()//��ٷ� �ڷ�Χ�ڲ���
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
//����ת�ַ���
char *intTOstr(int a)
{
	bool flagFu = false;
	if (a < 0)
	{
		a = abs(a);
		flagFu = true;
	}
	char temp;
	char *res = new char[5];//����ռ� Ҫ����λ��
	int i = 0;
	if (flagFu)res[i++] = '-';
	while (a)
	{
		temp = a % 10 + '0';//ת�ַ���
		res[i++] = temp;
		a = a / 10;
	}
	res[i] = '\0';
	printf("%s", res);
	return res;
}
//�ַ�������
void copyStr(char *des, const char *ori)//���޸�ԭ�ַ���
{
	if (ori == nullptr) return;
	int i = 0;
	while (*ori != '\0')
	{
		des[i++] = *ori;
		ori++;
	}
	des[i] = '\0';//��ӽ�����ʶ��
}
//�ַ����ƶ�
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
//ͳ��һ���ַ����ĵ�����
int latNumber(const char *str)
{
	int i, count = 0, flag;
	char *p = const_cast<char*>(str);//ǿ��ת��
	while (*p!='\0')
	{
		if ((*p >= 'A'&&*p <= 'Z') || *p >= 'a'&&*p <= 'z')//������ĸ
			flag = 1;
		else
			flag++;
		if (flag == 2)//�պ�Ϊ1������
			count++;
		p++;
	}
	return count;
}
//����һ���ֽڶ��ٱ��ó�1
int oneCount(unsigned char c)
{
	int count = 0;
	int i = 0;
	unsigned char tmp = (0x1 << 7);//һ���ֽ�8λ  ���λ�ó�1
	for (int i = 0; i < 8; i++)
	{
		if ((c&tmp) != 0)
			count++;
		tmp = tmp >> 1;//�θ�λΪ1 
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
	MyString(const char *str = NULL);//��ֵ
	~MyString(void);
	MyString(const MyString &other);//����
	MyString &operator=(const MyString &other);
private:
	char *m_data;
};
MyString::MyString(const char *str)
{
	if (str == NULL)
	{
		m_data = new char[1];//ֻ����1��ֵ
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
	m_data = NULL;//��ֹ��ΪҰָ��
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

//�������ı���  ǰ ��  ��  ��
struct Tree
{
	int value;
	Tree *left;
	Tree *right;
};
//ǰ
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
		top = s.top();//�����Һ���
		s.pop();
		cur = top->right;
	}
}
//��
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
	//�����
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
//��
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
//��
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

//дһ����̬ 
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
	void fun1(double a) {}//����ʱ��̬  ���� ��������ͬ ������ͬ  ���������Զ�ѡ��
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
		cout << *(*it);//ȡ����ָ��
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
	//	cout << *res;//����ַ�
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
	//delete b1;// ����b a
	//delete c1; //����c a

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
	//cout << strlen(a) << " " << sizeof(a);//strlen����\0  sizeof��\0 3 4

	resver("abcde");

	system("pause");
	return 0;
}