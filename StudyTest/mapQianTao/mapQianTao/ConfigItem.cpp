#include "ConfigItem.h"
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

/////////////ConfigItem
ConfigItem::ConfigItem()
{
	id = 0;
	condition = 0;
	reward = "";
}
ConfigItem::~ConfigItem()
{

}

void ConfigItem::fromRow(string &str)
{
	//readInt  readBool  readString
	reward = str;
	++id;
	++condition;
	//_reward_thing->push_back(reward);//放到这个里面

}

void ConfigItem::pack()
{
	//writeInt  writeBool  writeString
}

string ConfigItem::zuhewupin()
{
	return reward;
}

///////////////////////////config/////////////////////
Config::Config()
{
	id = 0;
	item = new ConfigItem;//这个不能够 重复  执行new
}

Config::~Config()
{
	delete item;
}

void Config::fromRow(string &str)
{
	item->fromRow(str);
	_item_config_map.insert(ItemConfigMap::value_type(++id, item));//存入之后  删除
}

void Config::pack()
{
}

void Config::listReward(sVector& thing_vec)
{
	//二级map 查找 然后放入到thing_vec
	ItemConfigMap::iterator iter =  _item_config_map.begin();
	for (; iter != _item_config_map.end(); iter++)
	{
		//cout << iter->second->zuhewupin();//一串字符串
		thing_vec.push_back(iter->second->zuhewupin());//将vector 存入到里面  单独拿出来 放到vector
	}
	cout << "";
}

void Config::clear()
{
	_item_config_map.clear();
}

