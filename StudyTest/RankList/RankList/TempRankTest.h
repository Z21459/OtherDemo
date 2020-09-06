#pragma once
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
///排行榜 有 RankService.h
///ThingBase   ThingBase.h    --这两个写在了GameService 命名空间里面

class RankKey
{
public:
	RankKey(int score, int time, int uid) :m_score(score), m_time(time), m_uid(uid) {}

	bool operator>(const RankKey &that)const {
		if (m_score == that.m_score)
		{
			if (m_time == that.m_time)
			{
				return m_uid < that.m_uid;//分数 时间都相同  uid 升序
			}
			else
			{
				return m_time < that.m_time;//当分数相同  时间不同  时间升序
			}
		}
		else
		{
			return m_score > that.m_score;//分数 降序
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

	void init(vector<pair<int, RankKey> >&rank);//int 是uid
	bool modify(int uid, RankKey);//int 是uid
	void remove(int uid,RankKey);
	void erase(int uid);//uid 是64为
	void clear();

	unsigned size() const;
	unsigned rank1(int uid) const;//根据uid得到名次
	int getUid(unsigned rank) const;//根据名次得到uid
	const RankKey *const getKey(int uid) const;//根据uid得到key信息

	vector<int> partialUserList(unsigned start, unsigned length)const;//取出多少排名区间
	const vector<pair<int, RankKey>> &get_vec_rank() { return rank; }//得到所有信息

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

	//构造
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
	void trim();//切割
	void swap(unsigned indexA, unsigned indexB);

private:
	
	RankKeyMap _rank_key_map;//存放具体的每一条  key是uid value是各项值
	RankKeyMapVec _rank_key_map_vec;//存放信息  里面存放一个一个_rank_key_map 顺序存储  方便根据关键字进行查找
	
	vector<pair<int, RankKey>> rank;//uid对应数据
	typedef map<int, unsigned>index;//uid对应排名  根据uid得到排名 ，然后利用排名 到vector里面按照下标取 相应的vector
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
	rank 里面放的是 存放的排名 顺序排名
	index  uid  value  //根据index里面的rank值 找到对应的玩家数据
	0       
	1
	2		3
	3		1
	4
	5		2
	index 里面放的是  
	uid rank
	1    3
	2    5
	3    2
	*/
	index.clear();//map进行清空    单独存放uid和排名的，根据uid得到排名   在根据排名找到vector对应索引   根据索引然后查到玩家具体的参数
	for (size_t i = 0; i < rank.size(); i++)
	{
		index[rank[i].first] = i;
	}
}

template <typename RankKey,int length,class Pr>
const RankKey* RankList<RankKey, length, Pr>::getKey(int uid)
{
	index it = index.find(uid);//查找关键字 根据uid
	if (it != index.end())
	{
		return &rank[it->second].second;//根据排名 查找玩家数据
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
		rank[it->second].second = key;//修改玩家数据
	}
	else
	{
		index[uid] = rank.size();//如果不存在   把当前玩家的排名排到最后
		rank.push_back(make_pair(uid, key));//插入数据
	}
	sort(index[uid]);//当前插入进行排序
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
	unsigned indexCurrent = it->second, indexLast = rank.size() - 1;//玩家当前的排名  和最后一个排名

	if (indexCurrent != indexLast)
	{
		swap(indexCurrent, indexLast);//交换当前和最后一个
	}
	rank.pop_back(); //删除最后一个
	index.erase(uid);//删除索引差值
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
	return it->second + 1;//根据uid 得到对应的rank  因为rank是从0开始  左移要加1
}
template <typename RankKey,int length,class Pr>
vector<int>RankList<RankKey, length, Pr>::partialUserList(unsigned start, unsigned len) const
{
	vector<int> v;//部分玩家数据
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
unsigned RankList<RankKey, length, Pr>::size() const//排名大小
{
	return rank.size();
}

template <typename RankKey,int length,class Pr>
void RankList<RankKey, length, Pr>::sortAll()//对vector按照定义规则进行排序
{
	std::sort(rank.begin(), rank.end(), RankComp<RankKey, Pr>);
}

template <typename RankKey,int length,class Pr>
void RankList<RankKey, length, Pr>::sort(unsigned index)//根据index 排序**********
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
void RankList<RankKey, length, Pr>::trim() //删除 最后一个玩家数据 空白
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




// 4.进一步说明排行榜参数 和次序
/*
template <typename RankKey,int length,class Pr>
bool RankList<RankKey, length, Pr>::modify(int uid, RankKey key)
{
	static Pr pr;
	index it = index.find(uid);
	size_t sz = rank.size();

	//容器满的时候，有新数据，新数据比最后一个还要 不计入
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
	//根据写好的排序规则 排序
	sort(index[uid]);
	//如果超出排行限制，排行榜大小编程传入参数的length大小
	trim();
	return true;
}*/

//保存数据



//等级排行榜
RankList<RankKey, 100>m_levelRankList;

//当有数据更新  或者有新数据调用
/*
for (int i = 0; i < 10; i++)
{
	int uid = i;
	time_t newtime = time(NULL) + i * 100;
	int lvl = i * 10;
	m_levelRankList.modify(uid, RankKey(lvl, newtime, uid));
}*/
/*
1. 如果根据排名进行发送奖励
可以调用vector<int>partialUserList(start,length)const;//读取范围内的用户uid 
带调用个发送邮件的接口 进行发送奖励

***发完奖励 一般需要clear()  将排行榜清空  防止逻辑错误 重发

**其中排行榜 和另一个map结合使用
map<int,int>m_mapAlldata;//玩家uid 玩家的得分  保存所有玩家数据  不管进不进入

RankList<RankKey,100>m_scoreRankList;//分数排行榜  仅仅保存进入排行榜的数据

一把情况下  先更新m_mapAlldata   然后更新排行榜调用modify


*/


