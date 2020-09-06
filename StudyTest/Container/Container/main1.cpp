#include <iostream>
#include <vector>
#include<algorithm>
#include <string>
using namespace std;

struct testStruct
{
	int a;
	int b;
	int c;
};
vector<testStruct>testStructVector;

bool Cmp(testStruct left)
{
	return left.a == 2 && left.b == 4;//根据特定去比较
}
//bool Cmp1(testStruct &left, testStruct &right)
//{
//	return left.a == right.a; //&&left.b > right.b;//根据特定去比较
//}

void test()
{
	testStruct struct1;
	testStruct struct2;
	testStruct struct3;
	struct1.a = 3;
	struct1.b = 3;
	struct1.c = 1;

	struct2.a = 3;
	struct2.b = 3;
	struct2.c = 2;

	struct3.a = 2;
	struct3.b = 3;
	struct3.c = 3;
	testStructVector.push_back(struct1);
	testStructVector.push_back(struct2);
	testStructVector.push_back(struct3);
	std::vector<int> nums_new;
//	std::unique_copy(testStructVector.begin(), testStructVector.end(), std::back_inserter(nums_new), Cmp1);
		
		
		
	auto rep = [](testStruct left, testStruct right)
	{
		return left.a == right.a;
	};
	

	auto find_same = unique(testStructVector.begin(), testStructVector.end(), rep);
	if (find_same != testStructVector.end())
	{
		;
	}

	//auto itrFind = find_if(testStructVector.begin(), testStructVector.end(), [](testStruct myStruct)
	//{
	//	return myStruct.a > 2 && myStruct.b < 8;//根据特定去比较
	//});
	auto itrFind = find_if(testStructVector.begin(), testStructVector.end(), Cmp);

	//for (int i = 0; i < testStructVector.size(); i++)
	//{
	//	for (int j = 0; j < testStructVector.size(); j++)
	//	{
	//		if (testStructVector[i].a == testStructVector[j].a && testStructVector[j].a == 2 &&
	//			testStructVector[i].b == testStructVector[j].b && testStructVector[j].b == 4)
	//		{
	//			cout << "okk" << endl;
	//		}
	//	}
	//}
	if (itrFind != testStructVector.end())
		cout << "found!";
	else
		cout << "not found!";
}

int main1()
{
	test();
	system("pause");
	return 0;
}