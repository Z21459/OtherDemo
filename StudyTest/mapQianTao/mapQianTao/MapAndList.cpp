#include <iostream>
#include <map>
#include <list>
#include <vector>
using namespace std;
template <typename TKey, typename TValue>

class B
{
public:
	struct A
	{
		int key;
		int value;
	};
	bool push(int key, int value)
	{
		auto it = a_map.find(key);
		if (it != a_map.end())
		{
			return false;
		}
		A a;
		a.key = key;
		a.value = value;
		list<A>iterator::iter;
		a_list.push_back(a);//将struct放入到list、
		iter = a_list.end();
		iter--;
		a_map.insert(make_pair(key, iter));
		return true;
	}
private:
	int b;
public:
	map<int, typename list<A>::iterator >a_map;
	list<A> a_list;
};


int main1()
{



	system("pause");
	return 0;
}