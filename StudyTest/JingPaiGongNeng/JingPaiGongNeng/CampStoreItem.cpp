//#include "CampStoreItem.h"
//
//
//
//CampStoreItem::CampStoreItem()
//{
//}
//
//
//CampStoreItem::~CampStoreItem()
//{
//}
//
//void CampStoreItem::fromDB(Data::Ptr row)
//{
//	store_id = row->getInt32("store_id");
//	good_id = row->getInt32("good_id");
//	good_name = row->getString("good_name");
//	good_count = row->getInt32("good_count");
//	good_type = row->getInt32("good_type");
//	good_quality = row->getInt32("good_quality");
//}
//
//void CampStoreItem::packItem(NetData::Ptr buf)
//{
//	ThingBase *thing = getThing();
//	if (!thing) return;
//	buf->writeInt32(store_id);
//	thing->pack(buf);
//}
//
//ThingBase * CampStoreItem::getThing()
//{
//	_thing = ThingBase::getInstance().create(good_type(), good_id(), good_count(), good_quality());
//	return _thing;
//}
//
//bool CampStoreItem::giveThing(User * user, int reason, string param)
//{
//	ThingBase *thing = this->getThing();
//	if (!thing) return false;
//	GloabalgManager::getInstance.logCampStoreRemoveItem();
//	thing->give(user, REASON_CAMP_STORE_GIVE, "store_id" + StringUtil::toString(store_id));
//	return true;
//}
