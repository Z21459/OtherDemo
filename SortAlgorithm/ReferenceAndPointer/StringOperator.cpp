#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


//��������Ӵ� ���ö�̬�滮���
char * findMax(char*s1, char* s2) {//"baucbaud";"baudbaud"
	int len = strlen(s1) <= strlen(s2) ? strlen(s1) : strlen(s2);//ȡ��С����
	int i, j, m = 0;
	int p, q;
	int length = strlen(s2);
	//char a[100] = { 0 };
	char *a = new char[100]{0};
	char *b = new char[100]{0};
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
			while (s1[p] == s2[q] && s1[p] != 0)//ѭ��֮������ж�  ������� �Ҷ̵Ĳ�Ϊ��
			{
				a[m] = s2[q];//��ֵ
				p++;
				q++;
				m++;
			}//������� �˳����ѭ�� ����ִ������// //"baucbaud";"baudbaud"

			if (strlen(a) > strlen(b))//b��һ��Ϊ��  ��ִ��һ��֮�� ��Ϊ���� �����a����ѭ��֮�����
				//ԭ�ȵ������ַ��� ����������¿��� ������ԭ�����
			{	
				//strcpy_s(b, a);//b����ʱ��ŵ�һ�δ�ŵ��Ӵ�
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
int strcmp1(const char*s1, const char*s2) {
	//�������
	int b = 0;
	if (s1 == nullptr || s2 == nullptr)
		b = -1;
	//while(!(b = *(unsigned char*)s1 - *(unsigned char*)s2) && *s2) {
	//	++s1;
	//	++s2;
	//}
	int i=0, j=0;
	for (; i < strlen(s1) || j < strlen(s2);) {
		if (s1[i++] != s2[j++]) {
			b = 1;//��ͬ����1
			break;
		}
	}
	//if (b < 0)
	//	b = -1;
	//else if(b>0)
	//	b = 1;

	return b;
}

int rewen(const char*s1) {
	int t = 1;
	if (s1 == nullptr)
		t = -1;
	int i;
	int len = strlen(s1);
	for (i = 0; i < len / 2;i++) {
		if (s1[i] != s1[len - i-1]) {
			t = 0;//���ǻ���
			break;
		}
	}
	return t;
}

//��������
char *strcpy1(char*s1, const char*s2) {
	if (s1 == nullptr)
		return nullptr;
	int i, j;
	for (i = 0,j=0; i < strlen(s2);) {
		s1[j++] = s2[i++];
	}
	return s1;
}

//���
char* strcat1(char* s1, const char* s2) {
	if (s2 == nullptr)
		return nullptr;
	int i, k;
	if (s1 == nullptr) {
		for (i = 0, k = 0; i < strlen(s2);) {
			s1[k++] = s2[i++];
		}
	}
	if(s1 != nullptr) {
		for (i = strlen(s1), k = 0; k <=strlen(s2);) {
			s1[i++] = s2[k++];
			}
	}
	return s1;
}

int main3() {
	char p[] = "baudbaud";
	char q[] = "baucbaud";
	const char *a = "abo";
	const char *b = "abc";
	const char *w = "abdca";
	char * tt = findMax(p, q);//��������Ӵ�
	cout << tt;


	char* temp = new char[256]; 
	*temp = '\0';
	char *t = strcat1(strcat1(temp, a), b);
	//cout << t;
	delete[]temp;
	char* temp1 = new char[256];
	strcpy1(temp1, b);//copy
	int z = strcmp1(a, b);//�Ƚ�
	//cout << z;
	delete[]temp1;
	int v = rewen(w);
	//cout << v;
	system("pause");
	return 0;
}