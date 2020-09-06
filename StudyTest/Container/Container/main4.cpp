#include<iostream>

using namespace std;

//����Ԫ��
void swap(int *num1, int *num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

//ð������ʵ��
void bubbleSort(int arr[], int len) {
	for (int i = 0; i < len - 1; i++) {
		bool sorted = true;
		for (int j = 0; j < len - 1 - i; j++) {
			if (arr[j] < arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				sorted = false;
			}
		}
		if (sorted)break;//���û�з�������,���ʾ���ź���,����,
		//������ѡ������������ÿ��Ԫ�ض�Ҫ���б�������,ִ��n-1��(n��Ԫ�ظ���).
	}
}

//����
int main4(void) {
	int girl[] = { 21,32,17,33,20,34,28,27,33 };
	int len = sizeof(girl) / sizeof(girl[0]);//��ȡԪ�ظ���
	bubbleSort(girl, len);
	for (int i = 0; i < len; i++) {
		cout << girl[i] << "\t";
	}
	cout << endl;

	system("pause");
	return 0;
}