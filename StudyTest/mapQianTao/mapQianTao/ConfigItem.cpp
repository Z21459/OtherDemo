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
	//_reward_thing->push_back(reward);//�ŵ��������

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
	item = new ConfigItem;//������ܹ� �ظ�  ִ��new
}

Config::~Config()
{
	delete item;
}

void Config::fromRow(string &str)
{
	item->fromRow(str);
	_item_config_map.insert(ItemConfigMap::value_type(++id, item));//����֮��  ɾ��
}

void Config::pack()
{
}

void Config::listReward(sVector& thing_vec)
{
	//����map ���� Ȼ����뵽thing_vec
	ItemConfigMap::iterator iter =  _item_config_map.begin();
	for (; iter != _item_config_map.end(); iter++)
	{
		//cout << iter->second->zuhewupin();//һ���ַ���
		thing_vec.push_back(iter->second->zuhewupin());//��vector ���뵽����  �����ó��� �ŵ�vector
	}
	cout << "";
}

void Config::clear()
{
	_item_config_map.clear();
}

