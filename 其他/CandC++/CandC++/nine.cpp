#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

//��Ҫ�ֳ�-- ����  ѡ�� ���� �鲢 ����
// ����  ϣ��  ð��  ���� ѡ�� ���� �鲢 ���� 

//���� --ֱ�Ӳ���  ���Ʒ�ʽ
void insertSort(int *a, int n) {
	int i,j, temp;
	for (i = 1; i < n; i++) {
		temp = a[i];
		for (j = i - 1; j > 0; j--) {
			a[j + 1] = a[j];//����
		}
		a[j + 1] = temp;
	}
}


int main8(int argc, char *argv[])
{


	system("pause");
	return 0;
}