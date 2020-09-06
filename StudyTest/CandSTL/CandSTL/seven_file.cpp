#include<iostream>
#include<fstream>
#include <cstdio>
#include <ctime>
#include <istream>
#include <ostream>
#include <string>//����ͷ�ļ�
using namespace std;

/*
���������I/O
//ͨ�� �� ������ �������� �麯�� ģ�� ���ؼ̳е���ʵ���������
cerr ��׼�������Ӧ
clog ��־���
ifstream --cin
ofstream --out
fstream  --

//��ȡ�ַ���  ���뺯��  �����ո����ʹ�� 
>> --���ܱ����ո�
get(s,num)
get(s,num,t)//tΪ�ָ�����
getline(s,num)
getline(s,num,t)
read(s,num)
readsome(s,num)
//�������
<<
put() �����ַ�д�������
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


	//�����־ ��|�ָ�
	std::ofstream file("a.txt", std::ios::out | std::ios::app);

	/*
	in �� �ļ�Ҫ���� r
	out д ��պ�д w
	out|app ��� a
	in|out ����д ���λ�õ���ʼ��  �ļ�Ҫ���� r+
	in|out|trunc �����  �ٶ�д w+
	
	///������3����Ա����
	open(name)
	open(name,flags)
	close()
	isopen()
	***���ļ�������һ��Ҫ�ر�
	*/


	//��I/O
	string filename;
	cin >> filename;
	ofstream fout(filename.c_str());//�������ļ�����
	fout << "saSJH\n";//������ļ�
	fout.clear();
	fout.close();
	ifstream fin(filename.c_str());

	char ch;
	while (fin.get(ch))
	{
		cout << ch;//��ȡ�ļ�
	}
	fin.close();




	//���ļ����ļ�ģʽ
	const string filename1 = "text.txt";
	ifstream in;
	in.open(filename1.c_str(), ios_base::in);//���ļ�
	if (in.is_open())
	{
		cout << in.rdbuf();//�������
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
	while (getline(cin, buffer) && buffer.size() > 0)//������������
	{
		out << buffer << endl;
	}
	out.clear();
	out.close();
	system("pause");
	return 0;
}