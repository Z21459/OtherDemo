#include <iostream>
#include"ChouXiangGongChang.h"
using namespace std;

/*
��������ģʽ�Ƕ���һ�����ڴ�������Ľӿڣ����������ʵ������һ��

IUser --- SQLUser  AccessUser
IFactory  --SQLFactory(CreateUser()/CreateDeparment())  AccessFactory(CreateUser()/CreateDeparment)
IDepartment  ---SQLDepartment AccessDeparment

�ṩ����һϵ����ػ��໥��������Ľӿڣ�������ָ�����Ǿ������



*/

int main()
{
	//
	User *user = new User;
	IFactory *factor = new S1Factory();// ֻ��Ҫ���Ķ�Ӧ���ഴ���Ϳ���

	IUser *iu = factor->CreateUser();

	iu->Insert(user);
	iu->getUser(1);


	//ͬUser


	system("pause");
	return 0;
}