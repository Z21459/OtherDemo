#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <fstream>//文件操作
#include <algorithm>//STL内部算法库

using namespace std;

//迭代器 iterator  容器 container  算法 Algorithm 
//STL标准模板库  里面含有model  模板 template  高效的c++库
//顺序容器  vector string deque(双向队列) list
//关联容器  set  map   multiset  multimap
//适配器 stack queue priority_queue


//vector(一段连续内存空间，支持随机存储。如果想高效存储，不在乎增删 可以选择) list(一段不连续空间。如果需要大量增删，不关心存储，可以选择)。
//vector 删除元素后  后面自动往前移 填充。list删除 erase当前节点 但是可以通过erase的返回值得到原链表的下一个元素。


//map内部是一个平衡二叉树(红黑树实现)
//map和hashmap  底层：红黑树和哈希表；前者可以自动按照键值排序，后者平均时间复杂度接近常数

//vector中的erase和algorithm中的remove：前者是真正删除 迭代器不可以访问，后者是移到最后位置，迭代器可以访问。

//智能指针
//auto_ptr保证当异常抛出时，分配的对象能被自动销毁，内存被释放

//函数对象 就是重载一个“()”运算符的类的对象，可以像一个函数一样使用

void  Sort(vector<int>&data) {//数据插入排序
	int i, j;
	int count = data.size();
	for (i = 0; i < count; i++) {
		j = i - 1;
		for (; j >= 0; --j) {
			if (data[j] <= data[i]) {//找到插入位置
				break;
			}
		}
		if (j != i - 1) {
			int temp = data[i];
			for (int k = i; k > j + 1; --k) {
				data[k] = data[k - 1];//后移动一位
			}
			data[j + 1] = temp;
		}
	}
}
int main11() {
	//vector 内部使用动态数组实现
	//vector<int> a;
	//a.push_back(1);
	//a.push_back(3);
	//cout << a.capacity() << endl;
	////使用迭代器 itertor
	//for (vector<int>::size_type i = a.size(); i > 0; --i) {//调用erase后，后面的元素自动前移动一位
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
	//while (in.eof()) {//不为空
	//	in >> temp;//数据打开保存
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
	//	out << data[i];//将文件中数据输出到 data中 排序之后
	//}
	//out.close();

	//set<string>str;
	//set<string>::iterator s;

	//map<int, string>mapstring;//键值int 值为string 

	//mapstring.insert(pair<int, string>(1, "one"));//插入
	//mapstring[1] = "two";//键1 已经存在 更新值  earse(1) 删除键1 的值
	//cout << mapstring[1];//打印
	//map<int, string>::iterator f = mapstring.find(1);//查找值

	//str.insert("1");
	//for (s = str.begin(); s != str.end(); s++) {
	//	cout << *s;
	//}

	//reverse 函数逆置 是全局函数，两个参数 第一个指向操作范围头指针，第二个指向操作函数尾指针
	//int a[4] = { 1,2,3,4 };
	//vector<int>b;
	//b.push_back(1);
	//b.push_back(2);
	//reverse<int [4]>(a, a + 4);//头尾指针
	//reverse<vector<int>::iterator>(b.begin(), b.end());//迭代器两个指针

	system("pause");
	return 0;
}