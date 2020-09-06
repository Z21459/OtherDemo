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


//部门表
//和用户表相似








//定义工厂方法接口
class IFactory
{
public:
	virtual IUser *CreateUser() { return NULL; }

	//多添加一个部分接口 
	//virtual IDepartment *CreateDepartment()
};

class S1Factory :public IFactory
{
public:
	IUser *CreateUser()
	{
		return (new S1());
	}
	//添加对应的部门类工厂
};

class S2Factory :public IFactory
{
public:
	IUser *CreateUser()
	{
		return new S2();
	}
	//同S1
};




class ChouXiangGongChang
{
public:
	ChouXiangGongChang();
	~ChouXiangGongChang();
};

