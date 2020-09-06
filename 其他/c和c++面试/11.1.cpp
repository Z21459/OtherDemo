#include <iostream>
#include <vector>
using namespace std;



int main(){
	//迭代器实现插入
	vector<int>a;
	a.push_back(1);
	a.push_back(2);
	for(vector<int>::size_type j = a.size();j>0;j-- ){
		cout << a[j-1];
	} 
	
	return 0;
} 
