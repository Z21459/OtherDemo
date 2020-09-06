#pragma once
#ifndef BATTLE
#define BATTLE

class Battle {
public:
	Battle();
	~Battle();
	//初始化屏幕
	void Initscreen();
		//两人战斗
	void TwoPeopleBattle();
private:
	int Battle_Score[2];//两个人的分数
	int Battle_Blood[2];//两个人的血量
	bool Battle_Flag[2];//标记1和2的战斗情况

};



#endif // !BATTLE

