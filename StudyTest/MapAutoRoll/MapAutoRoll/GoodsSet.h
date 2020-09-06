#pragma once
#include <map>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Thing
{
public:
	Thing();
	~Thing();
	
public:
	int id;//Ϊ1id
	int type_id;//����id
	int gid;//wupinid
	int quality;//Ʒ��
	int count;//����
	string name;
};

typedef map<int, Thing*>ThingMap;

class GoodsSet
{
public:
	GoodsSet();
	~GoodsSet();
	void loadThing();
	void Init();
	void SortMap();
	void AutoRoll();
	void CountSort(vector<Thing*>& quality_same, int rand_index);

private:
	ThingMap _thing_map;
	ThingMap _thing_map1;
	vector<int> result_vec;
	vector<Thing*> temp_vec_map;
	vector<int> vec;
	int count;


private:
	static bool sampleSort(const Thing *left, const Thing *right);
};

