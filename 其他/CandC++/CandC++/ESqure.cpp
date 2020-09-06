#include <iostream>
#include <ctime>
#include <Windows.h>
#include <cstdlib>
#include <cstring>
using namespace std;

//定义地图大小
#define HEIGHT 20
#define WIDTH 20
//构建数组地图
static int Mapsize[HEIGHT][WIDTH] = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

//方块初始阿虎位置
int Ix = 1;
int Iy = 8;

//方块形状
int SqureT[3][3] = {
	0,2,0,
	2,2,2,
	0,0,0,
};

//clear picture
void ClearSqure() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {//绘制初始化方块位置
			Mapsize[i + Ix][j + Iy] = 0;
		}
	}
}
void InitSqure() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {//绘制初始化方块位置
			Mapsize[i + Ix][j + Iy] = SqureT[i][j];
		}
	}
}
//绘制地图
void Drawmap(const int Mapsize[HEIGHT][WIDTH], int heigth, int width) {
	int nLen = 20 * 20 * 3 + 20 + 1;
	char strback[20 * 20 * 3 + 20 + 1] = { 0 };
	for (int i = 0; i < heigth; i++) {
		for (int j = 0; j < width; j++) {
			switch (Mapsize[i][j]) {
			case 0:
				strcat_s(strback, nLen, "  ");
				//std::cout << "  ";
				break;
			case 1:
				strcat_s(strback, nLen, "★");//
				//std::cout << "★";
				break;
			case 2:
				strcat_s(strback, nLen, "□");//闪烁 去除
				//std::cout << "□";
				break;
			case 3:
				strcat_s(strback, nLen, "■");//到底失心
				//std::cout << "□";
				break;
			}
		}
		strcat_s(strback, nLen, "\n");
		//cout << endl;
	}
	cout << strback;

}
//到底厅
void Stop() {
	if (Ix + 3 == 19) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				Mapsize[Ix+i][Iy+j] = 3;
			}
		}
		Ix = 1;
	}
}
#include <vector>
int f1(int n) {
	int ret = 1;
	if (n == 0)
		return ret;
	while (n > 0) {
		ret = ret * 2;
		n--;
	}
	return ret;
}
void f(unsigned int &a) {
	
	vector<int> ret;
	int temp = 0;
	while (a != 1) {
		temp = a % 2;
		//cout << "temp" << temp;
		ret.push_back(temp);
		a = a / 2;
		//cout << "temp" << temp;
		if (a == 1) {
			ret.push_back(a);
			ret.push_back(0);
		}
	}
	//cout << "ret.size()" << ret.size() << endl;
	int result = 0, k = 0;
	for (int i = ret.size() - 1; i >= 0; i--) {
		cout << ret[i];
		result = result + ret[i] * f1(k++);
	}
	a = result; //
}

int maine() {
	unsigned int a;
	cin >> a;
	f(a);
	cout << "\n" << a;

	system("pause");
	return 0;

	/*srand((unsigned int )time(NULL));//创建随机时间戳
	//画图初始化
	while (1) {
		system("cls");
		InitSqure();
		Stop();
		Drawmap(Mapsize, HEIGHT, WIDTH);
		ClearSqure();
		Ix++;
		Sleep(500);

	}

	getchar();
	//system("pause");
	//return 0;*/
}