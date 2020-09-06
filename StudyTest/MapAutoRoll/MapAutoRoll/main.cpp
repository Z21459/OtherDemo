#include <iostream>
#include "GoodsSet.h"
#include <ctime>
#include <algorithm>
#include<vector>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
using namespace std;

class A
{
public:
	A(){}
	~A() {};
	int a;
	int b;
};
typedef map<int, A*>AMap;

bool myfunction(int i, int j) { return (i < j); }

struct myclass {
	bool operator() (int i, int j) { return (i < j); }
} myobject;


int main()
{
	//GoodsSet good_set;
	//good_set.Init();
	/*struct tm t;
	time_t now;
	time(&now);
	localtime_s(&t, &now);
	//long int t1 = 23 * 60 * 60 + 59 * 60 + 59;
	while (1)//测试时间戳
	{
		time(&now);      //获取系统日期和时间
		localtime_s(&t, &now);   //获取当地日期和时间
		long int t1 = 22 * 60 * 60 + 21 * 60 + 1;
		long int t2 = t.tm_hour * 60 * 60 + t.tm_min * 60 + t.tm_sec;
		if (t1 - t2 == 0)
		{
			break;
		}
	}*/

	//AMap a_map;
	//A *a1 = new A;
	//a1->a = 1;
	//a1->b = 2;
	//A *a2 = new A;
	//a2->a = 4;
	//a2->b = 5;
	//A *a3 = new A;
	//a3->a = 3;
	//a3->b = 1;
	//A *a4 = new A;
	//a4->a = 3;
	//a4->b = 7;
	//a_map.insert(AMap::value_type(1, a1));
	//a_map.insert(AMap::value_type(2, a2));
	//a_map.insert(AMap::value_type(3, a3));
	//a_map.insert(AMap::value_type(4, a4));
	//map<int, A*>::iterator iter = a_map.begin();
	//for (; iter != a_map.end(); iter++)
	//{
	//	if (iter->first == 2 || iter->first == 4)
	//	{
	//		a_map.erase(iter--);
	//		continue;
	//	}
	//	cout << iter->second->a << " " << iter->second->b << endl;
	//}
	//排行榜 设计类

		//int myints[] = { 1,1,2,3,2,1,4,5 };
		//std::vector<int> myvector(myints, myints + 8);               // 32 71 12 45 26 80 53 33

		//// using default comparison (operator <):
		//std::sort(myvector.begin(), myvector.begin() + 4);           //(12 32 45 71)26 80 53 33

		// using function as comp  初始2  总共3个元素  2+3+1
		//std::sort(myvector.begin() + 4, myvector.begin()+7, myfunction); // 12 32 45 71(26 33 53 80)

		//// using object as comp
		//std::sort(myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

		//// print out content:
		//int a = 1, b = 2, c = 3;
		//while (1)
		//{
		//	cout << "输入a:";
		//	cin >> a;
		//	for (int i = 0; i < myvector.size(); i++)
		//	{
		//		if (a == myvector[i])
		//		{
		//			//当前值和第一个交换
		//			swap(myvector[0], myvector[i]);
		//			break;
		//		}
		//	}
		//	cout << "输入b：";
		//	cin >> b;
		//	for (int i = 0; i < myvector.size(); i++)
		//	{
		//		if (b == myvector[i])
		//		{
		//			//当前值和第一个交换
		//			swap(myvector[1], myvector[i]);
		//			break;
		//		}
		//	}
		//	cout << "输入c：";
		//	cin >> c;
		//	for (int i = 0; i < myvector.size(); i++)
		//	{
		//		if (c == myvector[i])
		//		{
		//			//当前值和第一个交换
		//			swap(myvector[2], myvector[i]);
		//			break;
		//		}
		//	}

		//}



		//std::cout << "myvector contains:";
		//for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		//	std::cout << ' ' << *it;
		//std::cout << '\n';

		/*typedef map<int, int>map1;
		map1 m1;
		m1.insert(map1::value_type(1, 1));
		m1.insert(map1::value_type(2, 2));
		m1.insert(map1::value_type(3, 3));
		m1.insert(map1::value_type(4, 4));
		cout << m1[m1.size()];//取最后一个元素*/

		int myints[] = { 1};
		//std::vector<int> myvector(myints, myints + 8);
		std::vector<int> myvector;
		myvector.push_back(1);
		myvector.push_back(6);
		std::vector<int>vec;
		std::vector<int>::iterator iter = myvector.begin();
		if ((*iter) != 0)
		{
			cout << (*iter) << " ";
			if (++iter != myvector.end())
			{
				cout << (*(iter));
			}
			cout << endl;
		}
		swap(myvector[0], myvector[myvector.size() - 1]);
		myvector.pop_back();
		int loc = 0;
		for (int i = 0; i < myvector.size(); i++)
		{
			for (int j = 0; j < myvector.size(); j++)
			{
				if (myvector[i] > myvector[j])
				{
					swap(myvector[i],myvector[j]);
					loc++;
				}
			}
		}
		cout << endl;

		//找所有重复的数
		/*swap(*(myvector.begin()), *(myvector.end()));//交换首尾
		myvector.pop_back();
		for (int i = 0; i < myvector.size(); i++)
		{
			cout << myvector[i] << " ";
		}*/
		
		/*std::vector<int> nums(myints, myints + 8);
		vector<int> r;
		for (auto i = 0; i < nums.size(); ++i) {
			if (nums[abs(nums[i]) - 1] < 0) { // 已经出现过了
				r.push_back(abs(nums[i]));
			}
			else {
				nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
			}
		}*/
		
		//查找重复数字 和出现的次数
		//int A[12] = { 1,3,4,7,2,3,9,4,0,2,1 ,1}, N = 12;
		//sort(A, A + N);
		//int i, p = A[0], n = 1;
		//printf("VAL\tNUM\n");
		//for (i = 1; i < N; i++)
		//{
		//	if (p != A[i])
		//	{
		//		if (n > 1)
		//		{
		//			printf("%d\t%d\n", p, n);
		//			vec.push_back(p);//重复的数值
		//		}
		//		p = A[i];
		//		n = 1;
		//	}
		//	else ++n;
		//}
		//cout << endl;
		//

	system("pause");
	return 0;
}