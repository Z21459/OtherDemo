#include<iostream>
#include "GongChangFangFa.h"
using namespace std;

/*
�򵥹������������а����˱�Ҫ���߼��ж� ���ݿͻ��˵�ѡ��������̬ʵ���������
��������������һ�����ڴ������� �ӿڣ����������ʵ�����ĸ��ࡣʹһ�����ʵ�����ӳٵ�����


*/
int main()
{
	IFactory1 *fac = new Stu;
	LeiFeng *s = fac->createLef();
	s->do1();
	s->do2();


	system("pause");
	return  0;
}