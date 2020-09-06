//������  Ĭ�Ϲ��졢���ơ���������ֵ��ȡֵ  --�����������  ����������
//��̬  ����-����   �麯��-����  ���캯���໥���� ��ջ���  explict��ֹ��ʽת��
// ����������-- ��һ�����ǻ���ʱ���Ű���������д���躯��  ��֤ ������Ե�������������   �����ڴ�й©
// �������� �͹��캯��ִ�е�˳�����෴�ģ�������������ջ�С�����new�ڶ��ڴ� 
//ǳ���� ��ָ�¾���������ָ��ͬһ���ⲿ���ݣ������ָΪ�¶����������ⲿ����Ķ������ơ�
#include <string>
#include <iostream>
using namespace std;
class MyString {
public:
	MyString(const char *str = nullptr);
	MyString(const MyString &other);
	~MyString(void);
	MyString &operator=(const MyString&other);
private:
	char * m_data;
};
//��д����
MyString::MyString(const char*str) {//���캯��
	if (m_data == nullptr) {
		m_data = new char[1];
		m_data = '\0';
	}
	else
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
}
MyString::~MyString(void) {
	if (m_data != nullptr) {
		delete[]m_data;
		m_data = nullptr;
	}
}
MyString::MyString(const MyString&other) {
	if (m_data != nullptr)
		m_data = nullptr;
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);
}
MyString& MyString::operator=(const MyString&other) {
	if (this == &other) {
		return *this;
	}
	delete[]m_data;
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data);
	return *this;
}