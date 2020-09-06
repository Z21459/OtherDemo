#pragma once
#include"OperatorItem.h"
#include <string>
using namespace std;
class OperatorFactory
{
public:
	OperatorFactory();
	~OperatorFactory();
	static OperatorItem* createOperate(int s);
};

