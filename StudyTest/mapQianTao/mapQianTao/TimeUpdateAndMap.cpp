//#include<map>
//class t
//{
//public:
//	t();
//	~t();
//public:
//	int id;
//	int a;
//	int b;
//};
//
//typedef std::map<int, t*>tmap;
//
//class t1
//{
//public:
//	t1();
//	~t1();
//public:
//	void init();
//	void printmap();
//public:
//	int id;
//	int c;
//	tmap _tmap;
//};
//
//
//typedef std::map<int, t1*>t1map;
//
//class t2
//{
//public:
//	t2();
//	~t2();
//public:
//	void init(t1& _t1);
//	void printmap();
//	void findvalue();//����id ���� ��һ��map
//public:
//	int id;
//	int d;
//	t1map _t1map;
//};

/*#include <iostream>
#include <map>
struct Man{
	std::string name;
	int age;
	bool operator<(const Man& g)const {
		if (age < g.age) {
			return true;
		}
		return false;
	}

};

struct Tripple
{
	int score [ 3 ];
};




int main() {
	std::map<Man, Tripple > Infos ;

	Tripple  triple_score1 = {70,80,90};

	Man man1,man2,man3;
	man1.name = "Lucy";
	man1.age = 20;
	man2.name = "July";
	man2.age = 21;
	man3.name = "James";
	man3.age = 22;
		Infos[man1]=triple_score1;


	for(std::map<Man, Tripple>::iterator iter = Infos.begin(); iter != Infos.end(); ++iter) {
		std::cout << iter->second.score[0]<< std::endl;
		std::cout << iter->second.score[1]<< std::endl;
		std::cout << iter->second.score[2]<< std::endl;
	}
	return 0;
}*/

//#include <iostream>
//#include <map>
//#include "config.h"
//#include <fstream>
//#include <vector>
//#include <string>
//using namespace std;
//
//
//t::t():id(0),a(0),b(0){}
//t::~t(){}
//
//t1::t1():id(0),c(0) {}
//t1::~t1()
//{
//	_tmap.clear();
//}
//void t1::init()
//{
//	t *t0 = new t;///�����ָ��  ��Ҫnewһ���ռ�  ������Ƕ�����newһ���ռ�
//	t0->id = 1;
//	t0->a = 2;
//	t0->b = 3;
//	_tmap.insert(tmap::value_type(id,t0));
//}
//void t1::printmap()
//{
//	std::map<int, t*>::iterator iter;
//	for (iter = _tmap.begin(); iter != _tmap.end(); ++iter)
//	{
//		//cout << iter->second();
//		cout << iter->second->id << iter->second->a << iter->second->b << endl;;
//		cout << "_tmap***" << endl;
//	}
//}
//t2::t2() :id(0), d(0) {}
//t2::~t2()
//{
//	_t1map.clear();
//}
//void t2::init(t1& _t1)
//{
//	//t1 *t10 = new t1;
//	//t10->c = 8;
//	_t1map.insert(t1map::value_type(id, &_t1));
//}
//void t2::printmap()
//{
//	std::map<int, t1*>::iterator iter2;
//	for(iter2=_t1map.begin();iter2 != _t1map.end();++iter2)
//	{
//		cout << iter2->second->c  << endl;
//		cout << "t2map***";
//	}
//}
//
//void t2::findvalue()
//{
//	auto m = _t1map.find(0);
//	if (m != _t1map.end())
//	{
//		cout << "find id 0::" << m->second->c;
//
//	}
//}
//
////class csvdata
////{
////public:
////	int id;
////	int a;
////	int b;
////};
////
//int main()
//{
//	t1 t10;
//	t2 t20;
//	t10.init();
//	t10.printmap();
//	t20.init(t10);
//	t20.printmap();
//	t20.findvalue();//����key  ����valueΪ��һ����map
////
////	ifstream inFinle("reward.csv", ios::in);
////	if (!inFinle.is_open())
////	{
////		cout << "error";
////	}
////	string strline;
////	std::map<string, string>result;
////	//�ָ�
////	while (getline(inFinle, strline))
////	{
////		
////		int index = strline.find(',');//�ԣ�Ϊ��׼���
////		string e = strline.substr(0, index);
////		//
////		string admin = strline.substr(index + 2, strline.size() - 1);
////		result[e] = admin;
////	}
////	std::map<string, string>::iterator iter;
////	for (iter = result.begin(); iter != result.end(); iter++)
////	{
////		cout << iter->first << iter->second << endl;
////	}
////
//	system("pause");
//	return 0;
//}


//#include <time.h>
//void testTime()
//{
//	struct tm t;   //tm�ṹָ��
//	time_t now;  //����time_t���ͱ���
//	time(&now);      //��ȡϵͳ���ں�ʱ��
//	localtime_s(&t, &now);   //��ȡ�������ں�ʱ��
//
//
//
//	////��ʽ���������ʱ��
//	//printf("�꣺%d\n", t.tm_year + 1900);
//	//printf("�£�%d\n", t.tm_mon + 1);
//	//printf("�գ�%d\n", t.tm_mday);
//	//printf("�ܣ�%d\n", t.tm_wday);
//	//printf("һ���У�%d\n", t.tm_yday);
//	//printf("ʱ��%d\n", t.tm_hour);
//	//printf("�֣�%d\n", t.tm_min);
//	//printf("�룺%d\n", t.tm_sec);
//	//printf("����ʱ��%d\n", t.tm_isdst);
//	//cout << t.tm_hour * 60 * 60 + t.tm_min * 60 + t.tm_sec << endl;
//	//long int t1 = 23 * 60 * 60 + 59 * 60 + 59;
//	while (1)//����ʱ���
//	{
//		time(&now);      //��ȡϵͳ���ں�ʱ��
//		localtime_s(&t, &now);   //��ȡ�������ں�ʱ��
//		long int t1 = 22 * 60 * 60 + 21 * 60 + 1;
//		long int t2 = t.tm_hour * 60 * 60 + t.tm_min * 60 + t.tm_sec;
//		if (t1 - t2 == 0)
//		{
//			break;
//		}
//	}
//}