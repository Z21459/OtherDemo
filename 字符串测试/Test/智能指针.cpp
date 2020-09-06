#include <algorithm>
#include <share.h>
#include <memory>
#include <iostream>

using namespace std;
/*
1.���滻auto_ptr��unique_ptrʵ�ֶ�ռʽӵ�л��ϸ�ӵ�и����֤ͬһʱ����ֻ��һ������ָ�����ָ��ö���
�����ڱ�����Դй¶(���硰��new�����������Ϊ�����쳣�����ǵ���delete��)�ر����á�

2. shared_ptrʵ�ֹ���ʽӵ�и���������ָ�����ָ����ͬ���󣬸ö�����������Դ���ڡ����һ�����ñ����١�ʱ���ͷš�
������share�Ϳ��Կ�������Դ���Ա����ָ�빲����ʹ�ü���������������Դ������ָ�빲������ͨ����Ա����use_count()���鿴��Դ�������߸�����
���˿���ͨ��new�����죬������ͨ������auto_ptr, unique_ptr,weak_ptr�����졣�����ǵ���release()ʱ����ǰָ����ͷ���Դ����Ȩ��������һ��
����������0ʱ����Դ�ᱻ�ͷš�
shared_ptr ��Ϊ�˽�� auto_ptr �ڶ�������Ȩ�ϵľ�����(auto_ptr �Ƕ�ռ��), ��ʹ�����ü����Ļ������ṩ�˿��Թ�������Ȩ������ָ��

3. share_ptr��Ȼ�Ѿ��ܺ����ˣ�������һ��share_ptr����ָ�뻹�����ڴ�й¶������������������໥ʹ��һ��shared_ptr��Ա����ָ��Է��������ѭ�����ã�ʹ���ü���ʧЧ���Ӷ������ڴ�й©��
weak_ptr������ָ�룻
weak_ptr ��һ�ֲ����ƶ����������ڵ�����ָ��, ��ָ��һ�� shared_ptr ����Ķ���. ���иö�����ڴ��������Ǹ�ǿ���õ�shared_ptr�� weak_ptrֻ���ṩ�˶Թ�������һ�������ֶΡ�
weak_ptr ��Ƶ�Ŀ����Ϊ��� shared_ptr �������һ������ָ����Э�� shared_ptr ����, ��ֻ���Դ�һ�� shared_ptr ����һ�� weak_ptr ������, ���Ĺ�������������������ü��������ӻ���١�
weak_ptr���������shared_ptr�໥����ʱ����������,���˵����shared_ptr�໥����,��ô������ָ������ü�����Զ�������½�Ϊ0,��Դ��Զ�����ͷš�
���ǶԶ����һ�������ã��������Ӷ�������ü�������shared_ptr֮������໥ת����shared_ptr����ֱ�Ӹ�ֵ������������ͨ������lock���������shared_ptr

*/
//share_ptr
void shareFun()
{
	string *s1 = new string("s1");

	shared_ptr<string> ps1(s1);
	shared_ptr<string> ps2;
	ps2 = ps1;

	cout << ps1.use_count() << endl;	//2
	cout << ps2.use_count() << endl;	//2
	cout << ps1.unique() << endl;	//0

	string *s3 = new string("s3");
	shared_ptr<string> ps3(s3);

	cout << (ps1.get()) << endl;	//033AEB48
	cout << ps3.get() << endl;	//033B2C50
	swap(ps1, ps3);	//������ӵ�еĶ���
	cout << (ps1.get()) << endl;	//033B2C50
	cout << ps3.get() << endl;	//033AEB48

	cout << ps1.use_count() << endl;	//1
	cout << ps2.use_count() << endl;	//2
	ps2 = ps1;
	cout << ps1.use_count() << endl;	//2
	cout << ps2.use_count() << endl;	//2
	ps1.reset();	//����ps1��ӵ��Ȩ�����ü����ļ���
	cout << ps1.use_count() << endl;	//0
	cout << ps2.use_count() << endl;	//1
}


//weak_ptr

class B;	//����
class A
{
public:
	weak_ptr<B> pb_;//��share_ptr�ĳ� weak_ptr  ��ֹ����
	~A()
	{
		cout << "A delete\n";
	}
};

class B
{
public:
	shared_ptr<A> pa_;
	~B()
	{
		cout << "B delete\n";
	}
	void printB() { cout << "printB\n"; }
};
//share_ptr�໥���� ����
void fun1()
{
	shared_ptr<B> pb(new B());
	shared_ptr<A> pa(new A());
	cout << pb.use_count() << endl;	//1
	cout << pa.use_count() << endl;	//1
	pb->pa_ = pa;
	pa->pb_ = pb;
	cout << pb.use_count() << endl;	//2
	cout << pa.use_count() << endl;	//2

	//������weak_ptr���ʶ��� ��ת��  �ڻ��
	//lock ���ڻ�ȡ������Ķ����ǿ����(shared_ptr).
	shared_ptr<B> p = pa->pb_.lock();
	p->printB();
}

int mainc()
{
	//shareFun();
    fun1();
	system("pause");
	return 0;
}