#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

class User
{
public:

};
class IUser
{
public:
	virtual void Insert(User *user) {}
	virtual User *getUser(int uid) { return nullptr; }
};

class S1 :public IUser
{
public:
	S1(){}
	~S1(){}
	void Insert(User *user)
	{
		cout << "Insert 1";
	}
	User *getUser(int uid)
	{
		cout << "get1";
		return nullptr;
	}
};

class S2 :public IUser
{
public:
	S2(){}
	~S2(){}
	void Insert(User *user)
	{
		cout << "Insert2";
	}
	User *getUser(int uid)
	{
		cout << "get2";
		return nullptr;
	}

};


//���ű�
//���û�������








//���幤�������ӿ�
class IFactory
{
public:
	virtual IUser *CreateUser() { return NULL; }

	//�����һ�����ֽӿ� 
	//virtual IDepartment *CreateDepartment()
};

class S1Factory :public IFactory
{
public:
	IUser *CreateUser()
	{
		return (new S1());
	}
	//��Ӷ�Ӧ�Ĳ����๤��
};

class S2Factory :public IFactory
{
public:
	IUser *CreateUser()
	{
		return new S2();
	}
	//ͬS1
};




class ChouXiangGongChang
{
public:
	ChouXiangGongChang();
	~ChouXiangGongChang();
};

