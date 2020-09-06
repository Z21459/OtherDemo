#include <iostream>
#include <vector>

using namespace std;
#include <WinSock2.h>//不引用  会出现fd  socket未声明标识符
#include "mysql.h"


//https://www.cnblogs.com/jailman/p/10194043.html

MYSQL mysql;//连接
MYSQL_FIELD *fd;//字段列数组
char fileld[32][32];//存字段名二维数组
MYSQL_RES *res;//返回行的一个查询结果集
MYSQL_ROW column;//一个行数据的类型安全表示   表示行的列
char query[150];//查询语句

bool ConnectDataBase();
void FreeConnect();
bool QueryDatabase1();  //查询1
bool QueryDatabase2();  //查询2
bool InsertData();
bool ModifyData();
bool DeleteData();

int main() {
	ConnectDataBase();
	QueryDatabase1();
	InsertData();
	QueryDatabase2();
	ModifyData();
	QueryDatabase2();
	DeleteData();
	QueryDatabase2();
	FreeConnect();


	system("pause");
	return 0;
}

bool ConnectDataBase() {
	//初始化
	mysql_init(&mysql);
	//连接   主机 用户名  密码  数据库名  端口号（可以默认0或者3306），可以参数穿进去
	bool flag = mysql_real_connect(&mysql, "localhost", "root", "root", "test",0, NULL, 0);
	if (flag) {
		std::cout << "Connected...\n";
		return flag;
	}
	else {
		std::cout << "Connect Fali!\n";
		return !flag;
	}
}

void FreeConnect() {
	//释放资源
	mysql_free_result(res);
	mysql_close(&mysql);
}

/***************************数据库操作***********************************/
//其实所有的数据库操作都是先写个sql语句，然后用mysql_query(&mysql,query)来完成，包括创建数据库或表，增删改查
bool QueryDatabase1() {
	sprintf_s(query, "select * from user"); //执行查询语句，这里是查询所有，user是表名，不用加引号，用strcpy也可以
	mysql_query(&mysql, "set names gbk"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码
	//返回0 查询成功，返回1查询失败
	if (mysql_query(&mysql, query))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("query success\n");
	}
	//获取结果集
	if (!(res = mysql_store_result(&mysql)))    //获得sql语句结束后返回的结果集
	{
		printf("Couldn't get result from %s\n", mysql_error(&mysql));
		return false;
	}

	//打印数据行数
	printf("number of dataline returned: %d\n", mysql_affected_rows(&mysql));

	//获取字段的信息
	char *str_field[32];  //定义一个字符串数组存储字段信息
	for (int i = 0; i < 4; i++)   //在已知字段数量的情况下获取字段名
	{
		str_field[i] = mysql_fetch_field(res)->name;
	}
	for (int i = 0; i < 4; i++)   //打印字段
		printf("%10s\t", str_field[i]);
	printf("\n");
	//打印获取的数据
	while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行
	{
		printf("%10s\t%10s\t%10s\t%10s\n", column[0], column[1], column[2], column[3]);  //column是列数组
	}
	return true;
}
bool QueryDatabase2() {
	mysql_query(&mysql, "set names gbk");
	//返回0 查询成功，返回1查询失败
	if (mysql_query(&mysql, "select * from user"))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("query success\n");
	}
	res = mysql_store_result(&mysql);
	//打印数据行数
	printf("number of dataline returned: %d\n", mysql_affected_rows(&mysql));
	for (int i = 0; fd = mysql_fetch_field(res); i++)  //获取字段名
		strcpy_s(fileld[i], fd->name);
	int j = mysql_num_fields(res);  // 获取列数
	for (int i = 0; i < j; i++)  //打印字段
		printf("%10s\t", fileld[i]);
	printf("\n");
	while (column = mysql_fetch_row(res))
	{
		for (int i = 0; i < j; i++)
			printf("%10s\t", column[i]);
		printf("\n");
	}
	return true;
}
bool InsertData() {
	sprintf_s(query, "insert into user values (6, 'lily', '666','lily@sina.cn');");  //可以想办法实现手动在控制台手动输入指令
	if (mysql_query(&mysql, query))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Insert success\n");
		return true;
	}
}
//修改数据
bool ModifyData()
{
	sprintf_s(query, "update user set email='lesk@163.com' where name='lesk'");
	if (mysql_query(&mysql, query))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Insert success\n");
		return true;
	}
}
bool DeleteData() {
	/*sprintf(query, "delete from user where id=6");*/
	char query[100];
	printf("please input the sql:\n");
	cin >> query;  //这里手动输入sql语句
	if (mysql_query(&mysql, query))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Insert success\n");
		return true;
	}
}