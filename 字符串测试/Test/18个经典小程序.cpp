#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "allHead.h"
#include <thread>
using namespace std;

//C语言必背18个经典程序


//9*9乘法表
void Formula()
{
	int i, j, result;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			if (j > i) continue;
			result = i * j;
			printf("%d*%d = %-3d", j, i, result);/*-3d表示左对齐，占3位*/
		}
		printf("\n");/*每一行后换行*/
	}
}

//小白兔生小白兔
void WhiteRabbit()
{
	long f1, f2;
	int i;
	f1 = f2 = 1;
	for (i = 1; i <= 20; i++)
	{
		printf(" % 12ld % 12ld", f1, f2);
		if (i % 2 == 0) printf("\n");/*控制输出，每行四个*/
		f1 = f1 + f2;/*前两个月加起来赋值给第三个月*/
		f2 = f1 + f2; /*前两个月加起来赋值给第三个月*/
	}
}

void rev(char *str)
{
	char *temp = str, *end = str, *start = str;
	while (*temp++)
	{
		if (temp == " " || temp == "\n")
		{
			end = temp - 1;
			while (start < end)
			{
				swap(*start++, *end--);
			}
			end = start = temp + 1;
		}
	}
	start = str, end = str - 2;
	while (start<end)
	{
		swap(*start++, *end--);
	}
}

void onMoHuMatch()
{
	vector <string> vec_str;
	vec_str.push_back("abcds");
	vec_str.push_back("abd");
	vec_str.push_back("bc");

	string key = "bc";
	vector<string>::iterator iter = vec_str.begin();
	for (; iter != vec_str.end(); iter++)
	{
		if ((*iter).find(key) != (*iter).npos)//如果找到了  返回下标位置，没找到则取值到末尾
		{
			cout << (*iter) << " ";
		}
	}

}


std::mutex mt;
class A
{
private:
	A(){}
	A(const A&f){}
	A& operator=(const A&) { return *this; }
public:
	static A *onGetA()
	{
		if (_a == nullptr)
		{
			mt.lock();
			if (_a == nullptr)
			{
				_a = new A();
			}
			mt.unlock();
		}
		return _a;
	}
private:
	static A *_a;

};
//多态需要写一个基类  和多个子类   再写一个参数类型为基类的函数
//小写转大写  c-'a'+'A'
//时间换空间  空间换时间---不同场景看
class B
{
public:
	virtual void onEat() {};
	virtual void onSleep() {};
};
class A1 :public B
{
public:
	void onEat() { cout << "a1e"; }
	void onSleep() { cout << "a1s"; }
};
class A2 :public B
{
public:
	void onEat() { cout << "a2e"; }
	void onSleep() { cout << "a2s"; }
};

void onSelect(B &a) {
	a.onEat();
	a.onSleep();
}

typedef map<string, string> Map;
void onReplaceStr()
{
	// 规则  如果abc  变成cba    -》如果cba-》abc就不生效
	string str = "abc 123 cdv cba";
	Map mapStr;
	mapStr["abc"] = "cba";
	mapStr["123"] = "321";
	mapStr["cba"] = "abc";
	Map::iterator iter = mapStr.begin();
	int index = 0;
	int lenRe = 0;//记录替换单词的长度
	for (; index != string::npos;)
	{
		if (index = str.find(mapStr["abc"]) != string::npos)
		{
			str.replace(index, mapStr["abc"].length(), mapStr["abc"]);
		}
		else if(index = str.find(mapStr["123"]) != string::npos)
		{
			str.replace(index, mapStr["123"].length(), mapStr["123"]);
		}
		else if (index = str.find(mapStr["cba"]) != string::npos)
		{
			str.replace(index, mapStr["cba"].length(), mapStr["cba"]);
		}
		else
		{
			break;
		}
		index = mapStr["abc"].length();
	}
	cout << str;
}


int main()
{
	//Formula();
	//WhiteRabbit();

	//onMoHuMatch();


	//A1 a1;
	//A2 a2;
	//onSelect(a2);

	onReplaceStr();

	system("pause");
	return 0;
}