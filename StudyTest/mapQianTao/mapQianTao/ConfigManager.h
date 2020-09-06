#pragma once
#include "ConfigItem.h"
#include <map>

typedef map<int, Config*>ConfigMap;//最外层的一级map   根据一级map的id查找二级map

class ConfigManager
{
public:
	ConfigManager();
	~ConfigManager();
	void loadConfig();
	void onUpdate();///判断用户在线 添加时间戳，记录数据库
	const ConfigMap& getConfigMap() { return _config_map; }
	sVector *getReward(int type_id);//根据id得到奖励
	bool checkOnOff();//判断活动开关

public:
	ConfigMap _config_map;
private:
	int id;
};