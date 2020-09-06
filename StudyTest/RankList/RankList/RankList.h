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

typedef map<int, string>ItemMapOne;//uid - ����
typedef map<int, Item*>ItemMap;//uid - ������Ϣ
typedef vector<ItemMap>ItemVec;//�����uid �õ����� ����ItemMapOne�õ������Σ� �������δ�vector(˳��洢)����ȡ��Ϣ


class RankList
{
public:
	RankList();
	~RankList();

	void Initialize();
	void Rank();//������

private:
	ItemMapOne _item_map_one;//�������uid ���ٲ鵽����
	ItemMap _item_map;//���������Ϣ  uid ����(��ҵ����л�������)
	ItemVec _item_vec;//�����ε����±� ����ȡ�������Ϣ
};


/*
1.
vector<pair<uid,������Ҫ�������Ϣ -���ṹ��>>
map<uid,�����������>
2.
�ڲ���vector��map��ɵ�������
vector ȡֵ����  map���ٲ���
2.1 --��ȡ���ο���
ͨ��map��uid �����õ�����
2.2ͨ�����Σ����ٵõ��������Ϣ
����map���ҵ�����  ������vector�±��ȡ�������Ϣ

3.ģ��ʵ��





����һ������   дһ����־λ flag  
����ﵽҪ�� �ͽ��뵽�������棬���������������Ȼ���͵��ͻ���
*/
