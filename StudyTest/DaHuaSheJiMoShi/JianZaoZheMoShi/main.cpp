#include<iostream>
#include"JianZaoZhe.h"

using namespace std;

/*
��һ������Ĺ��������ı�ʾ����  ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ

���ʹ���˽�����ģʽ �û�ֻ��Ҫָ����Ҫ��������;Ϳ��Եõ��������彨����̺�ϸ�ھͲ���Ҫ

������ģʽ   
���ࣺ�����麯��
���ࣺ�̳л���  ����ʵ��
ָ�����ࣺͨ��������������ʵ��  ���൱����ʹ�� ����  ����һ��ʹ��JianZao�ӿڵĶ���


������ģʽ  �����Ӷ�����㷨Ӧ�ö����ڸö������ɲ����Լ����ǵ�װ�䷽ʽʱ����
*/

int main()
{
	Penh *pen = new Penh();
	Graph *graph = new Graph();
	ThinPerson *jianzaoThin = new ThinPerson(graph, pen);
	PersonDirect *pdThin = new PersonDirect(jianzaoThin);//���൱����ʹ��
	pdThin->creatPerson();
	// ����ͬ��

	system("pause");
	return 0;
}