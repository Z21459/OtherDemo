#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//C���Աر�18���������


//9*9�˷���
void Formula()
{
	int i, j, result;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			if (j > i) continue;
			result = i * j;
			printf("%d*%d = %-3d", j, i, result);/*-3d��ʾ����룬ռ3λ*/
		}
		printf("\n");/*ÿһ�к���*/
	}
}

//С������С����
void WhiteRabbit()
{
	long f1, f2;
	int i;
	f1 = f2 = 1;
	for (i = 1; i <= 20; i++)
	{
		printf(" % 12ld % 12ld", f1, f2);
		if (i % 2 == 0) printf("\n");/*���������ÿ���ĸ�*/
		f1 = f1 + f2;/*ǰ�����¼�������ֵ����������*/
		f2 = f1 + f2; /*ǰ�����¼�������ֵ����������*/
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