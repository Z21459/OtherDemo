#pragma once
#include <iostream>
using namespace std;


class YuanXing
{
public:
	YuanXing();
	~YuanXing();

	YuanXing(int id)
	{
		this->id = id;
	}
	int Id()
	{
		return id;
	}

	virtual YuanXing *clone() { return nullptr; }

private:
	int id;
};

class JuTiYuanXing :public YuanXing
{
public:
	JuTiYuanXing(int id) :YuanXing(id)
	{

	}
	YuanXing *clone()
	{
		return (YuanXing*)this->clone();//Ç³¸´ÖÆ
	}
};

//¿Í»§¶Ë
//void client()
//{
//	JuTiYuanXing *p1 = new JuTiYuanXing(1);
//	JuTiYuanXing *p2 = (JuTiYuanXing*)p1->clone();
//}