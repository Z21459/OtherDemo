#include"UserManager.h"
#include <ctime>
int mainm()
{

	//UserManager usermanager;
	//ConfigManager configmanager;
	//configmanager.loadConfig();
	//usermanager.packReward();
	//ConfigItem configitem;
	//string str;
	//configitem.fromRow(str);
	//Config config;
	//config.fromRow();

	//���ҷ�����Сֵ��λ��
	int count_total = 0;
	
	vector<int>a;
	a.push_back(0);
	a.push_back(0);
	a.push_back(0);
	a.push_back(0);
	a.push_back(0);
	a.push_back(0);
	a.push_back(0);
	a.push_back(0);
	int hotPoint = 0;
	bool flag = false;
	
	cout << "��ʼ����Ԫ�أ�";
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
	}
	cout << "  ÿ��������ȥ2" << endl;
	int total = 0;//����
	while (1)
	{	
		cin >> count_total;
		total = count_total + total;
		while (total) {
			int min = a[0];
			int index = 0;
			for (int i = 1; i < a.size(); i++) {
				if (min == 0) {
					min = a[i];
					index = i;
				}
			}
			/*if (min == 0)
			{
				return 0;
			}*/
			for (int i = 0; i < a.size(); i++) {
				if (min > a[i] && a[i] > 0) {
					min = a[i];
					index = i;
				}
			}
			if (total >= min)
			{
				//��¼����������λ�ã�����ɾ���ͻ���ִ���
				if (min == 0)
				{
					cout << "����0 ��������" << endl;
					break;
				}
				else
				{
					if (flag)
					{
						cout << "ɾ��" << hotPoint << "���" << endl;
					}
					cout << "��" << index << "�ϻ����" << endl;
					hotPoint = index;
					total = (total - 2) <= 1 ? 0 : (total - 2);
					a[index] = (a[index] - 2) > 0 ? (a[index] - 2) : 0;
					flag = true;
					cout << "������ʣ��:" << total << endl;
					cout << "��������Ԫ�أ�";
					for (int i = 0; i < a.size(); i++) {
						cout << a[i];
					}
				}
			}
			if (total < min)
			{
				cout << "ɾ��" << hotPoint << "���" << endl;
				flag = false;
				cout << "���ʣ��:" << total << "  ��������С��������" << endl;
				cout << "\n";
				total = total;
				break;
			}
		}
	}
	//printf("min=%d", min);
	//printf("\nminλ����:%d\n", index);

	system("pause");
	return 0;
}

