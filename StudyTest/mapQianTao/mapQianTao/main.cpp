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

	//查找非零最小值的位置
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
	
	cout << "初始数组元素：";
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
	}
	cout << "  每次升级减去2" << endl;
	int total = 0;//总数
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
				//记录下来画红点的位置，否则删除就会出现错误
				if (min == 0)
				{
					cout << "都是0 升级已满" << endl;
					break;
				}
				else
				{
					if (flag)
					{
						cout << "删除" << hotPoint << "红点" << endl;
					}
					cout << "在" << index << "上画红点" << endl;
					hotPoint = index;
					total = (total - 2) <= 1 ? 0 : (total - 2);
					a[index] = (a[index] - 2) > 0 ? (a[index] - 2) : 0;
					flag = true;
					cout << "升级后剩余:" << total << endl;
					cout << "现在数组元素：";
					for (int i = 0; i < a.size(); i++) {
						cout << a[i];
					}
				}
			}
			if (total < min)
			{
				cout << "删除" << hotPoint << "红点" << endl;
				flag = false;
				cout << "最后剩余:" << total << "  不满足最小升级条件" << endl;
				cout << "\n";
				total = total;
				break;
			}
		}
	}
	//printf("min=%d", min);
	//printf("\nmin位置在:%d\n", index);

	system("pause");
	return 0;
}

