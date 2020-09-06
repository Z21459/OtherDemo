#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h> 
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

string oriPath1 = "E:\\FileCsv\\linkSql.txt";

MYSQL_RES* onGetSql(string path)//������ �������ݿ�
{
	ifstream file;
	file.open(path.c_str());
	string user;
	string passward;
	string host;
	string table;
	int port;

	MYSQL myCont;
	MYSQL_RES *result = nullptr;
	if (file.is_open())
	{
		char tmp[1000];
		while (!file.eof())//ѭ����ÿһ��
		{
			file.getline(tmp, 1000);
			string line(tmp);
			size_t pos = line.find("=");
			string key = line.substr(0, pos);//�ؼ���  �Ⱥ�ǰ
			if (key == "user")
				user = line.substr(pos + 1);//=��֮��
			else if (key == "passward")
				passward = line.substr(pos + 1);
			else if (key == "host")
				host = line.substr(pos + 1);
			else if (key == "table")
				table = line.substr(pos + 1);
			else if (key == "port")
				port = atoi(line.substr(pos + 1).c_str());//string תint
		}
		mysql_init(&myCont);
		if (mysql_real_connect(&myCont, host.data(), user.data(), passward.data(), table.data(), port, NULL, 0))
		{
			cout << "connect succeed!" << endl;
			mysql_query(&myCont, "SET NAMES GBK"); //���ñ����ʽ,������cmd���޷���ʾ����
			int res = mysql_query(&myCont, "select * from user");//��ѯ
			if (!res)
			{
				result = mysql_store_result(&myCont);//�����ѯ�������ݵ�result
			}
		}
		return result;
	}
	else
	{
		cout << "config error" << endl;
		return nullptr;
	}
	//mysql_close(&myCont);
}



int main()
{   
	MYSQL_ROW sql_row;
	MYSQL_FIELD *fd;
	char column[32][32];
	MYSQL_RES *resPtr = onGetSql(oriPath1);
	if (resPtr)
	{
		int i, j;
		cout << "number of result: " << (unsigned long)mysql_num_rows(resPtr) << endl;
		for (i = 0; fd = mysql_fetch_field(resPtr); i++)//��ȡ����
		{
			strcpy_s(column[i], fd->name);
		}
		j = mysql_num_fields(resPtr);
		for (i = 0; i < j; i++)
		{
			printf("%s\t", column[i]);
		}
		printf("\n");
		while (sql_row = mysql_fetch_row(resPtr))//��ȡ���������
		{
			for (i = 0; i < j; i++)
			{
				printf("%s\t", sql_row[i]);
			}
			printf("\n");
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}


	if (resPtr != NULL) mysql_free_result(resPtr);//�ͷŽ����Դ


	system("pause");
	return 0;
}