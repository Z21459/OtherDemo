#include <iostream>
#include "ShopDaZhe.h"
using namespace std;

/*
����ģʽ �������㷨���壬�ֱ��װ������֮����Ի����滻
��ģʽ���㷨�ı仯������Ӱ�쵽ʹ���㷨�Ŀͻ�

��װ�仯��--���������Ҫ˼ά

������ģʽ�͹���ģʽ���ʹ��



**********��ͬʱ���ò�ͬҵ���ʱ��  �Ϳ��Կ��ǲ���ģʽ
*/

int main()
{
	//���ͷ� ���൱����ʹ��
	Context *context = nullptr;
	
	//����
	//int way;
	//switch (way)//��������ڷ�����ж�   
	//{
	//case MANJIAN:
	//	context = new Context(new StrategyA);//���ݴ���Ĳ��� ��ͬ ���ö�Ӧ�ļ̳�����
	//	if(context) context->ContextInfeace();
	//	break;
	//case YOUHUISONG:
	//	context = new Context(new StretegyB);
	//	if (context) context->ContextInfeace();
	//	break;
	//default:
	//	break;
	//}

	cout << endl;
	//�����Ͳ��Խ��  ����ģʽ��װ�˱仯
	int w = 0;
	cin >> w;
	context = new Context(w);//ͨ����ͬ��w ִ�в�ͬ
	if (context) context->ContextInfeace();



	system("pause");
	return 0;
}