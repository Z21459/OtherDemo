#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

void Swap1(char &s1, char&s2) {
	char temp = s1;
	s1 = s2;
	s2 = temp;
}

//字符串常用  gets puts strcat  strcpy strlen   int2str  str2int

//将任意类型数值转成字符 itoa ltoa(长整型转字符串) ultoa(无符号型转字符串) gcvt(浮点转字符串) ecvt(双精度浮点转字符串) fcvt
//将字符串转成数值 atof(字符串转双精度) atoi（字符串转整型） atol（字符串转长整型） strtod（字符串转双精度）  strtol（字符串转长整形） strtoul
int strlen1(const char*s1) {
	//int len = 0;
	//while (*s1++ != '\0') {//循环直到遇到结束符
	//	len++;
	//}
	//return len;

	const char *s = s1;
	while (*s1 ++ != '\0');//结束符退出
	return(s1 - s - 1);
}
//字符串比较
int mystrcpy(char*s1, char*s2) {
	//int ret = 0;
	//while (!(ret = *(unsigned char*)s1 - *(unsigned char*)s2) && *s2) {
	//	++s1;
	//	++s2;
	//}
	////判断ret
	int flag;//0 相等 1 大于  -1 小于
	int len1 = strlen1(s1);
	int len2 = strlen1(s2);
	if (s1 == NULL && s2 == NULL) {
		flag = 0;
	}
	if (s1 == NULL) {
		flag = -1;//s1<s2
	}
	if (s2 == NULL)
		flag = 1;//s1>s2
	for (int i = 0, j = 0; i < len1&&j < len2; i++, j++) {
		if (s1[i] > s2[j])
			flag = 1;
		else if (s1[i] < s2[j])
			flag = -1;
		else
			flag = 0;
	}
	return flag;
}
//字符串拼接
char* strcat1(char *s1,char *s2) {
	if (s1 == NULL) {
		return s2;
	}
	if (s2 == NULL) {
		return s1;
	}
	int len = strlen1(s1) + strlen1(s2);
	char *s = new char[len];
	for (int i = 0; i < strlen1(s1); i++) {
		s[i] = s1[i];
	}
	for (int j = strlen1(s1),i=0; i < strlen1(s2); j++,i++) {
		s[j] = s2[i];
	}
	return s;
}
//字符串拷贝
char* strcpy1(char *s1,char *s2) {
	if (s1 == NULL||s2 == NULL) {
		return NULL;
	}
	char *Dest = s1;//保存目标首地址
	while (*s1++ != '\0') {//循环
		*Dest++ = *s1++;
	}
	return Dest;
}
//整型转字符串
void int2str(int num,char *str) {
	int i = 0;
	char s[10] = " ";
	int len = 0;
	int temp = num < 0 ? -num : num;//求取绝对值
	if (str == NULL) {
		return;
	}
	while (temp) {
		s[i++] = temp % 10 + '0';
		temp /= 10;
	}
	len = num < 0 ? ++i : i;//如果num是负数  则需要多一位放符号位
	s[i] = 0;
	while (1) {
		i--;
		if (s[len - i - 1] == 0) {
			break;
		}
		str[i] = s[len - i - 1];//将临时字符串拷贝到字符串里面
	}
	if (i == 0) {
		str[i] = '-';
	}
}
//字符串转整型
int str2int( char *s1) {
	int temp = 0;
	char *ptr = s1;
	if (*s1 == '-' || *s1 == '+') {
		*s1++;
	}
	while (*s1 != 0) {
		if ((*s1 < '0') || (*s1 > '9')) {
			break;
		}
		temp = temp * 10 + (*s1 - '0');//如果当前字符是数字，则计算数值
		s1++;//移到下一个字符
	}
	if (*ptr == '-'){
		temp=-temp;
	}
	return temp;
}

//strcpy和memcpy:复制内容不同--前者只复制字符串，后者复制任意内容；复制方法不同--前者不需要指定长度，后者需要；用途不同--通常复制字符串用前者，后者复制其他的

//子串查找 strstr
const char *strstr1(const char *Dest, const char *str) {
	const char* d;
	const char* s;
	if (Dest == NULL || str == NULL) {
		return Dest;
	}
	while (*Dest) {//遍历字符串 主串
		d = Dest;
		s = str;
		//while (*d++ == *s++) {//动态规划，进行内部循环
		//	if (!*s)
		//		return Dest;
		//}
		//Dest += 1;
		do {
			if (!*s)
				return Dest;
		} while (*d++ == *s++);
		Dest += 1;
	}
	return NULL;
}
//单词 字符穿翻转
void RevStr(char* str) {
	if (str == NULL) {
		return;
	}
	char *start=str,*end=str,*ptr=str;
	//栈后进先出
	while (*ptr++ != '\0') {//不到最后一个//不对原字符串进行操作   拷贝原字符串
		if (*ptr == ' '||*ptr=='\0') {//找到第一个单词
			end = ptr - 1;//指向单词末尾
			while (start < end) {
				Swap1(*start++, *end--);//单词字符逆置
			}
			start = end = ptr + 1;//指向下一个单词开头
		}
	}
	//打印出来
	start = str, end = ptr - 2;//字符串头 和字符串尾部
	while (start < end) {
		Swap1(*start++, *end--);//整个逆置
	}
}
//判断回文
bool IsRevStr(char *str) {
	bool flag = false;
	if (str == NULL) {
		flag = false;
	}
	int len = strlen1(str);
	for (int i = 0; i < strlen1(str) / 2; i++) {
		if (str[i] = str[len - i - 1])//*(str+i)==*(str+len-i-1)
			flag = true;
	}
	return flag;
}
//查找最大公共子串
char* FindMaxSub(char*s1, char*s2) {
	//利用动态规划
	int i, j;
	int m, n,k=0;
	char*a = new char[1024];
	char*b = new char[1024];
	int len1 = strlen1(s1);
	int len2 = strlen1(s2);
	char*longest, *shortest;//保存最小最短子串
	if (len1 < len2) {
		longest = s2;
		shortest = s1;
	}
	else {
		longest = s1;
		shortest = s2;
	}
	int lo = strlen1(longest);
	int sh = strlen1(shortest);
	//进行循环比较
	for (i = 0; i < sh; i++) {
		for (j = 0; j < lo; j++) {//每次循环后 长的网后面加1位 继续进行遍历
			m = i;
			n = j;
			for (;m<lo&&n<sh;) {
				if (s1[m] == s2[n]) {
					a[k++] = s1[m];
					m++;
					n++;
				}
				else {
					break;
				}
			}
			k = 0;
		}
		if (strlen1(a) > strlen1(b)) {
			for (int q = 0; q < strlen1(a); q++) {
				b[q] = a[q];
			}
		}
	}
	return b;
}
//字符串子串不翻转 利用栈   new 是申请堆内存
char *RevSubStr(char*str,char*sub) {
	stack<char>stack1;
	char*su = sub, *head = str, *rear = str;
	while (*head != '\0') {
		while (*head != '\0'&&*su == *head) {
			su++;
			head++;
		}
		if (*su == '\0') {
			char*p;
			for (p = head - 1; p > rear; p--) {
				stack1.push(*p);
			}
			su = sub;
			rear = head;
		}
		else {
			stack1.push(*rear++);
			head = rear;
			su = sub;
		}
	}
	char *pR = new char[strlen(str) + 1];
	int i = 0;
	while (!stack1.empty()) {
		pR[i++] = stack1.top();
		stack1.pop();
	}
	pR[i] = '\0';
	return pR;
}//字符串翻转  三种方式  --临时变量交换   --异或  --自加减
char strrev11(char*str) {
	int len = strlen1(str);
	for (int i = 0; i < len/2; i++) {
		char tmp = *(str + i);
		*(str + i) = *(str + len - i - 1);
		*(str + len - i - 1) = tmp;//交换
	}
}
//字符串移位
void strMove(char*  str, int n) {
	int len = strlen1(str);
	char *temp = new char[len];//存放临时移位变量
	//for (int i = 0; i < n; i++) {//拷贝
	//	temp[i] = str[i];
	//}
	////移位
	//for (int i = 0; i < (len-n); i++) {
	//	str[i] = str[n + i];//元素往前移动n位
	//}
	//printf("%s", str);//
	//for (int i = len-1,j=0; i >= n &&j<n; i--,j++) {///
	//	str[i] = temp[n-j-1];//进行连接拷贝到n后面的位置 从后往前拷贝
	//}
	int i = 0;
	for (int i = 0; i < n; i++)temp[i] = str[i];
	for (; i < len; i++)str[i - n] = str[i];
	//printf("%s", str);//
	for (i = 0; i < n; i++)str[len - n + i] = temp[i];
	delete[] temp;
}

//出现0和1的连续最大次数
void Calculate(char *str, int Max0, int Max1) {
	int m0 = 0, m1 = 0;
	char *s = str;
	while (*str != '\0') {
		if (*str == '0') {
			m0++;
			if (*(++str ) = '1') {
				if (m0 > Max0)
					Max0 = m0;
			}
			m0 = 0;
		}
		else if (*str == '1') {
			m1++;
			if (*(++str) == '0') {
				if (m1 > Max1) {
					Max1 = m1;
				}
			}
			m1 = 0;
		}
	}
	Max0 = m0;
	Max1 = m1;
}



int main4() {

	//int a[5] = {1,2,3,4,5},*p;
	//p = a;
	//cout << *(p+4*sizeof(int));//p+4指向最后一个元素   p+4*sizeof(int)  = p+16  指向第17个元素

	//char p[] = "12345";
	//char q[] = "35";
	//const char *r = strstr1(p, q);
	//char s[] = "1234567";
	//int t = 4;
	//strMove(s, t);
	//printf("\n%s", s);


	system("pause");
	return 0;
}