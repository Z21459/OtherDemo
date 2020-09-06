//#include <iostream>
//#include <cstdlib>
//#include <cstdio>
//using namespace std;
//
//friend ostream& operator << (ostream&, String&);
//friend istream& operator >>(istream&, String&);
//
//class String {
//	String(const char* str = NULL);
//	String(const String&str);
//	String& operator = (const String &str);
//	String& operator+=(const String &str);//+=元素符重载
//	String& operator+(const String &str);//+=元素符重载
//	bool operator==(const String &st);//==运算符重载
//	const char* c_str();
//	~String();
//
//private:
//	char *m_data;
//	size_t length;
//
//};
//
//ostream& String::operator <<(ostream &os, String &str) {
//	os << str.m_data;
//	return os;
//}
//istream& String::operator >>(istream &is, String &str) {
//	char temp[1000] = { 0 };
//	is >> temp;
//	str.length = strlen(temp);
//	str.m_data = new char[str.length];
//	strcpy(str_data, temp);
//	return is;
//}
//String& String ::operator+(const String&str) {
//	
//	char *temp = new char[strlen(str.m_data) + strlen(m_data)+1];
//	strcpy(temp, str.m_data);
//	strcat(temp, m_data);
//	return temp;
//
//}
//bool String::operator==(const String&str) {
//	if (strlen(str.m_data) != strlen(m_data)) {
//		return false;
//	}
//	return strcpy(str.m_data, m_data) == 0 ? true : false;
//}
//String::String(const char* str) {
//	if (!str) {
//		m_data = new char[1];
//		*m_data = '\0';
//		length = 0;
//	}
//	else
//	{
//		length = strlen(str);
//		m_data = new char[length];
//		strcpy(m_data, str);
//
//	}
//}
//String::~String() {
//	if (m_data) {
//		delete[]m_data;
//		m_data = NULL;
//		length = 0;
//	}
//}
//
//String::String(const String&str) {
//	if (!str.m_data)
//	{
//		m_data = '\0';
//	}
//	else
//	{
//		length = strlen(str.m_data);
//		m_data = new char(length + 1);
//		strcpy(m_data, str.m_data);
//	}
//}
//String& String::operator=(const String &str) {
//	if (this != &str) {
//		length = strlen(str.m_data);
//		m_data = new char(length + 1);
//		strcpy(m_data, str.m_data);
//	}
//	return *this;
//}
//
//char *strcat(char*str, const char*str2) {
//	if (!str2) {
//		return NULL;
//	}
//	char *tmp;
//	tmp = str;
//	while (*str++);
//	str--;
//	while (*str++ = *str2++);
//	return tmp;
//}
//char *strcpy(char *str, const char* str2) {
//	if (!str2) {
//		return NULL;
//	}
//	char * temp = str;
//	while ((*str++ = *str2++)!='\0');
//	return temp;
//}
//int strcmp(const char*str, const char*str2) {
//	int ret = 0;
//	while (!(ret = *(unsigned char*)str - *(unsigned char*)str2) && *str2) {
//		++str;
//		++str2;
//	}
//	if (ret < 0)
//		return -1;
//	else if (ret > 0)
//		ret = 1;
//	return ret;
//}
//
////查找两个字符串最大的共有串
//char *common(char* str1, char*str2) {
//	int i, j;
//	char *shortstr, *longstr;
//	char *substr;
//	if (str1 == NULL || str2 == NULL) {
//		return NULL;
//	}
//	if (strlen(str1) < strlen(str2)) {
//		shortstr = str1;
//		longstr = str2;
//	}
//	else {
//		shortstr = str2;
//		longstr = str1;
//	}
//	//判断是否有子串
//	if (strstr(str1, str2) != NULL) {
//		return shortstr;
//	}
//	substr = new char[sizeof(char)*(strlen(shortstr) + 1)];
//	for (i = strlen(shortstr) - 1; i > 0; ++i) {
//		for (j = 0; j < strlen(shortstr) - i; ++j) {
//			memcpy(substr, &shortstr[j], i);
//			substr[i] = '\0';
//			if (strstr(longstr, substr) != NULL)
//				return substr;
//		}
//	}
//	return NULL;
//}
////翻转字符串
//char *revstr(const char* str) {
//	char *ret;
//	if (str == NULL)
//		return NULL;
//	int length = strlen(str);
//
//	ret = new char[length + 1];
//	strcpy(ret, str);
//	for (int i = 0; i < length/2; ++i) {
//		char c = ret[i];
//		ret[i] = ret[length - i - 1];
//		ret[length - i - 1] = c;
//	}
//	return ret;
//}
//
////01串中出现连续0或者1 的最大数
//
//void Cauclat(const char* str, int *max0, int*max1) {
//	int sum[2] = { 0 };//sum[0]为0 sum[1]为1
//	while (*str)//遍历
//	{
//		if (*str == '0') {
//			(*max0)++;
//			if (*(++str) == '1') {
//				if (sum[0] < *max0) {
//					sum[0] = *max0;
//				}
//				*max0 = 0;
//			}
//		}
//		else if(*str == '1')
//		{
//			(*max1++);
//			if (*(++str) == '0') {
//				if (sum[1] < *max1) {
//					sum[1] = *max1;
//				}
//				*max1 = 0;
//			}
//		}
//	}
//	*max0 = sum[0];
//	*max1 = sum[1];
//}

//friend MyString& operator +=(const MyString &other);
#include<iostream>
#include<cstring>
using namespace std;
class MyString {
public:
	MyString(const char*str = nullptr);
	MyString(const MyString &other);
	~MyString(void);
	MyString& operator =(const MyString &other);
	MyString operator+(const MyString&other);
	bool operator ==(const MyString&other);
	bool operator >(const MyString&other);
	bool operator <(const MyString&other);

	char& operator[](int idx);
private:
	char *m_data;
};
MyString::MyString(const char* str) {
	if (str == nullptr) {
		m_data = new char[1];//申请一个空间
		*m_data = '\0';
	}
	else {
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
}
MyString::MyString(const MyString&other) {
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data,other.m_data);//
}
MyString::~MyString(void) {
	if (m_data != nullptr) {
		delete[]m_data;
		m_data = nullptr;
	}
}
MyString& MyString::operator=(const MyString&other) {
	if (this == &other) {
		return *this;
	}
	delete[]m_data;
	m_data = new char[strlen(other.m_data) + 1];//申请新空间  空间大小时other.m_data大小
	strcpy(m_data, other.m_data);
	return *this;
}
MyString MyString::operator+(const MyString&other) {
	MyString str;//申请一个新的空间 存放两个数据
	str.m_data = new char(strlen(m_data) + strlen(other.m_data) + 1);
	strcat(str.m_data,m_data);
	strcat(str.m_data, other.m_data);
	return str;
}
bool MyString::operator ==(const MyString&other) {
	if (strcmp(m_data, other.m_data) == 0)
		return true;
	else
		return false;
}
bool MyString::operator >(const MyString&other) {
	if (strcmp(m_data, other.m_data) > 0)
		return true;
	else
		return false;
}
bool MyString::operator <(const MyString&other) {
	if (strcmp(m_data, other.m_data) < 0)
		return true;
	else
		return false;
}
//重载[]
char& MyString::operator[](int idx) {
	return m_data[idx];
}