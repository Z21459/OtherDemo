#include "allHead.h"

/*
1.��ٷ����ڹ涨������Ľ�ռ䣬���ڽ�ռ���һһö��ÿһ�����ܵĽ�
//Ѱ��1-100��������
//Tom���� 5����3���� ��5*5*5 ����  --����ѭ��

2.�ݹ�ͷ��Σ�������ֽ��С����(�۰����--Ҳ��һ���ݹ����)
//�ݹ�n!
//���������Ļ��� һ��������������n�����ܻ���  6=6��6=2+4..

3.̰���㷨�����������ڵ�ǰ������õ�ѡ���һ�ַ���(�ֲ����Ž�)
//����װ������

4.���ݷ�:�������еĽ��У��������������Ѱ����
//N�ʺ�����

5.��ֵ�������� --���㶨����
//���ؿ���   ��˹ά��˹  ����� 

*/

//3.װ������
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

//N�ʺ�����
bool isCorrect(int i, int j, int(*Q)[4])//��ʾ��������
{
	int s, t;
	for (s = i, t = 0; t < 4; t++)//��
		if (Q[s][t] == 1 && t != j) return false;
	for (t = j, s = 0; s < 4; s++)//��
		if (Q[s][t] == 1 && s != i) return false;
	for (s = i-1, t = j-1; s>=0&&t >=  0; t--,s--)//����
		if (Q[s][t] == 1 ) return false;
	for (t = j+1, s = i+1; s < 4&&t<4; s++,t++)//����
		if (Q[s][t] == 1) return false;
	for (s = i-1, t = j+1; s>=0&&t < 4; s--,t++)//����
		if (Q[s][t] == 1) return false;
	for (t = j-1, s = i+1; s < 4&&t>=0; s++,t--)//����
		if (Q[s][t] == 1 ) return false;
	return true;
}
void Queue(int j, int(*Q)[4])//�õ���
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
			Queue(j + 1, Q);//�������������ռ�
			Q[i][j] = 0;
		}
	}
}

int maina()
{
	system("pause");
	return 0;
}