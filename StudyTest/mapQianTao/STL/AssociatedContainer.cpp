#include <iostream>
#include <set>
#include <map>
using namespace std;

/*���������Ƿ��������ṹ 
�Ƕ������ṹ ��Ԫ��֮��û���ϸ������ϵ��߼��ṹ
�ṩ�˵����� ����Ԫ�ص��ص� ������Ӧ��Ԫ��
�ص㣺���ݼ�ֵ������������ 
set multiset map multimap 
set:���ϣ�����ֵΨһ������˳�� ��ֵ�Բ��룬������ ������
multiset����Ҫ�����ֵΨһ
map�����ռ�ֵ��  �������ظ� ������set���Կ�������map��û��ֵֻ�м�
multimap���������Ψһ
Ĭ�ϲ�������������
���Ҹ��Ӷ�log��N��
*/



int main1()
{
	set<int> set1;
	set1.insert(1);
	set1.insert(2);
	set1.insert(1);

	multiset<int>mutset1;
	mutset1.insert(1);
	mutset1.insert(2);
	mutset1.insert(1);

	//set<int>::iterator it = set1.begin();
	//multiset<int>::iterator it = mutset1.begin();
	//for (; it != mutset1.end(); it++)
	//{
	//	std::cout << *it << endl;
	//}


	map<int, int> map1;
	map1.insert(make_pair(1, 2));
	map1.insert(make_pair(2, 3));
	map1.insert(make_pair(1, 2));

	multimap<int, int>multmap;
	multmap.insert(make_pair(1, 2));
	multmap.insert(make_pair(2, 3));
	multmap.insert(make_pair(1, 2));//������ռ�ֵ˳�� �������
	//map<int, int>::iterator it = map1.begin();
	map<int, int>::iterator it = multmap.begin();
	for (;it!= multmap.end();it++)
	{
		std::cout << it->second << endl;
	}

	system("pause");
	return 0;
}