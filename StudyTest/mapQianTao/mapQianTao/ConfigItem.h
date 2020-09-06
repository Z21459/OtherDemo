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
	string zuhewupin();//������ϵ���Ʒ id cond reward

private:
	int id;//���
	int condition;
	string reward; //����

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
	void listReward(sVector&thing_vec);//�����������vector
	void clear();
public:
	ItemConfigMap _item_config_map;
	ConfigItem *item;
private:
	int id;
};

