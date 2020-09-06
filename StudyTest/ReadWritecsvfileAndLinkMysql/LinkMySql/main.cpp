#include <iostream>
#include <vector>

using namespace std;
#include <WinSock2.h>//������  �����fd  socketδ������ʶ��
#include "mysql.h"


//https://www.cnblogs.com/jailman/p/10194043.html

MYSQL mysql;//����
MYSQL_FIELD *fd;//�ֶ�������
char fileld[32][32];//���ֶ�����ά����
MYSQL_RES *res;//�����е�һ����ѯ�����
MYSQL_ROW column;//һ�������ݵ����Ͱ�ȫ��ʾ   ��ʾ�е���
char query[150];//��ѯ���

bool ConnectDataBase();
void FreeConnect();
bool QueryDatabase1();  //��ѯ1
bool QueryDatabase2();  //��ѯ2
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
	//��ʼ��
	mysql_init(&mysql);
	//����   ���� �û���  ����  ���ݿ���  �˿ںţ�����Ĭ��0����3306�������Բ�������ȥ
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
	//�ͷ���Դ
	mysql_free_result(res);
	mysql_close(&mysql);
}

/***************************���ݿ����***********************************/
//��ʵ���е����ݿ����������д��sql��䣬Ȼ����mysql_query(&mysql,query)����ɣ������������ݿ�����ɾ�Ĳ�
bool QueryDatabase1() {
	sprintf_s(query, "select * from user"); //ִ�в�ѯ��䣬�����ǲ�ѯ���У�user�Ǳ��������ü����ţ���strcpyҲ����
	mysql_query(&mysql, "set names gbk"); //���ñ����ʽ��SET NAMES GBKҲ�У�������cmd����������
	//����0 ��ѯ�ɹ�������1��ѯʧ��
	if (mysql_query(&mysql, query))        //ִ��SQL���
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("query success\n");
	}
	//��ȡ�����
	if (!(res = mysql_store_result(&mysql)))    //���sql�������󷵻صĽ����
	{
		printf("Couldn't get result from %s\n", mysql_error(&mysql));
		return false;
	}

	//��ӡ��������
	printf("number of dataline returned: %d\n", mysql_affected_rows(&mysql));

	//��ȡ�ֶε���Ϣ
	char *str_field[32];  //����һ���ַ�������洢�ֶ���Ϣ
	for (int i = 0; i < 4; i++)   //����֪�ֶ�����������»�ȡ�ֶ���
	{
		str_field[i] = mysql_fetch_field(res)->name;
	}
	for (int i = 0; i < 4; i++)   //��ӡ�ֶ�
		printf("%10s\t", str_field[i]);
	printf("\n");
	//��ӡ��ȡ������
	while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
	{
		printf("%10s\t%10s\t%10s\t%10s\n", column[0], column[1], column[2], column[3]);  //column��������
	}
	return true;
}
bool QueryDatabase2() {
	mysql_query(&mysql, "set names gbk");
	//����0 ��ѯ�ɹ�������1��ѯʧ��
	if (mysql_query(&mysql, "select * from user"))        //ִ��SQL���
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("query success\n");
	}
	res = mysql_store_result(&mysql);
	//��ӡ��������
	printf("number of dataline returned: %d\n", mysql_affected_rows(&mysql));
	for (int i = 0; fd = mysql_fetch_field(res); i++)  //��ȡ�ֶ���
		strcpy_s(fileld[i], fd->name);
	int j = mysql_num_fields(res);  // ��ȡ����
	for (int i = 0; i < j; i++)  //��ӡ�ֶ�
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
	sprintf_s(query, "insert into user values (6, 'lily', '666','lily@sina.cn');");  //������취ʵ���ֶ��ڿ���̨�ֶ�����ָ��
	if (mysql_query(&mysql, query))        //ִ��SQL���
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
//�޸�����
bool ModifyData()
{
	sprintf_s(query, "update user set email='lesk@163.com' where name='lesk'");
	if (mysql_query(&mysql, query))        //ִ��SQL���
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
	cin >> query;  //�����ֶ�����sql���
	if (mysql_query(&mysql, query))        //ִ��SQL���
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