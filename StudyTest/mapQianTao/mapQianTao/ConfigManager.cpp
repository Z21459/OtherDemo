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
	//�����ļ�
	vector<string> vec;
	ifstream in("./reward.csv");
	string line;
	while (getline(in, line))
	{
		vec.push_back(line);
	}

	//ConfigMap _config_map = ConfigManager::getConfigMap();//���_config_map
	ConfigMap::iterator iter = _config_map.begin();
	//Config *config = new Config;
	sVector temp;
	if (iter != _config_map.end())
	{
		return;
	}
	else//������ڿ�  Ȼ�����
	{
		for (int i = 1; i < vec.size(); i++)
		{
			Config *config = new Config;//������new һ��  ����ÿ�η��ص���ͬһ�����
			config->fromRow(vec[i]);
			//ÿ�γ�����config���Ǵ����
			_config_map.insert(ConfigMap::value_type(i, config));//Config
			config->listReward(temp);//������ʹ�� vector  ���뵽vector  ������vector 
		}
	}
	ConfigMap::iterator iter1 = _config_map.begin();
	ConfigMap::iterator iter2 = _config_map.find(1);
	sVector vfind;
	if (iter1 != _config_map.end())
	{
		for (; iter1 != _config_map.end(); iter1++) {
			//cout << iter1->second << endl;//��������� ����ҵ���
			Config *configF = iter1->second;//���ݲ��ҵ��� id ����������ֵ
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
	//����map ���в���
	ConfigMap _config_map = ConfigManager::getConfigMap();//���_config_map
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

