#include <iostream>
using namespace std;

class SigleModel
{
private:
	SigleModel() {}
public:
	static SigleModel* init()
	{
		if (sigle_model == NULL)
		{
			sigle_model = new SigleModel();
		}
		return sigle_model;
	}

private:
	static SigleModel *sigle_model;
};

//lock ȷ��һ���߳����ٽ���ʱ����һ���̲߳������ٽ���
//��������߳���Ҫ���룬������ȴ�  ֱ���ͷ�