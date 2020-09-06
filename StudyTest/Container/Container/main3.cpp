#include <iostream>     // std::cout
#include <algorithm>    // std::unique_copy, std::sort, std::distance
#include <vector>       // std::vector
using namespace std;

int main3(int argc, char* argv[])
{
	int a[10] = { 1,3,6,4,7,2,3,4,8,9 }; // 1,2,3,3,4,4,6,7,8,9
	vector<int> ivec(a, a + 10);


	sort(ivec.begin(), ivec.end());// 1,2,3,3,4,4,6,7,8,9    



	vector<int>::iterator pos;
	pos = std::unique(ivec.begin(), ivec.end());  //1,2,3,4,6,7,8,9,3,4

	vector<int> result;
	
	//result.insert(pos, ivec.end());

	//earse(pos, ivec.end());     //1,2,3,4,6,7,8,9     
	cout << endl;

	//std::vector<int> vec;
	//vec.push_back(21);
	//vec.push_back(3);
	//vec.push_back(2);
	//vec.push_back(1);
	//vec.push_back(1);
	//vec.push_back(1);
	//vec.push_back(8);
	//vec.push_back(4);
	//vec.push_back(22);
	//std::vector<int> vec1(vec.begin(), vec.end());
	//std::sort(vec1.begin(), vec1.end());
	//std::vector<int> vec2;
	//	if (vec1.size() <= 1) return vec1.size();
	//	int i = 0;
	//	for (int j = 1; j < vec1.size(); ++j) {
	//		if (vec1[i] != vec1[j]) vec1[++i] = vec1[j];
	//		else vec2.push_back(vec1[j]);
	//	}
	//
	//	cout << endl;
	//std::sort(vec.begin(), vec.end());
	//std::vector<int>::iterator iter1;
	//for (iter1 = vec.begin(); iter1 != vec.end(); iter1++)
	//{
	//	printf("%d\n", (*iter1));
	//	cout << " ";
	//}
	//cout << endl;

	//std::vector<int>::iterator iter;
	////iter = std::unique(vec.begin(), vec.end());

	////for (iter = vec.begin(); iter != vec.end(); iter++)
	////{
	////	printf("%d\n", (*iter));
	////	cout << " ";
	////}
	////cout << endl;
	////vec.erase(iter, vec.end());

	//for (iter = vec.begin(); iter != vec.end(); iter++)
	//{
	//	printf("%d\n", (*iter));
	//	cout << " ";
	//}
	system("pause");

	return 0;
}