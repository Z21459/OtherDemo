#include "allHead.h"


/*
ָ��
ָ�������

������[�±�]
ָ�����[�±�]//ǰ��ָ�����ָ������


//ָ����ַ���
 %s ����\0�Ż�ֹͣ
 %c ��ȡһ���ַ�
*/

void func(int *a)
{
	*a = 20;//��a��ָ��Ĵ洢�ռ丳ֵ
}

//����ָ��ĺ���
char *test()
{
	const char *p = "aa";
	return const_cast<char*>(p);//��const ת�ɷ�const
}

void rever(string &str)
{
	string *p = &str;//��ָ�����
	cout << *p << endl;
	int i = 0;
	while (i < (*p).length())
	{
		cout << (*p)[i];
		i++;
	}

}

//ָ������ָ��
void tt()
{
	cout << "tt \n";
}
int maina()
{
	//int a = 10;
	//int *p = &a;//ָ��pֻ��ָ��int�͵�����
	//cout << a << " " << *p <<" "<< p << endl;

	//func(&a);//����ַ�������� �޸���a��ֵ����Ϊp������a���p��ֵҲ���޸�
	//cout << a << " " << *p << " " << p << endl;


	///*
	//ָ��ֻ��ָ��ͬ�����ֵ  
	//ָ��ֻ�ܴ洢��ַ
	//ָ��û��ʼ�������ܷ���
	//*/

	////ָ��ָ���ָ��
	//int b = 11;
	//int *pp = &b;
	//int **ppp = &pp;
	//cout << b << " " << *pp << " " << pp << " " << **ppp << " " 
	//	<< *ppp << " " << ppp << endl;
	//

	////ָ�������  �����������������Ԫ�صĵ�ַ
	////ָ�����+1��ַ��Ӽ�ȡ����ָ���������
	///*
	//int *p  p+1 �൱�ڵ�ַ+4
	//char *p p+1 �൱�ڵ�ַ+1
	//*/
	//int arr[3] = { 1,2,3 };
	//int *ap;
	//ap = &arr[0];//���� ap = arr;
	//
	//cout << arr[1] << " " << *(ap + 1) << endl;

	
	//ָ����ַ���
	//char s[] = "iata";
	//const char *s1 = "iata";//ָ��sָ���ַ����׵�ַ
	//const char *s2;
	//s2 = "iata";
	//const char *buf = "it";//ָ���ַ������׵�ַ
	//printf("%c \n", *buf);
	//printf("%s \n", buf);

	//����ָ��ĺ���
	//char *name = test();
	//printf("%s \n", name);

	//ָ������ָ��
	//(*p) �̶�д��������ָ�����p�����϶�ָ����

	//void(*p)();
	//p = tt;//ָ����� ָ����
	//cout << "(*p)()    ";
	//(*p)();//ֱ�ӵ���  �൱�ڵ��� tt();
	//cout << "tt()    ";
	//tt();
	//cout << "p()    ";
	//p();


	string  str("absbsb");
	rever(str);

	system("pause");
	return 0;
}