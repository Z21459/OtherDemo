#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>//�ڴ��д�ļ���

using namespace std;


int main() {
	//д
	ofstream outFile;
	outFile.open("./data1.csv", ios::out);
	if (!outFile) {
		cout << "Open Fail";
		return -1;
	}
	outFile << "name" << ","<< 18 <<","<< "age" << endl;
	outFile << "name1" <<","<< 20 << ","<<"age1" << endl;
	outFile.close();
	//��
	ifstream inFile("./data1.csv", ios::in);
	if (!inFile) {
		cout << "Open Fail";
		return -1;
	}
	string lineStr;
	vector<vector<string>> strArry;//�洢������
	while (getline(inFile, lineStr)) {
		//���ڶ�ά����
		stringstream ss(lineStr);
		string str;
		vector<string> lineArray;
		//�ָ�
		while(getline(ss, str, ',')){
			lineArray.push_back(str);//һ����vector����
		}
		strArry.push_back(lineArray);
	}

	for (int i = 0; i < strArry.size(); i++) {
		for (int j = 0; j < strArry[i].size(); j++) {
			cout << strArry[i][j] << " ";
		}
	}
	inFile.close();

	system("pause");
	return 0;
}
