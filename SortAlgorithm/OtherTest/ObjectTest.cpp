//空类中  默认构造、复制、析构、赋值、取值  --构造可以重载  析构不可以
//多态  重载-编译   虚函数-运行  构造函数相互调用 是栈溢出  explict防止隐式转换
// 虚析构函数-- 当一个类是基类时，才把析构函数写成需函数  保证 子类可以调用其析构函数   避免内存泄漏
// 析构函数 和构造函数执行的顺序是相反的，类声明对象在栈中。。。new在堆内存 
//浅复制 是指新旧两个对象指向同一个外部内容，深复制是指为新对象制作了外部对象的独立复制。
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
//重写函数
MyString::MyString(const char*str) {//构造函数
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