#include "allHead.h"


/*
指针
指针和数组

数组名[下标]
指针变量[下标]//前提指针变量指向数组


//指针和字符串
 %s 遇到\0才会停止
 %c 读取一个字符
*/

void func(int *a)
{
	*a = 20;//对a所指向的存储空间赋值
}

//返回指针的函数
char *test()
{
	const char *p = "aa";
	return const_cast<char*>(p);//将const 转成非const
}

void rever(string &str)
{
	string *p = &str;//用指针操作
	cout << *p << endl;
	int i = 0;
	while (i < (*p).length())
	{
		cout << (*p)[i];
		i++;
	}

}

//指向函数的指针
void tt()
{
	cout << "tt \n";
}
int maina()
{
	//int a = 10;
	//int *p = &a;//指针p只能指向int型的数据
	//cout << a << " " << *p <<" "<< p << endl;

	//func(&a);//将地址传给函数 修改了a的值，因为p关联了a因此p的值也被修改
	//cout << a << " " << *p << " " << p << endl;


	///*
	//指针只能指向同类的数值  
	//指针只能存储地址
	//指针没初始化，不能访问
	//*/

	////指向指针的指针
	//int b = 11;
	//int *pp = &b;
	//int **ppp = &pp;
	//cout << b << " " << *pp << " " << pp << " " << **ppp << " " 
	//	<< *ppp << " " << ppp << endl;
	//

	////指针和数组  数组名就是数组的首元素的地址
	////指针变量+1地址会加几取决于指针变量类型
	///*
	//int *p  p+1 相当于地址+4
	//char *p p+1 相当于地址+1
	//*/
	//int arr[3] = { 1,2,3 };
	//int *ap;
	//ap = &arr[0];//或者 ap = arr;
	//
	//cout << arr[1] << " " << *(ap + 1) << endl;

	
	//指针和字符串
	//char s[] = "iata";
	//const char *s1 = "iata";//指针s指向字符串首地址
	//const char *s2;
	//s2 = "iata";
	//const char *buf = "it";//指向字符串的首地址
	//printf("%c \n", *buf);
	//printf("%s \n", buf);

	//返回指针的函数
	//char *name = test();
	//printf("%s \n", name);

	//指向函数的指针
	//(*p) 固定写法，代表指针变量p将来肯定指向函数

	//void(*p)();
	//p = tt;//指针变量 指向函数
	//cout << "(*p)()    ";
	//(*p)();//直接调用  相当于调用 tt();
	//cout << "tt()    ";
	//tt();
	//cout << "p()    ";
	//p();


	string  str("absbsb");
	rever(str);

	system("pause");
	return 0;
}