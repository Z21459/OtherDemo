#include <iostream>
#include"MoBan.h"
using namespace std;

/*
ģ�巽����
����һ�������е��㷨�Ǽܣ����������ӳٵ�������ȥ��ģ�����ʹ���಻�ı�
һ���㷨�Ľṹ�������ض�����㷨��ĳЩ�ض�����


ģ�巽�����Ѳ���İ��Ƶ�������ȥ��ȥ�������е��ظ�����  ��������
*/

int main()
{
	//�ͻ���
	MoBan *m = new MoBan;
	m = new Con1();
	m->ab1();
	m->ab2();
	m = new Con2();
	m->ab1();
	m->ab2();

	system("pause");
	return 0;
}