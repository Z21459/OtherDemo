#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;


//容器内部排序  自定义规则
/*
1.sort()
2.stable_sort()//两者适用于 vector deque 
//上述两个默认排序为operator<
3.partial_sort()   局部排序
4. partial_sort_copy()

5.nth_element() 根据某个元素排序 --对指定区间内元素排序
并使滴=第n个位置的元素就位。即所有在位置n之前的元素小于等于他

//二元判断式自定义排序 学会写二元判断式

6. merge set_union set_difference set_intersection


搜索算法  binary_search 使用之前 园所是已经有序的 才可以
includes()
lower_bound()---返回第一个大于value的位置
upper_bound()


删除运算 
1.remove  指定范围内删除所有val ***函数返回值删除之后容器的新末尾处
remove_if 移除使条件为true的元素

//删除重复的 对于 vector list deque multiset multimap
   提供了unique()  可以实现容器中元素唯一值
*/
template <class T>
bool DefineSort(T elem1, T elem2)
{
	if (elem1 > elem2) return true;//降序
	else if (elem1 > 3 || elem2 > 3)
	{
		return true;
	}
	return false;
}


int main5()
{

	system("pause");
	return 0;
}