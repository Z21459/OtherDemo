#pragma once
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
///���а� �� RankService.h
///ThingBase   ThingBase.h    --������д����GameService �����ռ�����

class RankKey
{
public:
	RankKey(int score, int time, int uid) :m_score(score), m_time(time), m_uid(uid) {}

	bool operator>(const RankKey &that)const {
		if (m_score == that.m_score)
		{
			if (m_time == that.m_time)
			{
				return m_uid < that.m_uid;//���� ʱ�䶼��ͬ  uid ����
			}
			else
			{
				return m_time < that.m_time;//��������ͬ  ʱ�䲻ͬ  ʱ������
			}
		}
		else
		{
			return m_score > that.m_score;//���� ����
		}
	}

	int getScore() { return m_score; }
	int getUid() { return m_uid; }
	int getTime() { return m_time; }

private:
	int m_score;
	int m_uid;
	int m_time;
};
typedef map<int, RankKey*>RankKeyMap;
typedef vector< RankKeyMap*>RankKeyMapVec;


template <typename RankKey,int length,class Pr = std::greater<typename RankKey>>

//template<typename RankKey, int Length, class Pr = std::greater<typename RankKey>>

class RankList
{
public:
	RankList(){}
	~RankList() { clear(); }

	void init(vector<pair<int, RankKey> >&rank);//int ��uid
	bool modify(int uid, RankKey);//int ��uid
	void remove(int uid,RankKey);
	void erase(int uid);//uid ��64Ϊ
	void clear();

	unsigned size() const;
	unsigned rank1(int uid) const;//����uid�õ�����
	int getUid(unsigned rank) const;//�������εõ�uid
	const RankKey *const getKey(int uid) const;//����uid�õ�key��Ϣ

	vector<int> partialUserList(unsigned start, unsigned length)const;//ȡ��������������
	const vector<pair<int, RankKey>> &get_vec_rank() { return rank; }//�õ�������Ϣ

	// =
	RankList &operator=(const RankList& myRankList)
	{
		clear();
		this->index = myRankList.index;
		this->rank = myRankList.rank;
		return *this;
	}

	//[]
	const pair<int, RankKey>*operator[](int index)
	{
		if (index < 0 || index >= int(rank.size()))
		{
			return NULL;
		}
		return &this->rank[index];
	}

	//����
	RankList(const RankList& myRanklist)
	{
		clear();
		this->index = myRanklist.index;
		this->rank = myRanklist.rank;
	}

	const RankKey *getKey(int uid);

protected:
	void sortAll();
	void sort(unsigned index);
	void trim();//�и�
	void swap(unsigned indexA, unsigned indexB);

private:
	
	RankKeyMap _rank_key_map;//��ž����ÿһ��  key��uid value�Ǹ���ֵ
	RankKeyMapVec _rank_key_map_vec;//�����Ϣ  ������һ��һ��_rank_key_map ˳��洢  ������ݹؼ��ֽ��в���
	
	vector<pair<int, RankKey>> rank;//uid��Ӧ����
	typedef map<int, unsigned>index;//uid��Ӧ����  ����uid�õ����� ��Ȼ���������� ��vector���水���±�ȡ ��Ӧ��vector
};


//
template <typename RankKey,int length,class Pr>

void RankList<RankKey, length, Pr>::clear()
{
	vector<pair<int, RankKey>> temp;
	init(temp);
}

template<typename RankKey,class Pr>
static bool RankComp(const pair<int, RankKey>&lsh, const pair<int, RankKey>&rsh)
{
	static Pr pr;
	return pr(l.second, r.second);
}

template <typename RankKey,int length,class Pr>
void RankList<RankKey, length, Pr>::init(vector<pair<int, RankKey>>&rank)
{
	rank.swap(rank);
	sortAll();
	trim();
	/*
	rank ����ŵ��� ��ŵ����� ˳������
	index  uid  value  //����index�����rankֵ �ҵ���Ӧ���������
	0       
	1
	2		3
	3		1
	4
	5		2
	index ����ŵ���  
	uid rank
	1    3
	2    5
	3    2
	*/
	index.clear();//map�������    �������uid�������ģ�����uid�õ�����   �ڸ��������ҵ�vector��Ӧ����   ��������Ȼ��鵽��Ҿ���Ĳ���
	for (size_t i = 0; i < rank.size(); i++)
	{
		index[rank[i].first] = i;
	}
}

template <typename RankKey,int length,class Pr>
const RankKey* RankList<RankKey, length, Pr>::getKey(int uid)
{
	index it = index.find(uid);//���ҹؼ��� ����uid
	if (it != index.end())
	{
		return &rank[it->second].second;//�������� �����������
	}
	return NULL;
}

template <typename RankKey,int length,class Pr>
bool RankList<RankKey, length, Pr>::modify(int uid, RankKey key)
{
	static Pr pr;
	index it = index.find(uid);
	size_t sz = rank.size();

	//not in list now and will not be in list
	if (it == index.end() && sz >= length && !pr(key, rank[sz - 1].second))
		return false;
	if (it != index.end())
	{
		rank[it->second].second = key;//�޸��������
	}
	else
	{
		index[uid] = rank.size();//���������   �ѵ�ǰ��ҵ������ŵ����
		rank.push_back(make_pair(uid, key));//��������
	}
	sort(index[uid]);//��ǰ�����������
	trim();
	return true;
}

template<typename RankKey,int length,class Pr>
void RankList<RankKey, length, Pr>::erase(int uid)
{
	index it = index.find(uid);
	if (it == index.end() || rank.size() <= 0)
	{
		return;
	}
	unsigned indexCurrent = it->second, indexLast = rank.size() - 1;//��ҵ�ǰ������  �����һ������

	if (indexCurrent != indexLast)
	{
		swap(indexCurrent, indexLast);//������ǰ�����һ��
	}
	rank.pop_back(); //ɾ�����һ��
	index.erase(uid);//ɾ��������ֵ
	if (indexCurrent != indexLast)
	{
		sort(indexCurrent);
	}
}

template <typename RankKey, int length,class Pr>
unsigned RankList<RankKey, length, Pr>::rank1(int uid) const
{
	index it = index.find(uid);
	if (it == index.end())
	{
		return;
	}
	return it->second + 1;//����uid �õ���Ӧ��rank  ��Ϊrank�Ǵ�0��ʼ  ����Ҫ��1
}
template <typename RankKey,int length,class Pr>
vector<int>RankList<RankKey, length, Pr>::partialUserList(unsigned start, unsigned len) const
{
	vector<int> v;//�����������
	if (start < 0)
	{
		return v;
	}
	size_t sz = rank.size();
	for (size_t i = start; i < sz&&i < start + len; i++)
	{
		v.push_back(rank[i].first);
	}
	return v;
}

template <typename RankKey,int length,class Pr>
unsigned RankList<RankKey, length, Pr>::size() const//������С
{
	return rank.size();
}

template <typename RankKey,int length,class Pr>
void RankList<RankKey, length, Pr>::sortAll()//��vector���ն�������������
{
	std::sort(rank.begin(), rank.end(), RankComp<RankKey, Pr>);
}

template <typename RankKey,int length,class Pr>
void RankList<RankKey, length, Pr>::sort(unsigned index)//����index ����**********
{
	static Pr pr;
	while (index > 0 && pr(rank[index].second, rank[index - 1].second))
	{
		swap(index - 1, index);
		index--;
	}
	size_t sz = rank.size();
	while (sz > 0 && index < sz - 1 && pr(rank[index + 1].second, rank[index].second))
	{
		swap(index, index + 1);
		index++;
	}
}

template <typename RankKey,int length,class Pr>
void RankList<RankKey, length, Pr>::swap(unsigned indexA, unsigned indexB)
{
	if (indexA >= rank.size() || indexB >= rank.size())
	{
		return;
	}
	std::swap(rank[indexA, indexB]);
	index[rank[indexA].first] = indexA;
	index[eank[indexB].first] = indexB;
}

template<typename RankKey,int length,class Pr>
void RankList<RankKey, length, Pr>::trim() //ɾ�� ���һ��������� �հ�
{
	size_t sz = rank.size();
	while (sz > length)
	{
		index.erase(rank[sz - 1].first);
		rank.pop_back();
		sz--;
	}
}

template<typename RankKey,int length,class Pr>
void RankList<RankKey, length, Pr>::remove(int uid, RankKey key)
{
	static Pr pr;
	index it = index.find(uid);//
	//index it = index.begin();
	size_t sz = rank.size();

	if (it == index.end() && sz >= length && !pr(key, rank[sz - 1].second))
	{
		return;
	}

	int nIndex = index[uid];//
	if (it != index.end())
	{
		index.erase(uid);
		for (size_t i = 0; i < rank.size(); i++)
		{
			if (rank[i].first == uid)
			{
				rank.erase(rank.begin() + 1);
			}
		}
	}
	sort(nIndex);
	trim();
}

template<typename RankKey, int length,class Pr>
int RankList<RankKey, length, Pr>::getUid(unsigned rank) const
{
	if (index.size() < rank)
	{
		return 0;
	}
	index it = index.begin();
	for (; it != index.end(); ++it)
	{
		if ((it->second + 1) == rank)
		{
			return it->first;
			break;
		}
	}
	return 0;
}

template <typename RankKey,int length,class Pr>
const RankKey*const RankList<RankKey, length, Pr>::getKey(int uid) const
{
	index it = index.find(uid);
	if (it == it.end())
	{
		return NULL;
	}
	return &(rank[it->second].second);
}




// 4.��һ��˵�����а���� �ʹ���
/*
template <typename RankKey,int length,class Pr>
bool RankList<RankKey, length, Pr>::modify(int uid, RankKey key)
{
	static Pr pr;
	index it = index.find(uid);
	size_t sz = rank.size();

	//��������ʱ���������ݣ������ݱ����һ����Ҫ ������
	if (it == index.end() && sz >= length && !pr(key, rank[sz - 1].second))
	{
		return false;
	}
	if (it != index.end())
	{
		rank[it->second].second = key;
	}
	else
	{
		index[uid] = rank.size();
		rank.push_back(make_pair(uid, key));
	}
	//����д�õ�������� ����
	sort(index[uid]);
	//��������������ƣ����а��С��̴��������length��С
	trim();
	return true;
}*/

//��������



//�ȼ����а�
RankList<RankKey, 100>m_levelRankList;

//�������ݸ���  �����������ݵ���
/*
for (int i = 0; i < 10; i++)
{
	int uid = i;
	time_t newtime = time(NULL) + i * 100;
	int lvl = i * 10;
	m_levelRankList.modify(uid, RankKey(lvl, newtime, uid));
}*/
/*
1. ��������������з��ͽ���
���Ե���vector<int>partialUserList(start,length)const;//��ȡ��Χ�ڵ��û�uid 
�����ø������ʼ��Ľӿ� ���з��ͽ���

***���꽱�� һ����Ҫclear()  �����а����  ��ֹ�߼����� �ط�

**�������а� ����һ��map���ʹ��
map<int,int>m_mapAlldata;//���uid ��ҵĵ÷�  ���������������  ���ܽ�������

RankList<RankKey,100>m_scoreRankList;//�������а�  ��������������а������

һ�������  �ȸ���m_mapAlldata   Ȼ��������а����modify


*/


