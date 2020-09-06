#include <iostream>
using namespace std;

class CashSuper
{
public:
	virtual double acceptCash(double money);
};
class CashNormal :public CashSuper
{
public:
	double acceptCash(double money)
	{
		return money;
	}
};
class CashRebate :public CashSuper
{
private:
	double moneyRebate = 1.0;
public:
	CashRebate(string moneyRebate)
	{
		this->moneyRebate = atof(moneyRebate.c_str());//strign zhuan double
	}
	double acceptCash(double money) {
		return money * moneyRebate;
	}
};
class CashReturn :public CashSuper
{
public:
	CashReturn(string moneyCondition, string moneyReturn)
	{
		this->moneyCondition = atof(moneyCondition.c_str());
		this->moneyReturn = atof(moneyReturn.c_str());
	}
	double acceptCash(double money)
	{
		double result = money;
		if (money >= moneyCondition)
		{
			result = money - (money / moneyCondition)*moneyReturn;
			return result;
		}
	}
private:
	double moneyCondition = 0.0;
	double moneyReturn = 0.0;
};

class Context
{
private:
	CashSuper *cs = NULL;
public:
	Context(int type)//CashSuper cashSuper
	{
		switch (type)
		{
		case 0:
			CashNormal *cs0 = new CashNormal();
			cs = cs0;
			break;
		}
		//this->cs = cashSuper;
	}
	double getReturn(double money)
	{
		return cs->acceptCash(money);//根据策略不同
	}
};

//客户端
double total = 0.0;
void btn() {
	int type = 0;
	double getUi = 0.0;
	Context *text = new Context(type);
	double totalPrice = 0.0;
	totalPrice = text->getReturn(getUi);
	total = total + totalPrice;
}