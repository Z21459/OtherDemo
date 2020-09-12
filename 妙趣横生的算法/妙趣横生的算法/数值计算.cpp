#define _CRT_SECURE_NO_WARNINGS


#include "allHead.h"
/*
数值积分  方程求根  常微分方程求解  解线性方程

1.使用迭代 求解开根  区域值
2.破碎的砝码---穷举法  40g分成4块 可以得到1-40任意
3.求解24  --穷举法得到  考虑加不加括号进行运算
4.马踏棋盘  深度优先搜索的思想
5.简单文件加密解密

*/

//迭代开根方
void onOpenSqur()
{
	int input = 0;
	double xx = input, x = 0.0;
	while (abs(xx-x)>0.00001)
	{
		x = xx;
		xx = 0.5*(x + input / x);
	}
	cout << xx;


}
//高效的穷举 只考虑组合 不考虑排列
int onGetWeight(int i, int j, int k, int s, int weight)
{
	int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
	for (x1 = -1; x1 <= 1; x1++)
	{
		for (x2 = -1; x2 <= 1; x2++)
		{
			for (x3 = -1; x3 <= 1; x3++)
			{
				for (x4 = -1; x4 <= 1; x4++)
				{
					if (x1*i + x2 * j + x3 * k + x4 * s == weight)
					{
						return 1;
					}
				}
			}
		}
	}
	return 0;
}
int onJustify(int i, int j, int k, int s)
{
	int weight = 0;
	for (weight = 1; weight <= 40; weight++)
	{
		if (!onGetWeight(i, j, k, s, weight))
		{
			return 0;
		}
	}
	return 1;
}
void onZuHe()
{
	int i = 0, j = 0, k = 0, s = 0;
	for (i = 0; i <= 40; i++)
	{
		for (j = i + 1; j <= 40 - i; j++)
		{
			for (k = j + 1; k <= 40 - j - i; k++)
			{
				for (s = k + 1; s <= 40 - k - i - j; s++)
				{
					//得到一个组合  防止出现相同组合 不同排列
					if (i + j + k + s == 40)
					{
						if (onJustify(i, j, k, s))
						{
							cout << i << j << k << s << endl;
						}
					}
				}
			}
		}
	}
}
//简单文件加密解密
//读取源文件 用以加密和解密
void test()
{
	//FILE *fp, *temp;
	//char c[] = "This is runoob";
	//char buffer[20];

	///* 打开文件用于读写 */
	//fopen_s(&fp,"file.txt", "rb");

	///* 写入数据到文件 */
	////fwrite(c, strlen(c) + 1, 1, fp);

	///* 查找文件的开头 */
	//fseek(fp, 0, SEEK_SET);
	///* 读取并显示数据 */
	//fread(buffer, 1,strlen(c) + 1, fp);
	//printf("%s\n", buffer);
	//fclose(fp);


	FILE *fp;
	int len;

	fp = fopen("file.txt", "r");
	if (fp == NULL)
	{
		perror("打开文件错误");
		return;
	}
	fseek(fp, 0, SEEK_END);//先定位到尾部 求大小
	len = ftell(fp);
	char *str = new char[len + 1];
	//memset(str, 0, len + 1);//栈中不初始化可能出现 烫烫   堆中不初始化可能出现  屯屯屯     数组没有结束符也坑你会出现
	
	fseek(fp, 0, SEEK_SET);//再定位到头
	fread(str, 1, len + 1, fp);
	str[len] = '\0';//结束标志位
	printf("%s", str);
	fclose(fp);
	printf("file.txt 的总大小 = %d 字节\n", len);

	return;
}
int onOpenFile(char **buf, int flag)
{
	FILE *fp;
	//char filenames[20];
	long file_size;
	//scanf_s("%s", filenames);//输入文件名
	const char *filenames = NULL;
	if(flag == 0) filenames = "./jiami.txt";//NULL;
	if (flag == 1) filenames = "./jiemi.txt";
	//int p = fopen_s(&fp, "E:\\FileCsv\\jiami.txt", "rb");
	if ((fopen_s(&fp, filenames, "rb"))) cout << "Error \n";  //fopen_s  等于0返回成
	fseek(fp, 0, SEEK_END);
	file_size = ftell(fp);//文件长度
	*buf = new char[file_size+1];
	char buffer[1024];
	fseek(fp, 0, SEEK_SET);
	fread(*buf, 1, file_size + 1, fp); //file_size是0 证明打开错误
	(*buf)[file_size] = '\0';//结束标志  运算符优先级 否者也会出错
	printf("%s", *buf);
	fclose(fp);
	return file_size;

}
void onJiaMi(char buf[], int file_size, int key)
{
	int i = 0;
	for (i = 0; i < file_size; i++)
	{
		buf[i] = buf[i] + key;
	}
}
void onJieMi(char buf[], int file_size, int key)
{
	int i = 0;
	for (i = 0; i < file_size; i++)
	{
		buf[i] = buf[i] - key;
	}
}
void onSaveFile(char *buf, long file_size,int flag)
{
	FILE *fp;
	//char filenames[20];
	//scanf_s("%s", filenames);
	//const char *filenames = "E:\\FileCsv\\jiami.txt";//NULL;
	//int p = (fopen_s(&fp, filenames, "wb"));
	const char *filenames = NULL;
	if (flag == 0) filenames = "./jiemi.txt";//NULL;
	if (flag == 1) filenames = "./jiemi11.txt";
	if ((fopen_s(&fp,filenames, "w+"))) cout << "Error \n";
	fwrite(buf, 1, file_size, fp);
	fclose(fp);
	return;
}
void onJiaMiAndJieMi()
{
	//加密解密算法  函数
	char *buf = NULL;
	int key = 0;
	int flag = 0;
	long file_size = 0;
	while (1)
	{
		cout << "输入加解密 ";
		cin >> flag;
		if (flag == 2) break;
		cout << endl;
		file_size = onOpenFile(&buf, flag);
		cin >> key;

		if (flag == 0)
		{
			onJiaMi(buf, file_size, key);
		}
		else if (flag == 1)
		{
			onJieMi(buf, file_size, key);
		}
		else
		{
			cout << "Error \n";
			return;
		}
		onSaveFile(buf, file_size,flag);
	}
}



int main()
{


	//onZuHe();

	onJiaMiAndJieMi();
	//test();

	system("pause");
	return 0;
}