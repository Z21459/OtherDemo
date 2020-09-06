#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <queue>
using namespace std;


//template <class T>//声明模板

class Thing
{
public:
	Thing(){}
	~Thing(){}
	vector <int> getThing(vector <int> &vec)
	{ 
		vec.push_back(id);
		vec.push_back(age);
		//vec.push_back(name);
		return vec; 
	}
public:
	int id;
	int age;
	string name;
};

vector<Thing*>VectorThing;




class Temp 
{
public:
	Temp(){}
	~Temp(){}

public:
	int id;
	int age;
};

typedef map<int, Temp*>TempMap;
typedef map<int, int> IntMap;//存放奖励序号

class InsertTemp
{
public:
	InsertTemp(){}
	~InsertTemp(){}
	vector <Temp*> getThing(vector <Temp*> &vec,int id)//反会Thing*
	{
		map<int, Temp*>::iterator it = temp_map.find(id);
		if (it != temp_map.end())
		{
			vec.push_back(it->second);//放入到vector
		}
		/*for (; it != temp_map.end(); it++)
		{
			vec.push_back(it->second);//放入到vector
		}*/
		cout << "查找成功" << endl;
		return vec;
	}
	const TempMap &getTempMap() { cout << "成功得到Map" << endl; return temp_map; }
	void Insert()//插入
	{
		int id = 0;
		int age = 1;
		for (int i = 0; i < 3; i++) {
			Temp *temp = new Temp;
			temp->id = id++;
			temp->age = age++;
			temp_map.insert(TempMap::value_type(id, temp));
		}
		std::cout << "插入成功" << endl;
	}
private:
	TempMap temp_map;
};

vector<list<int>>veclist;
//list<int>plist;

class VectorList
{
public:
	VectorList(){}
	~VectorList(){}
	void Insert()
	{
		int id = 0;
		int age = 0;
		for (int i = 0; i < 3; i++)
		{
			id++;
			age++;
			list<int>plist[3];
			plist[i].push_back(id);
			plist[i].push_back(age);
			veclist.push_back(plist[i]);
		}
		cout << "插入成功" << endl;
	}

	void printVecList()
	{
		for (int i = 0; i < veclist.size(); i++)
		{
			list<int>::iterator it = veclist[i].begin();
			for (; it != veclist[i].end(); it++)
			{
				cout << *it << " ";//*it解析 去引用
			}
		}
		cout << endl;
	}
	void find(int id)
	{
		//在数组中查找下表
		if (id < 0 || id > veclist.size()) return;
		for (int i = 0; i < veclist.size(); i++)
		{
			if (id == i)
			{
				list<int>::iterator it = veclist[i].begin();
				for (; it != veclist[i].end(); it++)
				{
					cout << *it << " ";//解引用
				}
				cout << "查找成功" << endl;
			}
		}
	}

	void findInsert(int id)
	{
		if (id<0 || id>veclist.size()) return;
		veclist[id].push_back(4);
		veclist[id].push_back(5);
		for (int i = 0; i < veclist.size(); i++)
		{
			if (id = i)
			{
				//list<int>::iterator it = veclist[i].begin();
			}
		}
	}
public:
	int id;
	int age;
};

class W
{
public:
	W(){}
	~W(){}
	int get() { return a; }
	int getb() { return b; }
public:
	int a;
	int b;
};
vector<queue<W*>> vec[4];//
queue<W*>que[4];
typedef map<int, W*>wmap;

#include<map>
#include<string>
#include<iostream>
using namespace std;

typedef
pair<string,
	int>
	PAIR;





bool
cmp_by_value(const
	PAIR&
	lhs,
	const
	PAIR&
	rhs)
{


	return
		lhs.second
		<
		rhs.second;


}





struct CmpByValue
{
	bool operator()(const PAIR&lhs, const PAIR& rhs)
	{
		if (lhs.second == rhs.second == 80) return true;
		else false;
	}
};

int main()
{
	/*map<string,int>name_score_map;
	name_score_map["LiMin"]=80;
	name_score_map["ZiLinMi"]=89;
	name_score_map["BoB"]=82;
	name_score_map.insert(make_pair("Bing", 99));
	name_score_map.insert(make_pair("Albert", 86));

	//把map中元素转存到vector中  
	vector<PAIR>name_score_vec(name_score_map.begin(),name_score_map.end());

	sort(name_score_vec.begin(),name_score_vec.end(), CmpByValue());

	sort(name_score_vec.begin(), name_score_vec.end(), cmp_by_value);*/

	/*for(int i=0;i!=name_score_vec.size();i++)
	{
		cout <<name_score_vec[i].second<<endl;
	}*/

	vector<int>p = { 1,3,4,5,5,4,3,1,2,3 };
	
	for (auto i : p)
	{
		cout << i << ",";
	}
	cout << endl;
	int s1(4132);
	int n(0), loc(0);
	do
	{
		n = s1 / 1000;
		s1 = (s1 - n * 1000) * 10;
		cout << n ;
		for (auto i = loc; i < p.size(); i++) {
			if (n == p[i])//找到关键字  遍历
			{
				swap(p[i], p[loc]);
				++loc;
			}
		}
	} while (s1 != 0);
	cout << endl;

	for (auto i : p)
	{
		cout << i << ",";
	}
	/*vector<int> p = { 1,3,4,5,1,2,3,3,4,3 };
	//按照 4123  4411233335 排序
	//按照 2341  2333344115
	for (int i = 0; i < 10; i++)
	{
		//一趟解决
	}*/

	
	//vector<vector<bool>>state_standar;
	//vector<bool>get_state;
	//vector<bool>finish_standar;
	//get_state.push_back(true);
	//get_state.push_back(false);
	//get_state.push_back(false);
	//finish_standar.push_back(true);
	//finish_standar.push_back(true);
	//finish_standar.push_back(false);
	//state_standar.push_back(get_state);
	//state_standar.push_back(finish_standar);

	//vector<bool>::iterator iter_get_state = state_standar[0].begin();
	//vector<bool>::iterator iter_finish_standar = state_standar[1].begin();
	//for (; iter_get_state != state_standar[0].end() && iter_finish_standar != state_standar[1].end(); iter_get_state++, iter_finish_standar++)
	//{
	//	bool flag = *iter_get_state ? false : (*iter_finish_standar ? true : false);
	//	cout << flag << " ";
	//}

	//wmap mp;
	//int k = 1;
	//for (int i = 0; i < 4; i++)
	//{
	//	W*w = new W;
	//	w->a = 1;
	//	w->b = 2;
	//	mp.insert(wmap::value_type(k++, w));
	//}
	//W*w1 = new W;
	//w1->a = 2;
	//w1->b = 8;
	//mp.insert(wmap::value_type(k++, w1));
	//W*w2 = new W;
	//w2->a = 1;
	//w2->b = 9;
	//mp.insert(wmap::value_type(k++, w2));
	//W*w3 = new W;
	//w3->a = 1;
	//w3->b = 7;
	//mp.insert(wmap::value_type(k++, w3));
	//W*w4 = new W;
	//w4->a = 3;
	//w4->b = 6;
	//mp.insert(wmap::value_type(k++, w4));

	//map<int, W*>::iterator it = mp.begin();
	//for (; it != mp.end(); it++)
	//{
	//	if (it->second->a == 1)
	//	{
	//		que[0].push(it->second);
	//	}
	//	else if (it->second->a == 2)
	//	{
	//		que[1].push(it->second);
	//	}
	//	else if(it->second->a == 3)
	//	{
	//		que[2].push(it->second);
	//	}
	//	else
	//	{
	//		que[3].push(it->second);
	//	}
	//}
	//vec[0].push_back(que[0]);
	//vec[1].push_back(que[1]);
	//vec[2].push_back(que[2]);
	//vec[3].push_back(que[3]);

	//while (1)//设置条件
	//{
	//	if (vec[0][0].size() > 0)
	//	{
	//		for (int i = 0; i < vec[0][0].size(); i++)
	//		{
	//			//里面只有vec[0][0]
	//			//cout << vec[0][0].size();
	//			cout << vec[0][0].front()->getb();//对列头部
	//			if (vec[0][0].size() > 0)
	//			{
	//				vec[0][0].pop();//弹出
	//			}
	//			/*if (vec[0][0].size() == 0)
	//			{
	//				break;
	//			}*/
	//		}cout << "1结束\n";
	//	}
	//	else if (vec[0][0].size() ==0 && vec[1][1].size() > 0)
	//	{
	//		for (int i = 0; i < vec[1][1].size(); i++)
	//		{
	//			cout << vec[1][1].front()->getb();//对列头部
	//			if (vec[1][1].size() > 0)
	//			{
	//				vec[1][1].pop();//弹出
	//			}
	//		}
	//		cout << "2结束\n";
	//	}
	//	else if (vec[1][1].size() == 0 && vec[2][2].size() > 0)
	//	{
	//		for (int i = 0; i < vec[2][2].size(); i++)
	//		{
	//			cout << vec[2][2].front()->getb();//对列头部
	//			if (vec[2][2].size() > 0)
	//			{
	//				vec[2][2].pop();//弹出
	//			}
	//		}
	//		cout << "3结束\n";
	//	}
	//	else
	//	{
	//		for (int i = 0; i < vec[3][3].size(); i++)
	//		{
	//			cout << vec[3][3].front()->getb();//对列头部
	//			if (vec[3][3].size() > 0)
	//			{
	//				vec[3][3].pop();//弹出
	//			}
	//		}
	//		
	//		cout << "其他结束\n";
	//	}//break;
	//}
	
	/*//vector list嵌套
	VectorList vlist;
	vlist.Insert();
	vlist.printVecList();
	vlist.find(2);
	vlist.findInsert(2);
	vlist.printVecList();
	vlist.find(2);*/
	//map vector 嵌套类
	/*InsertTemp inserttemp;
	inserttemp.Insert();
	TempMap temp_map = inserttemp.getTempMap();//得到map；
	vector <Temp*> vec;
	int id = 2;
	vec = inserttemp.getThing(vec,id);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << "查找到了" << vec[i]->id << " " << vec[i]->age << endl;
	}*/


	//vector嵌套类
	/*vector<int>vec;
	Thing *thing = new Thing;
	thing->id = 1;
	thing->age = 2;
	VectorThing.push_back(thing);

	thing->getThing(vec);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i];
	}*/



	system("pause");
	return 0;
}