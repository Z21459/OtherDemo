#include <iostream>
using namespace std;


class Gril
{
public:
	/*��һ��set����*/
	string Name()
	{
		return name;
	}
private:
	string name;
};

class Give
{
public:
	virtual void GiveMoney();
	virtual void GIveFlow();
};

class Pur :public Give
{
public:
	Gril *mm;
	Pur(Gril *mm)
	{
		this->mm = mm;
	}
	void GiveMoney()
	{
		printf_s("%s", mm->Name);
	}
	//
};
class Pro :public Give
{
public:
	Pur *pur;
	Pro(Gril *mm)
	{
		pur = new Pur(mm);
	}
	void GiveMoney()
	{
		pur->GiveMoney();
	}
};

/*
*/
void funcmian()
{
	Gril *gril = new Gril;
	gril->Name = "jiaojiao";
	Pro *dayli = new Pro(gril->Name);
	dayli->GiveMoney();//�����Ǯ
}



class MainR
{
public:
	virtual void Request();
};
class RealR :public MainR
{
public:
	void Request();
};
class dayLi :public MainR
{
public:
	void Resuest() {
		RealR *re;
		if (re == NULL)
		{
			re = new RealR;
		}
		re->Request();//��ʵ����
	}
};
/*client*/
void client() {
	dayLi *new1 = new dayLi();
	new1->Request();
}

