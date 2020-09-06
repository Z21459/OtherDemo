class Context
{
private:
	State *state;
public:
	Context(State *state)
	{
		this->state = state;
	}
	void Request()
	{
		state->Handle(this);
	}
};
class State
{
public:
	virtual void Handle(Context contetx) = 0;
};

class A :public State
{
public:
	void Handle(Context context)
	{

	}
};
class B :public State
{
	void Hande(Context context)
	{

	}
};

//客户端
void fun()
{
	Context *c = new Context(new A());
	c->Request();
	c->Request();//不断请求改变状太
}