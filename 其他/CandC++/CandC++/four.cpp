#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <stdlib.h>
using namespace std;

//字符串 puts gets strcat strcpy strlen

//3 数字转字符串
void int2str(int num,char *str) {
	num = num < 0 ? -num : num;//取为正数
	char s[1024];
	int len = 0;
	int i = 0;
	while (num) {//不为0 一直循环
		int n = num % 10;//获取每一位 余数
		s[i++] =n + '0';
		num = num / 10;//减少一位
	}
	len = num < 0 ? ++i : i;//如果为负 多一位存储符号
	while (1) {
		i--;
		if (s[len - i - 1] == 0) {
			break;
		}
		str[i] = s[len - i - 1];
	}
	if (i == 0) {
		str[i] = '-';//如果负数  添加一个符号
	}
}
//4 字符串转数字
int str2int(char *str) {
	int result = 0;
	if (*str == '+' || *str == '-') {
		str++;
	}
	while (*str != 0) {
		if ((*str < '0') || (*str > '9')) {
			break;
		}
		result = result * 10 + (*str - '0');//当前数字  则计算数值
		str++;
	}
	if (*str == '-') {
		result = -result;
	}
	return result;
}
//5 实现strcpy
char *strcpy1(char *strDest, const char*strSrc)//返回char*能使用链式表达式
{
	if (strDest == NULL || strSrc == NULL) {
		return NULL;
	}
	char *strDestCopy = strDest;//保存目标字符串首地址
	while ((*strDest++ = *strSrc++) != '\0');//字符串复制  指针循环移动
	return strDestCopy;
}
//求字符串长度
int strlen1(const char* strSrc) {
	int len = 0;
	while (*strSrc != '\0') {//循环遇到结束符
		len++;
	}
	return len;
}
//6 实现memcpy函数
void *memcpy1(void *menTo, const void*menFrom, size_t size)//通过size确定复制多少字
{
	assert((menTo != NULL) && (menFrom != NULL));
	char *tempFrom = (char*)menFrom;
	char *tempTo = (char*)menTo;
	while (size-- > 0) {
		*tempTo++ = *tempFrom++;
	}
	return menTo;
}
//7 strcpy和memcpy两者区别  前者只能复制字符串，后者可以复制任意。复制方式后者需要确定长度。

//11 计算长度
int strlen2(const char* src) {
	assert(src != NULL);
	const char*temp = src;//保存首地址
	while (*src++ != '\0');//遇到结束符退出
	return (src - temp - 1);//尾指针和头指针之差，即长度
}
//12 字符串中查找子串
const char* strstr1(const char*src, const char*sub) {
	const char *bp;
	const char *sp;
	if (src == NULL || sub == NULL) {
		return src;
	}
	while (*src) {
		bp = src;//用于src遍历
		sp = sub;//用于sub遍历
		do {//遍历sub字符串
			if (!*sp)//如果到了sub字符串结束符位置
				return src;//表示找到sub
		} while (*bp++ == *sp++);
		src += 1;
		return NULL;
	}
}
//13 字符串各单词翻转  单词位置倒置，内部结构不改变
void RevStr(char *str) {
	char *start = str, *end = str, *ptr = str;
	while (*ptr++ != '\0') {//遍历整个字符串
		if (*ptr == ' ' || *ptr == '\0') {//找到第一个单词
			end = ptr - 1;//end指向单词末尾
			while (start < end) {//单词字母逆置
				swap(*start++, *end++);
			}
			start = end = ptr + 1;//指向下一个单词开头
		}
	}
		start = str, end = ptr - 2;//start指向字符串开头，end指向字符串末尾
		while (start < end) {
			swap(*start++,*end--);//整个字符串逆置
		}
}
//14 判断回文
int isRevStr(char *str) {
	int i, len;
	int found = 1;//1表示回文 0不是
	if (str == NULL) {
		return -1;
	}
	len = strlen(str);
	for (i = 0; i < len / 2; i++) {
		if (*(str + i) != *(str + len - i - 1)) {//遍历中如果发现相应的头尾字符不等
			found = 0;
			break;
		}
	}
	return found;
}
//15 strcmp 字符串比较
int strcmp1(const char*src, const char *dst) {
	int ret = 0;
	while (!(ret = *(unsigned char*)src-*(unsigned char*)dst)&&*dst)
	{//循环比较两个字符是否相等
		++src;
		++dst;
	}
	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1;
	return ret;
}
//16 两个字符串最大公串
char *comstring(char *str1, char *str2) {
	int i, j;
	char *shortstr, *longstr;
	char *substr = NULL;
	if (str1 == NULL || str2 == NULL) {
		return NULL;
	}
	if (strlen(str1) <= strlen(str2)) {
		shortstr = str1;
		longstr = str2;
	}
	else {
		shortstr = str2;
		longstr = str1;
	}
	if (strstr(longstr, shortstr) != NULL) {//判断能否找到子串
		return shortstr;
	}
	for (i = strlen(shortstr) - 1; i > 0; i--) {
		for (j = 0; j <= strlen(longstr) - i; j++) {
			memcpy(substr, &shortstr[j], i);//复制短字符串的一部分
			substr[i] = '\0';//长度渐渐减小
			if (strstr(longstr, substr) != NULL)
				return substr;
		}
	}
}
//20 字符串翻转 指定不转
#include <stack>
const char*reverse(const char*s1, const char *token) {
	stack<char> stack1;
	const char*ptoken = token, *head = s1, *rear = s1;
	assert(s1&&token);
	while (*head != '\0') {
		while (*head != '\0'&&*ptoken == *head) {
			ptoken++;
			head++;
		}
		if (*ptoken == '\0') {
			const char*p;
			for (p = head - 1; p >= rear; p--) {
				stack1.push(*p);
			}
			ptoken = token;
			rear = head;
		}
		else {
			stack1.push(*rear++);
			head = rear;
			ptoken = token;
		}
	}
	char *pReturn = new char[strlen(s1) + 1];
	int i = 0;
	while (!stack1.empty())
	{
		pReturn[i++] = stack1.top();
		stack1.pop();
	}
	pReturn[i] = '\0';
	return pReturn;
}
// 27 28 strcat 拼接字符串
char *strcat1(char *dest, const char*src) {
	char *ret;
	ret = dest;
	while (*dest++);//
	dest--;///此时dest字符串结尾符
	while (*dest++ = *src++);
	return ret;
}
int main4()
{

	system("pause");
	return 0;
}
