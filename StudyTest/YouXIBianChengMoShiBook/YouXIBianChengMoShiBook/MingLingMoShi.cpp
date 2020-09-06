
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

//输入处理
class InputHandel
{
public:
	void inputHandel();
	//绑定方法
private:
	Command *_btnx;
};

void InputHandel::inputHandel()
{
	if (/*按键按下*/0) _btnx->execute();//
}