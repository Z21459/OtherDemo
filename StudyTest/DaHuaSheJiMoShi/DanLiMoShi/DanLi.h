#pragma once
#include <iostream>
#include <string>
using namespace std;



class DanLi
{
public:
	DanLi();
	~DanLi();
};


class Signle
{
private:
	Signle(){}
	~Signle(){}
private:
	static Signle *signle;

public:
	static Signle& getInstance()
	{
		if (signle == nullptr)//������ newһ�� ������ֱ�ӷ���
		{
			signle = new Signle();
			cout << "1" << endl;
			return *signle;
		}
		else
		{
			cout << "222" << endl;
			return *signle;
		}
		
	}
};

