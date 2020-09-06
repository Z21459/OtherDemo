//#pragma once
//#include <iostream>
//#include <map>
//#include <vector>
//using namespace std;
//class CampStoreItemRoll//竞拍类
//{
//
//};
//class CampStoreItem
//{
//public:
//	CampStoreItem();
//	~CampStoreItem();
//private:
//	int store_id;//唯一id
//	int good_id;//商品id
//	string good_name;//商品名称
//	int good_type;//商品类型
//	int good_quality;//商品质量
//	int good_count;//商品数量
//
//	ThingBase* _thing;
//
//public:
//	void fromDB(Data::Ptr row);
//	void packItem(NetData::Ptr buf);
//	ThingBase* getThing();
//	bool giveThing(User *user,int reason,string param);
//
//	//
//	void insertDB();
//	void deleteDB();
//};
//
//typedef std::vector<CampStoreItem*>CampStoreItemVector;
//typedef std::map<int, CampStoreItem*>CampStoreItemMap;
//
//
