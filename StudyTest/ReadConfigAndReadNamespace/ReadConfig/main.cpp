#include <iostream>
#include <string.h>
#include <Windows.h>

#define MAX_PATH 1024

//读取字符串 DWORD GetPrivateProfileString()  返回值是Long
//读整数 UINT GetPrivateProfileInt()

//写入字符串 BOOL WritePrivateProfileString()
//写入整数，没有相关函数，可以通过写入字符串进行转换


int main1() {

	//写入配置
	/*LPTSTR lpPath = new char[MAX_PATH];

	strcpy_s(lpPath, MAX_PATH,"./Setting.ini");

	WritePrivateProfileString("LiMing", "Sex", "Man", lpPath);
	WritePrivateProfileString("LiMing", "Age", "20", lpPath);

	WritePrivateProfileString("Fangfang", "Sex", "Woman", lpPath);
	WritePrivateProfileString("Fangfang", "Age", "21", lpPath);

	delete[] lpPath;*/


	//读取配置文件
	LPTSTR lpPath1 = new char[MAX_PATH];
	LPTSTR LiMingSex = new char[6];
	int LiMingAge;
	LPTSTR FangfangSex = new char[6];
	int FangfangAge;
	strcpy_s(lpPath1, MAX_PATH, "./Setting.ini");

	GetPrivateProfileString("LiMing", "Sex", "", LiMingSex, 6, lpPath1);
	LiMingAge = GetPrivateProfileInt("LiMing", "Age", 0, lpPath1);

	GetPrivateProfileString("Fangfang", "Sex", "", FangfangSex, 6, lpPath1);
	FangfangAge = GetPrivateProfileInt("Fangfang", "Age", 0, lpPath1);

	delete[] lpPath1;




	std::cout << LiMingSex << " " << LiMingAge << "\n" << FangfangSex << " " << FangfangAge;


	system("pause");
	return 0;
}