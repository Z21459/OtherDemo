#include "allHead.h"

/*
1.穷举法：在规定的问题的解空间，并在解空间中一一枚举每一个可能的解
//寻找1-100的素数；
//Tom借书 5本借3个人 共5*5*5 方法  --三层循环

2.递归和分治：大问题分解成小问题(折半查找--也是一个递归过程)
//递归n!
//计算整数的划分 一个正整数可以有n个可能划分  6=6；6=2+4..

3.贪心算法：总是做出在当前看来最好的选择的一种方法(局部最优解)
//最优装船问题

4.回溯法:包含所有的解中，按照深度优先搜寻策略
//N皇后问题

5.数值概率问题 --计算定积分
//蒙特卡洛   拉斯维加斯  舍伍德 

*/

//3.装船问题
void Psort(int w[], int t[], int n)
{
	int i, j, tmp;
	int *w_tmp = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		t[i] = i;
	}
	for (i = 0; i < n; i++)
	{
		w_tmp[i] = w[i];
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (w_tmp[j] > w_tmp[j + 1])
			{
				tmp = w_tmp[j];
				w_tmp[j] = w_tmp[j + 1];
				w_tmp[j + 1] = tmp;

				tmp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = tmp;
			}
		}
	}
}
void load(int x[], int w[], int c, int n)
{
	int i, s = 0;
	int *t = (int*)malloc(sizeof(int)*n);
	Psort(x, w, n);
	for (i = 0; i < n; i++)
		x[i] = 0;
	for (i = 0; i < n&&w[t[i]] <= c; i++)
	{
		x[t[i]] = 1;
		c = c - w[t[i]];
	}
}

//N皇后问题
bool isCorrect(int i, int j, int(*Q)[4])//表示四行四列
{
	int s, t;
	for (s = i, t = 0; t < 4; t++)//行
		if (Q[s][t] == 1 && t != j) return false;
	for (t = j, s = 0; s < 4; s++)//列
		if (Q[s][t] == 1 && s != i) return false;
	for (s = i-1, t = j-1; s>=0&&t >=  0; t--,s--)//左上
		if (Q[s][t] == 1 ) return false;
	for (t = j+1, s = i+1; s < 4&&t<4; s++,t++)//右下
		if (Q[s][t] == 1) return false;
	for (s = i-1, t = j+1; s>=0&&t < 4; s--,t++)//右上
		if (Q[s][t] == 1) return false;
	for (t = j-1, s = i+1; s < 4&&t>=0; s++,t--)//左下
		if (Q[s][t] == 1 ) return false;
	return true;
}
void Queue(int j, int(*Q)[4])//得到解
{
	int i, k;
	if (j == 4)
	{
		for (i = 0; i < 4; i++)
		{
			for (k = 0; k < 4; k++)
			{
				printf("%d", Q[i][k]);
			}
			printf("\n");
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (isCorrect(i, j, Q))
		{
			Q[i][j] = 1;
			Queue(j + 1, Q);//深度优先搜索解空间
			Q[i][j] = 0;
		}
	}
}

int maina()
{
	system("pause");
	return 0;
}