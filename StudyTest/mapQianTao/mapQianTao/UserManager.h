#pragma once
#include "ConfigManager.h"
#include <map>
#include <ctime>


typedef map<int, vector<int>>VectorMap;//map�ļ���Ӧֵ��һ��vector

class UserManager
{
public:
	UserManager();
	~UserManager();
	void loadConfig();
	void onUpdateSql();//��ʼִ��
	void packReward();
	void onUserLogin();//�û�����

	//��ӦЭ��
	void onActiveList();
	void onFinishCounts();
	void onUserGetReward();

public:

private:
	
	int testid;
};

