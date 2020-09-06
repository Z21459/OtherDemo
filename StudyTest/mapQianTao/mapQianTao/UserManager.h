#pragma once
#include "ConfigManager.h"
#include <map>
#include <ctime>


typedef map<int, vector<int>>VectorMap;//map的键对应值是一个vector

class UserManager
{
public:
	UserManager();
	~UserManager();
	void loadConfig();
	void onUpdateSql();//开始执行
	void packReward();
	void onUserLogin();//用户在线

	//对应协议
	void onActiveList();
	void onFinishCounts();
	void onUserGetReward();

public:

private:
	
	int testid;
};

