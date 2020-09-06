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

//lock 确保一个线程在临界区时，另一个线程不进入临界区
//如果其他线程想要进入，这继续等待  直到释放