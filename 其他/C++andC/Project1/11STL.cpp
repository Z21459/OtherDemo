#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <fstream>//�ļ�����
#include <algorithm>//STL�ڲ��㷨��

using namespace std;

//������ iterator  ���� container  �㷨 Algorithm 
//STL��׼ģ���  ���溬��model  ģ�� template  ��Ч��c++��
//˳������  vector string deque(˫�����) list
//��������  set  map   multiset  multimap
//������ stack queue priority_queue


//vector(һ�������ڴ�ռ䣬֧������洢��������Ч�洢�����ں���ɾ ����ѡ��) list(һ�β������ռ䡣�����Ҫ������ɾ�������Ĵ洢������ѡ��)��
//vector ɾ��Ԫ�غ�  �����Զ���ǰ�� ��䡣listɾ�� erase��ǰ�ڵ� ���ǿ���ͨ��erase�ķ���ֵ�õ�ԭ�������һ��Ԫ�ء�


//map�ڲ���һ��ƽ�������(�����ʵ��)
//map��hashmap  �ײ㣺������͹�ϣ��ǰ�߿����Զ����ռ�ֵ���򣬺���ƽ��ʱ�临�ӶȽӽ�����

//vector�е�erase��algorithm�е�remove��ǰ��������ɾ�� �����������Է��ʣ��������Ƶ����λ�ã����������Է��ʡ�

//����ָ��
//auto_ptr��֤���쳣�׳�ʱ������Ķ����ܱ��Զ����٣��ڴ汻�ͷ�

//�������� ��������һ����()�����������Ķ��󣬿�����һ������һ��ʹ��

void  Sort(vector<int>&data) {//���ݲ�������
	int i, j;
	int count = data.size();
	for (i = 0; i < count; i++) {
		j = i - 1;
		for (; j >= 0; --j) {
			if (data[j] <= data[i]) {//�ҵ�����λ��
				break;
			}
		}
		if (j != i - 1) {
			int temp = data[i];
			for (int k = i; k > j + 1; --k) {
				data[k] = data[k - 1];//���ƶ�һλ
			}
			data[j + 1] = temp;
		}
	}
}
int main11() {
	//vector �ڲ�ʹ�ö�̬����ʵ��
	//vector<int> a;
	//a.push_back(1);
	//a.push_back(3);
	//cout << a.capacity() << endl;
	////ʹ�õ����� itertor
	//for (vector<int>::size_type i = a.size(); i > 0; --i) {//����erase�󣬺����Ԫ���Զ�ǰ�ƶ�һλ
	//	cout << a[i-1];
	//}

	//typedef vector<int> IntArr;
	//IntArr arry;
	//arry.push_back(1);
	//arry.push_back(2);
	//arry.push_back(2);
	//arry.push_back(3);
	//for (IntArr::iterator itro = arry.begin(); itro != arry.end(); ++itro) {
	//	if (*itro == 2) {
	//		arry.erase(itro);
	//		--itro;
	//	}
	//}
	//for (vector<int>::size_type i = arry.size(); i > 0; --i) {
	//	cout << arry[i - 1];
	//}

	//vector<int>data;
	//ifstream in("da.txt");
	//if (!in) {
	//	cout << "error";
	//	return -1;
	//}
	//int temp;
	//while (in.eof()) {//��Ϊ��
	//	in >> temp;//���ݴ򿪱���
	//	data.push_back(temp);
	//}
	//in.close();
	//Sort(data);
	//ofstream out("out.txt");
	//if (!out) {
	//	cout << "error";
	//	return 1;
	//}
	//for (int i = 0; i < data.size(); i++) {
	//	out << data[i];//���ļ������������ data�� ����֮��
	//}
	//out.close();

	//set<string>str;
	//set<string>::iterator s;

	//map<int, string>mapstring;//��ֵint ֵΪstring 

	//mapstring.insert(pair<int, string>(1, "one"));//����
	//mapstring[1] = "two";//��1 �Ѿ����� ����ֵ  earse(1) ɾ����1 ��ֵ
	//cout << mapstring[1];//��ӡ
	//map<int, string>::iterator f = mapstring.find(1);//����ֵ

	//str.insert("1");
	//for (s = str.begin(); s != str.end(); s++) {
	//	cout << *s;
	//}

	//reverse �������� ��ȫ�ֺ������������� ��һ��ָ�������Χͷָ�룬�ڶ���ָ���������βָ��
	//int a[4] = { 1,2,3,4 };
	//vector<int>b;
	//b.push_back(1);
	//b.push_back(2);
	//reverse<int [4]>(a, a + 4);//ͷβָ��
	//reverse<vector<int>::iterator>(b.begin(), b.end());//����������ָ��

	system("pause");
	return 0;
}