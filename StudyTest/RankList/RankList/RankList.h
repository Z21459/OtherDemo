#pragma once
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Item
{
public:
	Item();
	~Item();

public:
	int uid;
	int score;
	int rang;
	int finish_count;
};
class Rang
{
public:
	Rang();
	~Rang();
public:
	int uid;
};

typedef map<int, string>ItemMapOne;//uid - 名次
typedef map<int, Item*>ItemMap;//uid - 所有信息
typedef vector<ItemMap>ItemVec;//由玩家uid 得到排名 根据ItemMapOne得到的名次， 根据名次从vector(顺序存储)里面取信息


class RankList
{
public:
	RankList();
	~RankList();

	void Initialize();
	void Rank();//规则排

private:
	ItemMapOne _item_map_one;//根据玩家uid 快速查到名次
	ItemMap _item_map;//保存玩家信息  uid 和类(玩家的所有基础属性)
	ItemVec _item_vec;//把名次当作下标 快速取出玩家信息
};


/*
1.
vector<pair<uid,保存想要保存的信息 -类或结构体>>
map<uid,部分玩家名词>
2.
内部由vector和map组成的容器类
vector 取值方便  map快速查找
2.1 --获取名次快速
通过map的uid 快速拿到名次
2.2通过名次，快速得到保存的信息
根据map查找的名次  ，利用vector下表获取该玩家信息

3.模板实现





构建一个数组   写一个标志位 flag  
如果达到要求 就进入到数组里面，并对数组进行排序，然后发送到客户端
*/
