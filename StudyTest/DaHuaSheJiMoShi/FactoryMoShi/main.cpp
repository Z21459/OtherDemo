#include <iostream>
#include <vector>

using namespace std;

//static const int N = 2;
//static const int M = 3;
//int oddCells(int n, int m, vector<vector<int>>& indices) {
//	int oddNum = 0;
//	int arr[N][M];
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			arr[i][j] = 0;
//		}
//	}
//	for (int i = 0; i < indices.size(); i++)
//	{
//		int row = indices[i][0];//获得行++
//		int clo = indices[i][1];//获得列++
//		if (row < n)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				arr[row][j] = arr[row][j] + 1;
//			}
//		}
//		if (clo < m)
//		{
//			for (int k = 0; k < n; k++)
//			{
//				arr[k][clo] = arr[k][clo] + 1;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (arr[i][j] % 2 != 0) oddNum++;
//		}
//	}
//	return oddNum;
//}

vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
	vector<vector<int>> ans;
	vector<int>t1, t2;
	int n = colsum.size();
	for (int i = 0; i < n; i++) {
		if (colsum[i] == 0)
		{
			t1.push_back(0);
			t2.push_back(0);
		}
		else if (colsum[i] == 1) {//这一块 交替减去1 防止在最后面出现2
			if (upper > lower) {
				t1.push_back(1);
				t2.push_back(0);
				upper--;
			}
			else {
				t2.push_back(1);
				t1.push_back(0);
				lower--;
			}
		}
		else if (colsum[i] == 2) {
			t1.push_back(1);
			t2.push_back(1);
			upper--;
			lower--;
		}

	}
	if (upper != 0 || lower != 0)
		return ans;
	else {
		ans.push_back(t1);
		ans.push_back(t2);

	}
	return ans;
}
int main()
{
	//vector<vector<int>>indices;
	//vector<int> p;
	//p.push_back(0);
	//p.push_back(1);
	//vector<int> p1;
	//p1.push_back(1);
	//p1.push_back(1);
	//indices.push_back(p);
	//indices.push_back(p1);
	//for (int i = 0; i < indices.size(); i++)
	//{
	//	cout << indices[i][0] << indices[i][1] << endl;
	//}
	//
	//int addnum = oddCells(2, 3, indices);
	//cout << addnum;

	vector<int>colsum;
	colsum.push_back(2);
	colsum.push_back(1);
	colsum.push_back(2);
	colsum.push_back(0);
	colsum.push_back(1);
	colsum.push_back(0);
	colsum.push_back(1);
	colsum.push_back(2);
	colsum.push_back(0);
	colsum.push_back(1);
	vector<vector<int>> p = reconstructMatrix(5,5,colsum);
	cout << endl;
	system("pause");
	return 0;
}