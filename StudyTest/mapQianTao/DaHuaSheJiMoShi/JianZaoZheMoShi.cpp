#include <iostream>
using namespace std;

//����С��
class Pen
{

};
class Graphics
{

};
class Person
{
protected:
	Pen p;
	Graphics g;
public:
	Person() {}
	Person(Graphics g, Pen p)
	{
		this->g = g;
		this->p = p;
	}
	virtual void Head();
	virtual void Body();
	virtual void Left();
	virtual void Right();
	virtual void Up();
	virtual void Down();
};
class ThinPer:public Person
{
public:
	ThinPer(Graphics g, Pen p) :Person(g, p){}
	void  Head(){}
	void Body() {};
	///....
};

//ָ����
class Dir
{
private:
	Person pb;
public:
	Dir(Person pb)//��֪��Ҫʲô��С��
	{
		this->pb = pb;
	}
	void create()
	{
		pb.Body();
		//...
	}
};
//client
void func()
{
	Pen p;
	Graphics g;
	ThinPer *pb = new ThinPer(g,p);
	Dir *pt = new Dir(*pb);
	pt->create();//����
}