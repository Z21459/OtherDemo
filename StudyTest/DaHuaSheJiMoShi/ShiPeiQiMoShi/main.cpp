#include <iostream>
#include "ShiPeiQi.h"
using namespace std;

/*
������ģʽ����һ����Ľӿ�ת���ɿͻ�ϣ��������һ���ӿ�
Adapterģʽʹ��ԭ�����ڽӿڲ����ݶ�����һ��������Щ�����һ����

�����֣���������   ���������� ģʽ

//ʹ��һ���Ѿ����ڵ��࣬��������ǵĽӿ�(����)����Ҫ����ͬ����Ӧ�ÿ���������ģʽ
������������������ͬ�������ƣ����Ǿ��в�ͬ�Ľӿ�ʱʹ��


*/



int main()
{

	Target *target = new Adapter;//���൱����ʹ��  ͨ����̬ʵ��
	target->Request();
	cout << endl;

	Player *p = new Forwards("wang");
	p->Attach();
	p->Defend();

	Player *ym = new Translator("yao");
	ym->Attach();
	ym->Defend();

	system("pause");
	return 0;
}