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
//�ͻ���
void fun()
{
	Target *tar = new Adt();
	tar->Requset();//������ ֻ�ܶ���ָ��ָ�����
}