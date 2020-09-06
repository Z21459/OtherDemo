#include<iostream>
using namespace std;

char *strcpy1(char *strDest, const char *strSrc) {
	if (strSrc == nullptr || strDest==nullptr) {
		return nullptr;
	}
	while (*strSrc != '\0') {
		*strDest++ = *strSrc++;
	}
	return strDest;
}
void *memcpy1(void *menTo, const void*menForm, size_t size) {
	if (menTo == NULL || menForm == NULL) {
		return NULL;
	}
	char *tempTo = (char*)menTo;
	char *tempFrom = (char*)menForm;
	while (size-- > 0) {
		*tempTo++ = *tempFrom++;
	}
	return menTo;
}
int length1(const char*strSrc) {
	int temp;
	if (strSrc == nullptr) {//保证有效
		temp = 0;
	}
	while (*strSrc != '\0') {
		*strSrc++;
		temp++;
	}
	return temp;
}
//查找子串
char* strstr1(char* src, char* sub) {
	if (src == NULL || sub == NULL)
		return src;
	char *bp = NULL;
	char *sp = NULL;
	while (*src)
	{
		bp = src;
		sp = sub;
		while (*sp++ == *bp++)
		{
			if (!*sp)
				return src;
		}
		src += 1;
	}
	return nullptr;
}
//翻转
char * rever1(char *strDest) {
	if (strDest == nullptr)
		return nullptr;
	char *temp = new char[strlen(strDest)];
	int i, j;
	for (i = 0, j = strlen(strDest) - 1; i <= strlen(strDest), j>= 0 ;) {
		temp[i++] = strDest[j--];
	}
	return temp;
}
//比较
int strcmp1(const char* s1, const char* s2) {
	int temp;
	//if (s1 == nullptr || s2 == nullptr)
	//	temp = -1;//
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int i, j;
	if (len1 > len2) {
		temp = 1;
	}
	else if (len1 < len2) {
		temp = -1;
	}
	else {
		for (i = 0, j = 0; i < len1&&j < len2;i++,j++) {
			if (s1[i] == s2[j])
				temp = 0;//相同
			else if(s1[i] > s2[j]){
				temp = 1;//不同
			}
			else {
				temp = -1;
			}
		}
	}
	return temp;
}
//查找最大子串
char *bigSub(char*s1, char*s2) {
	int len = strlen(s1) <= strlen(s2) ? strlen(s1) : strlen(s2);//取最小长度
	int i, j, m = 0;
	int p, q;
	int length = strlen(s2);
	//char a[100] = { 0 };
	char *a = new char[100]{ 0 };
	char *b = new char[100]{ 0 };
	*a = '\0';
	*b = '\0';
	//char b[100] = { 0 };
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < length; j++)
		{
			//strcpy_s(a, "0");
			p = i;//0 0
			q = j;
			while (s1[p] == s2[q] && s1[p] != 0)//循环之后继续判断  两个相等 且短的不为空
			{
				a[m] = s2[q];//赋值
				p++;
				q++;
				m++;
			}//如果不等 退出这个循环 继续执行下面// //"baucbaud";"baudbaud"

			if (strlen(a) > strlen(b))//b第一次为空  ，执行一次之后 则不为空了 ，如果a继续循环之后大于
				//原先的所存字符串 ，则进行重新拷贝 ，否则原串最大
			{
				//strcpy_s(b, a);//b是临时存放第一次存放的子串
				//while ((*b++ = *a++) != 0);
				for (int w = 0, k = 0; w < strlen(b) || k < strlen(a);) {
					b[w++] = a[k++];
				}
			}
			m = 0;
		}
	}
	return b;
}
//字符串翻转  用栈实现
#include <stack>
char *strrev1(char *strSrc) {
	if (strSrc == nullptr) {
		return nullptr;
	}
	int k =0;
	char *t = new char[strlen(strSrc)+1];
	stack<char>temp;
	while (*strSrc != '\0') {
		temp.push(*strSrc++);
	}
	while (!temp.empty()) {
		t[k++] = temp.top();
		temp.pop();

	}
	t[k] = '\0';
	return t;
}
//连接
char * strcat1(char* s1, char*s2) {
	if (s1 == nullptr)
		return s2;
	else if (s2 == nullptr)
		return s1;
	char *res = new char[strlen(s1) + strlen(s2)-1];
	int lens = strlen(res);
	int k = 0, u = 0;
	for (k,u; k <= strlen(s1)&&u<=lens;) {
		res[u++] = s1[k++];
	}
	int j;
	int i;
	for (i = strlen(s1),j=0;i< lens,j < strlen(s2);i++,j++)
		res[i] = s2[j];
	return res;
}

//查找字符串连续出现0和1的最大个数
void max01(char *str,int *max0,int *max1) {//01011100
	int max_0 = 0;
	int max_1 = 0;

	while (*str != '\0')
	{
		//注意，这两个变量得放成局部变量，因为每统计一次连续的相同字符串，ret都应该从0开始
		int ret_0 = 0;
		int ret_1 = 0;
		while (*str != '\0' && *str == '0')
		{
			ret_0++;
			str++;
		}
		if (ret_0 > max_0)
		{
			max_0 = ret_0;
		}

		while (*str != '\0' && *str == '1')//判断字符串没有遍历完
		{
			ret_1++;
			str++;
		}
		if (ret_1 > max_1)
		{
			max_1 = ret_1;
		}
	}
	*max0 = max_0;
	*max1 = max_1;
}
int main2(int argc, char *argv[]) {
	//unsigned(只能是正数)无符号 32 和64 之中的char* 和 unsigned long  不同
	const char *a = "addg";
	const char *b = "adda";
	char *temp = new char[100]{ 0 };
	temp[strlen(a) + 1] = '\0';
	//strcpy1(temp, a);
	//memcpy1(temp, a, 3);
	//cout << temp;
	//cout << length1(a);
	char p[] = "abc";
	char q[] = "def";
	//char *t = strstr1(l, m);
	//if (t != NULL) {
	//	cout << t;
	//}
	//char *t = rever1(l);
	//cout << t;
	//printf_s("r:%s\n", t);
	//int w = strcmp1(a,b);
	//cout << w;

	//char *t = bigSub(p, q);
	//cout << t;
	//char *t = strrev1(p);
   //char *t = strcat1(p,q);
	int max0=0, max1 = 0;
	char r[] = "01011100";
	max01(r, &max0, &max1);
	cout << max0 << max1;
	//printf_s("r:%s\n", t);

	system("pause");
	return 0;
}