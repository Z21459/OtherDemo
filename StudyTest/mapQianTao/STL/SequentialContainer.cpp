#include <iostream>
#include <vector>
#include <list>
#include <deque>//˫�����
using namespace std;
/*
˳������--���Ա�  ���Խṹ 
vector �൱������ �Ӻ�����ٲ����ɾ��   ֱ�ӷ���Ԫ��
deque  ��ǰ��ͺ�����ٲ����ɾ��   ֱ�ӷ����κ�Ԫ��
list ˫���� ���κεط����ٲ����ɾ��

������������ȡ���������ݵĲ����ɾ��  deque��õ�ѡ��
*/


int mains()
{
	vector<int>vec;
	vec.push_back(1);
	vec.push_back(2);

	vector<int>vec1;
	vec1.push_back(3);
	vec1.push_back(2);

	vector<int>vec2;
	vec2.push_back(5);
	vec2.push_back(6);

	vec.insert(vec.end(), vec1.begin(), vec1.end());
	vec.insert(vec.end(), vec2.begin(), vec2.end());

	deque<int>de;
	de.push_back(1);//β����
	de.push_back(2);
	de.push_front(3);//ͷ����

	//cout << vec.at(1);����λ��

	list<int>m_list;
	m_list.push_back(1);
	m_list.push_back(2);
	m_list.push_front(3);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
		//cout << de[i] << endl;
	}
	/*list<int>::iterator it = m_list.begin();

	for (; it!=m_list.end();it++) 
	{
		cout << *it << endl;
	}*/
	system("pause");
	return 0;
}