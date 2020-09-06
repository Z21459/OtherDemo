#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>//内存读写文件流

using namespace std;


int main() {
	//写
	ofstream outFile;
	outFile.open("./data1.csv", ios::out);
	if (!outFile) {
		cout << "Open Fail";
		return -1;
	}
	outFile << "name" << ","<< 18 <<","<< "age" << endl;
	outFile << "name1" <<","<< 20 << ","<<"age1" << endl;
	outFile.close();
	//读
	ifstream inFile("./data1.csv", ios::in);
	if (!inFile) {
		cout << "Open Fail";
		return -1;
	}
	string lineStr;
	vector<vector<string>> strArry;//存储数据流
	while (getline(inFile, lineStr)) {
		//存在二维表中
		stringstream ss(lineStr);
		string str;
		vector<string> lineArray;
		//分割
		while(getline(ss, str, ',')){
			lineArray.push_back(str);//一行以vector保存
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
