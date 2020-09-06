class Target
{
public:
	virtual void Requset()
	{

	}
};
class Ad
{
public:
	void Specific()
	{

	}
};
class Adt :public Target
{
	Ad *ad = new Ad();
	void Request()
	{
		ad->Specific();
	}
};
//客户端
void fun()
{
	Target *tar = new Adt();
	tar->Requset();//抽象类 只能定义指针指向对象
}