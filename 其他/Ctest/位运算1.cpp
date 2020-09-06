///运算符  嵌入式


//一个字节byte 有8位 


#include <iostream>
using namespace std;
//交换
int main(){
	
	int a = 2,b=3;
	a = a^b;
	b = a^b;
	a = a^b;
	cout << a <<b;
	
	return 0;
}
//#define year(600*60*24*365)UL
// UL 无符号长整型

//当操作存在有符号和无符号时， 所有操作自动转换成无符号  很大的数


char *m_data;
String::String(const char*str){
	if(str!=nullptr){
		m_data = new char[strlen(str)+1];
		strcpy(m_data,str);
	}
	else{
		m_data = new char[1];
		*m_data = '\0';
	}
} 
String::String(const String &other){
	m_data = new char[strlen(other.m_data)+1];
	strcpy(m_data,other.m_data); 
}

String& String:: operator=(const String&other){
	if(this == &other){
		return *this;
	}
	delete[]m_data;
	m_data = new char[strlen(other.m_data)+1];
	strcpy(m_data,other.m_data);
	
}
String::~String(){
	if(m_data!=nullptr){
		delete[]m_data;
		m_data = NULL;
	}
	
}
