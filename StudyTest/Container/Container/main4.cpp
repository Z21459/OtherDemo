#include<iostream>

using namespace std;

//交换元素
void swap(int *num1, int *num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

//冒泡排序实现
void bubbleSort(int arr[], int len) {
	for (int i = 0; i < len - 1; i++) {
		bool sorted = true;
		for (int j = 0; j < len - 1 - i; j++) {
			if (arr[j] < arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				sorted = false;
			}
		}
		if (sorted)break;//如果没有发生交换,则表示已排好序,跳出,
		//不用像选择排序那样对每个元素都要进行遍历排序,执行n-1次(n即元素个数).
	}
}

//测试
int main4(void) {
	int girl[] = { 21,32,17,33,20,34,28,27,33 };
	int len = sizeof(girl) / sizeof(girl[0]);//获取元素个数
	bubbleSort(girl, len);
	for (int i = 0; i < len; i++) {
		cout << girl[i] << "\t";
	}
	cout << endl;

	system("pause");
	return 0;
}