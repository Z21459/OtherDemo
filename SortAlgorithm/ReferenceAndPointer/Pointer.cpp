//ָ�������
//& �� *
//�����Ǳ��� ָ���ǵ�ַ�����õı���Ҳ��ָ�룬�������ֲ���ͬ;��ʼ��Ҫ��ͬ ���޸��Բ�ͬ��������NULL���ã�������Ҫ����
//1��ע�ͣ���ϼ���Ctrl + K + C���� ...
///2��ȡ��ע�ͣ���ϼ���Ctrl + K + U�� ...
#include <iostream>
#include <cstring>
using namespace std;


int main2() {

	//int a = 10;
	//int z = 20;
	//int &b = a;
	//int c;
	//b = z;
	//c = (&a == &b) ? 1 : 0;

	//int a = 1;
	//int b = 10;
	//int *p = &a;
	//int *&pa = p;
	//(*pa)++;
	//cout << a << b << *p << endl;
	//pa = &b;
	//(*pa)++;
	//cout << a << b << *p;

	//char w[] = "abcdefgh";
	//char *u = w;
	//cout << *(u + 4) << u[4] << w[4] << *(w + 4) << *(u+4)+1;

	int a = 4, b = 3;
	int m = a % b;
	int n = a / b;
	int x = (2 * m >= n) ? (n + 1) : n;
	cout << x;

	system("pause");
	return 0;
}

//�����ַ���  ����char * p = "aaaa"
void swap(char*&x, char*&y) {
	char *temp;
	temp = x;
	x = y;
	y = temp;
}

