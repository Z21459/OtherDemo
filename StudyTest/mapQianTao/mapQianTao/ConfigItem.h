#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
typedef vector<string> sVector;

class ConfigItem
{
public:
	ConfigItem();
	~ConfigItem();
	void fromRow(string &string);
	void pack();
	string zuhewupin();//返回组合的物品 id cond reward

private:
	int id;//序号
	int condition;
	string reward; //奖励

	string _reward_thing;
};

typedef std::map<int, ConfigItem*>ItemConfigMap;

class Config
{
public:
	Config();
	~Config();
	void fromRow(string &str);
	void pack();
	void listReward(sVector&thing_vec);//打包奖励进入vector
	void clear();
public:
	ItemConfigMap _item_config_map;
	ConfigItem *item;
private:
	int id;
};

