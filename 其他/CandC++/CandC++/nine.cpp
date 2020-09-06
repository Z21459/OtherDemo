#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

//主要分成-- 插入  选择 交换 归并 分配
// 插入  希尔  冒泡  快排 选择 堆排 归并 基数 

//插入 --直接插入  打牌方式
void insertSort(int *a, int n) {
	int i,j, temp;
	for (i = 1; i < n; i++) {
		temp = a[i];
		for (j = i - 1; j > 0; j--) {
			a[j + 1] = a[j];//后移
		}
		a[j + 1] = temp;
	}
}


int main8(int argc, char *argv[])
{


	system("pause");
	return 0;
}