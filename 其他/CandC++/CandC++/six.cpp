#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
using namespace std;

//c������������̵ģ���c++��Ϊc���Եĳ���֧�֣������������ı��
//�������ĸ���������ǿ͹������ϵͳ˼ά�����û��ڶ���(ʵ��)�ĸ����ģ��
//ģ��͹������������ƣ�ʵ������İ취�������࣬������Ϣ�Լ�����ض���

//4 class��struct������Ҫ�ֳ�c��c++
//c:c��û��class��structֻ�ܶ����Ա���������ܶ����Ա����
//c++��class����Ĭ��Ϊ˽�����ͣ�����Ե���ģ�����ͣ�structĬ��Ϊ�������ͣ����ܵ���ģ������

//5 �����캯����������ʱ�򣬵��ò��������Ĺ��캯������Ҫ��С���š����������ȶ����ȳ�ʼ��

//9 �����ȫ�ֶ��󣬾�̬���ݳ�Ա�����ڳ���������ȫ�����ֳ�ͻ������������Ϣ�������Ϊprivate
//10 ��ʼ���б�--���к���const reference��Ա�����ͻ���Ĺ��캯��ʱ����ֵ--

//13 ִ��main����֮ǰ ��ִ��ȫ�ֶ���Ĺ��캯��

//14 15 c++����Ĭ��ִ��--Ĭ�Ϲ���͸��ƹ��죬��������ֵ��ȡֵ��  ���캯���������أ�����������

//20 ���������������ã���һ���౻������Ϊ�����ʱ�򣬰���������д���麯������֤��Դ�����ͷţ������ڴ�й©
//21 ��������ִ��˳��͹��캯��ִ��˳�򷴹���
//���ƹ���--�ɱ��������������һЩ����ͬһ�����������Ĺ�������ʼ��
//ǳ����--���¾���������ָ��ͬһ���ⲿ�����ݣ����--�¶����������ⲿ����Ķ������ơ�

//26 ��дString��
class String1 {
public:
	String1(const char* str = NULL);//��ͨ����
	String1(const String1 &other);//���ƹ���
	~String1(void);
	String1&operator=(const String1 &other);//��ֵ����
private:
	char *m_string;//˽�г�Ա
};
String1::~String1(void) {
	if (m_string != NULL) {
		delete[]m_string;
		m_string = NULL;//��Ϊ���ͷ�
	}
}
String1::String1(const char *str) {
	if (str == NULL) {
		m_string = new char[1];
		*m_string = '\0';//����һ���ֽ�
	}
	else {
		m_string = new char[strlen(str) + 1];//����ռ�
		//strcpy(m_string, str);
	}
}
String1::String1(const String1&other) {
	m_string = new char[strlen(other.m_string) + 1];
	//strcpy(m_string, other.m_string);
}
String1& String1::operator=(const String1 &other) {
	if (this == &other) {
		return *this;
	}
	delete[]m_string;
	m_string = new char[strlen(other.m_string) + 1];
	//strcpy(m_string,other.m_string);
	return *this;
}

//32 �������� --����ͬ������������ͬ�������ƵĹ��ܣ����������ͻ��߲�����ͬ�ĺ����������
//����������c++����������������ԭ��������������������������������Ϣ����c���Բ��Ժ��������д���

//34 ���غ͸�д
//����--ָ�����д���ࣻ��д--��ָͬһ�������Ĳ�ͬ�汾֮�������ͬ
//���أ�����һ�������к���ͬ��������ͬ�ķ���(��������ͬ�������б�ز���ͬ���������Ϳ��Բ�ͬ)
//��д����������д�����麯��(ֻ���麯���ͳ��󷽷��ܹ���д���������������б�����ֵ������ͬ)
//����һ���﷨�����ɱ������ڱ���׶���ɣ��������������ı�̣���д�����н׶ξ���������������̵���Ҫ������




int main6(int argc, char *argv[]) {
	


	system("pause");
	return 0;
}
