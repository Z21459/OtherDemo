#include <iostream>
#include"Component.h"
using namespace std;


/*
װ����ģʽ
��̬�ĸ�һ���������һЩ�����ְ��
�͹�����˵�������������Ϊ���

*/
int main()
{
	//װ�η��� 
	/*
	1.�� Com1ʵ����c
	2.��ʵ��������a1��װc
	3.��ʵ��������b1��װa1
	���ִ��b1��operator��
	*/
	//Com1 *c = new Com1;
	//DecoratorA *a1 = new DecoratorA;
	//DecoratorB *b1 = new DecoratorB;

	//a1->SetCom(c);
	//b1->SetCom(a1);
	//b1->Operator();


	Component *c = new Component("111");
	JuTiDec *j1 = new JuTiDec;
	JuTiDec1 * j2 = new JuTiDec1;
	j1->setDec(c);
	j2->setDec(j1);
	j2->Operator();

	system("pause");
	return 0;
}