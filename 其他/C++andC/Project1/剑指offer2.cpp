#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


//�������е��ظ���   �����±�͵�ǰ��ֵ���Ƿ���ͬ����ͬ�ͱ�ʾ�ظ���
bool dup(int num[], int len, int*d) {//ʱ�临�Ӷ�O(n)
	if (num == nullptr || len < 0) {
		return false;
	}
	for (int i = 0; i < len; i++) {
		if (num[i]<0 || num[i]>len - 1) {
			return false;
		}
	}
	for (int i = 0; i < len; i++) {
		while (num[i] != i) {
			if (num[i] == num[num[i]]) {
				*d = num[i];
				return true;
			}
			//����num[i]��num[num[i]]
			int tmp = num[i];
			num[i] = num[tmp];
			num[tmp] = tmp;
		}
	}
	return false;
}

//��ά���������ֵ�����������ϵ��£������ҵ�����   
//�ȴ����Ͻ��жϣ��������ɾ�������У����С��ɾ�������У��Դ˵ݹ���ȥ��  ÿ�ζ�ѡȡ�������Ͻǵ���ֵ
bool Find(int *matrix, int rows, int columns, int num) {
	bool found = false;
	if (matrix != nullptr&&rows > 0 && columns > 0) {
		int row = 0;
		int column = columns - 1;
		while (row < rows&&column>0) {
			if (matrix[row*columns + column] == num) {
				found = true;
				break;
			}
			else if (matrix[row*columns + column] > num) {
				--columns;
			}
			else {
				++row;
			}
		}
	}
	return found;
}

//���ո��滻�������ַ�  �Ӻ���ǰ�����滻������ʹ������ָ�룬�������ָ����ͬ��������滻��� p1ָ��ԭ�ַ���β����p2ָ���滻���β����
void Replace(char str[], int len) {
	if (str == nullptr || len < 0) {
		return;
	}
	int orlen = 0;//ԭʼ����
	int numbl = 0;//�ո���
	int i = 0;
	while (str[i] != '\0') {//ͳ�ƿո�����ԭʼ����
		++orlen;
		if (str[i] == ' ') {
			++numbl;
		}
		++i;
	}
	//�滻�󳤶�
	int newlen = orlen + numbl * 2;
	if (newlen > len) {
		return;
	}
	int indexo = orlen;
	int indexn = newlen;
	while (indexo >= 0 && indexn > indexo) {
		if (str[indexo] == ' ') {
			str[indexn--] = '0';
			str[indexn--] = '2';
			str[indexn--] = '%';
		}
		else {
			str[indexn--] = str[indexo];
		}
		--indexo;
	}
}

//쳲�����ʵ��
long long Fibon(unsigned n) {
	int res[2] = { 0,1 };
	if (n < 2)
		return res[n];
	long long fibO = 1;
	long long fibT = 0;
	long long fib = 0;
	for (unsigned i = 2; i < n; i++) {
		fib = fibO + fibT;
		fibT = fibO;
		fibO = fib;
	}
	return fib;
}

//��̬�滮--������  ��n>5ʱ������������Ϊ3�ģ���ʣ�³���Ϊ4ʱ������2*2��
int MaxLen(int len) {
	if (len < 2) {
		return 0;
	}
	if (len == 2) {
		return 1;
	}
	if (len == 3) {
		return 2;
	}
	int t3 = len / 3;
	if (len - 3 * t3 == 1) {
		t3 -= 1;
	}
	int t2 = (len - t3 * 3) / 2;
	return (int)(pow(3, t3))*(int)(pow(2, t2));
}

//�߼������  ��& ��| ��^  ����(���nλ�������ұ߲���n��0)  ����(���ұ�nλ����������ԭ��Ϊ���������ƺ���߲�n��0����ԭ��Ϊ���������ƺ�����߲�n��1)
//������һ�����Ķ�������1 �ĸ���
int num1(int n) {
	int count = 0;
	while (n) {
		++count;
		n = (n - 1)&n;
	}
	return count;
}


int main2o() {


	system("pause");
	return 0;
}