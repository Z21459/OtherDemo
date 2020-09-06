//#include "CampStoreManager.h"
//
//
//
//CampStoreManager::CampStoreManager()
//{
//}
//
//
//CampStoreManager::~CampStoreManager()
//{
//}
//
//void CampStoreManager::loadItem(DataRow::Ptr row)
//{
//	//如果出现ID是0 过滤掉防止客户端挂掉
//	if (row->getInt32("good_type") == THING_GOODS && row->getInt32("good_id") == 0)
//	{
//		return;
//	}
//	CampStoreItem *item = new CampStoreItem;
//	item->fromDB(row);
//	addItem(item);//插入
//}
//
//void CampStoreManager::addItem(CampStoreItem * item)
//{
//	_camp_item_store_map.insert(CampStoreItemMap::value_type(item->store_id(), item));
//}
//
//void CampStoreManager::deleteItem(int store_id)
//{
//	CampStoreItemMap::iterator it = camp_store_item_map.find(store_id);
//	if (it == camp_store_item_map.end())
//	{
//		//删除 调用更新数据库
//	}
//}
//
//void CampStoreManager::onGetData(User* user, NetData::Ptr reply)
//{
//	//判断是否在势力
//
//	int today_open_time = TimeUtil::getTimeOfToday();//设置开始时间   这个函数是得到零点
//	int today_close_time = today_open_time + 3600;//一小时后关闭
//	bool is_open = false;//是否开启
//	if (TimeUtil::now() >= today_open_time && TimeUtil::now() <= today_close_time)
//	{
//		is_open = true;
//	}
//	reply->writeBool(is_open);
//	//商城开启时间
//	//得到用户竞拍次数
//	reply->writeInt32();
//	//加载竞拍物品
//	{
//		AutoLock lock(camp_store_item_map_lock);
//		FOR_EACH(CampStoreItemMap, camp_store_item_map, iter)
//		{
//			CampStoreItem *item = iter->second;
//			if (!item || !item->getThing())
//			{
//				continue;
//			}
//			reply->writeBool(true);
//			item->packItem(reply);
//		}
//	}
//	reply->writeBool(false);
//}
