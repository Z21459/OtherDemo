#define _CRT_SECURE_NO_WARNINGS

#include"allHead.h"

#include <stdio.h>
#include <stdlib.h>

//字符串长度  strlen第一个字符串开始  到结束符0 中间的个数
/*
遍历  复制-防止越界  比较   删除  分割
*/
//打印
void printStr(const char*str)
{
	for (int i = 0; i < sizeof(str); i++)
	{
		printf("%c", str[i]);
		printf(" ");
	}
	printf("\n");
}
//test 各种字符串指针  和数组之间关系  指针可以转换成数组
//数值和指针 之间有着很微妙的关系  要善于利用   大小端 ：大端 高位存入低地址
void testPoint(const char *str)
{
	const char *des = str;
	//des++;
	//printf("des++    %c", *des);//b

	//printf("*des++    %c", *des++);//a

	//*des++;
	//printf("*des++    %c", *des);//b

	//*++des;
	//printf("*++des     %c", des);//y

	//printf("*++des     %c", *++des);//b

	//printf("*++des     %c", *(++des));//b

	const char arr[] = "abcde";

	//printf("%c", arr[1]); //b
	//printf("%c", *(arr+1)); //b
	//printf("%c", *arr); //a
	//printf("%c", *(des + 1));//b
}


//移动一次火柴棍  使等式成立
#include <vector>
#include <map>
#include <iostream>
#include <string>
using namespace std;
using std::string;
//定义运算是否出错
#define ERROR "Error"
//定义通过移动 减一个  加一个
#define SUBONE 1
#define ADDONE 2
#define SELFMOVE 3
#define NOMOVE 4

typedef map<int, int> Map;
Map _map_one;//定义三个数 的其余数
Map _map_two;
Map _map_three;
//输入三数 和符号 ，移动一笔 然后判断是否满足等式
void isOtherNum(int t,Map &tem_map)//用以输入一个数  将map进行保存
{
	switch (t)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		tem_map.insert(Map::value_type(3, NOMOVE));
		tem_map.insert(Map::value_type(9, ADDONE));
		tem_map.insert(Map::value_type(2, SELFMOVE));
		tem_map.insert(Map::value_type(5, SELFMOVE));
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		tem_map.insert(Map::value_type(6, NOMOVE));
		tem_map.insert(Map::value_type(8, ADDONE));
		tem_map.insert(Map::value_type(5, SUBONE));
		tem_map.insert(Map::value_type(0, SELFMOVE));
		tem_map.insert(Map::value_type(9, SELFMOVE));
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	default:
		break;
	}
}

bool isSucess(int a, int b, int c,char &s)
{
	if (a + b == c)
	{
		s = '+';
		return true;
	}
	if (a - b == c)
	{
		s = '-';
		return true;
	}
	else return false;
}

void inputNum(int a, int b, char str,int c)
{
	//数据合法性
	//printf("%c", str);
	if (!(str == '+' || str == '-'))
	{
		printf("%s\n", ERROR);
		return;
	}
	if (a < 0 || b < 0 || c < 0)
	{
		printf("%s\n", ERROR);
		return;
	}
	printf("原:%d %c %d = %d",a, str,b,c);
	isOtherNum(a, _map_one);//得到3个map  然后进行组合
	isOtherNum(b, _map_two);
	isOtherNum(c, _map_three);
	Map::iterator iter1 = _map_one.begin();
	Map::iterator iter2 = _map_two.begin();
	Map::iterator iter3 = _map_three.begin();
	bool first = false , second = false;
	int aa = 0, bb = 0, cc = 0;
	for (; iter1 != _map_one.end(); iter1++)
	{
		for (; iter2 != _map_two.end(); iter2++)
		{
			for (; iter3 != _map_three.end(); iter3++)
			{
				//构建一个函数  判断是否移动的值
				if (isSucess(iter1->first, iter2->first, iter3->first, str))
				{
					aa = iter1->first, bb = iter2->first, cc = iter3->first;
					second = true;
					break;
				}
			}
			if (second)
			{
				first = true;
				break;
			}
		}
		if (first) break;
	}
	printf("\n");
	printf("移动:%d %c %d = %d \n", aa, str ,bb, cc);
}

void swap_str(string &str,string &des, int j, int k)
{
	for (int i = k-1; i >= j; i--)
	{
		des += str[i];
	}
}
void recvStr(string &str)
{
	//stack<char> temstack;
	//for (int i = 0; i < str.length(); i++)
	//{
	//	temstack.push(str[i]);
	//}
	//str = " ";
	//while (!temstack.empty())
	//{
	//	str += temstack.top();
	//	temstack.pop();
	//}
	string pp = "";
	for (int i = str.length()-1; i >=0; i--)
	{
		pp += str[i];
	}
	//cout << pp;//ttz cba
	str = pp;
	int j = 0, k = 0;
	string des = "";
	for (int i = 0; i <= str.length(); i++)
	{
		if (str[i] == ' ' || i == str.length())
		{
			k = i;
			swap_str(str, des,j, k);
			des += ' ';
			j = k = i + 1;
		}
	}
	std::cout << des;
}

struct A//结构体 继承 和虚函数 和类相同
{
public:
	virtual void fun1() { cout << "1"; }
};

struct B :public A
{
public:
	virtual void fun1() { cout << "2"; }
	void fun2() { cout << "3"; }
};


int main()
{

	//const char* str = "abcde";
	//printStr(str);
	//testPoint(str);

	//char str = ' ';//输入一个字符   如果是字符串 const char*
	//scanf("%c", &str);//输入%s  否则出错
	//int a = 0, b = 0 ,c = 0;
	//scanf("%d%d%d", &a, &b,&c);
	//inputNum(a, b, str, c);

	//char s1 = 'b';
	//char s2 = 'D';
	////if (s1 - 'a' > s2 - 'A') 
	//std::cout << (s1 - 'a') << " " << (s2 - 'A');//1 3

	//char arr[][2] = { 1,2,3,4 };
	//string d = "abcde aaaa";
	//string *a = &d;
	//string **p = &a;
	//std::cout << (**p);// abcde aaaa

	//IntIntMap tem_map;
	//tem_map.insert(IntIntMap::value_type(3, NOMOVE));
	//tem_map.insert(IntIntMap::value_type(9, ADDONE));
	//tem_map.insert(IntIntMap::value_type(2, SELFMOVE));
	//tem_map.insert(IntIntMap::value_type(5, SELFMOVE));
	//FOR_EACH(IntIntMap, tem_map, iter)
	//{
	//	cout << iter->first;
	//}



	//string str = "abc ztt";
	//recvStr(str);
	//std::cout << str;

	//cout << endl;
	//int arr[5] = { 1,2,3,4,5 };
	//int *pt = arr;//指向1
	//cout << *pt << endl;
	//pt = pt + 1;//指向2
	//int *pe = &arr[4];//指向5
	//cout << *pe << endl;
	//pe = pe - 1;//指向4
	//int diff = pe - pt;
	//cout << *pt << " " << *pe << " "<<diff;

	A *a = new A();//结构体 可以多态
	if (a == nullptr) cout << "a null";
	else
	{
		a->fun1();
		cout << " ";
		a = new B();//指向子类
		a->fun1();
		cout << " ";
	}


	A a1;
	a1.fun1();
	B b1;
	a1 = b1;
	cout << " ";
	a1.fun1();
	//b1.fun1();


	system("pause");
	return 0;
}