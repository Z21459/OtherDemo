#pragma once
#include <iostream>
using namespace std;

enum ShopBuy
{
	DAZHE = 1,
	MANJIAN = 2,
	YOUHUISONG =3,
};
//���� �����㷨
class ShopDaZhe
{
public:
	ShopDaZhe();
	~ShopDaZhe();
	virtual void JuTiWays() {};
};

//�������  �����㷨
class StrategyA :public ShopDaZhe
{
public:
	void JuTiWays() {
		cout << "a";
	}
};

class StretegyB :public ShopDaZhe
{
public:
	void JuTiWays()
	{
		cout << "b";
	}
};

//���������� ������
class Context
{
public:
	ShopDaZhe *shop;

	//����ģʽ
	//Context(ShopDaZhe *shop)//��ʼ������������
	//{
	//	this->shop = shop;
	//}
	void ContextInfeace()//ͨ����� ���÷���  ִ�н��
	{
		shop->JuTiWays();//���ݲ���  ���÷���
	}

	//���Ժ͹������
	Context(int id)
	{
		switch (id) 
		{
		case DAZHE:
		{   //case ���涨�� ���� һ��Ҫ��{} ������  ���߻ᱨ�� case��ǩ����
			StrategyA *A = new StrategyA;
			shop = A;
			break;
		}
		case MANJIAN:
			StretegyB *B = new StretegyB;
			shop = B;
			break;
		}
	}
};

