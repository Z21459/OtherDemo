#define  _CRT_SECURE_NO_WARNINGS

#include "allHead.h"

/*
1.字符类型统计器
2.计算字符的ASCII码  //1字节 8(bits)位  空格是32
3.if-else语句嵌套
4.基于switch语句的译码器 --哈夫曼编码 前缀码
5.闰年（能被4 又能被400整除||被4整除不能被100整除）
6.指针变量当做参数
7.矩阵转置
8.矩阵乘法
9.位运算交换
10.文件读写
11.计算文件大小
12.记录程序运行时间
13.十进制转二进制


*/

//统计字符串内部含有的字符
void countZiFu(string str,int space,int &table,int &enter)
{
	for (int i = 0; i < str.length(); i++)
	{
		switch (str[i])
		{
		case 32://空格
			space++;
			break;
		case 9://制表符
			table++;
			break;
		case 10://换行符
			enter++; 
			break;
		default:
			break;
		}
	}
}
//字符的ASCII
void asciiMa(char s)
{
	//将%c 改成%d  输出的就是ascii码
	printf("%c  %d\n", s,s);
}
//switch译码器
void yiMaQi(string str,string dest)
{
	for (int i = 0; i < str.length(); i++)
	{
		switch ((str[i] - '0'))//转变成常量
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
//闰年
bool runYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0) return true;
	if (year % 400 == 0) return true;
	return false;
}
//指针变量当做参数
void inputArray(int *str)
{
	for (int i = 0; i < 10; i++)
	{
		//*(str + i) = (rand() % 10 + 1) + '0';//编程字符串
		*(str + i) = i;
	}
}
//矩阵转置运算
void arrResv(int(*a)[4], int(*b)[3])//a是原矩阵  b是转后的矩阵
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
			b[i][j] = a[j][i];
	}
}
//矩阵乘法 add加 sub减 mul乘  div除
void arrMul(int(*a)[3], int(*b)[4])
{
	int c[2][4] = { {0,0,0,0,} };//a两行 b三行
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
//位运算交换
void bitSwap(int &a, int &b)
{
	        //  a    b
	        //  10   01
	a ^= b; //  11   01
	b ^= a; //  11   10
	a ^= b; //  01   10
}
//文件读写
void readWrite(string path)
{
	//FILE *fopen  fclose  fread fwrite
	FILE *fp;
	char pathName[20], txt1[20] = { '\0' }, txt2[20] = { '\0' };

	//打开
	fp = fopen(pathName, "w");
	int fileLen = strlen(txt1);
	fwrite(txt1, fileLen, 1, fp);
	fclose(fp);

	fp = fopen(pathName, "r");
	fread(txt2, fileLen, 1, fp);
	fclose(fp);

}
//计算文件大小
void cauFile()
{
	//fseek--可以指向文件最后  ftell--指向文件开头相对偏移量

	FILE *fp;
	long f;
	fp = fopen(" file", "w");
	fseek(fp, 0, SEEK_END);//指向结尾
	f = ftell(fp);
	fclose(fp);
	cout << f;
}
//记录程序运行时间
void cauTime()
{
	clock_t start, end;
	start = clock();
	Sleep(1);
	end = clock();
}
//十进制转二进制
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


//反向输出字符串 递归 通过栈调用实现
void rPrint()
{
	char a;
	scanf("%c", &a);
	if (a != '#') rPrint();
	if (a != '#') printf("%c", a);
}


int mains()
{
	//EOF //字符串尾部
	//getchar()  //得到字符

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