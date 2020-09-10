#define _CRT_SECURE_NO_WARNINGS

#include"allHead.h"

#include <stdio.h>
#include <stdlib.h>

//�ַ�������  strlen��һ���ַ�����ʼ  ��������0 �м�ĸ���
/*
����  ����-��ֹԽ��  �Ƚ�   ɾ��  �ָ�
*/
//��ӡ
void printStr(const char*str)
{
	for (int i = 0; i < sizeof(str); i++)
	{
		printf("%c", str[i]);
		printf(" ");
	}
	printf("\n");
}
//test �����ַ���ָ��  ������֮���ϵ  ָ�����ת��������
//��ֵ��ָ�� ֮�����ź�΢��Ĺ�ϵ  Ҫ��������   ��С�� ����� ��λ����͵�ַ
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


//�ƶ�һ�λ���  ʹ��ʽ����
#include <vector>
#include <map>
#include <iostream>
#include <string>
using namespace std;
using std::string;
//���������Ƿ����
#define ERROR "Error"
//����ͨ���ƶ� ��һ��  ��һ��
#define SUBONE 1
#define ADDONE 2
#define SELFMOVE 3
#define NOMOVE 4

typedef map<int, int> Map;
Map _map_one;//���������� ��������
Map _map_two;
Map _map_three;
//�������� �ͷ��� ���ƶ�һ�� Ȼ���ж��Ƿ������ʽ
void isOtherNum(int t,Map &tem_map)//��������һ����  ��map���б���
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
	//���ݺϷ���
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
	printf("ԭ:%d %c %d = %d",a, str,b,c);
	isOtherNum(a, _map_one);//�õ�3��map  Ȼ��������
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
				//����һ������  �ж��Ƿ��ƶ���ֵ
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
	printf("�ƶ�:%d %c %d = %d \n", aa, str ,bb, cc);
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

struct A//�ṹ�� �̳� ���麯�� ������ͬ
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

class Temp
{
public:
	Temp(int xx,int yy):x(xx),y(yy){}
private:
	int const x;
	int const y;
};

int main()
{

	//const char* str = "abcde";
	//printStr(str);
	//testPoint(str);

	//char str = ' ';//����һ���ַ�   ������ַ��� const char*
	//scanf("%c", &str);//����%s  �������
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
	//int *pt = arr;//ָ��1
	//cout << *pt << endl;
	//pt = pt + 1;//ָ��2
	//int *pe = &arr[4];//ָ��5
	//cout << *pe << endl;
	//pe = pe - 1;//ָ��4
	//int diff = pe - pt;
	//cout << *pt << " " << *pe << " "<<diff;

	//A *a = new A();//�ṹ�� ���Զ�̬
	//if (a == nullptr) cout << "a null";
	//else
	//{
	//	a->fun1();
	//	cout << " ";
	//	a = new B();//ָ������
	//	a->fun1();
	//	cout << " ";
	//}
	//A a1;
	//a1.fun1();
	//B b1;
	//a1 = b1;
	//cout << " ";
	//a1.fun1();
	////b1.fun1();


	vector<Temp> int_vec;
	int_vec.push_back(Temp(1, 2));
	cout << endl;

	system("pause");
	return 0;
}