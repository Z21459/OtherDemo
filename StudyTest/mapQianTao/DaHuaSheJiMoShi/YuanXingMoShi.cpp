#include <iostream>
using namespace std;

class Clone
{
	virtual Clone& clone() = 0;
};
class jinali:public Clone
{
public:
	jinali(string name)
	{
		this->name = name;
	}
	
	void setp(string sex, string age)
	{
		this->age = age;
		this->sex = sex;
	}
	void show()
	{
		printf_s("%s%s%s", name, age, sex);
	}
	Clone& clone()//��д����
	{
		//return Clone
	}
	
private:
	string name;
	string age;
	string sex;
};
/*ԭ��ģʽ Prototype ��ԭ��ʵ��ָ��������������࣬����
ͨ��������Щԭ�ʹ����µĶ���*/

//client
void func()
{
	jinali *p = new jinali("i");
	//jinali p1 = p->clone();
}

class ab
{
public:
	virtual void eat() = 0;
};
class A :public ab
{
public:
	void eat() { cout << 'a'; }

};
class B :public ab
{
public:
	void eat() { cout << "b"; }
};

void func()
{
	ab *d;//�����಻�ܶ������
	d = new A();
	d->eat();

	d = new B();
	d->eat();
}