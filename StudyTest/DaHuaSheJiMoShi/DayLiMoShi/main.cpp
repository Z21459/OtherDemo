#include <iostream>
#include"Proxy.h"
using namespace std;

/*
����ģʽ   ׷����ͨ�������߰������͸���׷���� ʵ�ִ���ģʽ

*/

int main()
{
	Gril *gril = new Gril;
	gril->name = "www";

	Proxy *dayli = new Proxy(gril);
	dayli->giveA();
	dayli->giveB();


	system("pause");
	return 0;
}