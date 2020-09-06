//#include "UserCampStoreManager.h"
//
//
//
//UserCampStoreManager::UserCampStoreManager()
//{
//}
//
//
//UserCampStoreManager::~UserCampStoreManager()
//{
//}
//
//void UserCampStoreManager::loadDB()
//{
//	DataTable::Ptr table_store = DBService::getInstance().fetchRows(DbUtil::makeSelectSql(TABLE_MEM_CAMP_STORE));
//	for (int i = 0; i < table_store->getRowCount(); i++)
//	{
//		DataRow::Ptr row = table_store->getDataRow(i);
//		if (!row)
//		{
//			continue;
//		}
//		//≈–∂œÀ˘ Ù ∆¡¶
//		CampStoreManager p;
//		p.loadItem(row);
//	}
//}
