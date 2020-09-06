#include <stdio.h>
#include <math.h>
#include <iostream>
usiang namespace std;


#define SUM_SECONDS (365*24*60*60)UL     UL（表示无符号长整型） 

//写String类的构造、析构、赋值
class String{
	public:
		String(const char *str =nullptr);
		~String();
		String(const String &other);
		String &operator =(const String &other);
	private:
		char *m_data;
}; 

String::String(const char *str){
	if(str == nullptr)//给初值 
	{
		m_data = new char[1];
		*m_data = '\0';
	}
	else{
		m_data = new char[strlen(str)+1];
		strcpy(m_data,str);//如果不是空，进行赋值 
	}
	
}
String::~String(){
	if(m_data != nullptr){
		delete[]m_data;
		m_data = nullptr;
	}
}
String::String(const String&other){
	m_data = new char[strlen(other.m_data)+1];
	strcpy(m_data,other.m_data)
} 
String &String:: operator = (const String&other){
	if(this == &other){
		return *this;
	}
	delete[]m_data;
	m_data = new char[strlen(other.m_data)+1];
	strcpy(m_data,other.m_data);
	return *this;
}
int main()
{
	
	
	
	
	
	return 0;
}

