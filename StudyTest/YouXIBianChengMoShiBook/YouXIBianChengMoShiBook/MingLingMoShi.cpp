
#include <iostream>
using namespace std;

class Command
{
public:
	virtual ~Command(){}
	virtual void execute() = 0;
};

class JumpCommand :public Command
{
public:
	void execute() { jump(); }
	void jump() {}
};

//���봦��
class InputHandel
{
public:
	void inputHandel();
	//�󶨷���
private:
	Command *_btnx;
};

void InputHandel::inputHandel()
{
	if (/*��������*/0) _btnx->execute();//
}