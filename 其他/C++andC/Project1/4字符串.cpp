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

//�ַ�������  gets puts strcat  strcpy strlen   int2str  str2int

//������������ֵת���ַ� itoa ltoa(������ת�ַ���) ultoa(�޷�����ת�ַ���) gcvt(����ת�ַ���) ecvt(˫���ȸ���ת�ַ���) fcvt
//���ַ���ת����ֵ atof(�ַ���ת˫����) atoi���ַ���ת���ͣ� atol���ַ���ת�����ͣ� strtod���ַ���ת˫���ȣ�  strtol���ַ���ת�����Σ� strtoul
int strlen1(const char*s1) {
	//int len = 0;
	//while (*s1++ != '\0') {//ѭ��ֱ������������
	//	len++;
	//}
	//return len;

	const char *s = s1;
	while (*s1 ++ != '\0');//�������˳�
	return(s1 - s - 1);
}
//�ַ����Ƚ�
int mystrcpy(char*s1, char*s2) {
	//int ret = 0;
	//while (!(ret = *(unsigned char*)s1 - *(unsigned char*)s2) && *s2) {
	//	++s1;
	//	++s2;
	//}
	////�ж�ret
	int flag;//0 ��� 1 ����  -1 С��
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
//�ַ���ƴ��
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
//�ַ�������
char* strcpy1(char *s1,char *s2) {
	if (s1 == NULL||s2 == NULL) {
		return NULL;
	}
	char *Dest = s1;//����Ŀ���׵�ַ
	while (*s1++ != '\0') {//ѭ��
		*Dest++ = *s1++;
	}
	return Dest;
}
//����ת�ַ���
void int2str(int num,char *str) {
	int i = 0;
	char s[10] = " ";
	int len = 0;
	int temp = num < 0 ? -num : num;//��ȡ����ֵ
	if (str == NULL) {
		return;
	}
	while (temp) {
		s[i++] = temp % 10 + '0';
		temp /= 10;
	}
	len = num < 0 ? ++i : i;//���num�Ǹ���  ����Ҫ��һλ�ŷ���λ
	s[i] = 0;
	while (1) {
		i--;
		if (s[len - i - 1] == 0) {
			break;
		}
		str[i] = s[len - i - 1];//����ʱ�ַ����������ַ�������
	}
	if (i == 0) {
		str[i] = '-';
	}
}
//�ַ���ת����
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
		temp = temp * 10 + (*s1 - '0');//�����ǰ�ַ������֣��������ֵ
		s1++;//�Ƶ���һ���ַ�
	}
	if (*ptr == '-'){
		temp=-temp;
	}
	return temp;
}

//strcpy��memcpy:�������ݲ�ͬ--ǰ��ֻ�����ַ��������߸����������ݣ����Ʒ�����ͬ--ǰ�߲���Ҫָ�����ȣ�������Ҫ����;��ͬ--ͨ�������ַ�����ǰ�ߣ����߸���������

//�Ӵ����� strstr
const char *strstr1(const char *Dest, const char *str) {
	const char* d;
	const char* s;
	if (Dest == NULL || str == NULL) {
		return Dest;
	}
	while (*Dest) {//�����ַ��� ����
		d = Dest;
		s = str;
		//while (*d++ == *s++) {//��̬�滮�������ڲ�ѭ��
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
//���� �ַ�����ת
void RevStr(char* str) {
	if (str == NULL) {
		return;
	}
	char *start=str,*end=str,*ptr=str;
	//ջ����ȳ�
	while (*ptr++ != '\0') {//�������һ��//����ԭ�ַ������в���   ����ԭ�ַ���
		if (*ptr == ' '||*ptr=='\0') {//�ҵ���һ������
			end = ptr - 1;//ָ�򵥴�ĩβ
			while (start < end) {
				Swap1(*start++, *end--);//�����ַ�����
			}
			start = end = ptr + 1;//ָ����һ�����ʿ�ͷ
		}
	}
	//��ӡ����
	start = str, end = ptr - 2;//�ַ���ͷ ���ַ���β��
	while (start < end) {
		Swap1(*start++, *end--);//��������
	}
}
//�жϻ���
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
//������󹫹��Ӵ�
char* FindMaxSub(char*s1, char*s2) {
	//���ö�̬�滮
	int i, j;
	int m, n,k=0;
	char*a = new char[1024];
	char*b = new char[1024];
	int len1 = strlen1(s1);
	int len2 = strlen1(s2);
	char*longest, *shortest;//������С����Ӵ�
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
	//����ѭ���Ƚ�
	for (i = 0; i < sh; i++) {
		for (j = 0; j < lo; j++) {//ÿ��ѭ���� �����������1λ �������б���
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
//�ַ����Ӵ�����ת ����ջ   new ��������ڴ�
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
}//�ַ�����ת  ���ַ�ʽ  --��ʱ��������   --���  --�ԼӼ�
char strrev11(char*str) {
	int len = strlen1(str);
	for (int i = 0; i < len/2; i++) {
		char tmp = *(str + i);
		*(str + i) = *(str + len - i - 1);
		*(str + len - i - 1) = tmp;//����
	}
}
//�ַ�����λ
void strMove(char*  str, int n) {
	int len = strlen1(str);
	char *temp = new char[len];//�����ʱ��λ����
	//for (int i = 0; i < n; i++) {//����
	//	temp[i] = str[i];
	//}
	////��λ
	//for (int i = 0; i < (len-n); i++) {
	//	str[i] = str[n + i];//Ԫ����ǰ�ƶ�nλ
	//}
	//printf("%s", str);//
	//for (int i = len-1,j=0; i >= n &&j<n; i--,j++) {///
	//	str[i] = temp[n-j-1];//�������ӿ�����n�����λ�� �Ӻ���ǰ����
	//}
	int i = 0;
	for (int i = 0; i < n; i++)temp[i] = str[i];
	for (; i < len; i++)str[i - n] = str[i];
	//printf("%s", str);//
	for (i = 0; i < n; i++)str[len - n + i] = temp[i];
	delete[] temp;
}

//����0��1������������
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
	//cout << *(p+4*sizeof(int));//p+4ָ�����һ��Ԫ��   p+4*sizeof(int)  = p+16  ָ���17��Ԫ��

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