#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define YearMes (365*24*60*60)UL //�޷��ų�����
#define Max(x,y) (((x)>(y))?(x):(y))

//& ��| λ������   ^(���)  << >> (���ƺ�����)

//  һ���ֽ�(byte) ��8λ 1k= 1024bit

//�������д����з��ź��޷�������ʱ�����в����Զ�תת���޷�������

//static: �������ڣ�������������ù�����ά��ֵ���䣩����ģ����-��������(��ģ���ڱ�����Ϊ��̬������ֻ�ܱ�ģ���ں������ã����ܱ�ģ����������������)��
		//ģ���ڣ�һ������������Ϊ��̬������ֻ�ܱ���һģ���е������������ã����������������������ģ���ڣ�

//ʹ��^ʵ�ֽ���
void Swap1(int &a,int &b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
int  main5() {
	int i = 5.01;
	float j = 5;
	//printf("%f\n", j);//64 ��ռ��8λ
	int a = 2;
	int b = 3;
	Swap1(a, b);
	cout << a << b;


	system("pause");
	return 0;
}