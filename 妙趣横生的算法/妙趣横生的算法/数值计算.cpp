#define _CRT_SECURE_NO_WARNINGS


#include "allHead.h"
/*
��ֵ����  �������  ��΢�ַ������  �����Է���

1.ʹ�õ��� ��⿪��  ����ֵ
2.���������---��ٷ�  40g�ֳ�4�� ���Եõ�1-40����
3.���24  --��ٷ��õ�  ���ǼӲ������Ž�������
4.��̤����  �������������˼��
5.���ļ����ܽ���

*/

//����������
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
//��Ч����� ֻ������� ����������
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
					//�õ�һ�����  ��ֹ������ͬ��� ��ͬ����
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
//���ļ����ܽ���
//��ȡԴ�ļ� ���Լ��ܺͽ���
void test()
{
	//FILE *fp, *temp;
	//char c[] = "This is runoob";
	//char buffer[20];

	///* ���ļ����ڶ�д */
	//fopen_s(&fp,"file.txt", "rb");

	///* д�����ݵ��ļ� */
	////fwrite(c, strlen(c) + 1, 1, fp);

	///* �����ļ��Ŀ�ͷ */
	//fseek(fp, 0, SEEK_SET);
	///* ��ȡ����ʾ���� */
	//fread(buffer, 1,strlen(c) + 1, fp);
	//printf("%s\n", buffer);
	//fclose(fp);


	FILE *fp;
	int len;

	fp = fopen("file.txt", "r");
	if (fp == NULL)
	{
		perror("���ļ�����");
		return;
	}
	fseek(fp, 0, SEEK_END);//�ȶ�λ��β�� ���С
	len = ftell(fp);
	char *str = new char[len + 1];
	//memset(str, 0, len + 1);//ջ�в���ʼ�����ܳ��� ����   ���в���ʼ�����ܳ���  ������     ����û�н�����Ҳ��������
	
	fseek(fp, 0, SEEK_SET);//�ٶ�λ��ͷ
	fread(str, 1, len + 1, fp);
	str[len] = '\0';//������־λ
	printf("%s", str);
	fclose(fp);
	printf("file.txt ���ܴ�С = %d �ֽ�\n", len);

	return;
}
int onOpenFile(char **buf, int flag)
{
	FILE *fp;
	//char filenames[20];
	long file_size;
	//scanf_s("%s", filenames);//�����ļ���
	const char *filenames = NULL;
	if(flag == 0) filenames = "./jiami.txt";//NULL;
	if (flag == 1) filenames = "./jiemi.txt";
	//int p = fopen_s(&fp, "E:\\FileCsv\\jiami.txt", "rb");
	if ((fopen_s(&fp, filenames, "rb"))) cout << "Error \n";  //fopen_s  ����0���س�
	fseek(fp, 0, SEEK_END);
	file_size = ftell(fp);//�ļ�����
	*buf = new char[file_size+1];
	char buffer[1024];
	fseek(fp, 0, SEEK_SET);
	fread(*buf, 1, file_size + 1, fp); //file_size��0 ֤���򿪴���
	(*buf)[file_size] = '\0';//������־  ��������ȼ� ����Ҳ�����
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
	//���ܽ����㷨  ����
	char *buf = NULL;
	int key = 0;
	int flag = 0;
	long file_size = 0;
	while (1)
	{
		cout << "����ӽ��� ";
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