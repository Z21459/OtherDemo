#include "GoodsSet.h"
#include <time.h>
#include <cstdlib>
#include <cstdio>

//���������
//#define Randmod(x) rand()%x
#define Random(low,hight) (rand() % (hight - low)) + low + 1
//srand((unsigned)time(null));
//(low, up) #define Random(rand() % (up - low + 1)) + low - 1
//[low, up) #define Random(rand() % (up - low)) + low
//(low, up] #define Random(rand() % (up - low)) + low + 1
//[low, up] #define Random(rand() % (up - low + 1)) + low

/*
//����������������ʹ���������  �ڿͻ��˽����ж�
1 �Ŷ�  
2 ����
3 ����
4 ϴ��
5 ����
*/


GoodsSet::GoodsSet()
{
	vec.push_back(3);//���һ��ʼ����5
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(1);
	count = 10;
	while(count)
	{
		int type = rand() % 4 + 0;//0 1 2 3
		cout << type << endl;
		count--;
	}
	cout << endl;
}


GoodsSet::~GoodsSet()
{
}

void GoodsSet::Init()
{
	//loadThing();
	//SortMap();
	AutoRoll();
}
void GoodsSet::AutoRoll()
{
	//std::cout << "type_id����\n";
	//for (int i = 0; i < vec.size(); i++)
	//{
	//	std::cout << vec[i] << " ";
	//}
	std::cout << endl;
	int a = 10;
	while (a--)
	{
		temp_vec_map.clear();
		SortMap();
		//������ ����
		//std::cout << "������\n";
		//std::cout << "id " << "type_id " << "quality " << "count " << "name" << endl;
		//for (int i = 0; i < temp_vec_map.size(); i++)//���ʴ�_thing_map����õ�������
		//{
		//	std::cout << temp_vec_map[i]->id << " "
		//		<< temp_vec_map[i]->type_id << " "
		//		<< temp_vec_map[i]->quality << " "
		//		<< temp_vec_map[i]->count << " ";
		//	printf("%s", temp_vec_map[i]->name.c_str());
		//	std::cout << endl;
		//}
		std::cout << endl;
	}
	
}
bool GoodsSet::sampleSort(const Thing *left, const Thing *right)
{

	if (left->type_id != right->type_id)
		return left->type_id > right->type_id;
	if (left->quality != right->quality)
		return left->quality > right->quality;
	if (left->count != right->count)
		return left->count > right->count;//���� 
	/*if (left.type_id != right.type_id)
		return left.type_id > right.type_id;
	if (left.quality != right.quality)
		return left.quality > right.quality;
	if (left.count != right.count)
		return left.count > right.count;*/

	return left->type_id < right->type_id;//���� *** ��ȵ�ʱ�� ����false ����Խ��
}
bool cmp()
{
	return true;
}

void GoodsSet::SortMap()
{
	//��������������  ������ֲ������ĸ� ��������һ��vector  �������ȼ�
	
	//����ǰ���
	//std::cout << "type_id����\n";
	//for (int i = 0; i < vec.size(); i++)
	//{
	//	std::cout << vec[i] << " ";
	//}
	//std::cout << endl;

	/*std::cout << "û����ǰ" << endl;
	map<int, Thing*>::iterator iter3 = _thing_map.begin();
	std::cout << "id " << "type_id " << "quality " << "count " << "name " << endl;
	for (; iter3 != _thing_map.end(); iter3++)
	{
		std::cout << iter3->second->id << " "
			 << iter3->second->type_id << " "
			 << iter3->second->quality << " "
			 << iter3->second->count << " ";
		printf("%s", iter3->second->name.c_str());
		std::cout << endl;
	}*/
	//������ �ټ��� �������� �ظ�
	_thing_map.clear();
	loadThing();
	std::cout << endl;
	
	map<int, Thing*>::iterator iter = _thing_map.begin();
	for (; iter != _thing_map.end(); iter++)
	{
		temp_vec_map.push_back(iter->second);
		//std::cout << iter->first << " ";
	}
	std::cout << endl;

	int a = 4;
	int i = 0, cur = 0;
	int begin = 0;
	bool falg = false;
	vector<Thing*> other_vec;
	while (a)//�����һ�˽� �������4����������  ���ȼ�
	{
		for (int j = 0; j < vec.size(); j++)
		{
			temp_vec_map;
			for (int i = cur; i < temp_vec_map.size(); i++)
			{
				if (vec[j] != 1 && vec[j] != 2 && vec[j] != 3 && vec[j] != 4)//������Ϊ����
				{
					if (temp_vec_map[i]->type_id != 1 && temp_vec_map[i]->type_id != 2 && //vec 6 1 3 4
						temp_vec_map[i]->type_id != 3 && temp_vec_map[i]->type_id != 4)//�������ض��ļ��ֵ���
					{
						if (!falg)
						{
							begin = cur;//i
							falg = true;
						}
						other_vec.push_back(temp_vec_map[i]);
						swap(temp_vec_map[i], temp_vec_map[cur]);
						cur++;
						//�õ�������

					}
				}
				else
				{
					if (temp_vec_map[i]->type_id == vec[j])
					{
						swap(temp_vec_map[i], temp_vec_map[cur]);
						cur++;
					}
				}
			}
		}
		a--;
	}
	vector<Thing*>quality_same;
	int begin_same = 0;
	bool flag = false;
	if (!other_vec.empty())
	{
		//����Ʒ������
		for (int i = 0; i < other_vec.size(); i++)
		{
			for (int j = 0; j < other_vec.size(); j++)
			{
				if (other_vec[i]->quality > other_vec[j]->quality)
				{
					std::swap(other_vec[i], other_vec[j]);
				}
				if (other_vec[i]->quality == other_vec[j]->quality && (i != j))
				{
					if (!flag)
					{
						begin_same = j;
						flag = true;
					}
					if (std::find(quality_same.begin(), quality_same.end(), other_vec[j]) == quality_same.end())
					{
						quality_same.push_back(other_vec[j]);
					}
					
				}
			}
		}
		cout << "gid" << " " << "quality" << " " << "count" << endl;
		for (int i = 0; i < other_vec.size(); i++)
		{
			cout << other_vec[i]->gid << " " << other_vec[i]->quality << " " << other_vec[i]->count << endl;

		}
		//ԭ�������滻

		cout << endl;
		////Ʒ������� ������ͬƷ�ʵ� ���һ�� ������������
		////vector<Thing*>quality_same;
		//int begin_same = 0;
		//bool flag = false;
		//for (int i = 0; i < other_vec.size()-1; i++)
		//{
		//	if (other_vec[i]->quality == other_vec[i + 1]->quality)
		//	{
		//		if (!flag)
		//		{
		//			begin_same = i;
		//			flag = true;
		//		}
		//		//Խ����(i + 2) == other_vec.size() -1 ���ܻ�Խ��  
		//		if ((i + 2) == other_vec.size()/*|| other_vec[i]->quality!= other_vec[i + 2]->quality*/)//���i=2 Ҳ��Խ��
		//		{
		//			quality_same.push_back(other_vec[i]);
		//			quality_same.push_back(other_vec[i + 1]);
		//			break;
		//		}
		//		else
		//		{
		//			if (other_vec[i]->quality != other_vec[i + 2]->quality)
		//			{
		//				quality_same.push_back(other_vec[i]);
		//				quality_same.push_back(other_vec[i + 1]);
		//				break;
		//			}
		//			else
		//				quality_same.push_back(other_vec[i]);
		//		}
		//	}
		//}

		for (int i = 0; i < quality_same.size(); i++)
		{
			cout << quality_same[i]->gid << " " << quality_same[i]->quality << " " << quality_same[i]->count << endl;

		}
		
		if (!quality_same.empty())
		{
			int rand_index = Random(0, quality_same.size() - 1);//���һ����
			cout << "���һ��Ʒ����ͬ��:" << quality_same[rand_index]->gid << " " <<
				quality_same[rand_index]->quality << " " <<
				quality_same[rand_index]->count << endl;
			CountSort(quality_same, rand_index);
			cout << endl;
		}

		//Ʒ����ͬ�� ҲҪ�滻��
		for (int i = begin_same, j = 0; j < quality_same.size(); j++)
		{
			other_vec[i++] = quality_same[j];
		}

		for (int i = begin, j = 0; j < other_vec.size(); j++)
		{
			temp_vec_map[i++] = other_vec[j];
		}
		temp_vec_map;
	}

	

	//int temp = 0;
	//while (temp)
	//{
		//������������� ������������ �ڰ���quality ����  �����quality��ͬ��ѡ��һ��type ����count������
		
		/*for (int i = 0; i < temp_vec_map.size(); i++)//ֻ�������������
		{
			for (int j = 0; j < temp_vec_map.size(); j++)
			{
				if (temp_vec_map[i]->type_id != 1 && temp_vec_map[i]->type_id != 2 &&
					temp_vec_map[i]->type_id != 3 && temp_vec_map[i]->type_id != 4 &&
					temp_vec_map[j]->type_id != 1 && temp_vec_map[j]->type_id != 2 &&
					temp_vec_map[j]->type_id != 3 && temp_vec_map[j]->type_id != 4)//�����������ҲҪ��������
				{
					if (temp_vec_map[i]->quality > temp_vec_map[j]->quality)//�Ȱ���quality��������
					{
						swap(temp_vec_map[i], temp_vec_map[j]);
					}
					else
					{
						//���quality��ͬ  ���ѡ��һ��type ����count����
						//if (temp_vec_map[i]->quality == temp_vec_map[j]->quality && temp_vec_map[i]->count > temp_vec_map[j]->count)
						//{
						//	swap(temp_vec_map[i], temp_vec_map[j]);
						//}
						int type = rand() % 3 + 4;//����������� ����ֻ��5 ��6
						//����������  �ȸ���quality���� ,���quality��ͬ �����ѡ��һ��type �ٸ���ѡ���type ������������
						if (temp_vec_map[i]->quality == temp_vec_map[j]->quality&&temp_vec_map[i]->type_id == type)
						{
							if (temp_vec_map[i]->count > temp_vec_map[j]->count)
							{
								swap(temp_vec_map[i], temp_vec_map[j]);
							}
						}
					}
				}
			}
		}*/
	int x = 2, b = 6;
	std::sort(temp_vec_map.begin() + x, temp_vec_map.begin() + b, GoodsSet::sampleSort);

	//������ ��������������


		////������ ����
		//std::cout << "������\n";
		//std::cout << "id " << "type_id " << "quality " << "count " << "name" << endl;
		//for (int i = 0; i < temp_vec_map.size(); i++)//���ʴ�_thing_map����õ�������
		//{
		//	std::cout << temp_vec_map[i]->id << " "
		//		<< temp_vec_map[i]->type_id << " "
		//		<< temp_vec_map[i]->quality << " "
		//		<< temp_vec_map[i]->count << " ";
		//	printf("%s", temp_vec_map[i]->name.c_str());
		//	std::cout << endl;
		//}
		//std::cout << endl;

		//temp--;
		//std::cout << "suiji:" << temp++;
		//std::cout << endl;
	//}
	////������������� ������������ �ڰ���quality ����  �����quality��ͬ��ѡ��һ��type ����count������
	//for (int i = 0; i < temp_vec_map.size(); i++)//ֻ�������������
	//{
	//	for (int j = 0; j < temp_vec_map.size(); j++)
	//	{
	//		if (temp_vec_map[i]->type_id != 1 && temp_vec_map[i]->type_id != 2 &&
	//			temp_vec_map[i]->type_id != 3 && temp_vec_map[i]->type_id != 4 &&
	//			temp_vec_map[j]->type_id != 1 && temp_vec_map[j]->type_id != 2 &&
	//			temp_vec_map[j]->type_id != 3 && temp_vec_map[j]->type_id != 4)//�����������ҲҪ��������
	//		{
	//			if (temp_vec_map[i]->quality > temp_vec_map[j]->quality)//�Ȱ���quality��������
	//			{
	//				swap(temp_vec_map[i], temp_vec_map[j]);
	//			}
	//			else
	//			{
	//				//���quality��ͬ  ���ѡ��һ��type ����count����
	//				/*if (temp_vec_map[i]->quality == temp_vec_map[j]->quality && temp_vec_map[i]->count > temp_vec_map[j]->count)
	//				{
	//					swap(temp_vec_map[i], temp_vec_map[j]);
	//				}*/
	//				int type = rand() % 3 + 4;//����������� ����ֻ��5 ��6
	//				//����������  �ȸ���quality���� ,���quality��ͬ �����ѡ��һ��type �ٸ���ѡ���type ������������
	//				if (temp_vec_map[i]->quality == temp_vec_map[j]->quality&&temp_vec_map[i]->type_id == type)
	//				{
	//					if (temp_vec_map[i]->count > temp_vec_map[j]->count)
	//					{
	//						swap(temp_vec_map[i], temp_vec_map[j]);
	//					}
	//				}
	//			}
	//		}
	//	}
	//}

	//������ ����
	/*std::cout << "������\n";
	std::cout << "id " << "type_id " << "quality " << "count " << "name" << endl;
	for (int i = 0; i < temp_vec_map.size(); i++)//���ʴ�_thing_map����õ�������
	{
		std::cout << temp_vec_map[i]->id << " "
			<< temp_vec_map[i]->type_id << " "
			<< temp_vec_map[i]->quality << " "
			<< temp_vec_map[i]->count << " ";
		printf("%s", temp_vec_map[i]->name.c_str());
		std::cout << endl;
	}
	std::cout << endl;*/
	
	////���ȼ����� vec ������2 1 3 4 �ִ�map�в鵽 ����2��ֵ��id
	//std::cout << "û����ǰ" << endl;
	//map<int, Thing*>::iterator iter3 = _thing_map.begin();
	//for (; iter3 != _thing_map.end(); iter3++)
	//{
	//	std::cout << iter3->second->id << " "
	//		 << iter3->second->type_id << " "
	//		 << iter3->second->quality << " "
	//		 << iter3->second->count << " ";
	//	printf("%s", iter3->second->name.c_str());
	//	std::cout << endl;
	//}

	//vector<int>::iterator it1 = result_vec.begin();
	//for (; it1 != result_vec.end(); it1++)
	//{
	//	std::cout << *it1 << " ";
	//}
	//std::cout << endl;


	//std::cout << "������" << endl;
	//
	//vector<int>::iterator it = result_vec.begin();
	//for (; it != result_vec.end(); it++)
	//{
	//	std::cout << *it << " ";
	//}
	//std::cout << endl;

}
void GoodsSet::CountSort(vector<Thing*>& quality_same, int rand_index)
{
	Thing* thing = quality_same[rand_index];
	if (thing == nullptr)
	{
		return;
	}
	//����ѡ��� ��������
	int start_count = 0;
	bool flag_count = false;
	vector<Thing*> count_same;
	int loc = 1;
	for (int i = 0; i < quality_same.size(); i++)
	{
		for (int j = 0; j < quality_same.size(); j++)
		{
			if (quality_same[i]->type_id == quality_same[j]->type_id && quality_same[j]->type_id == thing->type_id&&
				quality_same[i]->gid == quality_same[j]->gid && quality_same[j]->gid == thing->gid)
			{
				if (quality_same[i]->count < quality_same[j]->count)
				{
					std::swap(quality_same[i],quality_same[j]);
				}
				//������ͬ������������
				if (quality_same[i]->count == quality_same[j]->count && (i!=j))
				{
					if (!flag_count)
					{
						start_count = i;
						flag_count = true;
					}
					if (std::find(count_same.begin(), count_same.end(), quality_same[j]) == count_same.end())//δ�ҵ�
					{
						count_same.push_back(quality_same[j]);
					}
				}
			}
		}
	}
	if (!count_same.empty())
	{
		int count_rand;
		if (count_same.size() == 1)
		{
			count_rand = 0;
		}
		else
		{
			count_rand = Random(0,count_same.size() - 1);//Random()// ��������ֵ����0
		}

		for (int i = 0; i < quality_same.size(); i++)
		{
			if (count_same[count_rand]->id == quality_same[i]->id)
			{
				std::swap(quality_same[start_count], quality_same[i]);
				break;
			}
		}
		
		
	}
}


Thing::Thing()
{
}

Thing::~Thing()
{
}



void GoodsSet::loadThing()
{

	Thing *thing1 = new Thing;
	thing1->id = 1;
	thing1->type_id = 4;//
	thing1->gid = 40000;
	thing1->quality = 2;
	thing1->count = 1;
	thing1->name = "��";

	Thing *thing2 = new Thing;
	thing2->id = 2;
	thing2->type_id = 4;
	thing2->gid = 40000;
	thing2->quality = 2;
	thing2->count = 3;
	thing2->name = "��";

	Thing *thing3 = new Thing;
	thing3->id = 3;
	thing3->type_id = 3;
	thing3->gid = 10000;
	thing3->quality = 3;
	thing3->count = 2;
	thing3->name = "��";

	Thing *thing4 = new Thing;
	thing4->id = 4;
	thing4->type_id = 3;
	thing4->gid = 10000;
	thing4->quality = 3;
	thing4->count = 2;
	thing4->name = "��";

	Thing *thing5 = new Thing;
	thing5->id = 5;
	thing5->type_id = 2;
	thing5->gid = 20000;
	thing5->quality = 1;
	thing5->count = 4;
	thing5->name = "��";

	Thing *thing6 = new Thing;
	thing6->id = 6;
	thing6->type_id = 2;
	thing6->gid = 20000;
	thing6->quality = 1;
	thing6->count = 3;
	thing6->name = "��";

	Thing *thing7 = new Thing;
	thing7->id = 7;
	thing7->type_id = 5;
	thing7->gid = 70000;//20000
	thing7->quality = 3;
	thing7->count = 1;
	thing7->name = "��";

	Thing *thing8 = new Thing;
	thing8->id = 8;
	thing8->type_id = 5;
	thing8->gid = 70000;
	thing8->quality = 3;
	thing8->count = 6;
	thing8->name = "��";

	Thing *thing9 = new Thing;
	thing9->id = 9;
	thing9->type_id = 5;
	thing9->gid = 70000;
	thing9->quality = 3;
	thing9->count = 6;//
	thing9->name = "��";

	Thing *thing10 = new Thing;
	thing10->id = 10;
	thing10->type_id = 5;
	thing10->gid = 30000;
	thing10->quality = 6;
	thing10->count = 2;
	thing10->name = "��";
	//if (count == 0)
	//{
		_thing_map.insert(ThingMap::value_type(thing1->id, thing1));
		_thing_map.insert(ThingMap::value_type(thing2->id, thing2));
		_thing_map.insert(ThingMap::value_type(thing3->id, thing3));
		_thing_map.insert(ThingMap::value_type(thing4->id, thing4));
		_thing_map.insert(ThingMap::value_type(thing5->id, thing5));
		_thing_map.insert(ThingMap::value_type(thing6->id, thing6));
		_thing_map.insert(ThingMap::value_type(thing7->id, thing7));
		_thing_map.insert(ThingMap::value_type(thing8->id, thing8));
		_thing_map.insert(ThingMap::value_type(thing9->id, thing9));
		_thing_map.insert(ThingMap::value_type(thing10->id, thing10));
		count++;
	//}
	//else if (count == 1)
	//{
	//	_thing_map.insert(ThingMap::value_type(thing1->id, thing1));
	//	_thing_map.insert(ThingMap::value_type(thing2->id, thing2));
	//	_thing_map.insert(ThingMap::value_type(thing3->id, thing3));
	//	_thing_map.insert(ThingMap::value_type(thing4->id, thing4));
	//	_thing_map.insert(ThingMap::value_type(thing5->id, thing5));
	//	_thing_map.insert(ThingMap::value_type(thing6->id, thing6));
	//	_thing_map.insert(ThingMap::value_type(thing7->id, thing7));
	//	_thing_map.insert(ThingMap::value_type(thing8->id, thing8));
	//	_thing_map.insert(ThingMap::value_type(thing9->id, thing9));
	//	count++;
	//}
	//else if (count == 2)
	//{
	//	_thing_map.insert(ThingMap::value_type(thing1->id, thing1));
	//	_thing_map.insert(ThingMap::value_type(thing2->id, thing2));
	//	_thing_map.insert(ThingMap::value_type(thing3->id, thing3));
	//	_thing_map.insert(ThingMap::value_type(thing4->id, thing4));
	//	_thing_map.insert(ThingMap::value_type(thing5->id, thing5));
	//	_thing_map.insert(ThingMap::value_type(thing6->id, thing6));
	//	_thing_map.insert(ThingMap::value_type(thing7->id, thing7));
	//	_thing_map.insert(ThingMap::value_type(thing8->id, thing8));
	//	count++;
	//}
	//else if (count == 3)
	//{
	//	_thing_map.insert(ThingMap::value_type(thing1->id, thing1));
	//	_thing_map.insert(ThingMap::value_type(thing2->id, thing2));
	//	_thing_map.insert(ThingMap::value_type(thing3->id, thing3));
	//	_thing_map.insert(ThingMap::value_type(thing4->id, thing4));
	//	_thing_map.insert(ThingMap::value_type(thing5->id, thing5));
	//	_thing_map.insert(ThingMap::value_type(thing6->id, thing6));
	//	count++;
	//}
	//else if (count == 4)
	//{
	//	_thing_map.insert(ThingMap::value_type(thing1->id, thing1));
	//	_thing_map.insert(ThingMap::value_type(thing2->id, thing2));
	//	_thing_map.insert(ThingMap::value_type(thing3->id, thing3));
	//	_thing_map.insert(ThingMap::value_type(thing4->id, thing4));
	//	count++;
	//}
	//else
	//{
	//	_thing_map.insert(ThingMap::value_type(thing1->id, thing1));
	//	_thing_map.insert(ThingMap::value_type(thing2->id, thing2));
	//	_thing_map.insert(ThingMap::value_type(thing3->id, thing3));
	//}
	/*delete thing1;
	delete thing2;
	delete thing3;
	delete thing4;
	delete thing5;
	delete thing6;
	delete thing7;
	delete thing8;
	delete thing9;
	delete thing10;*/
}

