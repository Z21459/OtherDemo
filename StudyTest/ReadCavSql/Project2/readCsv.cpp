#include <iostream>
#include <fstream>//��д�ļ�����
#include <map>
#include <algorithm>
#include <string>
#include <sstream>// ��д���뵽string����
#include <vector>
using namespace std;

typedef map<string, string> MapInt;
MapInt map_int;

typedef vector<vector<string> > StringVector;
string oriPath = "E:\\FileCsv\\";
StringVector onReadFile(string path)
{
	ifstream inFile(path,ios::in);//��ȡ
	string lineStr;
	getline(inFile, lineStr);
	vector<vector<string> > result;
	while (getline(inFile,lineStr))
	{
		stringstream ss(lineStr);//����sstream
		string str;
		vector<string>temp;
		while (getline(ss, str, ','))//���ն��ŷָ�
		{
			temp.push_back(str);
		}
		result.push_back(temp);
	}
	return result;
}

void onWriteFile(string path)
{
	//д�ļ�
	ofstream outFile; //����ļ���(������ļ�)
	outFile.open(path, ios::out);//��ģʽ��ʡ��
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
