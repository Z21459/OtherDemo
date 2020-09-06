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

MYSQL_RES* onGetSql(string path)//读配置 连接数据库
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
		while (!file.eof())//循环读每一行
		{
			file.getline(tmp, 1000);
			string line(tmp);
			size_t pos = line.find("=");
			string key = line.substr(0, pos);//关键字  等号前
			if (key == "user")
				user = line.substr(pos + 1);//=号之后
			else if (key == "passward")
				passward = line.substr(pos + 1);
			else if (key == "host")
				host = line.substr(pos + 1);
			else if (key == "table")
				table = line.substr(pos + 1);
			else if (key == "port")
				port = atoi(line.substr(pos + 1).c_str());//string 转int
		}
		mysql_init(&myCont);
		if (mysql_real_connect(&myCont, host.data(), user.data(), passward.data(), table.data(), port, NULL, 0))
		{
			cout << "connect succeed!" << endl;
			mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式,否则在cmd下无法显示中文
			int res = mysql_query(&myCont, "select * from user");//查询
			if (!res)
			{
				result = mysql_store_result(&myCont);//保存查询到的数据到result
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
		for (i = 0; fd = mysql_fetch_field(resPtr); i++)//获取列名
		{
			strcpy_s(column[i], fd->name);
		}
		j = mysql_num_fields(resPtr);
		for (i = 0; i < j; i++)
		{
			printf("%s\t", column[i]);
		}
		printf("\n");
		while (sql_row = mysql_fetch_row(resPtr))//获取具体的数据
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


	if (resPtr != NULL) mysql_free_result(resPtr);//释放结果资源


	system("pause");
	return 0;
}