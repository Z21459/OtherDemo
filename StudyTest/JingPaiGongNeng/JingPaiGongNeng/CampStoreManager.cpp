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
//	//�������ID��0 ���˵���ֹ�ͻ��˹ҵ�
//	if (row->getInt32("good_type") == THING_GOODS && row->getInt32("good_id") == 0)
//	{
//		return;
//	}
//	CampStoreItem *item = new CampStoreItem;
//	item->fromDB(row);
//	addItem(item);//����
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
//		//ɾ�� ���ø������ݿ�
//	}
//}
//
//void CampStoreManager::onGetData(User* user, NetData::Ptr reply)
//{
//	//�ж��Ƿ�������
//
//	int today_open_time = TimeUtil::getTimeOfToday();//���ÿ�ʼʱ��   ��������ǵõ����
//	int today_close_time = today_open_time + 3600;//һСʱ��ر�
//	bool is_open = false;//�Ƿ���
//	if (TimeUtil::now() >= today_open_time && TimeUtil::now() <= today_close_time)
//	{
//		is_open = true;
//	}
//	reply->writeBool(is_open);
//	//�̳ǿ���ʱ��
//	//�õ��û����Ĵ���
//	reply->writeInt32();
//	//���ؾ�����Ʒ
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
