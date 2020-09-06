#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <stdlib.h>
using namespace std;

//�ַ��� puts gets strcat strcpy strlen

//3 ����ת�ַ���
void int2str(int num,char *str) {
	num = num < 0 ? -num : num;//ȡΪ����
	char s[1024];
	int len = 0;
	int i = 0;
	while (num) {//��Ϊ0 һֱѭ��
		int n = num % 10;//��ȡÿһλ ����
		s[i++] =n + '0';
		num = num / 10;//����һλ
	}
	len = num < 0 ? ++i : i;//���Ϊ�� ��һλ�洢����
	while (1) {
		i--;
		if (s[len - i - 1] == 0) {
			break;
		}
		str[i] = s[len - i - 1];
	}
	if (i == 0) {
		str[i] = '-';//�������  ���һ������
	}
}
//4 �ַ���ת����
int str2int(char *str) {
	int result = 0;
	if (*str == '+' || *str == '-') {
		str++;
	}
	while (*str != 0) {
		if ((*str < '0') || (*str > '9')) {
			break;
		}
		result = result * 10 + (*str - '0');//��ǰ����  �������ֵ
		str++;
	}
	if (*str == '-') {
		result = -result;
	}
	return result;
}
//5 ʵ��strcpy
char *strcpy1(char *strDest, const char*strSrc)//����char*��ʹ����ʽ���ʽ
{
	if (strDest == NULL || strSrc == NULL) {
		return NULL;
	}
	char *strDestCopy = strDest;//����Ŀ���ַ����׵�ַ
	while ((*strDest++ = *strSrc++) != '\0');//�ַ�������  ָ��ѭ���ƶ�
	return strDestCopy;
}
//���ַ�������
int strlen1(const char* strSrc) {
	int len = 0;
	while (*strSrc != '\0') {//ѭ������������
		len++;
	}
	return len;
}
//6 ʵ��memcpy����
void *memcpy1(void *menTo, const void*menFrom, size_t size)//ͨ��sizeȷ�����ƶ�����
{
	assert((menTo != NULL) && (menFrom != NULL));
	char *tempFrom = (char*)menFrom;
	char *tempTo = (char*)menTo;
	while (size-- > 0) {
		*tempTo++ = *tempFrom++;
	}
	return menTo;
}
//7 strcpy��memcpy��������  ǰ��ֻ�ܸ����ַ��������߿��Ը������⡣���Ʒ�ʽ������Ҫȷ�����ȡ�

//11 ���㳤��
int strlen2(const char* src) {
	assert(src != NULL);
	const char*temp = src;//�����׵�ַ
	while (*src++ != '\0');//�����������˳�
	return (src - temp - 1);//βָ���ͷָ��֮�������
}
//12 �ַ����в����Ӵ�
const char* strstr1(const char*src, const char*sub) {
	const char *bp;
	const char *sp;
	if (src == NULL || sub == NULL) {
		return src;
	}
	while (*src) {
		bp = src;//����src����
		sp = sub;//����sub����
		do {//����sub�ַ���
			if (!*sp)//�������sub�ַ���������λ��
				return src;//��ʾ�ҵ�sub
		} while (*bp++ == *sp++);
		src += 1;
		return NULL;
	}
}
//13 �ַ��������ʷ�ת  ����λ�õ��ã��ڲ��ṹ���ı�
void RevStr(char *str) {
	char *start = str, *end = str, *ptr = str;
	while (*ptr++ != '\0') {//���������ַ���
		if (*ptr == ' ' || *ptr == '\0') {//�ҵ���һ������
			end = ptr - 1;//endָ�򵥴�ĩβ
			while (start < end) {//������ĸ����
				swap(*start++, *end++);
			}
			start = end = ptr + 1;//ָ����һ�����ʿ�ͷ
		}
	}
		start = str, end = ptr - 2;//startָ���ַ�����ͷ��endָ���ַ���ĩβ
		while (start < end) {
			swap(*start++,*end--);//�����ַ�������
		}
}
//14 �жϻ���
int isRevStr(char *str) {
	int i, len;
	int found = 1;//1��ʾ���� 0����
	if (str == NULL) {
		return -1;
	}
	len = strlen(str);
	for (i = 0; i < len / 2; i++) {
		if (*(str + i) != *(str + len - i - 1)) {//���������������Ӧ��ͷβ�ַ�����
			found = 0;
			break;
		}
	}
	return found;
}
//15 strcmp �ַ����Ƚ�
int strcmp1(const char*src, const char *dst) {
	int ret = 0;
	while (!(ret = *(unsigned char*)src-*(unsigned char*)dst)&&*dst)
	{//ѭ���Ƚ������ַ��Ƿ����
		++src;
		++dst;
	}
	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1;
	return ret;
}
//16 �����ַ�����󹫴�
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
	if (strstr(longstr, shortstr) != NULL) {//�ж��ܷ��ҵ��Ӵ�
		return shortstr;
	}
	for (i = strlen(shortstr) - 1; i > 0; i--) {
		for (j = 0; j <= strlen(longstr) - i; j++) {
			memcpy(substr, &shortstr[j], i);//���ƶ��ַ�����һ����
			substr[i] = '\0';//���Ƚ�����С
			if (strstr(longstr, substr) != NULL)
				return substr;
		}
	}
}
//20 �ַ�����ת ָ����ת
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
// 27 28 strcat ƴ���ַ���
char *strcat1(char *dest, const char*src) {
	char *ret;
	ret = dest;
	while (*dest++);//
	dest--;///��ʱdest�ַ�����β��
	while (*dest++ = *src++);
	return ret;
}
int main4()
{

	system("pause");
	return 0;
}
