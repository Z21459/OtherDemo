#include <iostream>
#include <string.h>
#include <Windows.h>

#define MAX_PATH 1024

//��ȡ�ַ��� DWORD GetPrivateProfileString()  ����ֵ��Long
//������ UINT GetPrivateProfileInt()

//д���ַ��� BOOL WritePrivateProfileString()
//д��������û����غ���������ͨ��д���ַ�������ת��


int main1() {

	//д������
	/*LPTSTR lpPath = new char[MAX_PATH];

	strcpy_s(lpPath, MAX_PATH,"./Setting.ini");

	WritePrivateProfileString("LiMing", "Sex", "Man", lpPath);
	WritePrivateProfileString("LiMing", "Age", "20", lpPath);

	WritePrivateProfileString("Fangfang", "Sex", "Woman", lpPath);
	WritePrivateProfileString("Fangfang", "Age", "21", lpPath);

	delete[] lpPath;*/


	//��ȡ�����ļ�
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