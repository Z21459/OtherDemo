#include <iostream>
using namespace std;

class Person
{
public:
	Person(){}
	Person(string name)
	{
		this->name = name;
	}
	virtual void Show() {
		printf_s("%s", name);
		//std::cout << "·þÊÌ" << name;
	}
private:
	string name;
};

class Finery :public Person
{
protected:
	Person person;
public:
	void Decorate(Person person)
	{
		this->person = person;
	}
	void Show() {
		if (!(&person))
		{
			person.Show();
		}

	}
};
class Ts :public Finery
{
public:
	void Show()
	{
		cout << "T";
		person.Show();
	}
};

class TT:public Finery
{
public:
	void Show()
	{
		cout << "TT";
		person.Show();
	}
private:

};

//
void mainFun()
{
	Person *rc = new Person("ww");
	cout << '1';
	TT *dtt = new TT();
	Ts *ds = new Ts();

	dtt->Decorate(*rc);//×°ÊÎ
	ds->Decorate(*dtt);
	ds->Show();
}