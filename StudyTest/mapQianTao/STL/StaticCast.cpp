#include <iostream>
using namespace std;

//static_cast ֧��ָ������ָ��ָ�������ָ��֮��ת��

class A
{
public:
	virtual void a()
	{
		cout << "a";
	}
};

class B :public A
{
public:
	void a()
	{
		cout << "b";
	}
};

int mainc()
{
	double da = 1.1;
	void *pa1 = &da;
	double *dp = static_cast<double*>(pa1);

	int ia = static_cast<int>(da);

	cout << *dp << endl;
	cout << ia << endl;

	A *pa = new A();

	B *pb = static_cast<B*>(pa);//*pa ��pa��vectorʱ ���н�����
	pb->a();//��ӡ����a

	B *ppb = new B();
	A *ppa = static_cast<A*>(ppb);

	system("pause");
	return 0;
}