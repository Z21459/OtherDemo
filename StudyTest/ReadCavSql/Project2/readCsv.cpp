#include <iostream>
#include <fstream>//读写文件定义
#include <map>
#include <algorithm>
#include <string>
#include <sstream>// 读写存入到string对象
#include <vector>
using namespace std;

typedef map<string, string> MapInt;
MapInt map_int;

typedef vector<vector<string> > StringVector;
string oriPath = "E:\\FileCsv\\";
StringVector onReadFile(string path)
{
	ifstream inFile(path,ios::in);//读取
	string lineStr;
	getline(inFile, lineStr);
	vector<vector<string> > result;
	while (getline(inFile,lineStr))
	{
		stringstream ss(lineStr);//来自sstream
		string str;
		vector<string>temp;
		while (getline(ss, str, ','))//按照逗号分隔
		{
			temp.push_back(str);
		}
		result.push_back(temp);
	}
	return result;
}

void onWriteFile(string path)
{
	//写文件
	ofstream outFile; //输出文件流(输出到文件)
	outFile.open(path, ios::out);//打开模式可省略
	outFile << "id" << ',' << "num" << endl;
	outFile << "1" << ',' << 18 << endl;
	outFile << "2" << ',' << 21 << endl;
	outFile << "3" << ',' << 23 << endl;
}


int mainv()
{

	StringVector stringVec = onReadFile(oriPath + "file.csv");

	StringVector::iterator iter = stringVec.begin();
	for (; iter != stringVec.end(); iter++)
	{
		map_int.insert(MapInt::value_type((*iter)[0], (*iter)[1]));
	}

	cout << endl;

	system("pause");
	return 0;
}
