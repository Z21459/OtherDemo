#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//C语言必背18个经典程序


//9*9乘法表
void Formula()
{
	int i, j, result;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			if (j > i) continue;
			result = i * j;
			printf("%d*%d = %-3d", j, i, result);/*-3d表示左对齐，占3位*/
		}
		printf("\n");/*每一行后换行*/
	}
}

//小白兔生小白兔
void WhiteRabbit()
{
	long f1, f2;
	int i;
	f1 = f2 = 1;
	for (i = 1; i <= 20; i++)
	{
		printf(" % 12ld % 12ld", f1, f2);
		if (i % 2 == 0) printf("\n");/*控制输出，每行四个*/
		f1 = f1 + f2;/*前两个月加起来赋值给第三个月*/
		f2 = f1 + f2; /*前两个月加起来赋值给第三个月*/
	}
}

void rev(char *str)
{
	char *temp = str, *end = str, *start = str;
	while (*temp++)
	{
		if (temp == " " || temp == "\n")
		{
			end = temp - 1;
			while (start < end)
			{
				swap(*start++, *end--);
			}
			end = start = temp + 1;
		}
	}
	start = str, end = str - 2;
	while (start<end)
	{
		swap(*start++, *end--);
	}
}

int mainq()
{
	//Formula();
	WhiteRabbit();


	system("pause");
	return 0;
}