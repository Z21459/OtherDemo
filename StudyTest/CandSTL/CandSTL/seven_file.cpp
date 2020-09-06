#include<iostream>
#include<fstream>
#include <cstdio>
#include <ctime>
#include <istream>
#include <ostream>
#include <string>//包含头文件
using namespace std;

/*
输入输出流I/O
//通过 类 派生类 函数重载 虚函数 模板 多重继承等来实现输入输出
cerr 标准错误相对应
clog 日志输出
ifstream --cin
ofstream --out
fstream  --

//读取字符串  输入函数  保留空格可以使用 
>> --不能保留空格
get(s,num)
get(s,num,t)//t为分隔符号
getline(s,num)
getline(s,num,t)
read(s,num)
readsome(s,num)
//输出函数
<<
put() 单个字符写至输出流
write()
flush()

*/

int main()
{
	string s;
	cin >> s;
	const char* cstring = "hello";
	cout << cstring;
	//cout << static_cast<void*>(cstring) << endl;
	cout << (void*)cstring << endl;


	//多个标志 用|分割
	std::ofstream file("a.txt", std::ios::out | std::ios::app);

	/*
	in 读 文件要存在 r
	out 写 清空后写 w
	out|app 添加 a
	in|out 读和写 最初位置的起始点  文件要存在 r+
	in|out|trunc 先清空  再读写 w+
	
	///定义了3个成员函数
	open(name)
	open(name,flags)
	close()
	isopen()
	***打开文件，用完一定要关闭
	*/


	//简单I/O
	string filename;
	cin >> filename;
	ofstream fout(filename.c_str());//将流和文件关联
	fout << "saSJH\n";//输出到文件
	fout.clear();
	fout.close();
	ifstream fin(filename.c_str());

	char ch;
	while (fin.get(ch))
	{
		cout << ch;//读取文件
	}
	fin.close();




	//打开文件和文件模式
	const string filename1 = "text.txt";
	ifstream in;
	in.open(filename1.c_str(), ios_base::in);//打开文件
	if (in.is_open())
	{
		cout << in.rdbuf();//输出内容
		cout << endl;
	}
	in.close();

	ofstream out;
	out.open(filename1.c_str(), ios_base::out | ios_base::app);
	if (!out.is_open())
	{
		cout << "open_error\n";
	}
	string buffer;
	while (getline(cin, buffer) && buffer.size() > 0)//输入整行数据
	{
		out << buffer << endl;
	}
	out.clear();
	out.close();
	system("pause");
	return 0;
}