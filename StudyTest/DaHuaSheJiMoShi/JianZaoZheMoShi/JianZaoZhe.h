#pragma once
#include <iostream>
using namespace std;


class Graph
{
public:

};

class Penh
{
public:

};

class JianZaoZhe
{
public:
	JianZaoZhe();
	~JianZaoZhe();

protected:
	Graph *graph;
	Penh *pen;
public:
	JianZaoZhe(Graph *graph, Penh *pen)
	{
		this->graph = graph;
		this->pen = pen;
	}
	virtual void BuilderHead(){}
	virtual void BuilderBody(){}
	virtual void BuilderArmLeft(){}
	virtual void BuilderArmRight(){}
	virtual void BuilderLegLeft(){}
	virtual void BuilderLegRight(){}

};
//具体绘制
class ThinPerson :public JianZaoZhe
{
public:
	Graph *graph;
	Penh *pen;
	ThinPerson(Graph *graph, Penh*pen) :JianZaoZhe(graph, pen)
	{

	}
	void BuilderBody() { cout << "thin"; }
	//...
};

//建造者最重要的 指挥者
class PersonDirect
{
private:
	JianZaoZhe *jianzao;
public:
	PersonDirect(JianZaoZhe *jianzao)
	{
		this->jianzao = jianzao;
	}
	void creatPerson()
	{
		jianzao->BuilderBody();
		jianzao->BuilderHead();
		//....
	}
};