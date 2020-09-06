#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


//找数组中的重复数   索引下表和当前数值的是否相同，不同就表示重复数
bool dup(int num[], int len, int*d) {//时间复杂度O(n)
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
			//交换num[i]和num[num[i]]
			int tmp = num[i];
			num[i] = num[tmp];
			num[tmp] = tmp;
		}
	}
	return false;
}

//二维数组查找数值，，，，从上到下，从左到右递增。   
//先从右上角判断，如果大于删除所在行，如果小于删除所在列，以此递归下去。  每次都选取数组右上角的数值
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

//将空格替换成其他字符  从后往前进行替换，并且使用两个指针，如果两个指针相同，则表明替换完成 p1指向原字符串尾部，p2指向替换后的尾部。
void Replace(char str[], int len) {
	if (str == nullptr || len < 0) {
		return;
	}
	int orlen = 0;//原始长度
	int numbl = 0;//空格数
	int i = 0;
	while (str[i] != '\0') {//统计空格数和原始长度
		++orlen;
		if (str[i] == ' ') {
			++numbl;
		}
		++i;
	}
	//替换后长度
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

//斐波那契实现
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

//动态规划--剪绳子  当n>5时，尽量减长度为3的，当剩下长度为4时，减成2*2的
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

//逻辑运算符  与& 或| 非^  左移(左边n位别丢弃，右边补上n个0)  右移(最右边n位被丢弃，若原先为正数，右移后左边补n个0；若原先为负数，右移后在左边补n个1)
//求输入一个数的二进制中1 的个数
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