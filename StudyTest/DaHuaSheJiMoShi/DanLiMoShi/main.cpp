#include <iostream>
#include "DanLi.h"
using namespace std;

/*
����ģʽ--�̰߳�ȫ

���������������  ����û�м�ֵ�Ķ���

�����඼�й��췽������������ϵͳĬ�����ɿյĹ��췽����
������ʾ����Ĺ��췽����Ĭ�Ϲ��췽���ͻ�ʧЧ

��˽���Ĺ��캯������д��private���ⲿ�����Ͳ���new

��֤��ֻ��һ��ʵ�������ṩһ����������ȫ�ַ��ʵ�



*/

Signle* Signle::signle = nullptr;//��̬������ʼ��
int main()
{

	Signle::getInstance();
	Signle::getInstance();//ֻ���ʼ��һ��
	//if (sign == sign1)
	//{
	//	cout << "ok";
	//}
	system("pause");
	return 0;
}