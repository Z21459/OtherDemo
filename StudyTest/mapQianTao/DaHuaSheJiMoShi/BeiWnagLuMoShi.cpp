#include <iostream>
using namespace std;
class Role
{
private:
	int vit;
	int act;
	int lif;
public:
	int getvit(int vi)
	{
		vit = vi;
		return vit;
	}
	//..
	void Show()
	{
		cout << getvit(2);
	}
	void Init()
	{
		this->vit = 10;
		this->act = 5;
		this->lif = 100;
	}
	void fight()
	{
		this->vit = 0;
		this->act = 0;
		this->lif = 0;
	}
	roleMen* Save()
	{
		return new roleMen(vit,act,lif);
	}
	void Reco(roleMen mento)
	{
		this->vit = mento.getAct();//..
	}
};

class roleMen
{
private:
	int vit;
	int cat;
	int lif;
public:
	roleMen(){}
	roleMen(int vit, int act, int lif)
	{
		this->vit = vit;
	}
	int getAct()
	{
		return vit;
	}
};

class roleManager
{
private:
	roleMen memto;
public:
	roleManager(){}
	roleMen men()
	{
		return memto;
	}
};

//client
void fun()
{
	Role *li = new Role();
	li->Show();

	//save;
	roleManager *s = new roleManager();
	s->men = li->Save();

	//huifu
	li->Reco(s->men);
	li->Show();

}
//代码无措未必优