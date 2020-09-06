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
		if (signle == nullptr)//不存在 new一个 ，存在直接返回
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

