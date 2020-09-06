#include <iostream>
#include"ChouXiangGongChang.h"
using namespace std;

/*
工厂方法模式是定义一个用于创建对象的接口，让子类决定实例化哪一个

IUser --- SQLUser  AccessUser
IFactory  --SQLFactory(CreateUser()/CreateDeparment())  AccessFactory(CreateUser()/CreateDeparment)
IDepartment  ---SQLDepartment AccessDeparment

提供创建一系列相关或相互依赖对象的接口，而无需指定他们具体的类



*/

int main()
{
	//
	User *user = new User;
	IFactory *factor = new S1Factory();// 只需要更改对应的类创建就可以

	IUser *iu = factor->CreateUser();

	iu->Insert(user);
	iu->getUser(1);


	//同User


	system("pause");
	return 0;
}