#pragma once
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

//һ�Զ����   һ������  ����۲�  ��ֽ�Ͷ��ı�ֽ��ʵ��
//Head First
static const int FLAGSAVE = 1;
class Object
{
public:
	Object(){}
	~Object(){}
public:
	virtual void update(float temp, float humid, float pressur) {};
};

class Subject
{
public:
	Subject(){}
	~Subject(){}

public:
	virtual void registObject(Object *obj) {};
	virtual void removeObject(Object *obj) {};
	virtual void notifyAll() {};//����ı�֪ͨ����
};

class Display
{
public:
	Display(){}
	~Display(){}
public:
	virtual void display() {};//��ʾ���ʹ��
};
typedef map<Object*, int> ObjectMap;
class Weather :public Subject
{
public:
	Weather(){}
	~Weather(){}
private:
	float _temp;
	float _humid;
	float _pressur;
	ObjectMap _obj_map;
public:
	void registObject(Object *obj)
	{
		if (obj)
			_obj_map.insert(ObjectMap::value_type(obj, FLAGSAVE));
	}
	void removeObject(Object *obj)
	{
		ObjectMap::iterator iter = _obj_map.find(obj);
		if (iter != _obj_map.end())
		{
			_obj_map.erase(iter);
		}
	}
	void notifyAll()
	{
		ObjectMap::iterator iter = _obj_map.begin();
		for (; iter != _obj_map.end(); iter++)
		{
			Object *object = iter->first;//�õ� ÿ��֪ͨ
			object->update(_temp,_humid,_pressur);
		}
	}
	//�������� ��֪ͨ
	void dataChange()
	{
		notifyAll();
	}
	//�õ��ڲ�����״̬
	float getTemp()
	{
		return _temp;
	}
	float getHumid()
	{
		return _humid;
	}
	float  getPressur()
	{
		return _pressur;
	}

	void setData(float temp, float humid, float pressur)
	{
		_temp = temp;
		_humid = humid;
		_pressur = pressur;
		dataChange();
	}
	//��������
};

//��ʾ������ ���岼���� ���ؼ̳�
class CurDiaplay :public Object, public Display
{
public:
	CurDiaplay(){}
	CurDiaplay(){}
private:
	float _temp;
	float _humid;
	float _pressur;
	Weather *_wea_data;//��������
	
public:
	CurDiaplay(Weather *wea_data)//��������  ���ܹ������麯����
	{
		this->_wea_data = wea_data;
		wea_data->registObject(this);
	}
	void update(float temp, float humid, float pressur)
	{
		_temp = temp;
		_humid = humid;
		display();
	}
	void diaplay()
	{
		cout << "111" << endl;
	}
};

//�ͻ���
void ClientStart()
{

	Weather *wea = new Weather();
	CurDiaplay *cur_dis = new CurDiaplay(wea);
	//������ʵ�ֵķ��� ��CurDiaply����
	wea->setData(80, 65, 30.1);
};













//����ӿ� ֪ͨ��  ֪ͨ�������������߶��  ��ȷ��
class Subject
{
public:
	virtual void Attach(/*GuanCaZhe* guanca*/) {}
	virtual void Detach(/*GuanCaZhe* guanca*/) {}
	virtual void Notify() {}
	string SubjectState() { return ""; }
};


class GuanCaZhe
{
public:
	GuanCaZhe();
	~GuanCaZhe();
public:
	//����ĸĳɳ���֪ͨ��Subject
	GuanCaZhe(string name, Subject *sub)
	{
		this->name = name;
		this->sub = sub;
	}
	virtual void upDate()
	{
		//cout << "close" << name;
	}
private:
	string name;
	Subject *sub;
};




class Boss :public Subject
{
private:
	list<GuanCaZhe*>list_guan;
	string action;

public:
	void Attach(GuanCaZhe *obser)
	{
		list_guan.push_back(obser);//���۲��� �����б� ����֪ͨ
	}

	void Detach(GuanCaZhe *obser)
	{
		list_guan.remove(obser);
	}

	void Notify()
	{
		//֪ͨ ���еǼǵ���
		for (auto o : list_guan)
		{
			//֪ͨ�б��������
			o->upDate();
		}
	}
	//ǰ̨�õ�״̬
	string BossAction()
	{
		return action;//
	}
};

class Secretary:public Subject
{
private:
	list<GuanCaZhe*>list_guan;
	string action;

public:
	void Attach(GuanCaZhe *obser) 
	{
		list_guan.push_back(obser);//���۲��� �����б� ����֪ͨ
	}
	
	void Detach(GuanCaZhe *obser)
	{
		list_guan.remove(obser);
	}
	
	void Notify()
	{
		//֪ͨ ���еǼǵ���
		for (auto o : list_guan)
		{
			//֪ͨ�б��������
			o->upDate();
		}
	}
	//ǰ̨�õ�״̬
	string SecretAction()
	{
		return action;//
	}
};

//����۲��� �̳л���
class GuanCaA :public GuanCaZhe
{
public:
	//����ĸĳɳ���֪ͨ��Subject *sub
	GuanCaA(string name, Subject *sub) :GuanCaZhe(name, sub)
	{

	}
	void upDate()
	{
		cout << "closeA";
	}
};

