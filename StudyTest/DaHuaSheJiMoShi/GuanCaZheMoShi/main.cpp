#include<iostream>
#include"GuanCaZhe.h"
#include <algorithm>//ʹ��ģ��������㷨�⺯��
using namespace std;

/*
�۲���ģʽ����������ģʽ
������һ��һ�Զ��������ϵ���ö���۲��߶���ͬʱ����ĳһ���������
�����������ڷ����仯ʱ����֪ͨ���й۲��߶���

abstract sbject  --���屻�۲��� NBA  ��Ʊ��
abstract observe --����۲���  boss security


//��һ������ĸı���Ҫͬʱ�ı���������  ���Ҳ�֪�������ж��ٶ�����ı�

//�۲���ģʽ ��Ҫ�ǽ����� ����ϵ�˫���������ڳ��󣬲������ھ��壬ʹ���Եİ��껰������Ӱ����һ�ߵı仯


ί�У��¼�������� ---һ�����÷���������
���ί�з����˷�������ί����÷���������ȫ��ͬ����Ϊ

һ��ί�п��Դ��ض����������Щ�������α����ѣ���Щ�������Բ�����ͬһ����

delegate void EventHandler();

*/


int main()
{
	Boss *boss = new Boss();
	//������
	GuanCaA *guancaA = new GuanCaA("name", boss);
	boss->Attach(guancaA);

	//֪ͨ���ȥ

	//boss->BossAction = "come";
	boss->Notify();//֪ͨ

	system("pause");
	return 0;
}