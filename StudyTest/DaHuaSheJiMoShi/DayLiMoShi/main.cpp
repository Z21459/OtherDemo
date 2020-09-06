#include <iostream>
#include"Proxy.h"
using namespace std;

/*
代理模式   追求者通过代理者把礼物送给被追求者 实现代理模式

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