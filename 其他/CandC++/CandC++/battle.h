#pragma once
#ifndef BATTLE
#define BATTLE

class Battle {
public:
	Battle();
	~Battle();
	//��ʼ����Ļ
	void Initscreen();
		//����ս��
	void TwoPeopleBattle();
private:
	int Battle_Score[2];//�����˵ķ���
	int Battle_Blood[2];//�����˵�Ѫ��
	bool Battle_Flag[2];//���1��2��ս�����

};



#endif // !BATTLE

