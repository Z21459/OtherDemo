#include<iostream>
#include"OperatorFactory.h"
#include"OperatorItem.h"

/*
�򵥹���ģʽ ��дһ�����࣬�����麯��������ֱ�̳и���ķ���
ͨ�������࣬���������ͬ��new�����Ӧ�����࣬�������������ظ����麯���ķ�����
*/
int main()
{
	//OperatorItem *oper = new OperatorItem;
	//OperatorFactory * factor = new OperatorFactory;
	OperatorItem *oper = OperatorFactory::createOperate(1);
	//oper->setA(1);
	//oper->setB(2);
	//oper->getA();
	//oper->getB();
	//cout << oper->getA();
	if (oper)
	{
		int result = oper->getResult(1, 2);
		cout << result;
	}
	system("pause");
	return 0;
}
