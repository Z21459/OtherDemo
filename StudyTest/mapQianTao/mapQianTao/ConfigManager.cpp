#include "ConfigManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

/////ConfigManager
ConfigManager::ConfigManager()
	:id(0)
{
	//id = 0;
}

ConfigManager::~ConfigManager()
{
	
}

void ConfigManager::loadConfig()
{
	//加载文件
	vector<string> vec;
	ifstream in("./reward.csv");
	string line;
	while (getline(in, line))
	{
		vec.push_back(line);
	}

	//ConfigMap _config_map = ConfigManager::getConfigMap();//获得_config_map
	ConfigMap::iterator iter = _config_map.begin();
	//Config *config = new Config;
	sVector temp;
	if (iter != _config_map.end())
	{
		return;
	}
	else//如果等于空  然后插入
	{
		for (int i = 1; i < vec.size(); i++)
		{
			Config *config = new Config;//在这里new 一个  否则每次返回的是同一个结果
			config->fromRow(vec[i]);
			//每次出来的config就是错误的
			_config_map.insert(ConfigMap::value_type(i, config));//Config
			config->listReward(temp);//单个的使用 vector  放入到vector  现在是vector 
		}
	}
	ConfigMap::iterator iter1 = _config_map.begin();
	ConfigMap::iterator iter2 = _config_map.find(1);
	sVector vfind;
	if (iter1 != _config_map.end())
	{
		for (; iter1 != _config_map.end(); iter1++) {
			//cout << iter1->second << endl;//如果不等于 则查找到了
			Config *configF = iter1->second;//根据查找到的 id 来输出里面的值
			configF->listReward(vfind);
		}
	}
	for (int i = 0; i < vfind.size(); i++)
	{
		cout << vfind[i] << endl;
	}
	
	/*for (; iter1 != _config_map.end(); iter1++)
	{
		cout << iter1->second << endl;
	}
	for (int i = 0; i< temp.size(); i++)
	{
		cout << temp[i] << endl;
	}*/
}

void ConfigManager::onUpdate()
{

}

sVector *ConfigManager::getReward(int type_id)
{
	//根据map 进行查找
	ConfigMap _config_map = ConfigManager::getConfigMap();//获得_config_map
	ConfigMap::iterator iter = _config_map.begin();//find(type_id);
	if (iter != _config_map.end())
	{
		sVector result;
		Config *config = new Config;
		config->listReward(result);
		if (config)
		{
			return &result;
		}	
	}
	return nullptr;
}

bool ConfigManager::checkOnOff()
{
	if (id==0)
		return true;
	return false;
}

