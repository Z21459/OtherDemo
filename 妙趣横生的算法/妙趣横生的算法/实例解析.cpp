#define  _CRT_SECURE_NO_WARNINGS

#include "allHead.h"

/*
1.�ַ�����ͳ����
2.�����ַ���ASCII��  //1�ֽ� 8(bits)λ  �ո���32
3.if-else���Ƕ��
4.����switch���������� --���������� ǰ׺��
5.���꣨�ܱ�4 ���ܱ�400����||��4�������ܱ�100������
6.ָ�������������
7.����ת��
8.����˷�
9.λ���㽻��
10.�ļ���д
11.�����ļ���С
12.��¼��������ʱ��
13.ʮ����ת������


*/

//ͳ���ַ����ڲ����е��ַ�
void countZiFu(string str,int space,int &table,int &enter)
{
	for (int i = 0; i < str.length(); i++)
	{
		switch (str[i])
		{
		case 32://�ո�
			space++;
			break;
		case 9://�Ʊ��
			table++;
			break;
		case 10://���з�
			enter++; 
			break;
		default:
			break;
		}
	}
}
//�ַ���ASCII
void asciiMa(char s)
{
	//��%c �ĳ�%d  ����ľ���ascii��
	printf("%c  %d\n", s,s);
}
//switch������
void yiMaQi(string str,string dest)
{
	for (int i = 0; i < str.length(); i++)
	{
		switch ((str[i] - '0'))//ת��ɳ���
		{
		case 1:
			dest += 'a';
			break;
		case 0:
		{
			i++;
			switch ((str[i] - '0'))
			{
			case 1:
				dest += 'b';
				break;
			case 0:
			{
				i++;
				switch ((str[i] - '0'))
				{
				case 1:
					dest += 'c';
					break;
				}
				break;
			}
			default:
				break;
			}
		}
		default:
			break;
		}
	}
}
//����
bool runYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0) return true;
	if (year % 400 == 0) return true;
	return false;
}
//ָ�������������
void inputArray(int *str)
{
	for (int i = 0; i < 10; i++)
	{
		//*(str + i) = (rand() % 10 + 1) + '0';//����ַ���
		*(str + i) = i;
	}
}
//����ת������
void arrResv(int(*a)[4], int(*b)[3])//a��ԭ����  b��ת��ľ���
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
			b[i][j] = a[j][i];
	}
}
//����˷� add�� sub�� mul��  div��
void arrMul(int(*a)[3], int(*b)[4])
{
	int c[2][4] = { {0,0,0,0,} };//a���� b����
	int i, j, k;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 3; k++)
			{
				c[i][j] = a[i][j] + a[i][k] * b[k][j];
			}
		}
	}
}
//λ���㽻��
void bitSwap(int &a, int &b)
{
	        //  a    b
	        //  10   01
	a ^= b; //  11   01
	b ^= a; //  11   10
	a ^= b; //  01   10
}
//�ļ���д
void readWrite(string path)
{
	//FILE *fopen  fclose  fread fwrite
	FILE *fp;
	char pathName[20], txt1[20] = { '\0' }, txt2[20] = { '\0' };

	//��
	fp = fopen(pathName, "w");
	int fileLen = strlen(txt1);
	fwrite(txt1, fileLen, 1, fp);
	fclose(fp);

	fp = fopen(pathName, "r");
	fread(txt2, fileLen, 1, fp);
	fclose(fp);

}
//�����ļ���С
void cauFile()
{
	//fseek--����ָ���ļ����  ftell--ָ���ļ���ͷ���ƫ����

	FILE *fp;
	long f;
	fp = fopen(" file", "w");
	fseek(fp, 0, SEEK_END);//ָ���β
	f = ftell(fp);
	fclose(fp);
	cout << f;
}
//��¼��������ʱ��
void cauTime()
{
	clock_t start, end;
	start = clock();
	Sleep(1);
	end = clock();
}
//ʮ����ת������
void tenTotwo(int a)
{
	stack<int>sta;
	while (a)
	{
		int temp = a % 2;
		sta.push(temp);
		a = a / 2;
	}
	while (!sta.empty())
	{
		cout << sta.top();
		sta.pop();
	}
}


//��������ַ��� �ݹ� ͨ��ջ����ʵ��
void rPrint()
{
	char a;
	scanf("%c", &a);
	if (a != '#') rPrint();
	if (a != '#') printf("%c", a);
}


int mains()
{
	//EOF //�ַ���β��
	//getchar()  //�õ��ַ�

	//asciiMa('a');

	//int arr[10];
	//inputArray(arr);
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << arr[i] << " ";
	//}
	//cout << "\n";

	//tenTotwo(4);
	rPrint();


	system("pause");
	return 0;
}