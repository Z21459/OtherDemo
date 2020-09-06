#pragma once
#include "ConfigItem.h"
#include <map>

typedef map<int, Config*>ConfigMap;//������һ��map   ����һ��map��id���Ҷ���map

class ConfigManager
{
public:
	ConfigManager();
	~ConfigManager();
	void loadConfig();
	void onUpdate();///�ж��û����� ���ʱ�������¼���ݿ�
	const ConfigMap& getConfigMap() { return _config_map; }
	sVector *getReward(int type_id);//����id�õ�����
	bool checkOnOff();//�жϻ����

public:
	ConfigMap _config_map;
private:
	int id;
};