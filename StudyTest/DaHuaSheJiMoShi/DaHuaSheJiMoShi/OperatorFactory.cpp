#include "OperatorFactory.h"
#include"OperatorItem.h"
#include <iostream>
using namespace std;

enum Caculate
{
	ADD = 1,
	SUB = 2,
	CHENG = 3,
	CHU = 4
};
OperatorFactory::OperatorFactory()
{
}


OperatorFactory::~OperatorFactory()
{
}

OperatorItem* OperatorFactory::createOperate(int s)
{
	OperatorItem *oper = NULL;
	switch (s)
	{
	case ADD:
		oper = new  AddClass;
		break;
	case SUB:
		oper = new W;
		break;
	default:
		break;
	}
	return oper;
}
